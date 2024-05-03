#include <iostream>
#include <set>
#include <map>
#include "Vacaciones.cpp"
#include "VacacionesPYC.cpp"

using namespace std;


int main(){
    
    TioBorracho tio;
    TioSobrio tio1;
    string miembro;
    int opcion,opcion1;
    
    while (true){
        
        cout << "Bienvenido al sistema de registro de viajes" << endl;
        cout << "1. para la solucion de Conjuntos y mapas" << endl << "2. para la solucion de Colas y Pilas" << endl << "3. para salir" << endl;
        cin >> opcion;
        
        if(opcion == 1){
            tio.menu();
        }
        else if(opcion == 2){
            tio1.menu();
        }
        else if(opcion == 3){
            cout << "Saliendo del sistema" << endl;
            break;
        }
        else{
            cout << "Opcion invalida" << endl;
        }

    }
    

    return 0;
}
