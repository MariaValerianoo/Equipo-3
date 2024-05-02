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
        queue <string> viajesGenerales;
        queue <string> fechasGenerales;
        int dia1, mes1, anio1;

    public:

    void anadirDestinos(){
    
        while(true){

            cout << "Ingrese el nombre del miembro: " << endl;
            cin >> viaje.miembro;
            cout << "Ingrese el destino del viaje (0. para salir): " << endl;
            cin >> viaje.destino;
            
            if (viaje.destino == "0"){
                break;
            }
            else if(buscarDestino(viaje.destino) == true){
                
                cout << "El destino ya ha sido registrado" << endl;
                cout << "Ingrese otro valido" << endl;

            }
            else{

                viaje.fecha = anadirFechas();
                colaViajes.push(viaje);
                viajesGenerales.push(viaje.destino);
                fechasGenerales.push(viaje.fecha);
                cout << "Destino Registrado" << endl;
                
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

    bool buscarFecha(string fecha){

        queue <Viaje> colaAux = colaViajes;
        while(!colaAux.empty()){
            Viaje viaje = colaAux.front();
            if(viaje.fecha == fecha){
                return true; // si esta en la cola
            }
            else{
                colaAux.pop();
            }
            
        }

        return false; // si no esta en la cola

    }

    string anadirFechas(){

        while(true){

            cout << "Ingrese la fecha del viaje ((DD/MM/AAAA)  0. para salir): " << endl;
            cin >> dia1 >> mes1 >> anio1;

            if(fechaValida(dia1, mes1, anio1)){

                string fecha = to_string(dia1) + "/" + to_string(mes1) + "/" + to_string(anio1);
                
                if(buscarDestino(viaje.destino) == true){
                
                    cout << "La fecha ya ha sido registrada" << endl;
                    cout << "Ingrese otro valido" << endl;
                
                }
                else{

                    cout << "Fecha registada" << endl;
                    return fecha;
                }

            }
            else{
                
                cout << "Fecha no valida" << endl;
                cout << "Ingrese otra fecha" << endl;
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

    void verViajesGenerales(){

        queue <string> aux = viajesGenerales;
        cout << "Destinos generales: " << endl;
        while(!aux.empty()){
            cout << aux.front() << endl;
            aux.pop();
        }

    }

    void verFechasGenerales(){

        queue <string> aux = fechasGenerales;
        cout << "Fechas generales: " << endl;
        while(!aux.empty()){
            cout << aux.front() << endl;
            aux.pop();
        }

    }

};