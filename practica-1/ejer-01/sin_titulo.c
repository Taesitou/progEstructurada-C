#include <stdio.h>


int redondeo(float num) {
	int res;
	float decimal;
	decimal = num - (int)num; 
	if (decimal >= 0.5) {
		res = 1 - decimal + num;
	} else {
		res = (int)num;
	}
	return res;
}

int piso(float num) {
	int res = (int)num;
	return res;
}

int techo(float num) {
	int res = (int)num;
	if(num != res){
		res++;
	}
	return res;
}

int main() {
	float num;
	printf("Ingrese un numero real: ");
	scanf("%f", &num);
	
	printf("Piso: %d\n", piso(num));
	printf("Techo: %d\n", techo(num));
	printf("Redondeo: %d\n", redondeo(num));
	return 0;
}
