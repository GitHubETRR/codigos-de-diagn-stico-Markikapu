#include <stdio.h>
#define MAX_AUTOS 100
#define MAX_CHAR 30

typedef struct{
    char marca[MAX_CHAR];
    char modelo[MAX_CHAR];
    char patente[MAX_CHAR];
    int precio;
} KapuConcesionario_t;

void verAutos(KapuConcesionario_t autos[], int numAutos) {
    if (numAutos == 0){
        printf("\nNo hay autos cargados.\n");
        return;
    }

    for (int i=0;i<numAutos;i++){
        printf("\nAuto %d:\n", i + 1);
        printf("\nMarca: %s\n", autos[i].marca);
        printf("Modelo: %s\n", autos[i].modelo);
        printf("Patente: %s\n", autos[i].patente);
        printf("Precio: $%d\n", autos[i].precio);
    }
}

void ingresarAuto(KapuConcesionario_t autos[], int *numAutos){
    if (*numAutos>=MAX_AUTOS){
        printf("\nSe ha alcanzado el límite de autos.\n");
        return;
    }

    printf("\nIngrese los datos del auto\n");
    printf("\nMarca: ");
    scanf("%s", autos[*numAutos].marca);

    printf("Modelo: ");
    scanf("%s", autos[*numAutos].modelo);

    printf("Patente: ");
    scanf("%s", autos[*numAutos].patente);

    printf("Precio: ");
    scanf("%d", &autos[*numAutos].precio);

    (*numAutos)++;
    printf("\n\nAuto ingresado con éxito.\n");
}

int main(){
    KapuConcesionario_t autos[MAX_AUTOS];
    int numAutos = 0;
    int opcion;

    do{
        printf("\n-----CONCESIONARIO DE KAPU-----\n");
        printf("\n1. Ver autos\n");
        printf("2. Ingresar un auto\n");
        printf("3. Salir\n");
        printf("\nElegí una opción: ");
        scanf("%d", &opcion);
        printf("\n-------------------------------\n");

        switch(opcion){
            case 1:
                verAutos(autos, numAutos);
                break;
            case 2:
                ingresarAuto(autos, &numAutos);
                break;
            case 3:
                printf("\n Gracias por su tiempo, tenga un gran día.\n");
                break;
        }
    } while (opcion < 4);

    return 0;
}
