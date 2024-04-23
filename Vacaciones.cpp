#include <iostream>
#include <set>
#include <map>
using namespace std;

class TioBorracho{
    
    public:
  
        set <string> destinosGenerales;
        set <string> fechasGenerales;
        map <string, map<string,string>> miembrosDestinos;
        string miembro, destino, iteBuscar;

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
                cout << "Ingrese otro destino" << endl;
            }
            else{

                destinosGenerales.insert(destino);
                miembrosDestinos[miembro].insert(pair<string,string>(destino, anadirFechas()));
                cout << "Destino Registrado" << endl;
                break;

            }
        }
        
    }
    
    string anadirFechas(){

        while(true){

            cout << "Ingrese la fecha del viaje ((DD/MM/AAAA)  0. para salir): " << endl;
            cin >> dia1 >> mes1 >> anio1;

            if(fechaValida(dia1, mes1, anio1)){

                string fecha = to_string(dia1) + "/" + to_string(mes1) + "/" + to_string(anio1);
                
                auto iteBuscar = fechasGenerales.find(fecha);
                if(iteBuscar != fechasGenerales.end()){

                    cout << "La fecha ya ha sido registrada" << endl;
                    cout << "Ingrese otra fecha" << endl;
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

    void verViajesMiembro(string miembro){

        auto itBus = miembrosDestinos.find(miembro);

        if(itBus != miembrosDestinos.end()){
            cout << "Miembro: " << itBus->first << endl;
            for(auto& ite2  : itBus -> second){
                cout << "Destino: " << ite2.first << " Fecha: " << ite2.second << endl;
            }

        }
        else{
            cout << "Miembro no encontrado" << endl;
        }

    }
    
    void verViajesGenerales(){

        if(destinosGenerales.empty()){

            cout << "No hay destinos registrados" << endl;
            cout << "por favor resgistre un destino" << endl;

        }
        else{

            for(auto& ite : destinosGenerales){
                cout << "Destino: " << ite << endl;
            }

        }

    }

    void verFechasGenerales(){

        if(fechasGenerales.empty()){

            cout << "No hay fechas registradas" << endl;
            cout << "por favor resgistre una fecha" << endl;

        }
        else{

            for(auto& ite : fechasGenerales){
                cout << "Fecha: " << ite << endl;
            }

        }

    }

    
};

