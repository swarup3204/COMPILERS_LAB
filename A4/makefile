parser:ass4_20CS30062_20CS30043.o ass4_20CS30062_20CS30043.tab.o lex.yy.o 
	cc ass4_20CS30062_20CS30043.o ass4_20CS30062_20CS30043.tab.o lex.yy.o -lfl -o parser
ass4_20CS30062_20CS30043.o:ass4_20CS30062_20CS30043.c 
	cc -c ass4_20CS30062_20CS30043.c
ass4_20CS30062_20CS30043.tab.o:	ass4_20CS30062_20CS30043.tab.c
	cc -c ass4_20CS30062_20CS30043.tab.c
ass4_20CS30062_20CS30043.tab.c ass4_20CS30062_20CS30043.tab.h:	ass4_20CS30062_20CS30043.y
	bison -dtv ass4_20CS30062_20CS30043.y
lex.yy.c:	ass4_20CS30062_20CS30043.l ass4_20CS30062_20CS30043.tab.h
	flex ass4_20CS30062_20CS30043.l
lex.yy.o:	lex.yy.c
	cc -c lex.yy.c
output:	parser ass4_20CS30062_20CS30043_test.c
	./parser ass4_20CS30062_20CS30043_test.c > output.txt
clean:
	rm parser ass4_20CS30062_20CS30043.o ass4_20CS30062_20CS30043.output ass4_20CS30062_20CS30043.tab.* lex.yy.* output.txt

