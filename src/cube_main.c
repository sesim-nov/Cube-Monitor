#include <stdio.h>
#include "cube.h"
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main(){
	printf("CubeSat Monitoring Loop Running with PID: %i\n", getpid());
	cube_event_loop();
	return 0;
	}
