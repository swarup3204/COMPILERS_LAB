a.out:mainIO.o libIO.a
		gcc mainIO.o -L. -lIO			    

mainIO.o:myl.h mainIO.c
		gcc -Wall -c mainIO.c

printFlt.o:myl.h printFlt.c	
		gcc -Wall -c printFlt.c

printInt.o:myl.h printInt.c
		gcc -Wall -c printInt.c

printStr.o:myl.h printStr.c
		gcc -Wall -c printStr.c     

readFlt.o:myl.h  readFlt.c
		gcc -Wall -c readFlt.c

readInt.o:myl.h readInt.c
		gcc -Wall -c readInt.c

libIO.a:printFlt.o printInt.o printStr.o readFlt.o readInt.o
		ar -rcs libIO.a printFlt.o printInt.o printStr.o readFlt.o readInt.o
clean:
		rm a.out mainIO.o libIO.a printInt.o printStr.o printFlt.o readFlt.o readInt.o