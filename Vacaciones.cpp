#include <iostream>
#include <set>
#include <cstdlib>
#include <map>
using namespace std;

class TioBorracho{
    
    private:
  
        set <string> destinosGenerales;
        map <string, string> fechasGenerales;
    
    public:
    
    void anadirDestinos(){
    
        string destino;
            
        cout << "Ingrese el destino del viaje: " << endl;
        cin >> destino;
        
        
        while(true){
            
            destinosGenerales.insert(destino);
            auto iteDestino = destinosGenerales.find(destino);
            
            if (iteDestino!=destinosGenerales.end())
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
        int dia1, mes1, anio1;

        cout << "Ingrese fecha de inicio (DD/MM/AAAA): " << endl;
        cin >> dia >> mes >> anio;

        cout << "Ingrese fecha de fin (DD/MM/AAAA): " << endl;
        cin >> dia1 >> mes1 >> anio1;
        
        fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
        fecha1 = to_string(dia1) + "/" + to_string(mes1) + "/" + to_string(anio1);
        // es mejor un mapa para guardar inicio y fin del destino
        
        while(true){
            
            fechasGenerales.insert(fecha, fecha1);
            auto iteFecha = fechasGenerales.find(fecha);
            
            if (iteFecha!= fechasGenerales.end())
            {
                cout << "La fecha ingresado ya esta registrado" << endl;
                fechasGenerales.erase(fecha);
                
            }else{
                
                cout << "Fechas registradas" << endl;
                break;
            }
            
        }
        
        
    }

    void mostrarDestinos(){
        
        for(auto iteDestino = destinosGenerales.begin(); iteDestino != destinosGenerales.end(); iteDestino++){
            
            cout << *iteDestino << endl;
        }
        
    }
    


};
