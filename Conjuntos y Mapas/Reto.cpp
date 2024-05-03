#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
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

    // Métodos para obtener los atributos del destino
    string getNombre() const {
        return nombre;
    }

    string getFecha() const {
        return fecha;
    }

    string getItinerario() const {
        return itinerario;
    }
    
    bool operator==(const Destino& otro) const {
        return nombre == otro.nombre;
    }
};

class MiembroFami {
private:
    string nombre;
    unordered_set<Destino*> destinosPlanificados;

public:
    // Constructor de la clase MiembroFamilia
    MiembroFami(string nombre) : nombre(nombre) {}

    // Método para obtener el nombre del miembro
    string getNombre() const {
        return nombre;
    }

    // Método para agregar un destino planificado al miembro
    void agregarDestino(Destino* destino) {
        destinosPlanificados.insert(destino);
    }

    // Método para obtener los destinos planificados del miembro
    const unordered_set<Destino*>& getDestinosPlanificados() const {
        return destinosPlanificados;
    }
};

class GestionVacaciones {
private:
    unordered_set<Destino*> destinosGenerales;
    map<string, MiembroFami*> miembrosFamilia;
    map<Destino*, string> itinerarios;

public:
    // Método para agregar un nuevo destino a la lista general de destinos
    void agregarDest(const string& nombre, const string& fecha, const string& itinerario) {
        string itin = itinerario;
        char opcion;
        cout << "¿Desea crear un itinerario personalizado? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            genItinerarioUsuario(itin);
        } else {
            itin = "Día 1: Llegada y check-in\nDía 2: Explorar lugares de interés\nDía 3: Actividades recreativas\nDía 4: Check-out y partida";
        }
        
        Destino* ptrNuevoDestino = new Destino(nombre, fecha, itin);
        destinosGenerales.insert(ptrNuevoDestino);
        itinerarios[ptrNuevoDestino] = itin;
        cout << "Agregado con éxito. Si deseas conocer el itinerario, puedes encontrarlo al momento de planificar un viaje" << endl;
    }

    // Método para permitir a un miembro de la familia planificar un viaje a un destino específico
    void planificarViaje(MiembroFami* miembro, const string& destinoNom, const string& fecha) {
        cout << "Lista de destinos disponibles:" << endl;
        for (const Destino* destino : destinosGenerales) {
            cout << destino->getNombre() << endl;
        }

        auto it = find_if(destinosGenerales.begin(), destinosGenerales.end(), [&destinoNom](const Destino* destino){
            return destino->getNombre() == destinoNom;
        });
        
        if (it == destinosGenerales.end()) {
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
                agregarDest(destinoNom, fecha, itinerario);
                planificarViaje(miembro, destinoNom, fecha);
                return;
            } else {
                return;
            }
        }
        
        miembro->agregarDestino(*it);
    }

    // Método para mostrar los destinos planificados por un miembro de la familia
    void consultarDestinosPlanificados(MiembroFami* miembro) const {
        cout << "Destinos planificados para " << miembro->getNombre() << ":" << endl;
        for (const Destino* destino : miembro->getDestinosPlanificados()) {
            cout << destino->getNombre() << " - Fecha: " << destino->getFecha() << endl;
            cout << "Itinerario: " << destino->getItinerario() << endl;
        }
    }

    // Método para encontrar los miembros de la familia que planean visitar un destino específico
    void encontrarMiembrosPorDestino(const string& destinoNom) const {
        cout << "Miembros que planean visitar " << destinoNom << ":" << endl;
        for (const auto& pair : miembrosFamilia) {
            const MiembroFami* miembro = pair.second;
            for (const Destino* destino : miembro->getDestinosPlanificados()) {
                if (destino->getNombre() == destinoNom) {
                    cout << miembro->getNombre() << endl;
                    break;
                }
            }
        }
    }

    // Método para generar un itinerario personalizado para un destino
    void genItinerarioUsuario(string& itinerario) {
        cout << "Ingrese el itinerario para los siguientes tres días:" << endl;
        for (int i = 1; i <= 3; ++i) {
            cout << "Día " << i << ": ";
            string actividad;
            cin.ignore(); 
            getline(cin, actividad);
            itinerario += "\nDía " + to_string(i) + ": " + actividad;
        }
        cout << "Creado con éxito" << endl;
    }
};
