#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
falta hacer las funciones
*/

typedef struct{
	int x;
	int y;
} punto;

void lector(char archivo[20], punto point[10]){
	int aux;
	int i = 0;
	
	FILE*arch;
	arch = fopen(archivo, "r");
	
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{
	
		do{
			aux = fscanf(arch,"%d,%d,", &point[i].x, &point[i].y); // coma al final para que ignore las comas, sino se bugea
			printf("%d,%d\n", point[i].x, point[i].y);
			i++;
			
		} while(aux!= EOF && i<10);
	}
	
	
	fclose(arch);
}

	
void minimaDistParam(punto point1, punto point2){
	double sumaPuntos;
	sumaPuntos= sqrt(pow(point1.x-point2.x,2)+pow(point1.y-point2.y,2));	
	printf("\nLa minima distancia entre ambos puntos (%d,%d) y (%d,%d) es de: %.2f\n", point1.x, point1.y, point2.x, point2.y, sumaPuntos);
}
double minimaDist(punto point1, punto point2){
	double sumaPuntos;
	sumaPuntos= sqrt(pow(point1.x-point2.x,2)+pow(point1.y-point2.y,2));	
	return sumaPuntos;
}

void minimaDistCons(punto point[10]){
	int i;
	for(i=0;i<10-1;i++){
		
		minimaDistParam(point[i], point[i+1]);
	}
}

void minimadistCualq(punto point[10]){
	int i, j;
	punto temp;

	for(i=0;i<10;i++){
		double minimo = 999.9; // si lo pongo afuera no se reinicia
		temp.x = 0; // Lo reinicio para que no se conserve el anterior valor
		temp.y = 0;
		for(j=0; j<10-1;j++){
			if(minimaDist(point[i], point[j+1]) < minimo && i != j+1){
				minimo = minimaDist(point[i],point[j+1]);
				temp.x = point[j+1].x;
				temp.y = point[j+1].y;
				
			}
		}
		printf("El punto (%d,%d) esta mas cerca con (%d,%d) con una distancia de; %.2f\n", point[i].x,point[i].y, temp.x, temp.y, minimo);
	}
	
}


int main(int argc, char *argv[]) {
	
	punto point[10];
	char archivo[20] = "puntos.txt";
	lector(archivo, point);
	minimaDistParam(point[0],point[1]);
	minimaDistCons(point);
	printf("\nMinima dist entre 2 puntos cualesquiera:\n");
	minimadistCualq(point);
	
	return 0;
	
}

