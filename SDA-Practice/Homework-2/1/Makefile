PROG = app
CC = g++
OBJS = main.o CommandResolver.o UpdateCommand.o DeleteCommand.o ExitCommand.o SequentialSearchCommand.o Student.o StudentDb.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) -c main.cpp
CommandResolver.o : CommandResolver.h
	$(CC) -c CommandResolver.cpp
UpdateCommand.o : UpdateCommand.h
	$(CC) -c UpdateCommand.cpp
DeleteCommand.o : DeleteCommand.h
	$(CC) -c DeleteCommand.cpp
ExitCommand.o : ExitCommand.h
	$(CC) -c ExitCommand.cpp
SequentialSearchCommand.o : SequentialSearchCommand.h
	$(CC) -c SequentialSearchCommand.cpp
Student.o : Student.h
	$(CC) -c Student.cpp
StudentDb.o : StudentDb.h
	$(CC) -c StudentDb.cpp
clean:
	rm -f core $(PROG) $(OBJS)
