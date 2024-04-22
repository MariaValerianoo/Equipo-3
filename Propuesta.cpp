#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Viaje {
    string destino;
    string fecha;
};

bool compararViajes(const Viaje& v1, const Viaje& v2) {
    return v1.fecha < v2.fecha;
}

class Familia {
private:
    map<string, set<Viaje>> miembros;
    set<Viaje, decltype(compararViajes)> destinos;

public:
    void agregarDestino(string destino, string fecha) {
        Viaje nuevoDestino{destino, fecha};
        if (destinos.find(nuevoDestino) == destinos.end()) {
            destinos.insert(nuevoDestino);
            cout << "Destino agregado exitosamente." << endl;
        } else {
            cout << "El destino ya existe en la lista." << endl;
        }
    }

    void planificarViaje(string miembro, string destino, string fecha) {
        auto it = destinos.find({destino, fecha});
        if (it != destinos.end()) {
            cout << "La fecha para este destino ya está ocupada." << endl;
            return;
        }

        Viaje nuevoViaje{destino, fecha};
        miembros[miembro].insert(nuevoViaje);
        destinos.insert(nuevoViaje);
        cout << "Viaje planificado para " << miembro << " al destino " << destino << " en la fecha " << fecha << endl;
    }

    void consultarDestinosPlanificados(string miembro) {
        if (miembros.find(miembro) != miembros.end()) {
            cout << "Destinos planificados para " << miembro << ":" << endl;
            for (const auto& viaje : miembros[miembro]) {
                cout << viaje.destino << " - Fecha: " << viaje.fecha << endl;
            }
        } else {
            cout << "No se encontraron destinos planificados para " << miembro << endl;
        }
    }

    void encontrarMiembrosPorDestino(string destino) {
        cout << "Miembros que tienen planificado visitar " << destino << ":" << endl;
        for (const auto& miembro : miembros) {
            if (miembro.second.find({destino, ""}) != miembro.second.end()) {
                cout << miembro.first << endl;
                break;
            }
        }
    }

    string obtenerUsuario() {
        string miembro;
        cout << "Ingrese su nombre de usuario: ";
        cin >> miembro;
        return miembro;
    }

    string obtenerMiembro() {
        string miembro;
        cout << "Ingrese el nombre de miembro de la familia: ";
        cin >> miembro;
        return miembro;
    }
};

int main() {
    Familia familia;

    int opcion;
    string miembro;

    while (true) {
        cout << "\n--- Menú principal ---" << endl;
        cout << "1. Seleccionar miembro" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                miembro = familia.obtenerMiembro();
                while (true) {
                    cout << "\n--- Menú de " << miembro << " ---" << endl;
                    cout << "1. Planear vacaciones" << endl;
                    cout << "2. Ver itinerario" << endl;
                    cout << "3. Volver al menú principal" << endl;
                    cout << "Ingrese una opción: ";
                    cin >> opcion;

                    string destino, fecha;

                    switch (opcion) {
                        case 1:
                            cout << "Ingrese el destino: ";
                            cin >> destino;
                            cout << "Ingrese la fecha (YYYY-MM-DD): ";
                            cin >> fecha;
                            familia.planificarViaje(miembro, destino, fecha);
                            break;
                        case 2:
                            familia.consultarDestinosPlanificados(miembro);
                            break;
                        case 3:
                            goto menu_principal;
                        default:
                            cout << "Opción inválida." << endl;
                    }
                }
                break;
            case 2:
                return 0;
            default:
                cout << "Opción inválida." << endl;
        }
    }

menu_principal:;
}
