#include <iostream> 
using namespace std;

struct{
    int a;
    int b;
}var1;

class alumno{
    public:
        int edad;
        int peso;
        void cantar (void);
        void cumpleanios (void);
        void mostrarDatos (void);
        alumno (int edading,int pesoing);
        alumno (void);
        int edadAlumno(void);
    
}kapu;

int main(){
    class alumno kapu(17, 75);
    kapu.cumpleanios();
    alumno ();
    kapu.mostrarDatos();
    cout<<kapu.edadAlumno()<<endl;
    var1.a=10;
    var1.b=20;
    
    kapu.edad=17;
    kapu.peso=75;
    
    int variable =17;
    float ncoma = 3.14;
    
    cout<<"Hola Isiii"<<endl<<endl;
    cout<<"Kapu en decimal tiene: "<<variable<< endl;
    cout<<"Y en hexa tiene: 0x"<< hex <<variable<<endl;
    cout<<"Y un float que nada que ver: "<<dec<<ncoma<<endl<<endl;
  
    cout<<"a en var1 es: "<<var1.a<<endl;
    cout<<"b en var1 es: "<<var1.b<<endl<<endl<<endl;
    kapu.mostrarDatos();
    
    
    return 0;
}

    void alumno::cantar (void){
        cout<<"Con la misma moneda te pagué infeliz"<<endl<<endl;
    }
    void alumno::cumpleanios (void){
        cantar();
        edad++;
    }
    void alumno::mostrarDatos (void){
        cout<<"Kapu tiene: "<<edad<<" años"<<endl;
        cout<<"Kapu pesa: "<<peso<<"kg"<<endl;
    }
    alumno::alumno (int edading, int pesoing){
        edad=edading;
        peso=pesoing;
    }
    alumno::alumno(){
        
    }
    int alumno::edadAlumno(){
        return edad;
    }
