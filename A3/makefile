./a.out:ass3_20CS30043_20CS30062.o lex.yy.o
	gcc ass3_20CS30043_20CS30062.o lex.yy.o

ass3_20CS30043_20CS30062.o:ass3_20CS30043_20CS30062.c 
	gcc -c ass3_20CS30043_20CS30062.c

lex.yy.o:lex.yy.c
	gcc -c lex.yy.c -lfl

lex.yy.c:ass3_20CS30043_20CS30062.l
	flex ass3_20CS30043_20CS30062.l

run:./a.out
	./a.out ass3_20CS30043_20CS30062_test.c 
clean:
	rm lex.yy.c ./a.out output.txt lex.yy.o ass3_20CS30043_20CS30062.o
