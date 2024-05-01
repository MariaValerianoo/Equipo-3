#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Viaje{
    string destino;
    string miembro;
    string fecha;
};

class TioSobrio{

    public:
        
        Viaje viaje;
        queue <Viaje> colaViajes;

    public:

    void anadirDestinos(){
    
        while(true){

            cout << "Ingrese el nombre del miembro: " << endl;
            cin >> viaje.miembro;
            cout << "Ingrese el destino del viaje (0. para salir): " << endl;
            cin >> viaje.destino;
            
            if(buscarDestino(viaje.destino)){
                
                cout << "El destino ya ha sido registrado" << endl;

            }
            else{

                
            }
        }
        
    }

    bool buscarDestino(string destino){

        queue <Viaje> colaAux = colaViajes;
        while(!colaAux.empty()){
            Viaje viaje = colaAux.front();
            if(viaje.destino == destino){
                return true; // si esta en la cola
            }
            else{
                colaAux.pop();
            }
            
        }

        return false; // si no esta en la cola

    }
};