#include <iostream>
#include <queue>
#include <stack>

using namespace std;
// definimos una estructura para almacenar la informacion
struct Viaje1{
    string destino;
    string miembro;
    string fecha;
    string actividades;
    string hora;
};

class TioSobrio{

    public:
        //instanciamos la clase y creamos colas para los destinios, fechas, actividades y horas
        Viaje1 viaje;
        queue <Viaje1> colaViajes;
        queue <string> viajesGenerales;
        queue <string> fechasGenerales;
        queue <string> actividadesGenerales;
        queue <string> horasGenerales;
        int dia1, mes1, anio1;

    public:

    void anadirDestinos(){
        
        while(true){
            //solicitamos nombre y destino
            cout << "Ingrese el nombre del miembro: " << endl;
            cin >> viaje.miembro;
            cout << "Ingrese el destino del viaje (0. para salir): " << endl;
            cin >> viaje.destino; 
            
            if (viaje.destino == "0"){
                break;
            }// llama a la funcion y valida si el destino esta resgistrado
            else if(buscarDestino(viaje.destino) == true){
                
                cout << "El destino ya ha sido registrado" << endl;
                cout << "Ingrese otro valido" << endl;

            }
            else if(buscarDestino(viaje.destino) == false){
                // para la cada objeto de la struct llama una funcion
                viaje.fecha = anadirFechas();
                viaje.actividades = anadirActividades();
                viaje.hora = anadirHora();
                //una vez llena la struct la agrega a la cola
                colaViajes.push(viaje);
                // agrega los objetos a las colas generales
                viajesGenerales.push(viaje.destino);
                fechasGenerales.push(viaje.fecha);
                actividadesGenerales.push(viaje.actividades);
                horasGenerales.push(viaje.hora);
                
                cout << "Destino Registrado" << endl;
                break;
            }
        }
    }

    string anadirFechas(){

        while(true){
            //solcita la fecha 
            cout << "Ingrese la fecha del viaje (DD/MM/AAAA): " << endl;
            cin >> dia1 >> mes1 >> anio1;
            // valida si la fecha esta en los rangos y la pasa a string y valida si esta en las colas generales
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
            // solicita la hora
            cout << "Ingrese la hora de la actividad (HH:MM): " << endl;
            cin >> hora >> minuto;
            // valida si la hora esta en los rangos y la pasa a string y valida si esta en las colas generales
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
            // solicita las actividades
            cout << "Ingrese las actividades del viaje : " << endl;
            cin >> viaje.actividades;
            //valida si esta en las colas generales
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
        //crea un cola aux y valida si esta el parametro en la cola aux
        queue <Viaje1> colaAux = colaViajes;
        while(!colaAux.empty()){
            Viaje1 viaje = colaAux.front();
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
        //crea un cola aux y valida si esta el parametro en la cola aux
        queue <Viaje1> colaAux = colaViajes;
        while(!colaAux.empty()){
            Viaje1 viaje = colaAux.front();
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
        //crea un cola aux y valida si esta el parametro en la cola aux
        queue <Viaje1> colaAux = colaViajes;
        while(!colaAux.empty()){
            Viaje1 viaje = colaAux.front();
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
        //crea un cola aux y valida si esta el parametro en la cola aux
        queue <Viaje1> colaAux = colaViajes;
        while(!colaAux.empty()){
            Viaje1 viaje = colaAux.front();
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
        //valida si la fecha esta en los rangos
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
        // valida si la hora esta en los rangos establecidos
        if(hora < 0 || hora > 24){
            return false;
        }

        if(minuto < 0 || minuto > 60){
            return false;
        }


        return true;

    }

    void verViajesGenerales(){
        // crea un cola aux e imprime 
        queue <string> aux = viajesGenerales;
        cout << "Destinos generales: " << endl;
        while(!aux.empty()){
            cout << aux.front() << endl;
            aux.pop();
        }

    }

    void verFechasGenerales(){
        // crea un cola aux e imprime 
        queue <string> aux = fechasGenerales;
        cout << "Fechas generales: " << endl;
        while(!aux.empty()){
            cout << aux.front() << endl;
            aux.pop();
        }

    }
    
    void verActividadesGenerales(){
        // crea un cola aux e imprime 
        queue <string> aux = actividadesGenerales;
        cout << "Fechas generales: " << endl;
        while(!aux.empty()){
            cout << aux.front() << endl;
            aux.pop();
        }

    }

    void verViajesMiembro(string miembro){
        // crea un cola aux e imprime los datos del miembro pasado al parametro
        queue <Viaje1> colaAux = colaViajes;
        cout << "Viajes de " << miembro << ": " << endl;
        while(!colaAux.empty()){
            Viaje1 viaje = colaAux.front();
            if(viaje.miembro == miembro){
                cout << "Destino: " << viaje.destino << " Fecha: " << viaje.fecha << endl << "Actividades: " << viaje.actividades << endl << "Hora: " << viaje.hora << endl;
            }   
            colaAux.pop();
        }


    }

    void menu(){
            
            int opcion;
            string miembro;
    
            while(true){
                // menu para el usuario
                cout << "1. para registrar un viaje" << endl << "2. para ver los destinos generales" << endl << "3. para ver las fechas generales" << endl << "4. para ver las actividades generales" << endl << "5. para ver los viajes de un miembro" << endl << "6. para salir" << endl;
                cin >> opcion;
    
                if(opcion == 1){
                    anadirDestinos();
                }
                else if(opcion == 2){
                    verViajesGenerales();
                }
                else if(opcion == 3){
                    verFechasGenerales();
                }
                else if(opcion == 4){
                    verActividadesGenerales();
                }
                else if(opcion == 5){
                    cout << "Ingrese el nombre del miembro: " << endl;
                    cin >> miembro;
                    verViajesMiembro(miembro);
                }
                else if(opcion == 6){
                    cout << "Saliendo del sistema" << endl;
                    break;
                }
                else{
                    cout << "Opcion invalida" << endl;
                }
    
            }
    }

};
