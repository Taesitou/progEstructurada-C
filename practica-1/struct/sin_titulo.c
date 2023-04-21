#include <stdio.h>
#include <string.h>

struct s_fecha{
	int aa,mm,dd;
};
typedef struct s_fecha t_fecha; 
struct s_punto{
	int x;
	int y;
	char nom[20];
	t_fecha fecha;
};


typedef struct s_punto t_punto;

int main(int argc, char *argv[]) {
	
	t_punto arrP[10];
	int i;
	t_punto pa;
	
	/*
	printf("pa -> x: %d, y: %d", pa.x, pa.y);
	pa.x=10;
	pa.y=20;
	strcpy(pa.nom,"Lucia");
	printf("pa -> x: %d, y: %d, nom=%s\n", pa.x, pa.y, pa.nom);
	pb=pa;
	*/
	i=0;
	arrP[i].x = 20;
	arrP[i].y=20;
	strcpy(arrP[i].nom,"Lucia");
	printf("pa -> x: %d, y: %d, nom=%s\n", arrP[i].x, arrP[i].y, arrP[i].nom);
	
	t_fecha fecha;
	fecha.aa = 2023;
	fecha.mm =  4;
	fecha.dd = 13;
	
	printf("dia: %d, mes: %d, año: %d",fecha.dd,fecha.mm,fecha.aa);
	
	
	return 0;
}

