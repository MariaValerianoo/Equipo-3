#include <iostream>
#include <set>
#include <cstdlib>
#include <map>
using namespace std;

class TioBorracho{
    
    private:
  
        set <string> destinosGenerales;
        map <string, string> fechasGenerales;
        
        int dia1, mes1, anio1;
    
    public:
    
    void anadirDestinos(){
    
        string destino;
            
        cout << "Ingrese el destino del viaje: " << endl;
        cin >> destino;
        
        
        while(true){
            
            destinosGenerales.insert(destino);
            auto iteDestino = destinosGenerales.find(destino);
            
            if (destinosGenerales.size() != 0 && iteDestino==destinosGenerales.end())
            {
                cout << "El destino ingresado ya esta registrado" << endl;
                destinosGenerales.erase(destino);
                
            }else{
                
                cout << "Destino registrado" << endl;
                break;
            }
            
        }
        
    }
    
    void anadirFechas(){

        string fecha, fecha1;
        int dia, mes, anio;

        cout << "Ingrese fecha de inicio (DD/MM/AAAA): " << endl;
        cin >> dia >> mes >> anio;

        cout << "Ingrese fecha de fin (DD/MM/AAAA): " << endl;
        cin >> dia1 >> mes1 >> anio1;
                  
        while(true){
            
            if (fechaValida(dia, mes, anio) == true && fechaValida(dia1, mes1, anio1) == true){

                fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
                fecha1 = to_string(dia1) + "/" + to_string(mes1) + "/" + to_string(anio1);

                fechasGenerales.insert(pair<string, string>(fecha, fecha1));
                auto iteFecha = fechasGenerales.find(fecha);
                auto iteFecha1 = fechasGenerales.find(fecha1);
                
                if (iteFecha!= fechasGenerales.end() && iteFecha1!= fechasGenerales.end())
                {
                    cout << "La fecha ingresado ya esta registrado" << endl;
                    fechasGenerales.erase(fecha);
                    
                }else{
                    
                    cout << "Fechas registradas" << endl;
                    break;
                }
            }
            else{

                cout << "Fecha no valida, ingrese nuevamente" << endl;
                break;

            }
        } 
        
        
    }

    bool fechaDisponible(int dia, int mes, int anio){


        if(dia > dia1 || mes > mes1 || anio > anio1){

            return true;

        }
        else{

            cout << "En esta fecha no hay disponibilidad de viaje" << endl;
            return false;

        }

    }
    
    
    void mostrarDestinos(){
        
        for(auto iteDestino = destinosGenerales.begin(); iteDestino != destinosGenerales.end(); iteDestino++){
            
            cout << *iteDestino << endl;
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

int main(){
    
    TioBorracho tio;
    
    tio.anadirDestinos();
    tio.anadirFechas();
    tio.mostrarDestinos();
    
    return 0;
}
