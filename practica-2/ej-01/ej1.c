#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
} punto;


int main(int argc, char *argv[]) {
	int i;
	punto point[3];
	point[0].x = 0;
	point[0].y =0;
	
	for(i=1;i<3;i++){
		printf("Ingrese el punto x: ");
		scanf("%d", &point[i].x);
		printf("Ingrese el punto y: ");
		scanf("%d", &point[i].y);
		printf("\n");
	}
	
	int sumaPunto1= point[1].x + point[1].y;
	int sumaPunto2= point[2].x + point[2].y;
	
	printf("El punto 1 es: (%d,%d)\n", point[1].x, point[1].y);
	printf("El punto 2 es: (%d,%d)\n", point[2].x, point[2].y);
	
	if(sumaPunto1 > sumaPunto2){
		printf("El punto 1 esta mas alejado que el punto 2 del origen");
	}else if(sumaPunto2 > sumaPunto1 ){
		printf("El punto 2 esta mas alejado que el punto 1 del origen");
	}else{
		printf("Ambos puntos estan igual de alejados al origen");
	}
	
	
	

	
	
	
	
	return 0;
}

