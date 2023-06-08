#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_cabecera{
    char tit1[20], tit2[20], tit3[20];
};
typedef struct s_cabecera t_cabecera;

struct s_producto{
    char* nombre;
    float precio;
    int codProducto;
};
typedef struct s_producto t_producto;

struct s_nodo{
    t_producto producto;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

t_cabecera cargar_lista(char* filename, t_nodo* nodo);

void append(t_nodo* nodo, t_producto producto);
void insert_por_codigo(t_nodo* nodo, t_producto producto);
void insert_por_nombre(t_nodo* nodo, t_producto producto);
void insert_adelante(t_nodo* nodo, t_producto producto);

void imprimir_lista_R(t_nodo lista);
void imprimir_lista_invertida_R(t_nodo lista);
void imprimir_lista_I(t_nodo lista, t_cabecera cabecera);
void imprimir_cabecera(t_cabecera cabecera);

void delete_codProducto(t_nodo* nodo, int codProducto);
void delete_nombre(t_nodo* nodo, char* nombre);
void delete_rango_precio(t_nodo* nodo, int inf, int sup);

t_nodo buscar_codProducto(t_nodo lista, int codProducto);
t_nodo buscar_nombre(t_nodo lista, char* nombre);
t_nodo buscar_rango_precio(t_nodo lista, int inf, int sup);

int main(){

    t_nodo lista = NULL;

    t_cabecera cabecera = cargar_lista("datos.txt", &lista);

    t_nodo listaFiltrada = buscar_rango_precio(lista, 6, 10);

    //imprimir_lista_I(listaFiltrada, cabecera);

    delete_codProducto(&lista, 736);

    imprimir_lista_I(lista, cabecera);

    return 0;
}

t_cabecera cargar_lista(char* filename, t_nodo* nodo){

    FILE* archivo;
    archivo = fopen(filename,"r");

    t_cabecera cabecera;
    t_producto producto;
    int letra, i;

    if(archivo != NULL){
        //leo cabecera
        fscanf(archivo, "%[^,],%[^,],%[^\n]\n", cabecera.tit1, cabecera.tit2, cabecera.tit3);

        while(!feof(archivo)){
            i = 0;
            //leo nombre del producto
            letra = fgetc(archivo);
            producto.nombre = malloc(sizeof(char));
            while(letra != ','){
                producto.nombre[i] = letra;
                i++;
                producto.nombre = realloc(producto.nombre, sizeof(char) * (i+1));
                letra = fgetc(archivo);
            }
            producto.nombre[i] = '\0';

            //leo precio y codProducto
            fscanf(archivo, "%f,%d\n", &producto.precio, &producto.codProducto);

            //printf("%20s | %20.2f | %20d\n", producto.nombre, producto.precio, producto.codProducto);
            //append(nodo, producto);
            append(nodo, producto);
        }

        free(producto.nombre);
        fclose(archivo);
    }
    else{
        printf("Hubo un problema abriendo el archivo!\n");
    }

    return cabecera;
}

void append(t_nodo* nodo, t_producto producto){
    if(*nodo == NULL){
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->producto = producto;
        (*nodo)->sig = NULL;
    }
    else{
        append(&((*nodo)->sig), producto);
    }
}

void insert_por_codigo(t_nodo* nodo, t_producto producto){
    t_nodo aux = NULL;
    if(*nodo == NULL){
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->producto = producto;
        (*nodo)->sig = NULL;
    }
    else{
        if(producto.codProducto < (*nodo)->producto.codProducto){
            aux = malloc(sizeof(struct s_nodo));
            aux->producto = producto;
            aux->sig = *nodo;
            *nodo = aux;
        }
        else{
            insert_por_codigo(&((*nodo)->sig), producto);
        }
    }
}

void insert_por_nombre(t_nodo* nodo, t_producto producto){
    t_nodo aux = NULL;
    if(*nodo == NULL){
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->producto = producto;
        (*nodo)->sig = NULL;
    }
    else{
        if(strcmp(producto.nombre, (*nodo)->producto.nombre)<0){
            aux = malloc(sizeof(struct s_nodo));
            aux->producto = producto;
            aux->sig = *nodo;
            *nodo = aux;
        }
        else{
            insert_por_nombre(&((*nodo)->sig), producto);
        }
    }
}

void insert_adelante(t_nodo* nodo, t_producto producto){
    t_nodo aux = NULL;
    if(*nodo == NULL){
        *nodo = malloc(sizeof(struct s_nodo));
        (*nodo)->producto = producto;
        (*nodo)->sig = NULL;
    }
    else{
        aux = malloc(sizeof(struct s_nodo));
        aux->producto = producto;
        aux->sig = *nodo;
        *nodo = aux;
    }
}

void imprimir_lista_R(t_nodo lista){
    if(lista != NULL){
        printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codProducto);
        imprimir_lista_R(lista->sig);
    }
}

