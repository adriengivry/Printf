CC = gcc
 
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = app
 
all : $(AOUT) 
 
$(AOUT) : $(OBJS)
	$(CC) -o $@ $^
%.o : %.c
	$(CC) -o $@ -c $<
clean :
	@rm *.o
cleaner : clean
	@rm $(AOUT)
