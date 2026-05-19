#ifndef PRODUCCION_H
#define PRODUCCION_H


#define MAX_PROD 5 


typedef struct {
    char nombre[30];
    int tiempo_fab; 
    int recursos;   
    int demanda;    
} Producto;


int compararCadenas(const char *cadena1, const char *cadena2);
int buscarProducto(Producto arr[], int contador, const char *nombre_buscado);
void ingresarProducto(Producto arr[], int *contador);
void editarProducto(Producto arr[], int contador);
void eliminarProducto(Producto arr[], int *contador);
void analizarViabilidad(Producto arr[], int contador);

#endif