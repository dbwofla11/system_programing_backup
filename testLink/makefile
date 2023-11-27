all: static static_lib dynamic dynamic_lib

static: static_lib
	gcc -c main2.c
	gcc -static -o prog2 main2.o ./libvector.a

static_lib: addvec.c multvec.c
	gcc -c addvec.c multvec.c
	ar rcs libvector.a addvec.o multvec.o


dynamic: dynamic_lib
	gcc -o dll dll.c -ldl

dynamic_lib:
	gcc -shared -o libvector.so addvec.c 

clean:
	rm *.o prog2