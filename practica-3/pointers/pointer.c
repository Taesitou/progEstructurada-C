#include <stdio.h>


/*
& la direccion de memoria de ..
%p para puntero (imprime en hexadecimal)
char*
* "El contenido de.." y para declarar una variable puntero

*/

void fun(char* a){
	*a=100;
}


int main(int argc, char *argv[]) {
	/*
	char a= '@';
	char* pa =NULL;
	
	printf("%d\n", a);
	printf("%p\n", &a);
	pa = &a;
	printf("%p\n", *pa); // vale 2d 
	*/
	
	char a= 64;
	printf("%d\n", a);
	printf("- - - - - \n");
	fun(&a);
	printf("%d\n",a);
	return 0;
}

