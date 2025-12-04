#include <iostream>
#include <string>
using namespace std;

/*====================================
  CLASE BASE
====================================*/
class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona() : nombre("Sin_nombre"), edad(0) {}
    virtual ~Persona() {}

    virtual void cargarDatos() {
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Edad: ";
        cin >> edad;
    }

    virtual void mostrarDatos() const {
        cout << "Nombre: " << nombre << "\nEdad: " << edad << endl;
    }

    virtual void registrarMarca() = 0; // POLIMORFISMO PURO
};


/*====================================
  CORREDOR
====================================*/
class Corredor : public Persona {
private:
    float mejorTiempo;

public:
    Corredor() : mejorTiempo(0) {}

    void registrarMarca() override {
        cout << "Tiempo del corredor (s): ";
        cin >> mejorTiempo;
    }

    void mostrarDatos() const override {
        Persona::mostrarDatos();
        cout << "Mejor tiempo: " << mejorTiempo << "s\n";
    }
};


/*====================================
  SALTADOR
====================================*/
class Saltador : public Persona {
private:
    float mejorSalto;

public:
    Saltador() : mejorSalto(0) {}

    void registrarMarca() override {
        cout << "Salto (m): ";
        cin >> mejorSalto;
    }

    void mostrarDatos() const override {
        Persona::mostrarDatos();
        cout << "Mejor salto: " << mejorSalto << " m\n";
    }
};


/*====================================
  LANZADOR
====================================*/
class Lanzador : public Persona {
private:
    float mejorLanzamiento;

public:
    Lanzador() : mejorLanzamiento(0) {}

    void registrarMarca() override {
        cout << "Lanzamiento (m): ";
        cin >> mejorLanzamiento;
    }

    void mostrarDatos() const override {
        Persona::mostrarDatos();
        cout << "Mejor lanzamiento: " << mejorLanzamiento << " m\n";
    }
};


/*====================================
  MAIN
====================================*/
int main() {
    Persona* atletas[20];
    int cant = 0;
    int opcion;

    do {
        cout << "\n------- MENU -------\n";
        cout << "1. Agregar atleta\n";
        cout << "2. Registrar marca\n";
        cout << "3. Mostrar datos\n";
        cout << "4. Salir\n";
        cout << "--------------------\n";
        cout << "Opcion: ";
        cin >> opcion;
        cout << "--------------------\n";

        /*--------------------------------*/
        /* 1. AGREGAR ATLETA */
        /*--------------------------------*/
        if (opcion == 1) {
            if (cant >= 20) {
                cout << "No hay más espacio.\n";
                continue;
            }

            int tipo;
            cout << "Tipo de atleta:\n";
            cout << "1. Corredor\n";
            cout << "2. Saltador\n";
            cout << "3. Lanzador\n";
            cout << "Elija: ";
            cin >> tipo;

            if (tipo == 1) atletas[cant] = new Corredor();
            else if (tipo == 2) atletas[cant] = new Saltador();
            else if (tipo == 3) atletas[cant] = new Lanzador();
            else {
                cout << "Tipo invalido.\n";
                continue;
            }

            atletas[cant]->cargarDatos();
            cant++;
            cout << "\nAtleta agregado correctamente.\n";
        }

        /*--------------------------------*/
        /* 2. REGISTRAR MARCA */
        /*--------------------------------*/
        else if (opcion == 2) {
            if (cant == 0) {
                cout << "No hay atletas cargados.\n";
                continue;
            }

            cout << "Numero de atleta: ";
            if (cant == 1) cout << "(0): ";
            else cout << "(0 a " << cant - 1 << "): ";

            int id;
            cin >> id;

            if (id >= 0 && id < cant) {
                atletas[id]->registrarMarca();  // POLIMORFISMO
                cout << "Marca registrada.\n";
            } else {
                cout << "Indice invalido.\n";
            }
        }

        /*--------------------------------*/
        /* 3. MOSTRAR DATOS */
        /*--------------------------------*/
        else if (opcion == 3) {
            if (cant == 0) {
                cout << "No hay atletas cargados.\n";
                continue;
            }

            cout << "Numero de atleta: ";
            if (cant == 1) cout << "(0): ";
            else cout << "(0 a " << cant - 1 << "): ";

            int id;
            cin >> id;

            if (id >= 0 && id < cant) {
                atletas[id]->mostrarDatos();
            } else {
                cout << "Indice invalido.\n";
            }
        }

    } while (opcion != 4);

    cout << "Gracias por usar el sistema. :)\n";

    for (int i = 0; i < cant; i++) delete atletas[i];

    return 0;
}
