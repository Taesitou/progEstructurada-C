#include <stdio.h>
#include <stdlib.h>
#define NA 3
#define NM 5

typedef struct
{
	char nombre[100];
	int legajo, materias[30];
}t_alumno;

typedef struct
{
	char nombre[100];
	int codigo;
}t_materia;

typedef struct
{
	int legajo_alumno;
	int cod_materia,nota;
}t_nota;


void cargarDatos(char archivo[20], t_alumno alumno[NA], t_alumno arrayAlumnos[NA]){
	FILE*arch = fopen(archivo, "w");
	int j=0; 
	char caracter;
	
	int legajo = 1;
	int materia;
	
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{
		
		
		while(legajo != 0 && j < NA){
			int condicional = 1, i=0;
			printf("Escribe el nombre del Alumno [%d]: ", j);
			while(i < 100 && condicional == 1){
				caracter = getchar();
				if(caracter == '\n'){
					alumno[j].nombre[i] = '\0';
					arrayAlumnos[j].nombre[i] = '\0'; // punto 3
					fprintf(arch, "%s,",alumno[j].nombre);
					i=0;
					condicional = 0;
				}else{
					alumno[j].nombre[i] = caracter;
					arrayAlumnos[j].nombre[i] = caracter; // punto 3
					i++;
				}
				
			}
			// reinicio condicional
			condicional = 1;
			while(i<30 && condicional == 1 ){
				printf("Introduzca el codigo de las materias del alumno [%d] (presione 0 para terminar): ", j);
				scanf("%d", &materia);
				if(materia !=0){
					alumno[j].materias[i] = materia;
					arrayAlumnos[j].materias[i] = materia; // punto 3
					fprintf(arch, "%d,", materia);
					
					i++;
				}else{
					condicional = 0;
				}
			}
			
			
			
			printf("\nEscribe el legajo del Alumno [%d]: ", j);
			scanf("%d", &legajo);
			if(legajo == 0){
				printf("Alumno/s ingresados correctamente\n");
			}else{
				alumno[j].legajo = legajo;
				arrayAlumnos[j].legajo = legajo; 
				fprintf(arch,"%d\n", legajo);
			}
			printf("\n\n array:  %s %d %d\n", arrayAlumnos[j].nombre, arrayAlumnos[j].materias[0], arrayAlumnos[j].legajo); // corroboro lo del array, printeo unicamente la materia 1
			   
			fflush(stdin);
			j++;
		}
		
	}

}
	
	
void cargarMaterias(char archivo[20], t_materia materia[NM], t_materia arrayMaterias[NM]){
	FILE*arch = fopen(archivo, "w");
	int codigo = 1;
	int j=0;
	char caracter;
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{ 
		while(j<NM && codigo != 0){
			
			int condicional = 1, i=0;
			
			printf("Escribe el nombre de la materia [%d]: ", j);
			while(i < 100 && condicional == 1){
				caracter = getchar();
				if(caracter == '\n'){
					materia[j].nombre[i] = '\0';
					arrayMaterias[j].nombre[i] = '\0';
					fprintf(arch, "%s,",materia[j].nombre);
					i=0;
					condicional = 0;
				}else{
					materia[j].nombre[i] = caracter;
					arrayMaterias[j].nombre[i] = caracter;
					i++;
				}
				
			}
			
			
			printf("Introduzca el codigo de la materia [%d]: ", j );
			scanf("%d", &codigo);
			if(codigo == 0){
				printf("Materias Ingresadas correctamente :)");
			}else{
				arrayMaterias[j].codigo = codigo;
				fprintf(arch, "%d\n", codigo);
			}
		
			getchar();
			j++;
		}
	}
	
}

void cargarNotas(char archivo[20], t_alumno arrayAlumnos[NA], t_materia arrayMaterias[NM], t_nota arrayNotas[NM]){
	FILE*arch = fopen(archivo, "w");
	
	int j= 0;
	int nota;
	
	t_nota notas[NM];
	
	
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{
		while(j<NA){
			int i;
			int materiaAlumno = 0; // hago otra variable para el arrayAlumnos porque si uso i  para ambos, me compara a la vez 0 0 1 1 2 2, y no de la forma 0 0 0 1 0 2
			int x = 0; //Variable que utilizaremos como referencia a la posicion de almacenamiento del dato
			for(i=0;i<NM;i++){
				
				if(arrayAlumnos[j].materias[materiaAlumno] == arrayMaterias[i].codigo && arrayMaterias[i].codigo != 0){ // comparo  el codigo de las materias del alumno hasta encontrar la materia
					printf("Ingrese la nota de %s para la materia %s: ", arrayAlumnos[j].nombre, arrayMaterias[i].nombre);
					scanf("%d", &nota);
					
					notas[j].legajo_alumno = arrayAlumnos[j].legajo;
					notas[j].nota = nota;
					notas[j].cod_materia = arrayMaterias[i].codigo; 
					arrayNotas[j].legajo_alumno = arrayAlumnos[j].legajo;
					arrayNotas[j].nota = nota;
					arrayNotas[j].cod_materia = arrayMaterias[i].codigo;
					printf("%d,%d,%d\n", arrayNotas[j].legajo_alumno, arrayNotas[j].nota,arrayNotas[j].cod_materia);
					fprintf(arch, "%d,%d,%d\n", notas[j].legajo_alumno, notas[j].nota, notas[j].cod_materia);
					materiaAlumno++; // si entro sumo para ver la proxima materia
					
				}
			}
			j++;
		}
	}
}
	
	
	
void listadoMatAl(int legajo, t_alumno arrayAlumnos[NA], t_materia arrayMaterias[NM], t_nota arrayNotas[NM]){ // con el legajo del alumno, mostrar sus materias y notas
	int j, i, k, m;
	printf("%d",arrayNotas[0].cod_materia);
	for(i=0;i<NA;i++){
		if(arrayAlumnos[i].legajo == legajo){
			printf("\n------------------------\n");
			printf("El alumno: %s\n", arrayAlumnos[i].nombre);
			for(j=0;j<NM;j++){
				for(k=0; k<30 && arrayAlumnos[i].materias[k] != 0;k++){
					printf("materia Alumno : %d, Codigo materia : %d, legajo: %d\n",arrayAlumnos[i].materias[j],arrayNotas[k].cod_materia, arrayNotas[k].legajo_alumno );
					if(arrayNotas[j].cod_materia == arrayAlumnos[i].materias[k] && arrayNotas[j].legajo_alumno == legajo ){
						
						printf("Materia: %d, Nota: %d\n", arrayNotas[j].cod_materia, arrayNotas[j].nota);
					

					}
				}
			}
		}
	}

	
}



int main(int argc, char *argv[]) {
	t_alumno alumno[NA];
	t_alumno arrayAlumnos[NA] = {0};
	t_materia materia[NM];
	t_materia arrayMaterias[NM] = {0};
	t_nota arrayNotas[NM];
	char archivoAlumnos[20] = "alumnos.txt";
	char archivoMaterias[20] = "materias.txt";
	char archivoNotas[20] = "notas.txt";
	cargarDatos(archivoAlumnos, alumno, arrayAlumnos);
	cargarMaterias(archivoMaterias, materia, arrayMaterias);
	cargarNotas(archivoNotas, arrayAlumnos, arrayMaterias, arrayNotas);
	printf("---%d",arrayNotas[0].cod_materia);
	listadoMatAl(12, arrayAlumnos, arrayMaterias, arrayNotas);
	
	
	
	return 0;
}

