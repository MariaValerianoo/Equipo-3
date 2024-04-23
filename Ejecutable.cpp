#include <iostream>
#include <set>
#include <cstdlib>
#include <map>
#include "Vacaciones.cpp"
using namespace std;


int main(){
    
    TioBorracho tio;
    string miembro;
    int opcion,opcion1;
    
    while (true)
    {
        cout << "Bienvenido familiar :" << endl;
        cout << "1. para registrar destinos \n2. para ver destinos " << endl << "0.para salir" << endl;
        cin >> opcion;
        
        if(opcion == 1){
            tio.anadirDestinos();
        }
        else if(opcion == 2){
            cout << "1. Ver destinos generales \n2. Ver destinos por miembro \n3. Ver viajes por fecha" << endl;
            cin >> opcion1;
            if (opcion1 == 1){
                tio.verViajesGenerales();
            }
            else if (opcion1 == 2){
                cout << "Ingrese el nombre del miembro: " << endl;
                cin >> miembro;
                tio.verViajesMiembro(miembro);
            }
            else if (opcion1 == 2){
                tio.verFechasGenerales();
            }
        }     
        else if(opcion == 0){
            cout << "Hasta luego" << endl;
            break;
        }
        else{
            cout << "Opcion no valida" << endl;
        }
    }

    return 0;
}
