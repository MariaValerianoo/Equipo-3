#include<iostream>
using namespace std;
#include "./Reto.cpp"




// Función principal
int main() {
    // Crear objeto para gestionar las vacaciones
    GestionVacaciones gestion;

    int opcion;
    string nombre;
    string fecha;
    string destinoNom;
    while (true) {
        // Menú de opciones
        cout << "¡Bienvenido al sistema de gestión de vacaciones de la familia!" << endl;
        cout << "1. Agregar destino a la lista general" << endl;
        cout << "2. Planificar viaje para un miembro de la familia" << endl;
        cout << "3. Consultar destinos planificados para un miembro de la familia" << endl;
        cout << "4. Encontrar miembros que planean visitar un destino específico" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese el número de la opción que desea ejecutar: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Opción para agregar un destino a la lista general
                cout << "Ingrese el nombre del destino: ";
                cin >> nombre;
                cout << "Ingrese la fecha del destino: ";
                cin >> fecha;
                gestion.agregarDest(nombre, fecha, ""); 
                break;
            case 2:
                // Opción para planificar un viaje para un miembro de la familia
                cout << "Ingrese el nombre del miembro de la familia: ";
                cin >> nombre;
                cout << "Ingrese el nombre del destino: ";
                cin >> destinoNom;
                cout << "Ingrese la fecha del viaje: ";
                cin >> fecha;
                cin.ignore();
                gestion.planificarViaje(new MiembroFami(nombre), destinoNom, fecha);
                break;
            case 3:
                // Opción para consultar destinos planificados para un miembro de la familia
                cout << "Ingrese el nombre del miembro de la familia: ";
                cin >> nombre;
                gestion.consultarDestinosPlanificados(new MiembroFami(nombre));
                break;
            case 4:
                // Opción para encontrar miembros que planean visitar un destino específico
                cout << "Ingrese el nombre del destino: ";
                cin >> destinoNom;
                gestion.encontrarMiembrosPorDestino(destinoNom);
                break;
            case 5:
                // Opción para salir del programa
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
