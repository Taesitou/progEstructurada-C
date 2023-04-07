#include <stdio.h>

int suma(int num1, int num2){
	int res;
	res = num1 + num2;
	return res;
}
	
int resta(int num1, int num2){
	int res;
	res = num1 - num2;
	return res;
}
int division(int num1, int num2){
	int res;
	res = num1 / num2;
	return res;
}

int producto(int num1, int num2){
	int res;
	res = num1 * num2;
	return res;
}
		
void operacion(int num1, int num2, char operador){
	int res;
	if(operador == '+'){
		res = suma(num1,num2);
	}else if(operador == '-'){
		res = resta(num1,num2);
	}else if(operador == '*'){
		res = producto(num1,num2);
	}else if(operador == '/'){
		res = division(num1,num2);
	}
	
	printf("%d %c %d = %d",num1,operador,num2,res);
}


int main() {
	int num1;
	int num2;
	char operador;
	printf("Ingrese primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese segundo numero: ");
	scanf("%d", &num2);
	getchar();
	printf("ingrese un operador [+ - * /]: ");
	operador = getchar();
	operacion(num1,num2,operador);
	return 0;
}

