#include<iostream>
using namespace std;
#include "./Reto.cpp"

// Función para mostrar el menú de opciones
void mostrarMenu() {
    cout << "¡Bienvenido al sistema de gestion de vacaciones de la familia!" << endl;
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
                cin>>nombre;
                cout << "Ingrese la fecha del destino: ";
                cin>>fecha;
                cout << "Ingrese el itinerario del destino: ";
                getline(cin, destinoNombre);
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
                cin.ignore();
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
                cout << "Opcion invalida. Por favor, ingrese un numero valido." << endl;
                break;
        }
    }
    return 0;
}
