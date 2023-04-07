#include <stdio.h>



int main() {
	char nombres_facultad[][500] = {"", "", "", ""};
	int size_facultad = sizeof(nombres_facultad) / sizeof(nombres_facultad[0]);
	printf("La cantidad de amigos de la facultad es: %d\n", size_facultad);
	
	char nombres_colegio[][500] = {"Juan", "Maria", "Pedro", "Ana"};
	int size_colegio = sizeof(nombres_colegio) / sizeof(nombres_colegio[0]);
	printf("La cantidad de amigos de la colegio es: %d\n", size_colegio);
	
	char nombres_twitch[][500] = {"Juan", "Maria", "Pedro", "Ana"};
	int size_twitch = sizeof(nombres_twitch) / sizeof(nombres_twitch[0]);
	printf("La cantidad de amigos de la twitch es: %d\n", size_twitch);
	
	printf("La cantidad de amigos TOTAL es: %d\n", size_twitch + size_colegio + size_facultad);
	
	
	return 0;
}

