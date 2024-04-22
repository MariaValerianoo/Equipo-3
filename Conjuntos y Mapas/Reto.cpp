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

// Función para mostrar el menú de opciones
void mostrarMenu() {
    cout << "¡Bienvenido al sistema de gestión de vacaciones de la familia!" << endl;
    cout << "1. Agregar destino a la lista general" << endl;
    cout << "2. Planificar viaje para un miembro de la familia" << endl;
    cout << "3. Consultar destinos planificados para un miembro de la familia" << endl;
    cout << "4. Encontrar miembros que planean visitar un destino específico" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese el número de la opción que desea ejecutar: ";
}

// Función principal
int main() {
    // Crear una instancia de la clase GestionVacaciones
    GestionVacaciones gestion;

    int opcion;
    string nombre, fecha, destinoNombre;
    while (true) {
        // Mostrar el menú y leer la opción del usuario
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Agregar destino a la lista general
                cout << "Ingrese el nombre del destino: ";
                cin >> nombre;
                cout << "Ingrese la fecha del destino: ";
                cin >> fecha;
                cout << "Ingrese el itinerario del destino: ";
                cin >> destinoNombre;
                gestion.agregarDestino(nombre, fecha, destinoNombre);
                break;
            case 2:
                // Planificar viaje para un miembro de la familia
                cout << "Ingrese el nombre del miembro de la familia: ";
                cin >> nombre;
                cout << "Ingrese el nombre del destino: ";
                cin >> destinoNombre;
                cout << "Ingrese la fecha del viaje: ";
                cin >> fecha;
                gestion.planificarViaje(new MiembroFamilia(nombre), destinoNombre, fecha);
                break;
            case 3:
                // Consultar destinos planificados para un miembro de la familia
                cout << "Ingrese el nombre del miembro de la familia: ";
                cin >> nombre;
                gestion.consultarDestinosPlanificados(new MiembroFamilia(nombre));
                break;
            case 4:
                // Encontrar miembros que planean visitar un destino específico
                cout << "Ingrese el nombre del destino: ";
                cin >> destinoNombre;
                gestion.encontrarMiembrosPorDestino(destinoNombre);
                break;
            case 5:
                // Salir del programa
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                // Opción inválida
                cout << "Opción inválida. Por favor, ingrese un número válido." << endl;
                break;
        }
    }
    return 0;
}
