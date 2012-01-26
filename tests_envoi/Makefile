CC=gcc
CFLAGS=-Wall
OBJS = message_manager_test.o write_to_port.o message_manager.o

all: message_manager_test

message_manager_test: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o message_manager_test
	
message_manager_test.o: message_manager_test.c message_manager_test.h
	$(CC) $(CFLAGS) message_manager_test.c -c

message_manager.o: message_manager.c message_manager.h
	$(CC) $(CFLAGS) message_manager.c -c

write_to_port.o: write_to_port.c write_to_port.h
	$(CC) $(CFLAGS) write_to_port.c -c

clean:
	rm -rf *.o

