PROG = app
CC = g++
OBJS = main.o CommandResolver.o CreateCommand.o ExitCommand.o SequentialSearchCommand.o Student.o StudentDb.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) -c main.cpp
CommandResolver.o : CommandResolver.h
	$(CC) -c CommandResolver.cpp
CreateCommand.o : CreateCommand.h
	$(CC) -c CreateCommand.cpp
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
