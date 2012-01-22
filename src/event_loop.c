#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>

int* continuity; // 0 for closed, 1 for open. 

int mygetch( ) {
  struct termios oldt,
                 newt;
  int            ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}


void cube_process_events(char event){

	switch (event){
		case 'q':
			raise(SIGINT);
			break;
		case 'c':
			raise(SIGUSR1);
			break;
		default:
			puts("Unknown Signal. Continuing...\n");

	}

}

void continuity_change (int signo){
	puts("Continuity Change Detected!\n");
	switch(*continuity){
		case 0:
			*continuity = 1;
			puts("Baloon is OPEN\n");
			break;
		default:
			*continuity = 0;
			puts("Baloon is CLOSED\n");
	}
	signal(SIGUSR1, continuity_change);
}

void sigint_handler (int signo){
	puts("SIGINT caught. Program terminating...\n");
	signal(SIGINT,SIG_DFL);
	raise(SIGINT);
	}

void cube_event_loop () {
	char fromstdin;
	continuity = malloc(sizeof(int));
	*continuity = 0;
	signal(SIGUSR1, continuity_change);
	signal(SIGINT, sigint_handler);
	
	for (;;){
		fromstdin = mygetch();
		cube_process_events(fromstdin);
		sleep(0.5);
		}
	}

