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
    
    while (true){
        
        int opcion, familiar;
        cout <<"Ingrese el familiar que desea registrar: " << endl;
        
        switch (familiar)
        {
        case 1:
            
            cout << "1. Anadir destino" << endl;
            cout << "2. Anadir fechas" << endl;
            cout << "3. Mostrar destinos" << endl;
            cout << "4. Salir" << endl;
            
            cout << "Ingrese una opcion: " << endl;
            cin >> opcion;
            
            if (opcion == 1)
            {
                tio.anadirDestinos();
            }
            
            if (opcion == 2)
            {
                tio.anadirFechas();
            }
            
            if (opcion == 3)
            {
                tio.mostrarDestinos();
            }
            
            if (opcion == 4)
            {
                break;
            }
            break;
        
        case 2:

            cout << "1. Anadir destino" << endl;
            cout << "2. Anadir fechas" << endl;
            cout << "3. Mostrar destinos" << endl;
            cout << "4. Salir" << endl;
            
            cout << "Ingrese una opcion: " << endl;
            cin >> opcion;
            
            if (opcion == 1)
            {
                persona.anadirDestinos();
            }
            
            if (opcion == 2)
            {
                persona.anadirFechas();
            }
            
            if (opcion == 3)
            {
                persona.mostrarDestinos();
            }
            
            if (opcion == 4)
            {
                break;
            }
            break;

        case 3:

            cout << "1. Anadir destino" << endl;
            cout << "2. Anadir fechas" << endl;
            cout << "3. Mostrar destinos" << endl;
            cout << "4. Salir" << endl;
            
            cout << "Ingrese una opcion: " << endl;
            cin >> opcion;
            
            if (opcion == 1)
            {
                persona1.anadirDestinos();
            }
            
            if (opcion == 2)
            {
                persona1.anadirFechas();
            }
            
            if (opcion == 3)
            {
                persona1.mostrarDestinos();
            }
            
            if (opcion == 4)
            {
                break;
            }
            break;

        case 4:
            
            cout << "1. Anadir destino" << endl;
            cout << "2. Anadir fechas" << endl;
            cout << "3. Mostrar destinos" << endl;
            cout << "4. Salir" << endl;
            
            cout << "Ingrese una opcion: " << endl;
            cin >> opcion;
            
            if (opcion == 1)
            {
                persona2.anadirDestinos();
            }
            
            if (opcion == 2)
            {
                persona2.anadirFechas();
            }
            
            if (opcion == 3)
            {
                persona2.mostrarDestinos();
            }
            
            if (opcion == 4)
            {
                break;
            }
            break;

        default:

            cout << "Familiar no encontrado" << endl;
            break;
        }

    }
    
    return 0;
}
