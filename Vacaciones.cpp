#include <iostream>
#include <set>
#include <cstdlib>
#include <map>
using namespace std;

class TioBorracho{
    
    private:
  
        set <string> destinosGenerales;
        set <string> fechasGenerales;
    
    public:
    
    void anadirDestinos(){
    
        string destino;
            
        cout << "ingrese: " << endl;
        cin >> destino;
        
        
        
        while(true){
            
            destinosGenerales.insert(destino);
            auto iteDestino = destinosGenerales.find(destino);
            
            if (iteDestino!=destinosGenerales.end())
            {
                cout << "El destino ingresado ya esta registrado" << endl;
                destinosGenerales.erase(destino);
                
            }else{
                
                cout << "destino registrado" << endl;
                
            }
            
        }
        
        
        
    }
    
    void anadirFechas(){
        
        string fecha;
        int dia, mes, anio;
            
        cout << "ingrese dia /mes / año " << endl;
        cin >> dia >> mes >> anio;
        
        
        fecha = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
        // es mejor un mapa para guardar inicio y fin del destino
        
        while(true){
            
            fechasGenerales.insert(fecha);
            auto iteFecha = fechasGenerales.find(fecha);
            
            if (iteFecha!= fechasGenerales.end())
            {
                cout << "La fecha ingresado ya esta registrado" << endl;
                fechasGenerales.erase(fecha);
                
            }else{
                
                cout << "fechas registrado" << endl;
                
            }
            
        }
        
    }
    
};
