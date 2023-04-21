#include <stdio.h>

int main(int argc, char *argv[]) {
	/* WRITING A FILE
	//FILE * fpointer = fopen("employees.txt","w"); // r, w, a-> append
	//fprintf(fpointer, "Jim, Salesman\nPam, receptionist\nOscar, Accounting");
	FILE * fpointer = fopen("employees.txt","a");
	fprintf(fpointer, "\ntuvi, que linda que es");
	fclose(fpointer);
	*/
	
	// READING
	char line[255];
	FILE * fpointer = fopen("employees.txt","r");
	fgets(line, 255, fpointer); //read the lines one by one // first line
	fgets(line, 255, fpointer); // second line
	printf("%s", line);
	return 0;
}

