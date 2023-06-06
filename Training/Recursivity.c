#include <stdio.h>
/*
Tecnica de programacion utilizada en reemplazo de los programas iterativos
Permite diseñar algoritmos de una manera mas simple y elegante (puede usar muchs recursos)

Funcion que se invoca a si mismo, generando en cada invocacion un caso "mas pequeño" del problema

Llamada recursiva consiste de:
1- Llamada recursiva: Se invoca a si mismo con un valor que haga que este mas cerca del caso base
2- El caso base: Es la condicion de finalizacion de la recursion

Ejemplo factorial de un numero: 

n!(
si n = 0 entonces: devolver 1 (caso base)
si n > 0 entonces: devolver n * (n-1)!
)
la funcion se va quedando guardada en una pila (un stack) hasta que la funcion vuelva para atras (se va desapilando la pila)

TIPOS DE RECURSIVIDAD
Indirecta(mutua): cuando una funcion A llama a otra funcion B y a su vez la funcion B llama a A
A<-->B (No comun)

Directa: donde una funcion se llama a si misma una o mas vecs. Como ejemplo es el caso del factorial que vimos anteriormente.}
	Directa multiple: Donde una funcion de llama a si misma mas de una vez dentro de la misma sentencia. Por ejemplo, la sucesion de Fibonacci:
	fib(n) = fib(n-1) + fib(n-2)

	Directa lineal: Donde una funcion se invoca como mucho una vez dentro de la misma sentencia. Ejmplo: Factorial.
	
	Directa lineal Final: Donde una funcion se invoca como mucho una vez dentro de la misma sentencia y esta llamada recursiva es lo ultimo que se hace (cuando la func esta solapa)


*/

int factorial(int num){
	if(num>0){
		return num*factorial(num-1); // se va acercando al case base
	}else{
		return 1;
	}
}

int fact_it(int n){
	int i, f = 1;
	for(i=1;i<=n; i++){
		f*=i;
	}
	return f;
}
	

int main() {
	
	printf("Factorial recursivo: %d", factorial(3));
	printf("\nFactorial iterativo: %d", fact_it(3));
	
	return 0;
}

