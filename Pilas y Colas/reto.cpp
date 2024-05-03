#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

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
};

// Definición de la clase MiembroFamilia
class MiembroFamilia {
private:
    string nombre;
    Destino** destinosPlanificados;
    int numDestinos;
    stack<Destino*> destinosPendientes; // Pila de destinos pendientes por visitar
    queue<Destino*> destinosVisitados;  // Cola de destinos visitados

public:
    // Constructor de la clase
    MiembroFamilia(string nombre) : nombre(nombre), destinosPlanificados(nullptr), numDestinos(0) {}

    // Destructor de la clase
    ~MiembroFamilia() {
        delete[] destinosPlanificados;
    }

    // Métodos para obtener los atributos
    string getNombre() const {
        return nombre;
    }

    // Agregar un destino planificado al arreglo dinámico de destinos y a la pila de destinos pendientes
    void agregarDestino(Destino* destino) {
        Destino** temp = new Destino*[numDestinos + 1];
        for (int i = 0; i < numDestinos; ++i) {
            temp[i] = destinosPlanificados[i];
        }
        temp[numDestinos] = destino;
        delete[] destinosPlanificados;
        destinosPlanificados = temp;
        numDestinos++;
        destinosPendientes.push(destino);
    }

    // Obtener el número de destinos planificados
    int getNumDestinos() const {
        return numDestinos;
    }

    // Obtener el arreglo de destinos planificados
    Destino** getDestinosPlanificados() const {
        return destinosPlanificados;
    }

    // Obtener el próximo destino pendiente por visitar y eliminarlo de la pila
    Destino* getNextDestinoPendiente() {
        if (!destinosPendientes.empty()) {
            Destino* proximoDestino = destinosPendientes.top();
            destinosPendientes.pop();
            destinosVisitados.push(proximoDestino);
            return proximoDestino;
        } else {
            return nullptr;
        }
    }

    // Obtener el último destino visitado y eliminarlo de la cola
    Destino* getLastDestinoVisitado() {
        if (!destinosVisitados.empty()) {
            Destino* ultimoDestino = destinosVisitados.front();
            destinosVisitados.pop();
            return ultimoDestino;
        } else {
            return nullptr;
        }
    }
};

// Definición de la clase GestionVacaciones
class GestionVacaciones {
private:
    Destino** destinosGenerales;
    int numDestinos;
    MiembroFamilia** miembrosFamilia;
    int numMiembros;

public:
    // Constructor de la clase
    GestionVacaciones() : destinosGenerales(nullptr), numDestinos(0), miembrosFamilia(nullptr), numMiembros(0) {}

    // Destructor de la clase
    ~GestionVacaciones() {
        // Liberar memoria de destinos generales
        for (int i = 0; i < numDestinos; ++i) {
            delete destinosGenerales[i];
        }
        delete[] destinosGenerales;

        // Liberar memoria de miembros de familia
        for (int i = 0; i < numMiembros; ++i) {
            delete miembrosFamilia[i];
        }
        delete[] miembrosFamilia;
    }

    // Agregar un nuevo destino a la lista general de destinos
    void agregarDestino(const string& nombre, const string& fecha, const string& itinerario) {
        Destino* nuevoDestino = new Destino(nombre, fecha, itinerario);
        Destino** temp = new Destino*[numDestinos + 1];
        for (int i = 0; i < numDestinos; ++i) {
            temp[i] = destinosGenerales[i];
        }
        temp[numDestinos] = nuevoDestino;
        delete[] destinosGenerales;
        destinosGenerales = temp;
        numDestinos++;
    }

    // Planificar un viaje para un miembro de la familia hacia un destino específico
    void planificarViaje(MiembroFamilia* miembro, const string& destinoNombre, const string& fecha) {
        for (int i = 0; i < numDestinos; ++i) {
            if (destinosGenerales[i]->getNombre() == destinoNombre) {
                miembro->agregarDestino(destinosGenerales[i]);
                return;
            }
        }
        cout << "El destino especificado no existe." << endl;
    }

    // Consultar los destinos planificados para un miembro de la familia
    void consultarDestinosPlanificados(MiembroFamilia* miembro) const {
        cout << "Destinos planificados para " << miembro->getNombre() << ":" << endl;
        for (int i = 0; i < miembro->getNumDestinos(); ++i) {
            Destino* destino = miembro->getDestinosPlanificados()[i];
            cout << destino->getNombre() << " - Fecha: " << destino->getFecha() << endl;
            cout << "Itinerario: " << destino->getItinerario() << endl;
        }
    }
};

