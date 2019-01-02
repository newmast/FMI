PROG = app
CC = g++
OBJS = main.o CommandResolver.o InsertCommand.o DeleteCommand.o FindCommand.o TraverseCommand.o ExitCommand.o BinarySearchTree.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) -c main.cpp
CommandResolver.o : CommandResolver.h
	$(CC) -c CommandResolver.cpp
InsertCommand.o : InsertCommand.h
	$(CC) -c InsertCommand.cpp
DeleteCommand.o : DeleteCommand.h
	$(CC) -c DeleteCommand.cpp
FindCommand.o : FindCommand.h
	$(CC) -c FindCommand.cpp
TraverseCommand.o : TraverseCommand.h
	$(CC) -c TraverseCommand.cpp
ExitCommand.o : ExitCommand.h
	$(CC) -c ExitCommand.cpp
Student.o : Student.h
	$(CC) -c Student.cpp
BinarySearchTree.o : BinarySearchTree.h
	$(CC) -c BinarySearchTree.cpp
clean:
	rm -f core $(PROG) $(OBJS)
