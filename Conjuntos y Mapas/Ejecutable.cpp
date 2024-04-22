#include<iostream>
using namespace std;
#include "./Reto.cpp"

void mostrarMenu() {
    cout << "¡Bienvenido al sistema de gestión de vacaciones de la familia!" << endl;
    cout << "1. Agregar destino a la lista general" << endl;
    cout << "2. Planificar viaje para un miembro de la familia" << endl;
    cout << "3. Consultar destinos planificados para un miembro de la familia" << endl;
    cout << "4. Encontrar miembros que planean visitar un destino específico" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese el numero de la opcion que desea ejecutar: ";
}


int main() {
    GestionVacaciones gestion;

    int opcion;
    string nombre, fecha, destinoNombre;
    while (true) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del destino: ";
                cin >> nombre;
                cout << "Ingrese la fecha del destino: ";
                cin >> fecha;
                cout << "Ingrese el itinerario del destino: ";
                cin >> destinoNombre;
                gestion.agregarDestino(nombre, fecha, destinoNombre);
                break;
            case 2:
                cout << "Ingrese el nombre del miembro de la familia: ";
                cin >> nombre;
                cout << "Ingrese el nombre del destino: ";
                cin >> destinoNombre;
                cout << "Ingrese la fecha del viaje: ";
                cin >> fecha;
                gestion.planificarViaje(new MiembroFamilia(nombre), destinoNombre, fecha);
                break;
            case 3:
                cout << "Ingrese el nombre del miembro de la familia: ";
                cin >> nombre;
                gestion.consultarDestinosPlanificados(new MiembroFamilia(nombre));
                break;
            case 4:
                cout << "Ingrese el nombre del destino: ";
                cin >> destinoNombre;
                gestion.encontrarMiembrosPorDestino(destinoNombre);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opción inválida. Por favor, ingrese un número válido." << endl;
                break;
        }
    }
    return 0;
}
