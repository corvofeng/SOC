all:
	flex minic.l
	byacc -d -v minic.y
	gcc -c -g y.tab.c lex.yy.c definition.c CtoMIPS.c
	gcc -o start y.tab.o lex.yy.o definition.o CtoMIPS.o

clean:
	rm -rf *.o
	rm -rf y.tab.c lex.yy.c y.output y.tab.h
