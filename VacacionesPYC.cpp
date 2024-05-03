#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Viaje{
    string destino;
    string miembro;
    string fecha;
    string actividades;
    string hora;
};

class TioSobrio{

    public:
        
        Viaje viaje;
        queue <Viaje> colaViajes;
        queue <string> viajesGenerales;
        queue <string> fechasGenerales;
        queue <string> actividadesGenerales;
        queue <string> horasGenerales;
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
            else if(buscarDestino(viaje.destino) == false){

                viaje.fecha = anadirFechas();
                viaje.actividades = anadirActividades();
                viaje.hora = anadirHora();
                
                colaViajes.push(viaje);
                                
                viajesGenerales.push(viaje.destino);
                fechasGenerales.push(viaje.fecha);
                actividadesGenerales.push(viaje.actividades);
                horasGenerales.push(viaje.hora);
                
                cout << "Destino Registrado" << endl;
                
            }
        }
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

    string anadirHora(){

        int hora, minuto;

        while(true){

            cout << "Ingrese la hora de la actividad (HH:MM): " << endl;
            cin >> hora >> minuto;

            if(horaValida(hora,minuto)){

                string hora1 = to_string(hora)+ ":" + to_string(minuto);

                if(buscarHora(hora1) == true){
                
                cout << "Ya hay actividades registradas en esas horas" << endl;
                cout << "Ingrese otras validas" << endl;

                }
                else if(buscarHora(hora1) == false){
                    
                    cout << "Actividades registradas" << endl;
                    return hora1;

                }

            }

        }

    }

    string anadirActividades(){

        while(true){

            cout << "Ingrese las actividades del viaje : " << endl;
            cin >> viaje.actividades;

            if(buscarActividad(viaje.actividades) == true){
                
                cout << "Las actividades ya han sido registradas" << endl;
                cout << "Ingrese otras validas" << endl;

            }
            else if(buscarActividad(viaje.actividades) == false){
                
                cout << "Actividades registradas" << endl;
                return viaje.actividades;

            }

        }

    }

    bool buscarActividad(string actividad){

        queue <Viaje> colaAux = colaViajes;
        while(!colaAux.empty()){
            Viaje viaje = colaAux.front();
            if(viaje.actividades == actividad){
                return true; // si esta en la cola
            }
            else{
                colaAux.pop();
            }
            
        }

        return false; // si no esta en la cola

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

    bool buscarHora(string hora){

        queue <Viaje> colaAux = colaViajes;
        while(!colaAux.empty()){
            Viaje viaje = colaAux.front();
            if(viaje.hora == hora){
                return true; // si esta en la cola
            }
            else{
                colaAux.pop();
            }
            
        }

        return false; // si no esta en la cola

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

    bool horaValida(int hora, int minuto){

        if(hora < 0 || hora > 24){
            return false;
        }

        if(minuto < 0 || minuto > 60){
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
    
    void verActividadesGenerales(){

        queue <string> aux = actividadesGenerales;
        cout << "Fechas generales: " << endl;
        while(!aux.empty()){
            cout << aux.front() << endl;
            aux.pop();
        }

    }

    void verViajesMiembro(string miembro){

        queue <Viaje> colaAux = colaViajes;
        cout << "Viajes de " << miembro << ": " << endl;
        while(!colaAux.empty()){
            Viaje viaje = colaAux.front();
            if(viaje.miembro == miembro){
                cout << "Destino: " << viaje.destino << " Fecha: " << viaje.fecha << endl << "Actividades: " << viaje.actividades << endl << "Hora: " << viaje.hora << endl;
            }   
            colaAux.pop();
        }


    }

};


int main(){

    TioSobrio tio;
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