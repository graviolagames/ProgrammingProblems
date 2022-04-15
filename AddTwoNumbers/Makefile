# A very simple makefile.

addTwoNumbers:Answer.o lList.o
	cc -o addTwoNumbers Answer.o lList.o

Answer.o:Answer.c lList.h 
	cc -c Answer.c

IList.o:IList.c lList.h
	cc -c lList.c

clean:
	rm addTwoNumbers Answer.o lList.o



