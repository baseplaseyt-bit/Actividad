#include <stdio.h>
#include "produccion.h"

int main() {
    Producto inventario[MAX_PROD];
    int contador_productos = 0;
    int opcion;

    do {
        printf("\n FABRICA \n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Analizar viabilidad y totales\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarProducto(inventario, &contador_productos);
                break;
            case 2:
                editarProducto(inventario, contador_productos);
                break;
            case 3:
                eliminarProducto(inventario, &contador_productos);
                break;
            case 4:
                if (contador_productos == 0) {
                    printf("No hay productos para analizar.\n");
                } else {
                    analizarViabilidad(inventario, contador_productos);
                }
                break;
            case 5:
                printf("Saliendo\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}