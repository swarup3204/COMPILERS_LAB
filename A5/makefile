./a.out:ass5_20CS30062_20CS30043_translator.o ass5_20CS30062_20CS30043.tab.o lex.yy.o
		g++ ass5_20CS30062_20CS30043_translator.o ass5_20CS30062_20CS30043.tab.o lex.yy.o -lfl


ass5_20CS30062_20CS30043.tab.o:ass5_20CS30062_20CS30043.tab.c ass5_20CS30062_20CS30043.tab.h
							g++ -c ass5_20CS30062_20CS30043.tab.c

ass5_20CS30062_20CS30043_translator.o:ass5_20CS30062_20CS30043_translator.cxx ass5_20CS30062_20CS30043_translator.h
							g++ -c ass5_20CS30062_20CS30043_translator.cxx

lex.yy.o:lex.yy.c
		g++ -c lex.yy.c

lex.yy.c:ass5_20CS30062_20CS30043.l ass5_20CS30062_20CS30043.tab.h ass5_20CS30062_20CS30043_translator.h
		flex ass5_20CS30062_20CS30043.l

ass5_20CS30062_20CS30043.tab.c ass5_20CS30062_20CS30043.tab.h ass5_20CS30062_20CS30043.output:ass5_20CS30062_20CS30043.y ass5_20CS30062_20CS30043_translator.h
							bison -dtv ass5_20CS30062_20CS30043.y


run:	
		@echo "Running on test files\n"
		./a.out < test1.c > ass5_20CS30062_20CS30043_quads_1.txt
		./a.out < test2.c > ass5_20CS30062_20CS30043_quads_2.txt
		./a.out < test3.c > ass5_20CS30062_20CS30043_quads_3.txt
	    ./a.out < test4.c > ass5_20CS30062_20CS30043_quads_4.txt
		./a.out < test5.c > ass5_20CS30062_20CS30043_quads_5.txt


clean:
	rm ./a.out ass5_20CS30062_20CS30043_translator.o ass5_20CS30062_20CS30043.tab.o lex.yy.o ass5_20CS30062_20CS30043.tab.c ass5_20CS30062_20CS30043.tab.h lex.yy.c ass5_20CS30062_20CS30043.output ass5_20CS30062_20CS30043_quads_[0-9].txt