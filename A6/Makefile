tinyC_compiler: lex.yy.o ass6_20CS30062_20CS30043.tab.o ass6_20CS30062_20CS30043_translator.o ass6_20CS30062_20CS30043_target_translator.o
	g++ lex.yy.o ass6_20CS30062_20CS30043.tab.o ass6_20CS30062_20CS30043_translator.o ass6_20CS30062_20CS30043_target_translator.o -lfl -o tinyC_compiler

ass6_20CS30062_20CS30043_target_translator.o: ass6_20CS30062_20CS30043_target_translator.cxx
	g++ -c ass6_20CS30062_20CS30043_target_translator.cxx

ass6_20CS30062_20CS30043_translator.o: ass6_20CS30062_20CS30043_translator.h ass6_20CS30062_20CS30043_translator.cxx
	g++ -c ass6_20CS30062_20CS30043_translator.h
	g++ -c ass6_20CS30062_20CS30043_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

ass6_20CS30062_20CS30043.tab.o: ass6_20CS30062_20CS30043.tab.c
	g++ -c ass6_20CS30062_20CS30043.tab.c

lex.yy.c: ass6_20CS30062_20CS30043.l ass6_20CS30062_20CS30043.tab.h ass6_20CS30062_20CS30043_translator.h
	flex ass6_20CS30062_20CS30043.l

ass6_20CS30062_20CS30043.tab.c: ass6_20CS30062_20CS30043.y
	bison -dtv ass6_20CS30062_20CS30043.y

ass6_20CS30062_20CS30043.tab.h: ass6_20CS30062_20CS30043.y
	bison -dtv ass6_20CS30062_20CS30043.y

libass6_20CS30062_20CS30043.a: ass6_20CS30062_20CS30043.o
	ar -rcs libass6_20CS30062_20CS30043.a ass6_20CS30062_20CS30043.o

ass6_20CS30062_20CS30043.o: ass6_20CS30062_20CS30043.c myl.h
	gcc -c ass6_20CS30062_20CS30043.c

ass6_20CS30062_20CS30043.c:
	touch ass6_20CS30062_20CS30043.c

test: tinyC_compiler libass6_20CS30062_20CS30043.a
	@mkdir -p test-outputs
	@mkdir -p bin

	@echo "\nRunning Tests"
	./tinyC_compiler 1 < test1.c > test-outputs/ass6_20CS30062_20CS30043_quads1.out
	mv ass6_20CS30062_20CS30043_1.s test-outputs/ass6_20CS30062_20CS30043_1.s
	gcc -c test-outputs/ass6_20CS30062_20CS30043_1.s -o test-outputs/ass6_20CS30062_20CS30043_1.o
	gcc test-outputs/ass6_20CS30062_20CS30043_1.o -o bin/test1 -L. -lass6_20CS30062_20CS30043 -no-pie

	./tinyC_compiler 2 < test2.c > test-outputs/ass6_20CS30062_20CS30043_quads2.out
	mv ass6_20CS30062_20CS30043_2.s test-outputs/ass6_20CS30062_20CS30043_2.s
	gcc -c test-outputs/ass6_20CS30062_20CS30043_2.s -o test-outputs/ass6_20CS30062_20CS30043_2.o
	gcc test-outputs/ass6_20CS30062_20CS30043_2.o -o bin/test2 -L. -lass6_20CS30062_20CS30043 -no-pie

	./tinyC_compiler 3 < test3.c > test-outputs/ass6_20CS30062_20CS30043_quads3.out
	mv ass6_20CS30062_20CS30043_3.s test-outputs/ass6_20CS30062_20CS30043_3.s
	gcc -c test-outputs/ass6_20CS30062_20CS30043_3.s -o test-outputs/ass6_20CS30062_20CS30043_3.o
	gcc test-outputs/ass6_20CS30062_20CS30043_3.o -o bin/test3 -L. -lass6_20CS30062_20CS30043 -no-pie

	./tinyC_compiler 4 < test4.c > test-outputs/ass6_20CS30062_20CS30043_quads4.out
	mv ass6_20CS30062_20CS30043_4.s test-outputs/ass6_20CS30062_20CS30043_4.s
	gcc -c test-outputs/ass6_20CS30062_20CS30043_4.s -o test-outputs/ass6_20CS30062_20CS30043_4.o
	gcc test-outputs/ass6_20CS30062_20CS30043_4.o -o bin/test4 -L. -lass6_20CS30062_20CS30043 -no-pie

	./tinyC_compiler 5 < test5.c > test-outputs/ass6_20CS30062_20CS30043_quads5.out
	mv ass6_20CS30062_20CS30043_5.s test-outputs/ass6_20CS30062_20CS30043_5.s
	gcc -c test-outputs/ass6_20CS30062_20CS30043_5.s -o test-outputs/ass6_20CS30062_20CS30043_5.o
	gcc test-outputs/ass6_20CS30062_20CS30043_5.o -o bin/test5 -L. -lass6_20CS30062_20CS30043 -no-pie



clean:
	rm -f lex.yy.c *.tab.c *.tab.h *.output *.o *.s *.a *.out *.gch tinyC_compiler test-outputs/* bin/*