main: client
	
client: events client-tcp
	gcc -Wall src/client/cube_loop.o src/client/cube_tcp.o src/client/cube_main.c -o cubeclient

events:
	gcc -Wall -c src/client/event_loop.c -o src/client/cube_loop.o

client-tcp:
	gcc -Wall -c src/client/cube_tcp.c -o src/client/cube_tcp.o

clean:
	rm -rf src/client/*o ./cubeclient
