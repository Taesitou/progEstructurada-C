#include <stdio.h>

void cargarArr(int array[10]){
	
	int i = 0;
	do{
		printf("Ingrese un numero entero: ");
		scanf("%d", &array[i]);
		i++;
	}while(array[i-1] != 0 && i < 10);
	
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

void invertirArr(int array[], int len){
	int x, y;
	x = 0;
	y = len;
	int variable;
	while(x != y){
		variable = array[x];
		array[x] = array[y-1];
		array[y-1] = variable;
		x++;
		y--;
	}
	
	
}

int main() {
	
	int arr1[10];
	cargarArr(arr1);
	imprimirArr(arr1);
	
	// length
	int len = 0;
	for (int u=0; arr1[u] !=0 && u<10; u++){
		len++;
	}
	//printf("%d", len);
	invertirArr(arr1, len);
	imprimirArr(arr1);
	
	// segundo array, cargar, ordenar e imprimir
	
	int arr2[10];
	cargarArr(arr2);
	
	int len2 = 0;
	for (int j=0; arr2[j] !=0 && j<10; j++){
		len2++;
	}
	
	for(int x = 0; x < len2 && arr2[x] != 0; x++){
		for(int indiceActual = 0; arr2[indiceActual] != 0 &&  indiceActual < len2-1; indiceActual++){
			
			int indiceSigEl = indiceActual +1;
			if(arr2[indiceActual]> arr2[indiceSigEl]){
				int temporal = arr2[indiceActual];
				arr2[indiceActual] = arr2[indiceSigEl];
				arr2[indiceSigEl] = temporal;
			}
			
		}
	}
	
	imprimirArr(arr2);
	
	
	
	return 0;
}





/*
 void cargaArr(int numeros[10]) {
     int i = 0;

     do {
         printf("Ingresa un numero: ");    
         scanf("%d", &numeros[i]);
         i++;
     } while (numeros[i-1] != 0 && i < 10);
 }

 void imprimirArr(int numeros[], int len) {
     printf("El array ingresado es: [");
     for (int j = 0; numeros[j] != 0 && j < len + 1; j++) {
 		if (numeros[j+1] == 0 || j == 9) {
 			printf("%d", numeros[j]);
 		} else {
 			printf("%d, ", numeros[j]);
 		}
     }
 	printf("]\n");
 }

 void invertirArr(int numeros[], int len) {
     int x = 0;
     int y = (len-1);
     while (x < (len-1)/2) {
         int temp = numeros[x];
         numeros[x] = numeros[y];
         numeros[y] = temp;
        x++;
         y--;
     }
 }

 int main() {
     int numeros[10];
     cargaArr(numeros);
     // int numeros[10] = {5, 1, 3, 2, 4};

     int len = 0;
     for(int u = 0; numeros[u] != 0 && u < 10 ; u++) {
         len++;
     }    

     // printf("\nEl numero de elementos en la array es: %d\n", len);

     // printf("\n%d, %d", (len-1), numeros[len-1]);
     // printf("\n%d, %d\n", (len-1)/2, numeros[(len-1)/2]);

     invertirArr(numeros, len);

     imprimirArr(numeros, len);

     int numeros1[10];
     cargaArr(numeros1);

     int len1 = 0;
     for(int j = 0; numeros1[j] != 0 && j < 10 ; j++) {
         len1++;
     }    

     for(int x = 0; numeros1[x] != 0 && x < len1-1; x++) {
        for(int y = x + 1; numeros1[y] != 0 && y < len1; y++) {
             // printf("%d y %d\n", numeros[x], numeros[y]);
             if(numeros1[x] > numeros1[y]) {
                 int temp = numeros1[x];
                 numeros1[x] = numeros1[y];                 numeros1[y] = temp;
             }
         }
     }

     imprimirArr(numeros1, len1);

     return 0;
 }
*/
