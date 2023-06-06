// EJERCICIO 12
#include <stdio.h>
#include <stdlib.h>
struct s_texto{
	char * txt;
	int lon;
};
typedef struct s_texto t_texto;
int cargarTexto(t_texto* p){
	int i=0;
	int c;
	p->txt=malloc(sizeof(char)*1);
	c = getchar();
	while(c!='\n'){
		p->txt[i]=c;
		i+=1;
		p->txt=realloc(p->txt,sizeof(char)*(i+1));
		c = getchar();
	}
	p->txt[i]='\0';
	p->lon=i;
	return i;
}
void cargarFrase(t_texto** arrT){
	int i=0,lon=0;
	*arrT=malloc(sizeof(t_texto)*1);
	lon=cargarTexto((*arrT)+i);
	while(lon!=0){
		i+=1;
		*arrT=(t_texto*)realloc((*arrT),sizeof(t_texto)*(i+1));
		lon=cargarTexto((*arrT)+i);
	}
	
}
void imprimirFrase(t_texto* arrT){
	int i=0;
	if (arrT!=NULL){
		while((arrT+i)->lon!=0){
			printf("<%d>: %s\n",(arrT+i)->lon,(arrT+i)->txt);
			i+=1;
		}		
	}
}
int main() {
	t_texto* arrT=NULL;	
	cargarFrase(&arrT);
	imprimirFrase(arrT);
	return 0;
}


/*
// ejercicio 10 

#include <stdio.h>
#include <stdlib.h>
struct s_texto{
	char * txt;
	int lon;
};
typedef struct s_texto t_texto;
int cargarTexto(t_texto* p){
	int i=0;
	int c;
	p->txt=malloc(sizeof(char)*1);
	c = getchar();
	while(c!='\n'){
		p->txt[i]=c;
		i+=1;
		p->txt=realloc(p->txt,sizeof(char)*(i+1));
		c = getchar();
	}
	p->txt[i]='\0';
	p->lon=i;
	return i;
}
int main() {
	t_texto t;
	cargarTexto(&t);
	printf("<%d>: %s\n",t.lon,t.txt);	
	return 0;
}
*/

