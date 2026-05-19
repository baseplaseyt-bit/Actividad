#include <stdio.h>
#include "produccion.h"


int compararCadenas(const char *c1, const char *c2) {
    int i = 0;
    while (c1[i] != '\0' && c2[i] != '\0') {
        if (c1[i] != c2[i]) return 0;
        i++;
    }
    return c1[i] == c2[i];
}


int buscarProducto(Producto arr[], int contador, const char *nombre_buscado) {
    for (int i = 0; i < contador; i++) {
        if (compararCadenas(arr[i].nombre, nombre_buscado)) {
            return i;
        }
    }
    return -1;
}

void ingresarProducto(Producto arr[], int *contador) {
    if (*contador >= MAX_PROD) {
        printf("Límite de la fábrica (5 productos) alcanzado.\n");
        return;
    }
    printf("Nombre del producto: ");
    scanf("%29s", arr[*contador].nombre);
    printf("Tiempo de fabricacion por unidad: ");
    scanf("%d", &arr[*contador].tiempo_fab);
    printf("Recursos por unidad: ");
    scanf("%d", &arr[*contador].recursos);
    printf("Cantidad demandada: ");
    scanf("%d", &arr[*contador].demanda);
    (*contador)++;
    printf("Producto ingresado con éxito.\n");
}

void editarProducto(Producto arr[], int contador) {
    char nombre_buscado[30];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%29s", nombre_buscado);
    
    int indice = buscarProducto(arr, contador, nombre_buscado);
    if (indice != -1) {
        printf("Editando producto [%s]\n", arr[indice].nombre);
        printf("Nuevo tiempo de fabricacion: ");
        scanf("%d", &arr[indice].tiempo_fab);
        printf("Nuevos recursos por unidad: ");
        scanf("%d", &arr[indice].recursos);
        printf("Nueva demanda: ");
        scanf("%d", &arr[indice].demanda);
        printf("Actualizado correctamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto(Producto arr[], int *contador) {
    char nombre_buscado[30];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%29s", nombre_buscado);
    
    int indice = buscarProducto(arr, *contador, nombre_buscado);
    if (indice != -1) {
        
        for (int i = indice; i < (*contador) - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*contador)--;
        printf("Producto eliminado correctamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void analizarViabilidad(Producto arr[], int contador) {
    int tiempo_disp, recursos_disp;
    printf("Analisis de Viabilidad\n");
    printf("Ingrese Tiempo de Produccion Disponible: ");
    scanf("%d", &tiempo_disp);
    printf("Ingrese Recursos Disponibles: ");
    scanf("%d", &recursos_disp);

    int tiempo_total = 0;
    int recursos_totales = 0;

    for (int i = 0; i < contador; i++) {
        tiempo_total += (arr[i].tiempo_fab * arr[i].demanda);
        recursos_totales += (arr[i].recursos * arr[i].demanda);
    }

    printf("\nResultados:\n");
    printf("Tiempo total requerido: %d (Disp: %d)\n", tiempo_total, tiempo_disp);
    printf("Recursos totales requeridos: %d (Disp: %d)\n", recursos_totales, recursos_disp);

    if (tiempo_total <= tiempo_disp && recursos_totales <= recursos_disp) {
        printf("La fabrica SI PUEDE cumplir con la demanda.\n");
    } else {
        printf("La fabrica NO PUEDE cumplir con la demanda.\n");
    }
}