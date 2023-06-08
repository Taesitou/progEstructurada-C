#include <stdio.h>

/*
What is?
-un valor que es una direccion en memoria 

 * ->  d reference =  go to the address pointed to by the pointer and grab that value 

Why?



*/



int main(int argc, char *argv[]) {
	
	int x = 4; // integer named x is set to 4
	int * pX = &x; // "integer pointer" "named" pX (pointer to x) "is set to" "the address of" x
	int y = *pX;  // y = x, integer named y is set to "the thing pointed to by" pX
	return 0;
}

