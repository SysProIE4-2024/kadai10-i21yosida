all: mysysmain

mysysmain: mysystem.h mysystem.c mysysmain.c
	cc -Wall -std=c99 -o mysysmain mysysmain.c  mysystem.c

clean:
	rm -f mysysmain