void imprimir_lista_invertida_R(t_nodo lista){
    if(lista != NULL){
        imprimir_lista_invertida_R(lista->sig);
        printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codProducto);
    }
}

void imprimir_lista_I(t_nodo lista, t_cabecera cabecera){
    imprimir_cabecera(cabecera);
    while(lista != NULL){
        printf("%20s | %14.2f | %14d\n", lista->producto.nombre, lista->producto.precio, lista->producto.codProducto);
        lista = lista->sig;
    }
}

void imprimir_cabecera(t_cabecera cabecera){
    printf("%20s | %14s | %14s\n", cabecera.tit1, cabecera.tit2, cabecera.tit3);
}

void delete_codProducto(t_nodo* nodo, int codProducto){
    t_nodo aux = NULL;
    if(*nodo != NULL){
        if((*nodo)->producto.codProducto == codProducto){
            aux = *nodo;
            *nodo = (*nodo)->sig;
            free(aux);
        }
        else{
            delete_codProducto(&((*nodo)->sig), codProducto);
        }
    }
}

void delete_nombre(t_nodo* nodo, char* nombre){
    t_nodo aux = NULL;
    if(*nodo != NULL){
        if(strcmp((*nodo)->producto.nombre, nombre) == 0){
            aux = *nodo;
            *nodo = (*nodo)->sig;
            free(aux);
        }
        else{
            delete_nombre(&((*nodo)->sig), nombre);
        }
    }
}

void delete_rango_precio(t_nodo* nodo, int inf, int sup){
    t_nodo aux = NULL;
    if(*nodo != NULL){
        if((*nodo)->producto.precio >= inf && (*nodo)->producto.precio <= sup){
            aux = *nodo;
            *nodo = (*nodo)->sig;
            free(aux);
        }
        else{
            delete_rango_precio(&((*nodo)->sig), inf, sup);
        }
    }
}

t_nodo buscar_codProducto(t_nodo lista, int codProducto){
    t_nodo listaFiltrada = NULL;
    while(lista != NULL){
        if(lista->producto.codProducto == codProducto){
            append(&listaFiltrada, lista->producto);
        }
        lista = lista->sig;
    }

    return listaFiltrada;
}

t_nodo buscar_nombre(t_nodo lista, char* nombre){
    t_nodo listaFiltrada = NULL;
    while(lista != NULL){
        if(strcmp(lista->producto.nombre, nombre) == 0){
            append(&listaFiltrada, lista->producto);
        }
        lista = lista->sig;
    }

    return listaFiltrada;
}

t_nodo buscar_rango_precio(t_nodo lista, int inf, int sup){
    t_nodo listaFiltrada = NULL;
    while(lista != NULL){
        if(lista->producto.precio >= inf && lista->producto.precio <= sup){
            append(&listaFiltrada, lista->producto);
        }
        lista = lista->sig;
    }

    return listaFiltrada;
}
