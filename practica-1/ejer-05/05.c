#include <stdio.h>



int estaEnArr(int array[], int num){
	int x = 0;
	int res;
	for(x=0; x < 10; x++){
		if(array[x] == num){
			res = 1;
		}
	}
	
	return res;
}

int esPos(int num){
	int res;
	if(num>=0){
		res = 1;
	}else{
		res = 0;
	}
	return res;
}
	void cargarArrPNR(int array[10]){
		int i = 0;
		int numero;
		do{
			printf("Ingrese un numero natural mayor a 0: ");
			scanf("%d", &numero);
			if(estaEnArr(array, numero) == 0 && esPos(numero) == 1){
				array[i] = numero;
				i++;
			}else{
				printf("El numero debe de ser mayor a 0 y no debe de estar en el array\n");
			}
			
		} while(i<10 && array[i-1]!= 0);
		
		
	}

void imprimirArr(int array[10]){
	int i;
	printf("Tu array es:  [");
	for( i = 0; array[i] != 0 && i < 10; i++){
		if (array[i+1] == 0 || i == 9){
			printf("%d]\n", array[i]);
			
		}else{
			printf("%d, ", array[i]);
		}
	}
	
}

int main() {
	int array[10];
	cargarArrPNR(array);
	imprimirArr(array);
	
	return 0;
}

