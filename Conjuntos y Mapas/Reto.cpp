#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

// Definición de la clase Destino
class Destino {
private:
    string nombre;
    string fecha;
    string itinerario;

public:
    // Constructor de la clase
    Destino(string nombre, string fecha, string itinerario) : nombre(nombre), fecha(fecha), itinerario(itinerario) {}

    // Métodos para obtener los atributos
    string getNombre() const {
        return nombre;
    }

    string getFecha() const {
        return fecha;
    }

    string getItinerario() const {
        return itinerario;
    }
    
    // Sobrecarga del operador de igualdad para comparar destinos por nombre
    bool operator==(const Destino& otro) const {
        return nombre == otro.nombre;
    }
};

// Definición de la clase MiembroFamilia
class MiembroFamilia {
private:
    string nombre;
    unordered_set<Destino*> destinosPlanificados;

public:
    // Constructor de la clase
    MiembroFamilia(string nombre) : nombre(nombre) {}

    // Métodos para obtener los atributos
    string getNombre() const {
        return nombre;
    }

    // Agregar un destino planificado al conjunto
    void agregarDestino(Destino* destino) {
        destinosPlanificados.insert(destino);
    }

    // Obtener una referencia constante al conjunto de destinos planificados
    const unordered_set<Destino*>& getDestinosPlanificados() const {
        return destinosPlanificados;
    }
};

// Definición de la clase GestionVacaciones
class GestionVacaciones {
private:
    unordered_set<Destino*> destinosGenerales;
    map<string, MiembroFamilia*> miembrosFamilia;
    map<Destino*, string> itinerarios;

public:
    // Agregar un nuevo destino a la lista general de destinos
    void agregarDestino(const string& nombre, const string& fecha, const string& itinerario) {
        Destino nuevoDestino(nombre, fecha, itinerario);
        // Verificar si el destino ya existe en la lista general
        if (destinosGenerales.find(&nuevoDestino) != destinosGenerales.end()) {
            cout << "El destino ya existe en la lista general." << endl;
            return;
        }
        // Crear un nuevo objeto Destino en el heap y agregarlo al conjunto
        Destino* ptrNuevoDestino = new Destino(nombre, fecha, itinerario);
        destinosGenerales.insert(ptrNuevoDestino);
        itinerarios[ptrNuevoDestino] = itinerario;
    }

    // Planificar un viaje para un miembro de la familia hacia un destino específico
    void planificarViaje(MiembroFamilia* miembro, const string& destinoNombre, const string& fecha) {
        // Buscar el destino en la lista general
        auto it = find_if(destinosGenerales.begin(), destinosGenerales.end(), [&destinoNombre](const Destino* destino){
            return destino->getNombre() == destinoNombre;
        });
        // Verificar si el destino especificado existe
        if (it == destinosGenerales.end()) {
            cout << "El destino especificado no existe." << endl;
            return;
        }
        // Agregar el destino planificado al miembro de la familia
        miembro->agregarDestino(*it);
    }

    // Consultar los destinos planificados para un miembro de la familia
    void consultarDestinosPlanificados(MiembroFamilia* miembro) const {
        cout << "Destinos planificados para " << miembro->getNombre() << ":" << endl;
        for (const Destino* destino : miembro->getDestinosPlanificados()) {
            cout << destino->getNombre() << " - Fecha: " << destino->getFecha() << endl;
            cout << "Itinerario: " << destino->getItinerario() << endl;
        }
    }

    // Encontrar miembros de la familia que planean visitar un destino específico
    void encontrarMiembrosPorDestino(const string& destinoNombre) const {
        cout << "Miembros que planean visitar " << destinoNombre << ":" << endl;
        for (const auto& pair : miembrosFamilia) {
            const MiembroFamilia* miembro = pair.second;
            for (const Destino* destino : miembro->getDestinosPlanificados()) {
                if (destino->getNombre() == destinoNombre) {
                    cout << miembro->getNombre() << endl;
                    break;
                }
            }
        }
    }
};

