#include <stdio.h>

#define MAX 10

// Estructura de productos
typedef struct {
    int codigo;
    char nombre[30];
    float precio;
} Item;

// Carrito
typedef struct {
    int codigo;
    int cantidad;
} Pedido;

Item lista[6] = {
    {1, "Arepa", 5000},
    {2, "Hamburguesa", 12000},
    {3, "Pizza", 15000},
    {4, "Jugo", 3000},
    {5, "Salchipapa", 10000},
    {6, "Helado", 4000}
};

Pedido pedidos[MAX];
int contador = 0;

// Mostrar productos
void verMenu() {
    printf("\n--- PRODUCTOS DISPONIBLES ---\n");
    for(int i = 0; i < 6; i++) {
        printf("%d - %s ($%.0f)\n", lista[i].codigo, lista[i].nombre, lista[i].precio);
    }
}

// Buscar producto
int existeProducto(int codigo) {
    for(int i = 0; i < 6; i++) {
        if(lista[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Agregar pedido
void agregarPedido() {
    int cod, cant;

    verMenu();
    printf("Ingrese codigo del producto: ");
    scanf("%d", &cod);

    int pos = existeProducto(cod);

    if(pos == -1) {
        printf("Ese producto no existe.\n");
        return;
    }

    printf("Cantidad: ");
    scanf("%d", &cant);

    if(cant <= 0) {
        printf("Cantidad invalida.\n");
        return;
    }

    pedidos[contador].codigo = cod;
    pedidos[contador].cantidad = cant;
    contador++;

    printf("Agregado correctamente.\n");
}

// Mostrar carrito
void mostrarPedido() {
    float total = 0;

    if(contador == 0) {
        printf("No hay pedidos.\n");
        return;
    }

    printf("\n--- TU PEDIDO ---\n");

    for(int i = 0; i < contador; i++) {
        int pos = existeProducto(pedidos[i].codigo);
        float parcial = lista[pos].precio * pedidos[i].cantidad;

        printf("%s x%d = $%.0f\n",
            lista[pos].nombre,
            pedidos[i].cantidad,
            parcial);

        total += parcial;
    }

    total += 2000; // domicilio
    printf("Domicilio: $2000\n");
    printf("Total a pagar: $%.0f\n", total);
}

// Confirmar
void finalizar() {
    if(contador == 0) {
        printf("No hay nada para confirmar.\n");
    } else {
        printf("Pedido enviado con exito.\n");
        contador = 0;
    }
}

int main() {
    int opcion;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Ver productos\n");
        printf("2. Hacer pedido\n");
        printf("3. Ver pedido\n");
        printf("4. Confirmar\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                verMenu();
                break;
            case 2:
                agregarPedido();
                break;
            case 3:
                mostrarPedido();
                break;
            case 4:
                finalizar();
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
        }

    } while(opcion != 5);

    return 0;
}