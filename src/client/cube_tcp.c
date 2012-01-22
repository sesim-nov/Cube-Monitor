#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct sockaddr_in server_address, client_address;
int tcp_init_switch=0, socket_descriptor, new_socket_des;

int tcp_printstring(char *printhis){
	char strout[128];
	if (tcp_init_switch == 1){
		
		snprintf(strout,sizeof(strout),"This will eventually throw a string to the server. the string will say %s\n", printhis);
		puts(strout);
		return 0;
		}
	else puts("You fucked up. Initialize the tcp library first. \n");
	return -1;
}

void tcp_init(){
	
	tcp_init_switch = 1;
	puts("This will eventually initialize the connection to the server.\n");

	}

