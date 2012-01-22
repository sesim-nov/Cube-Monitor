#include <stdio.h>
#include "cube.h"
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "cube_tcp.h"

int main(){
	printf("CubeSat Monitoring Loop Running with PID: %i\n", getpid());
	tcp_init();
	cube_event_loop();
	return 0;
	}
