main: events
	gcc -Wall src/cube_loop.o src/cube_main.c -o cubemonitor


events:
	gcc -Wall -c src/event_loop.c -o src/cube_loop.o

clean:
	rm -rf src/*o ./cubemonitor
