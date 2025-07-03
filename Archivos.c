#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100
#define ARCHIVO "agenda.txt"

#define AGREGAR 1
#define MOSTRAR 2
#define GUARDAR 3
#define CARGAR 4
#define SALIR  5

typedef struct Persona {
    char nombre[MAX_CHAR];
    int edad;
    struct Persona *sig;
} Persona;

void agregar(Persona **lista) {
    Persona *nueva = malloc(sizeof(Persona));
    printf("\nNombre: ");
    fgets(nueva->nombre, MAX_CHAR, stdin);
    nueva->nombre[strcspn(nueva->nombre, "\n")] = 0;
    printf("Edad: ");
    scanf("%d", &nueva->edad);
    getchar();
    nueva->sig = *lista;
    *lista = nueva;
}

void mostrar(Persona *lista) {
    if (!lista) printf("\nLista vacía.\n");
    while (lista) {
        printf("%s - %d años\n", lista->nombre, lista->edad);
        lista = lista->sig;
    }
}

void guardar(Persona *lista) {
    FILE *f = fopen(ARCHIVO, "w");
    while (lista) {
        fprintf(f, "%s;%d\n", lista->nombre, lista->edad);
        lista = lista->sig;
    }
    fclose(f);
    printf("\nGuardado en %s\n", ARCHIVO);
}

void cargar(Persona **lista) {
    FILE *f = fopen(ARCHIVO, "r");
    char linea[MAX_CHAR];
    while (fgets(linea, MAX_CHAR, f)) {
        Persona *nueva = malloc(sizeof(Persona));
        sscanf(linea, "%[^;];%d", nueva->nombre, &nueva->edad);
        nueva->sig = *lista;
        *lista = nueva;
    }
    fclose(f);
    printf("\nDatos cargados desde %s\n", ARCHIVO);
}

void liberar(Persona *lista) {
    while (lista) {
        Persona *tmp = lista;
        lista = lista->sig;
        free(tmp);
    }
}

int main() {
    Persona *lista = NULL;
    int op;

    do {
        printf("\n -----My Friends------");
        printf("\n1- Agregar");
        printf("\n2- Mostrar");
        printf("\n3- Guardar");
        printf("\n4- Cargar");
        printf("\n5- Salir");
        printf("\n ---------------------\n");
        printf(" Que querés hacer? ");
        scanf("%d", &op);
        getchar();

        if (op == AGREGAR) agregar(&lista);
        else if (op == MOSTRAR) mostrar(lista);
        else if (op == GUARDAR) guardar(lista);
        else if (op == CARGAR) {
            liberar(lista);
            lista = NULL;
            cargar(&lista);
        }
        else if (op != SALIR) printf("Opción inválida.\n");

    } while (op != SALIR);

    liberar(lista);
    return 0;
}
