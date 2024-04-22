#include <iostream>
#include <set>
#include <cstdlib>
#include <map>
#include "Vacaciones.cpp"
using namespace std;


int main(){
    
    TioBorracho tio;
    int opcion;
    
    while (true)
    {
        cout << "Bienvenido familiar :" << endl;
        cout << "1. para registrar destinos \n 2. para ver destinos " << endl << "0.para salir";
        cin >> opcion;
        if(opcion == 1){
            tio.anadirDestinos();
            tio.anadirFechas();
        }
        else if(opcion == 2 && tio.miembrosDestinos.size() != 0){

            tio.mostrarViajes();
        }
        else if(opcion == 0){
            break;
        }
        else{
            cout << "Ingrese una opcion valida" << endl;
        }
    }

    return 0;
}
