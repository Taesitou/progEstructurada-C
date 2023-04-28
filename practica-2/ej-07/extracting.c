#include <stdio.h>
#define NM 5


typedef struct
{
	char nombre[100];
	int codigo;
}
t_materia;

void leer(t_materia materias[NM], char archivo[20]){
	FILE*arch = fopen(archivo, "r");
	int i= 0;
	if(arch == NULL){
		printf("No se pudo abrir el archivo.");
	}else{
		while(i<NM && (fscanf(arch,"%[^,],%d\n", materias[i].nombre, &materias[i].codigo)) != EOF){
			
			printf("%s, %d\n", materias[i].nombre, materias[i].codigo);
			i++;
			
		}
	}
	
}


int main(int argc, char *argv[]) {
	char archivo[20] = "materias.txt";
	t_materia materias[NM];
	leer(materias, archivo);
	
	
	
	return 0;
}

