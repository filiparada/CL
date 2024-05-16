CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

tarea_3: main.o bus.o stop.o passenger.o
	@$(CC) $(CFLAGS) main.o bus.o stop.o passenger.o -o tarea_3

main.o: main.cpp bus.h stop.h
	@$(CC) $(CFLAGS) -c main.cpp

bus.o: bus.cpp bus.h passenger.h
	@$(CC) $(CFLAGS) -c bus.cpp

stop.o: stop.cpp stop.h passenger.h
	@$(CC) $(CFLAGS) -c stop.cpp

passenger.o: passenger.cpp passenger.h
	@$(CC) $(CFLAGS) -c passenger.cpp

clean:
	@rm -f tarea_3 *.o