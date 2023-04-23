#include <stdio.h>
#include <stdlib.h>
#define filas 12
#define columnas 31

void diasMedidos(char archivo[20]){
	FILE*arch;
	arch = fopen(archivo, "r");
	int num1, num2, num3, num4, num5, num6, num7, num8,
		num9, num10, num11, num12;
	int total;
	
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{
		fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8,&num9, &num10, &num11, &num12);
		total= num1 + num2 +num3 +num4 +num5 +num6 +num7 + num8 + num9 + num10 + num11+ num12;
	}
	
	fclose(arch);
	printf("\nLa cantidad total de dias medidos es de: %d", total);
}

void cargarMatNumDeArch(int matriz[filas][columnas], char archivo[20]){
	FILE*arch;
	arch = fopen(archivo, "r");
	int num1, num2, num3, num4, num5, num6, num7, num8,
		num9, num10, num11, num12, num13, num14, num15, num16,
		num17, num18, num19, num20, num21, num22, num23, num24,
		num25, num26, num27, num28, num29, num30,num31;
	int aux;
	int fil = 0; // sumara para si misma, like i j k
	if(arch == NULL){
		printf("No se pudo abrir el archivo");
	}else{ // no lee, (todo aquello que este en el segundo argumento que no sea un tipo de dato, lo evita)
		aux = fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
					&num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8,
					&num9, &num10, &num11, &num12, &num13, &num14,&num15,&num16,
					&num17, &num18, &num19, &num20, &num21, &num22, &num23, &num24, &num25,
					&num26, &num27, &num28, &num29,&num30, &num31);
		while(aux != EOF && fil<filas ){
			matriz[fil][0]= num1;
			matriz[fil][1]= num2;
			matriz[fil][2]= num3;
			matriz[fil][3]= num4;
			matriz[fil][4]= num5;
			matriz[fil][5]= num6;
			matriz[fil][6]= num7;
			matriz[fil][7]= num8;
			matriz[fil][8]= num9;
			matriz[fil][9]= num10;
			matriz[fil][10]= num11;
			matriz[fil][11]= num12;
			matriz[fil][12]= num13;
			matriz[fil][13]= num14;
			matriz[fil][14]= num15;
			matriz[fil][15]= num16;
			matriz[fil][16]= num17;
			matriz[fil][17]= num18;
			matriz[fil][18]= num19;
			matriz[fil][19]= num20;
			matriz[fil][20]= num21;
			matriz[fil][21]= num22;
			matriz[fil][22]= num23;
			matriz[fil][23]= num24;
			matriz[fil][24]= num25;
			matriz[fil][25]= num26;
			matriz[fil][26]= num27;
			matriz[fil][27]= num28;
			matriz[fil][28]= num29;
			matriz[fil][29]= num30;
			matriz[fil][30]= num31;
			
			aux = fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
						 &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8,
						 &num9, &num10, &num11, &num12, &num13, &num14,&num15,&num16,
						 &num17, &num18, &num19, &num20, &num21, &num22, &num23, &num24, &num25,
						 &num26, &num27, &num28, &num29,&num30, &num31);
			fil++;
		}
		fclose(arch);
	}
	
}

void imprimirMatNum(int matriz[filas][columnas]){
	int f, c;
	for (f=0; f<filas; f++){
		printf("[");
		for(c=0; c<columnas-1 ; c++){
			printf("%5d", matriz[f][c]);
		}
		printf("]\n");
	}
}
	
int medirPromedioAnual(int matriz[filas][columnas]){
	int promedio = 0;
	int anio = 365;
	int f,c;
	for(f=0;f<filas;f++){
		
		for(c=0;c<columnas;c++){
				promedio += matriz[f][c];
		}
		
	}
	int promedioAnual= promedio / anio;
	return promedioAnual;
}

void medirMinTemp(int matriz[filas][columnas]){
	int minimo = matriz[0][0];
	int maximo = matriz[0][0];
	int f,c; 
	
	for(f=0;f<filas;f++){
		for(c=0;c<columnas;c++){
			if (matriz[f][c] < matriz[f][c+1] && matriz[f][c] <= minimo){
				minimo = matriz[f][c];
			}
			
		}
	}
	printf("\nTemperatura Minima Anual: %d\n", minimo);
	
	
	
	for(f=0;f<filas;f++){
		for(c=0;c<columnas;c++){
			if (matriz[f][c] > matriz[f][c+1] && matriz[f][c] >= maximo){
				maximo = matriz[f][c];
			}
			
		}
	}
	printf("\nTemperatura Maxima Anual: %d\n", maximo);
	
}

void medirTempMen(int matriz[filas][columnas]){
	int f,c;
	double sumMeses[filas] = {0}, promMeses[filas] = {0};
	int diasMeses = 0;
	double maxMes = 0, minMes =100 ;
	int namemaxMes, nameminMes;
	
	for(f=0;f<filas;f++){
		for(c=0;c<columnas;c++){
			sumMeses[f] += matriz[f][c];
			diasMeses++;
		}
		
		promMeses[f] = sumMeses[f] / diasMeses;
		
		if(promMeses[f]>maxMes){
			maxMes = promMeses[f];
			namemaxMes = f+1;
		}
		if(promMeses[f]<minMes){
			minMes = promMeses[f];
			nameminMes = f+1;
		}
		
		
		diasMeses = 0;
		
		
		
	}
	
	printf("Promedio mensual de: %.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\n", promMeses[0], promMeses[1], promMeses[2], promMeses[3], promMeses[4], promMeses[5], promMeses[6], promMeses[7], promMeses[8], promMeses[9],
				 promMeses[10], promMeses[11]);
	printf("El mes mas caluroso en cuanto a promedio fue el: %d \ncon un valor de temperatura de: %.1f\n", namemaxMes, maxMes);
	printf("\n");
	printf("El mes mas frio en cuanto a promedio fue el: %d \ncon un valor de temperatura de: %.1f", nameminMes, minMes);
	
	
}
	
int main() {
	int matriz[filas][columnas] = {0};
	char archivo[20] = "temperaturas.txt";
	char archivo2[20] = "diasMedidos.txt";
	cargarMatNumDeArch(matriz, archivo);
	imprimirMatNum(matriz);
	printf("\nTemperatura Media Anual: %d\n", medirPromedioAnual(matriz));
	
	medirMinTemp(matriz);
	medirTempMen(matriz);
	diasMedidos(archivo2);

	
	
	
	return 0;
}

