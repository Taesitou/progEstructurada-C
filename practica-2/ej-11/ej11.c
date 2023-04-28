#include <stdio.h>

int nose(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4){
	unsigned int resultado = 0;
	resultado |= c1;            // 00000000 00000000 00000000 00000001
	resultado |= (c2 << 8);    // 00000000 00000000 00000010 00000001
	resultado |= (c3 << 16);   // 00000000 00000011 00000010 00000001
	resultado |= (c4 << 24);   // 00000100 00000011 00000010 00000001
	
	
	return resultado;
}



int main(int argc, char *argv[]) {
	unsigned char c1 = 'h';
	unsigned char c2 = 'o';
	unsigned char c3 = 'l';
	unsigned char c4 = 'a';
	printf("%u",nose(c1,c2,c3,c4) );	
	return 0;
}

