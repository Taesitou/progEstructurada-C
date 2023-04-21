#include <stdio.h>
#include <stdlib.h>
#define filas 12
#define columnas 31

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
			matriz[fil][0]= num11;
			matriz[fil][1]= num12;
			matriz[fil][2]= num13;
			matriz[fil][3]= num14;
			matriz[fil][4]= num15;
			matriz[fil][5]= num16;
			matriz[fil][6]= num17;
			matriz[fil][7]= num18;
			matriz[fil][8]= num19;
			matriz[fil][9]= num20;
			matriz[fil][0]= num21;
			matriz[fil][1]= num22;
			matriz[fil][2]= num23;
			matriz[fil][3]= num24;
			matriz[fil][4]= num25;
			matriz[fil][5]= num26;
			matriz[fil][6]= num27;
			matriz[fil][7]= num28;
			matriz[fil][8]= num29;
			matriz[fil][9]= num30;
			matriz[fil][30]= num31;
			
			
			
			aux = fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
						 &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8,
						 &num9, &num10, &num11, &num12, &num13, &num14,&num15,&num16,
						 &num17, &num18, &num19, &num20, &num21, &num22, &num23, &num24, &num25,
						 &num26, &num27, &num28, &num29,&num30, &num31);
			fil++;
		}
	}
}

int main() {
	int matriz[filas][columnas] = {0};
	char archivo[20] = "temperaturas.txt";
	cargarMatNumDeArch(matriz, archivo);
	
	return 0;
}

