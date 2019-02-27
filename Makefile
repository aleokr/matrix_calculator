CC=gcc
CCFLAGS= -std=c99
TARGET=projektIII

$(TARGET): main.o functions_to_calculate.o calculator_stack.o functions_to_read_file.o tab_stack.o
	$(CC) main.o functions_to_calculate.o calculator_stack.o functions_to_read_file.o tab_stack.o -o $(TARGET)
	
main.o: main.c
	$(CC) $(CCFLAGS) -c main.c

functions_to_calculate.o: functions_to_calculate.c functions_to_calculate.h
	$(CC) $(CCFLAGS) -c functions_to_calculate.c

functions_to_read_file.o: functions_to_read_file.c functions_to_read_file.h
	$(CC) $(CCFLAGS) -c functions_to_read_file.c

calculator_stack.o: calculator_stack.c calculator_stack.h
	$(CC) $(CCFLAGS) -c calculator_stack.c

tab_stack.o: tab_stack.c tab_stack.h
	$(CC) $(CCFLAGS) -c tab_stack.c
	
clean:
	rm -f *.o
	rm -f $(TARGET)
