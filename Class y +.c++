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
    class alumno kapu(17, 80);
    kapu.cantar();
    kapu.cumpleanios();
    alumno ();
    kapu.mostrarDatos();
    cout<<kapu.edadAlumno()<<endl;
    var1.a=10;
    var1.b=20;
    
    kapu.edad=17;
    kapu.peso=80;
    
    int variable =14;
    float ncoma = 3.14;
    
    cout<<"Hola Isiii"<<endl<<endl;
    cout<<"El int en decimal vale: "<<variable<< endl;
    cout<<"El int en hexa vale: 0x"<< hex <<variable<<endl;
    cout<<"El float: "<<dec<<ncoma<<endl<<endl;
  
    cout<<"a en var1 es: "<<var1.a<<endl;
    cout<<"b en var1 es: "<<var1.b<<endl<<endl<<endl;
    kapu.mostrarDatos();
    
    
    return 0;
}

    void alumno::cantar (void){
        cout<<"Con la misma moneda te pagué infeliz"<<endl;
    }
    void alumno::cumpleanios (void){
        edad++;
        cantar();
    }
    void alumno::mostrarDatos (void){
        cout<<"Kapu tiene: "<<edad<<"años"<<endl;
        cout<<"Kapu pesa: "<<peso<<"kg"<<endl;
    }
    void alumno::alumno (int edading,int pesoing){
        edad=edading;
        peso=pesoing;
    }
    int alumno::edadAlumno(){
        return edad;
    }
    
