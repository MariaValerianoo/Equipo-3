#include <iostream>
#include <set>
#include <cstdlib>
#include <map>
using namespace std;

class TioBorracho{
    
    public:
  
        set <string> destinosGenerales;
        set <string> fechasGenerales;
        map <string, set<string>> miembrosDestinos;
        string miembro, destino, iteBuscar;;

        int dia1, mes1, anio1;
    
    public:
    
    void anadirDestinos(){
    
        while(true){

            cout << "Ingrese el nombre del miembro: " << endl;
            cin >> miembro;
            cout << "Ingrese el destino del viaje (0. para salir): " << endl;
            cin >> destino;
            
            auto iteBuscar = destinosGenerales.find(destino);

            if(iteBuscar != destinosGenerales.end()){
                cout << "El destino ya ha sido registrado" << endl;
            }
            else{

                destinosGenerales.insert(destino);
                miembrosDestinos[miembro].insert(destino);
                cout << "Destino Registrado" << endl;

            }
        }
        
    }
    
    
    
    

    bool fechaValida(int dia, int mes, int anio){
        
        if (dia < 1 || dia > 31)
        {
            return false;
        }
        
        if (mes < 1 || mes > 12)
        {
            return false;
        }
        
        if (anio < 2023)
        {
            return false;
        }
        
        return true;
    }

    

    
};

