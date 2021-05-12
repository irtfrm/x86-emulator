TARGET = px86
OBJS = main.o emulator_function.o instruction.o modrm.o

CC = /usr/bin/gcc
CFLAGS += -Wall

.PHONY: all
all :
	make $(TARGET)

%.o : src/%.c Makefile
	$(CC) $(CFLAGS) -c $<

$(TARGET) : $(OBJS) Makefile
	$(CC) -o $@ $(OBJS)
