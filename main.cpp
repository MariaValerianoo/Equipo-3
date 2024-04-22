#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Destino
{
private:
    string nombre; // nombre del destino
public:
    Destino(string &n)
    {
        nombre = n;
    }

    Destino() {}

    void setNombre(const string &nombre)
    {
        this->nombre = nombre;
    }

    string getNombre() const
    {
        return nombre;
    }

    bool operator<(const Destino &other) const
    {
        return nombre < other.nombre;
    }

    void Agregar_Destino(Destino &destino, set<Destino> &destinos)
    {
        destinos.insert(destino);

        cout << "Destino agregado" << endl;
        cout << "" << endl;
    }
};

class Viaje
{
private:
    string destino;
    string fecha;

public:
    Viaje() {}
    Viaje(string destino, string fecha)
    {
        this->destino = destino;
        this->fecha = fecha;
    }
    string getDestino()
    {
        return destino;
    }
    string getFecha()
    {
        return fecha;
    }
    void setDestino(string destino)
    {
        this->destino = destino;
    }
    void setFecha(string fecha)
    {
        this->fecha = fecha;
    }
};

class Planeacion_viaje
{
private:
    string miembro_familia;

public:
    Planeacion_viaje() {}

    Planeacion_viaje(string miembro_familia)
    {
        this->miembro_familia = miembro_familia;
    }

    string getMiembro_Familia(string miembro_familia)
    {
        return miembro_familia;
    }

    void setMiembro_Fmilia(string miembro_familia)
    {
        this->miembro_familia = miembro_familia;
    }

    void Asignar_viaje(string miembro_familia, map<string, Viaje> &Asignaciones_familia, Viaje viaje)
    {

        if (Asignaciones_familia.find(miembro_familia) != Asignaciones_familia.end())
        {
            cout << " el familiar ya tiene un viaje asignado" << endl;
            return;
        }

        for (const auto &par : Asignaciones_familia)
        {
            if (par.first == miembro_familia)
            {
                if (viaje.getFecha() == par.second.getFecha())
                {
                    cout << "CONFLICO DE FECHAS!!! El usuario ya tiene un viaje para la misma fecha" << endl;
                }
            }
        }

        Asignaciones_familia.insert(pair<string, Viaje>(miembro_familia, viaje));
        cout << "Viaje asignado" << endl;
    }
};

void Consultar_Destino(string miembro, map<string, Viaje> &Asignaciones_familia, )
{
    cout << "Ingrese el familiar al cual quiere saver los destinos: " << miembro << endl;
    auto iterador = Asignaciones_familia.find(miembro);

    if (iterador != Asignaciones_familia.end())
    {
        cout << "Destino planificado para el miembro:  " << miembro << " " << iterador->second.getDestino() << endl;
    }
    else
    {
        cout << "No se encontró ningun destino para el miemro " << miembro << endl;
    }
}

void destino_especifico(string &destino_bucar, map<string, Viaje> &Asignaciones_familia)
{
    cout << "Ingrese el destino que desea buscar: " << endl;
    cin >> destino_bucar;

    bool encontrado = false;

    if (!encontrado)
    {
        cout << "ningun miembro de la familia quiere ir a este sitio" << endl;
    }

    for (const auto &par : Asignaciones_familia)
    {
        if (par.second.getDestino() == destino_bucar)
        {
            cout << "los miembros " << Asignaciones_familia << " tienen planificado visitar" << par.second.getDestino() << endl;
            encontrado = true;
        }
    }
}

class Interfaz
{
private:
    Destino destino;
    Planeacion_viaje planeacion_viaje;
    string nombre;
    string miembro_familia;
    string destino_llegada;
    string fecha_viaje;
    set<Destino> destinos;
    map<string, Viaje> Asignaciones_familia;
    Viaje viaje;
    int opcion;
    int shutdown = 0;

public:
    Interfaz() {}
    void Menu()
    {
        cout << " " << endl;
        cout << "Bienvenido al sistema de planeacion de viajes, espero que su viaje sea exitoso" << endl;
        cout << " " << endl;

        while (shutdown == 0)
        {

            cout << "Seleccione una opcion" << endl;
            cout << " " << endl;
            cout << "1. Agregar destino" << endl;
            cout << "2. Asignar viaje" << endl;
            cout << "3. Consultar destino" << endl;
            cout << "4. Consultar destinos repetidos entre familias" << endl;
            cout << "4. Salir" << endl;

            cin >> opcion;
            cout << " " << endl;

            switch (opcion)
            {
            case 1:
                cout << "Ingrese su destino: " << endl;
                cin >> nombre;

                destino.setNombre(nombre);

                destino.Agregar_Destino(destino, destinos);
                break;
            case 2:
                cout << "Ingrese su familiar: " << endl;
                cin >> miembro_familia;

                cout << "Ingrese su destino: " << endl;
                cin >> destino_llegada;

                cout << "Ingrese la fecha: " << endl;
                cin >> fecha_viaje;

                viaje.setDestino(destino_llegada);
                viaje.setFecha(fecha_viaje);

                planeacion_viaje.Asignar_viaje(miembro_familia, Asignaciones_familia, viaje);

                break;

            case 3:
                Consultar_Destino(Asignaciones_familia, miembro_familia);

                break;

            case 4:
                cout << "Gracias por usar el sistema" << endl;
                break;

            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
};

int main()
{

    Interfaz interfaz1;
    interfaz1.Menu();

    return 0;
}