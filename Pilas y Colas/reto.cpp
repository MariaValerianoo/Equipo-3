#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Destino {
private:
    string nombre;
    string fecha;
    string itinerario;

public:
    // Constructor de la clase Destino
    Destino(string nombre, string fecha, string itinerario) : nombre(nombre), fecha(fecha), itinerario(itinerario) {}

    // Métodos para obtener los detalles del destino
    string obtenerNombre() const {
        return nombre;
    }

    string obtenerFecha() const {
        return fecha;
    }

    string obtenerItinerario() const {
        return itinerario;
    }
    
    // Sobrecarga del operador de igualdad para comparar destinos
    bool operator==(const Destino& otro) const {
        return nombre == otro.nombre;
    }
};

class MiembroFamilia {
private:
    string nombre;
    queue<Destino*> destinosPlanificados; // Cola para mantener el orden de llegada de los destinos planificados

public:
    // Constructor de la clase MiembroFamilia
    MiembroFamilia(string nombre) : nombre(nombre) {}

    // Método para obtener el nombre del miembro de la familia
    string obtenerNombre() const {
        return nombre;
    }

    // Método para agregar un destino planificado al miembro de la familia
    void agregarDestino(Destino* destino) {
        destinosPlanificados.push(destino);
    }

    // Método para obtener los destinos planificados del miembro de la familia
    const queue<Destino*>& obtenerDestinosPlanificados() const {
        return destinosPlanificados;
    }
};

class GestionVacaciones {
private:
    stack<Destino*> destinosGenerales; // Pila para mantener el último destino agregado en la parte superior
    stack<MiembroFamilia*> miembrosFamilia; // Pila para mantener el último miembro de la familia agregado en la parte superior
    stack<pair<Destino*, string>> itinerarios; // Pila para mantener el último itinerario agregado en la parte superior

public:
    // Método para agregar un nuevo destino a la lista general de destinos
    void agregarDestino(const string& nombre, const string& fecha, const string& itinerario) {
        string itin = itinerario;
        char opcion;
        cout << "¿Desea crear un itinerario personalizado? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            generarItinerarioUsuario(itin);
        } else {
            itin = "Día 1: Llegada y check-in\nDía 2: Explorar lugares de interés\nDía 3: Actividades recreativas\nDía 4: Check-out y partida";
        }
        
        Destino* nuevoDestino = new Destino(nombre, fecha, itin);
        destinosGenerales.push(nuevoDestino);
        itinerarios.push(make_pair(nuevoDestino, itin));
        cout << "Destino agregado exitosamente. Puedes ver el itinerario al momento de planificar un viaje." << endl;
    }

    // Método para permitir que un miembro de la familia planifique un viaje a un destino específico
    void planificarViaje(MiembroFamilia* miembro, const string& nombreDestino, const string& fecha) {
        cout << "Lista de destinos disponibles:" << endl;
        stack<Destino*> destinosTemp = destinosGenerales; // Copia temporal de la pila para no modificar la original
        while (!destinosTemp.empty()) {
            cout << destinosTemp.top()->obtenerNombre() << endl;
            destinosTemp.pop();
        }

        bool encontrado = false;
        while (!destinosGenerales.empty()) {
            if (destinosGenerales.top()->obtenerNombre() == nombreDestino) {
                miembro->agregarDestino(destinosGenerales.top());
                encontrado = true;
                break;
            }
            destinosGenerales.pop();
        }
        
        if (!encontrado) {
            cout << "El destino especificado no existe." << endl;
            char opcion;
            cout << "¿Desea agregar este destino a la lista general? (s/n): ";
            cin >> opcion;
            if (opcion == 's' || opcion == 'S') {
                string fecha, itinerario;
                cout << "Ingrese la fecha del destino: ";
                cin >> fecha;
                cout << "Ingrese el itinerario del destino: ";
                cin.ignore();
                getline(cin, itinerario);
                agregarDestino(nombreDestino, fecha, itinerario);
                planificarViaje(miembro, nombreDestino, fecha);
                return;
            } else {
                return;
            }
        }
    }

    // Método para mostrar los destinos planificados por un miembro de la familia
    void consultarDestinosPlanificados(MiembroFamilia* miembro) const {
        cout << "Destinos planificados para " << miembro->obtenerNombre() << ":" << endl;
        queue<Destino*> destinosTemp = miembro->obtenerDestinosPlanificados(); // Copia temporal de la cola para no modificar la original
        while (!destinosTemp.empty()) {
            Destino* destino = destinosTemp.front();
            cout << destino->obtenerNombre() << " - Fecha: " << destino->obtenerFecha() << endl;
            cout << "Itinerario: " << destino->obtenerItinerario() << endl;
            destinosTemp.pop();
        }
    }

    // Método para encontrar los miembros de la familia que planean visitar un destino específico
    void encontrarMiembrosPorDestino(const string& nombreDestino) const {
        cout << "Miembros que planean visitar " << nombreDestino << ":" << endl;
        stack<MiembroFamilia*> miembrosTemp = miembrosFamilia; // Copia temporal de la pila para no modificar la original
        while (!miembrosTemp.empty()) {
            queue<Destino*> destinosTemp = miembrosTemp.top()->obtenerDestinosPlanificados(); // Copia temporal de la cola para no modificar la original
            while (!destinosTemp.empty()) {
                if (destinosTemp.front()->obtenerNombre() == nombreDestino) {
                    cout << miembrosTemp.top()->obtenerNombre() << endl;
                    break;
                }
                destinosTemp.pop();
            }
            miembrosTemp.pop();
        }
    }

    // Método para generar un itinerario personalizado para un destino
    void generarItinerarioUsuario(string& itinerario) {
        cout << "Ingrese el itinerario para los siguientes tres días:" << endl;
        for (int i = 1; i <= 3; ++i) {
            cout << "Día " << i << ": ";
            string actividad;
            cin.ignore(); 
            getline(cin, actividad);
            itinerario += "\nDía " + to_string(i) + ": " + actividad;
        }
        cout << "Itinerario creado exitosamente" << endl;
    }
};

