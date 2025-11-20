#include <iostream>
#include <string>
using namespace std;

typedef enum {
    CARRERA_100 = 1,
    SALTO_LARGO,
    LANZAMIENTO_BALA,
    SALTO_ALTO,
    CARRERA_400,
    SALTO_GARROCHA,
    LANZAMIENTO_DISCO,
    CARRERA_110V,
    LANZAMIENTO_JABALINA,
    CARRERA_1500
} prueba_t;

class Persona {
protected:
    string nombre;
    int edad;
    float altura;
    float peso;

public:
    Persona() {
        nombre = "Sin_nombre";
        edad = 0;
        altura = 0;
        peso = 0;
    }

    void cargarDatos() {
        cout << "Ingrese nombre: ";
        cin >> nombre;
        cout << "Edad: ";
        cin >> edad;
        cout << "Altura (m): ";
        cin >> altura;
        cout << "Peso (kg): ";
        cin >> peso;
    }

    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Altura: " << altura << " m" << endl;
        cout << "Peso: " << peso << " kg" << endl;
    }

    string getNombre() { return nombre; }
};


class Atleta : public Persona {
private:
    float marcas[11]; // usamos 1..10

public:
    Atleta() {
        for (int i = 0; i <= 10; i++)
            marcas[i] = 0;
    }

    void registrarMarca() {
        int opcion;
        cout << "\n----- Pruebas del Decathlon -----\n";
        cout << "1. 100m\n";
        cout << "2. Salto en largo\n";
        cout << "3. Bala\n";
        cout << "4. Salto en alto\n";
        cout << "5. 400m\n";
        cout << "6. Garrocha\n";
        cout << "7. Disco\n";
        cout << "8. 110m c/v\n";
        cout << "9. Jabalina\n";
        cout << "10. 1500m\n\n";
        cout << "Seleccione prueba: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 10) {
            cout << "Prueba invalida.\n";
            return;
        }

        float m;
        cout << "Ingrese marca: ";
        cin >> m;

        marcas[opcion] = m;
        cout << "Marca registrada correctamente.\n";
    }

    void mostrarMarcas() {
        cout << "\n--- Marcas de " << nombre << " ---\n";

        for (int i = 1; i <= 10; i++) {
            cout << i << ". ";
            switch (i) {
                case CARRERA_100: cout << "100m: "; break;
                case SALTO_LARGO: cout << "Salto en largo: "; break;
                case LANZAMIENTO_BALA: cout << "Bala: "; break;
                case SALTO_ALTO: cout << "Salto en alto: "; break;
                case CARRERA_400: cout << "400m: "; break;
                case SALTO_GARROCHA: cout << "Garrocha: "; break;
                case LANZAMIENTO_DISCO: cout << "Disco: "; break;
                case CARRERA_110V: cout << "110m c/v: "; break;
                case LANZAMIENTO_JABALINA: cout << "Jabalina: "; break;
                case CARRERA_1500: cout << "1500m: "; break;
            }
            cout << marcas[i] << endl;
        }
    }
};

int main() {
    Atleta atletas[20];
    int cantidad = 0;
    int opcion;

    do {
        cout << "\n------- el mein -------\n";
        cout << "1. Agregar atleta\n";
        cout << "2. Registrar marca a un atleta\n";
        cout << "3. Mostrar datos de un atleta\n";
        cout << "4. Mostrar marcas de un atleta\n";
        cout << "5. Salir\n";
        cout << "------------------------\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;
        cout << "------------------------\n";

        if (opcion == 1) {
            if (cantidad < 20) {
                cout << "Ingrese datos del atleta...\n";
                atletas[cantidad].cargarDatos();
                cantidad++;
                cout << "\nListo, su atleta agregado.\n";
            } else {
                cout << "No hay mas espacio.\n";
            }
        }
        else if (opcion == 2) {
            if (cantidad == 0) {
                cout << "No hay atletas cargados.\n";
                continue;
            }

            int numeroAtletas;
            cout << "Numero de atleta (0 a " << cantidad << "): ";
            cin >> numeroAtletas;

            if (numeroAtletas >= 0 && numeroAtletas < cantidad)
                atletas[numeroAtletas].registrarMarca();
            else
                cout << "Indice invalido.\n";
        }
        else if (opcion == 3) {
            if (cantidad == 1) {
                cout << "No hay atletas cargados.\n";
                continue;
            }

            int numeroAtletas;
            cout << "Numero de atleta (1 a " << cantidad << "): ";
            cin >> numeroAtletas;

            if (numeroAtletas >= 0 && numeroAtletas < cantidad)
                atletas[numeroAtletas].mostrarDatos();
            else
                cout << "Indice invalido.\n";
        }
        else if (opcion == 4) {
            if (cantidad == 1) {
                cout << "No hay atletas cargados.\n";
                continue;
            }

            int numeroAtletas;
            cout << "Numero de atleta (0 a " << cantidad - 1 << "): ";
            cin >> numeroAtletas;

            if (numeroAtletas >= 1 && numeroAtletas < cantidad)
                atletas[numeroAtletas].mostrarMarcas();
            else
                cout << "Indice invalido.\n";
        }

    } while (opcion != 5);

    cout << "gracias, espero haber sido util :)\n";
    return 0;
}
