#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char nombre[50];
	int puntos;
	int partJugados;
	int dif;
	int cantPartidosWin;
	int cantPartidosLose;
	int cantPartidosTie;
	int cantGoalsWin;
	int cantGoalsLose;
} equipo;

void cargarDatos(equipo teams[5], char archivoItems[20], char archivoDatos[20] ){
	FILE*archItems = fopen(archivoItems, "r");
	FILE*archDatos = fopen(archivoDatos, "r");
	char caracter;
	int f=0,c=0;
	int j=0;
	int aux;
	
	if(archItems == NULL || archDatos == NULL){
		printf("No se pudieron abrir los archivos");
	}else{
		while((caracter = fgetc(archItems)) !=EOF){
			if(caracter == '\n'){
				teams[f].nombre[c]= '\0';
				c=0;
				f++;
			}else{
				teams[f].nombre[c] = caracter;
				c++;
			}
		}
		do{
			aux = fscanf(archDatos,"%d,%d,%d,%d,%d,%d,%d,%d", &teams[j].puntos, &teams[j].partJugados, &teams[j].cantPartidosWin, &teams[j].cantPartidosTie, &teams[j].cantPartidosLose, &teams[j].cantGoalsWin, &teams[j].cantGoalsLose, &teams[j].dif);
			printf("%d,%d,%d,%d,%d,%d,%d,%d\n", teams[j].puntos, teams[j].partJugados, teams[j].cantPartidosWin, teams[j].cantPartidosTie, teams[j].cantPartidosLose, teams[j].cantGoalsWin, teams[j].cantGoalsLose, teams[j].dif );
			j++;
		} while(aux!=EOF && j<5);
		
	}
}

void mostrarTabla(equipo teams[5], char archivoCabeceras[20]){
	FILE*archCabeceras = fopen(archivoCabeceras, "r");
	char cabeceras[10][10] = {0};
	char caracter;
	int i, j;
	int f=0,c=0;
	
	// armo matriz de cabeceras
	while((caracter=fgetc(archCabeceras))!= EOF){
		if(caracter != '\n'){
			cabeceras[f][c] = caracter;
			c++;
		}else{
			cabeceras[f][c] = '\0';
			c=0;
			f++;
		};
	}
	
	
	if (archCabeceras == NULL){
		printf("No se pudo abrir el archivo");
		
	}else{
		for(j=0;j<9;j++){
			if(j == 0){
				printf("%-15s", cabeceras[j]);
			}else{
				printf("%6s", cabeceras[j]);
			}
		
		}
		
		printf("\n-----------------------------------------------------\n");
		for(i=0; i<5; i++){
			if(teams[i].dif > 0){
				printf("%-13s %5d %5d %5d %5d %5d %5d %5d %+5d \n", teams[i].nombre, teams[i].puntos, teams[i].partJugados, teams[i].cantPartidosWin, teams[i].cantPartidosTie, teams[i].cantPartidosLose, teams[i].cantGoalsWin, teams[i].cantGoalsLose, teams[i].dif );
			}else{
				printf("%-13s %5d %5d %5d %5d %5d %5d %5d %5d \n", teams[i].nombre, teams[i].puntos, teams[i].partJugados, teams[i].cantPartidosWin, teams[i].cantPartidosTie, teams[i].cantPartidosLose, teams[i].cantGoalsWin, teams[i].cantGoalsLose, teams[i].dif );
			}
		}
	}
}


int main(int argc, char *argv[]) {
	char archivoCabeceras[20] = "cabeceras.txt";
	char archivoItems[20] = "items.txt";
	char archivoDatos[20] = "datos.txt";
	equipo teams[5];
	cargarDatos(teams, archivoItems, archivoDatos);
	mostrarTabla(teams, archivoCabeceras);
	
	
	
	return 0;
}

