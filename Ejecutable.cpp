#include <iostream>
#include <set>
#include <cstdlib>
#include <map>
#include "Vacaciones.cpp"
using namespace std;


int main(){
    
    TioBorracho tio;
    TioBorracho persona;
    TioBorracho persona1;
    TioBorracho persona2;
    
    int opcion, familiar;
    cout <<"Ingrese el familiar que desea registrar: " << endl;
    cin >> familiar;
    
    switch (familiar)
    {
        case 1:
            
            cout << "Bienvenido" << endl;
            
            tio.anadirDestinos();
            tio.anadirFechas();
        
            break;
        
        case 2:

            cout << "Bienvenido" << endl;
            persona.anadirDestinos();
            persona.anadirFechas();
            
            break;

        case 3:

            cout << "Bienvenido" << endl;
            persona1.anadirDestinos();
            persona1.anadirFechas();
            
            break;

        case 4:
            
            cout << "Bienvenido" << endl;
            persona2.anadirDestinos();
            persona2.anadirFechas();
            
            break;

        default:

            cout << "Familiar no encontrado" << endl;
            break;
    }

    

    return 0;
}
