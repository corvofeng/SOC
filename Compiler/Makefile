all:
	flex test.l
	cc lex.yy.c -ll
	./a.out < test.c

clean:
	rm -rf a.out
	rm -rf lex.yy.c
