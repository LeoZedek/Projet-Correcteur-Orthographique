all : bin/tri tests/testTris

bin/tri : lib/libtris.a lib/libechanger.a src/main.o
	gcc -o bin/tri src/main.o -Llib -ltris -lechanger

lib/libechanger.a : src/echanger.o
	ar -r lib/libechanger.a src/echanger.o
	
lib/libtris.a : lib/libechanger.a src/triParMinSuccessif.o src/triRapide.o src/triFusion.o src/triParInsertion.o
	ar -r lib/libtris.a src/triParMinSuccessif.o src/triRapide.o src/triFusion.o src/triParInsertion.o 

src/echanger.o : src/echanger.c
	gcc -o src/echanger.o -c -Wall -pedantic -Iinclude src/echanger.c

src/triParMinSuccessif.o : src/triParMinSuccessif.c
	gcc -o src/triParMinSuccessif.o -c -Wall -pedantic -Iinclude src/triParMinSuccessif.c

src/triRapide.o : src/triRapide.c
	gcc -o src/triRapide.o -c -Wall -pedantic -Iinclude src/triRapide.c
	
src/triFusion.o : src/triFusion.c
	gcc -o src/triFusion.o -c -Wall -pedantic -Iinclude src/triFusion.c
	
src/triParInsertion.o : src/triParInsertion.c
	gcc -o src/triParInsertion.o -c -Wall -pedantic -Iinclude src/triParInsertion.c

src/main.o : src/main.c
	gcc -o src/main.o -c -Wall -pedantic -Iinclude src/main.c
	
src/testTris.o : src/testTris.c
	gcc -o src/testTris.o -c -Wall -pedantic -Iinclude src/testTris.c

tests/testTris : lib/libtris.a lib/libechanger.a src/testTris.o
	gcc -o tests/testTris src/testTris.o -Llib -ltris -lechanger -lcunit
	
clean :
	rm -f bin/*
	rm -f src/*.o
	rm -f lib/*.a
	rm -f tests/*
