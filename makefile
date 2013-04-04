
a.out: main.o f_prima_1.o f_prima_2.o runge.o
	cc -lm main.o f_prima_1.o f_prima_2.o runge.o

main.o: main.c
	cc -c main.c

f_prima_1.o: f_prima_1.c
	cc -c f_prima_1.c

f_prima_2.o: f_prima_2.c
	cc -c f_prima_2.c

runge.o: runge.c
	cc -c runge.c

all: a.out

clean:
	rm -f *.o