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
    Destino(string nombre, string fecha, string itinerario) : nombre(nombre), fecha(fecha), itinerario(itinerario) {}

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

class MiembroFamilia {
private:
    string nombre;
    unordered_set<Destino*> destinosPlanificados;

public:
    MiembroFamilia(string nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }

    void agregarDestino(Destino* destino) {
        destinosPlanificados.insert(destino);
    }

    const unordered_set<Destino*>& getDestinosPlanificados() const {
        return destinosPlanificados;
    }
};

class GestionVacaciones {
private:
    unordered_set<Destino*> destinosGenerales;
    map<string, MiembroFamilia*> miembrosFamilia;
    map<Destino*, string> itinerarios;
public:
    void agregarDestino(const string& nombre, const string& fecha, const string& itinerario) {
        Destino nuevoDestino(nombre, fecha, itinerario);
        if (destinosGenerales.find(&nuevoDestino) != destinosGenerales.end()) {
            cout << "El destino ya existe en la lista general." << endl;
            return;
        }
        Destino* ptrNuevoDestino = new Destino(nombre, fecha, itinerario);
        destinosGenerales.insert(ptrNuevoDestino);
        itinerarios[ptrNuevoDestino] = itinerario;
    }

    void planificarViaje(MiembroFamilia* miembro, const string& destinoNombre, const string& fecha) {
        auto it = find_if(destinosGenerales.begin(), destinosGenerales.end(), [&destinoNombre](const Destino* destino){
            return destino->getNombre() == destinoNombre;
        });
        if (it == destinosGenerales.end()) {
            cout << "El destino especificado no existe." << endl;
            return;
        }
        miembro->agregarDestino(*it);
    }

    void consultarDestinosPlanificados(MiembroFamilia* miembro) const {
        cout << "Destinos planificados para " << miembro->getNombre() << ":" << endl;
        for (const Destino* destino : miembro->getDestinosPlanificados()) {
            cout << destino->getNombre() << " - Fecha: " << destino->getFecha() << endl;
            cout << "Itinerario: " << destino->getItinerario() << endl;
        }
    }

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


