#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
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

    void Agregar_Destino(Destino &destino, stack<Destino> &destinos)
    {

        destinos.push(destino);

        cout << "Destino agregado" << endl;
        cout << "" << endl;
    }
};

class Actividades
{
private:
    string actividad;
    string hora;
    string lugar;
    string descripcion;
    vector<Actividades> actividades;

public:
    Actividades() {}
    Actividades(string nombre_actividad, string hora_actividad, string lugar_actividad, string descripcion_actividad)
    {
        this->actividad = actividad;
        this->hora = hora;
        this->lugar = lugar;
        this->descripcion = descripcion;
    }
    string getActividad()
    {
        return actividad;
    }
    string getHora()
    {
        return hora;
    }
    string getLugar()
    {
        return lugar;
    }
    string getDescripcion()
    {
        return descripcion;
    }
    void setActividad(string actividad)
    {
        this->actividad = actividad;
    }
    void setHora(string hora)
    {
        this->hora = hora;
    }
    void setLugar(string lugar)
    {
        this->lugar = lugar;
    }
    void setDescripcion(string descripcion)
    {
        this->descripcion = descripcion;
    }

    vector<Actividades> getActividades()
    {
        return actividades;
    }

    void agregaractividad(const Actividades &actividad)
    {
        actividades.push_back(actividad);
    }

    void Crear_actividad(string miembro_familia, Actividades actividades, map<string, queue<Actividades>> &asignaciones_actividad)
    {
        asignaciones_actividad[miembro_familia].push(actividades);
        cout << "Actividad asignado" << endl;
    }

    void mostrar_actividades(string miembro_familia, map<string, queue<Actividades>> &asignaciones_actividad)
    {
        auto iterador = asignaciones_actividad.find(miembro_familia);

        if (iterador != asignaciones_actividad.end())
        {
            queue<Actividades> cola = iterador->second;
            Actividades actividades = cola.front();
            string actividad = actividades.getActividad();
            cout << "las/ la actividad que planifico el miembro:  " << miembro_familia << " son: " << actividad << endl;
        }
        else
        {
            cout << "No se encontró ninguna actividad para el miemro " << miembro_familia << endl;
        }
    }
};

class Viaje
{
private:
    string destino;
    string fecha_salida;
    string fecha_devuelta;

public:
    Viaje() {}
    Viaje(string &destino, string &fecha_salida, string &fecha_devuelta)
    {
        this->destino = destino;
        this->fecha_salida = fecha_salida;
        this->fecha_devuelta = fecha_devuelta;
    }
    string getDestino() const
    {
        return destino;
    }
    string getFecha_Salida() const
    {
        return fecha_salida;
    }
    string getFecha_Devuelta() const
    {
        return fecha_devuelta;
    }
    void setDestino(string &destino)
    {
        this->destino = destino;
    }
    void setFecha_Salida(string &fecha_salida)
    {
        this->fecha_salida = fecha_salida;
    }
    void setFecha_Devuelta(string &fecha_devuelta)
    {
        this->fecha_devuelta = fecha_devuelta;
    }
};

class Planeacion_viaje
{
private:
    string miembro_familia;
    map<string, Viaje> asignaciones_familia;

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

    void Asignar_viaje(string miembro_familia, map<string, queue<Viaje>> &asignaciones_familia, Viaje viaje)
    {

        if (asignaciones_familia.find(miembro_familia) != asignaciones_familia.end())
        {
            cout << " el familiar ya tiene un viaje asignado" << endl;
            return;
        }

        for (const auto &par : asignaciones_familia)
        {
            queue<Viaje> cola = par.second;
            Viaje viaje_existente = cola.front();

            if (par.first == miembro_familia)
            {
                if (viaje.getFecha_Salida() == viaje_existente.getFecha_Salida() || viaje.getFecha_Devuelta() == viaje_existente.getFecha_Devuelta())
                {
                    cout << "CONFLICO DE FECHAS!!! El usuario ya tiene un viaje para la misma fecha" << endl;
                }
            }
            // par.firs+ primer valor del dato (familiar) par.second = queue
        }

        asignaciones_familia[miembro_familia].push(viaje);
        cout << "Viaje asignado" << endl;
    }
};

void Consultar_Destino(string miembro, map<string, queue<Viaje>> &asignaciones_familia)
{
    auto iterador = asignaciones_familia.find(miembro);

    if (iterador != asignaciones_familia.end())
    {
        queue<Viaje> cola = iterador->second;
        Viaje viaje = cola.front();
        string destino = viaje.getDestino();
        cout << "Destino planificado para el miembro:  " << miembro << ", " << destino << endl;
    }
    else
    {
        cout << "No se encontró ningun destino para el miemro " << miembro << endl;
    }
}

void destino_especifico(string &destino_bucar, map<string, queue<Viaje>> &asignaciones_familia)
{
    bool encontrado;

    cout << "Ingrese el destino que desea buscar: " << endl;
    cin >> destino_bucar;

    encontrado = false;

    for (const auto &par : asignaciones_familia)
    {
        queue<Viaje> cola = par.second;
        Viaje viaje = cola.front();
        string destino = viaje.getDestino();

        if (destino == destino_bucar)
        {

            cout << "los miembros " << par.first << " tienen planificado visitar " << destino << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "ningun miembro de la familia quiere ir a este sitio" << endl;
    }
}

class Interfaz
{
private:
    Destino destino;
    Planeacion_viaje planeacion_viaje;
    Viaje actividad;
    string nombre;
    string miembro_familia;
    string destino_llegada;
    string fecha_llegada;
    string fecha_salida;
    string destino_bucar;
    string nombre_actividad;
    string hora_actividad;
    string lugar_actividad;
    string describ_actividad;
    stack<Destino> destinos;
    map<string, queue<Viaje>> asignaciones_familia;
    Viaje viaje;
    Actividades actividades;
    map<string, queue<Actividades>> asignaciones_actividad;

    int opcion;
    int shutdown = 0;

public:
    Interfaz() {}
    void Menu()
    {
        cout << " " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "-°-°-°-°-  WanderWise  -°-°-°-°-" << endl;
        cout << "-°- Descubre, Conecta, Crece -°-" << endl;
        cout << " " << endl;
        cout << "Bienvenido a WanderWise, donde tu aventura es nuestra pacion," << endl;
        cout << "Danos la oportunidad de descubrir el mundo a tu lado y generar experiencias." << endl;
        cout << " " << endl;
        cout << "Es hora de viajar :D, adelante y buen viaje." << endl;
        cout << " " << endl;

        while (shutdown == 0)
        {
            cout << " " << endl;
            cout << "Seleccione una opcion" << endl;
            cout << " " << endl;
            cout << "1. Agregar destino" << endl;
            cout << "2. Lista general de los viajes" << endl;
            cout << "3. Asignar viaje" << endl;
            cout << "4. Consultar destino de un miembro" << endl;
            cout << "5. Consultar destinos especificos" << endl;
            cout << "6. Asignar actividades. " << endl;
            cout << "7. Mostrar actividades. " << endl;
            cout << "8. Salir" << endl;
            cout << " " << endl;

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
                cout << "lista general de viajes: " << endl;
                // for (const auto &destino : destinos)
                // {
                //     cout << " - " << destino.getNombre() << endl;
                // }
                // break;
            case 3:
                cout << "Ingrese su familiar: " << endl;
                cin >> miembro_familia;

                cout << "Ingrese su destino: " << endl;
                cin >> destino_llegada;

                cout << "Ingrese la fecha del vuelo de salida al pais(dd/mm): " << endl;
                cin >> fecha_llegada;

                cout << "Ingrese la fecha del vuelo de llegada del pais(dd/mm): " << endl;
                cin >> fecha_salida;

                viaje.setDestino(destino_llegada);
                viaje.setFecha_Salida(fecha_llegada);
                viaje.setFecha_Devuelta(fecha_salida);

                planeacion_viaje.Asignar_viaje(miembro_familia, asignaciones_familia, viaje);

                break;

            case 4:
                cout << "Ingrese el familiar al cual quiere saber los destinos: " << endl;
                cin >> miembro_familia;

                Consultar_Destino(miembro_familia, asignaciones_familia);

                break;
            case 5:

                destino_especifico(destino_bucar, asignaciones_familia);
                break;
            case 6:
                cin.ignore();
                cout << "Ingrese el nombre del familiar: " << endl;
                getline(cin, miembro_familia);

                cout << "Ingrese el nombre de la actividad: " << endl;
                getline(cin, nombre_actividad);

                cout << "Ingrese la hora de la actividad: " << endl;
                getline(cin, hora_actividad);

                cout << "Ingrese el lugar de la actividad: " << endl;
                getline(cin, lugar_actividad);

                cout << "Ingrese la descripcion de la actividad: " << endl;
                getline(cin, describ_actividad);

                actividades.setActividad(nombre_actividad);
                actividades.setHora(hora_actividad);
                actividades.setLugar(lugar_actividad);
                actividades.setDescripcion(describ_actividad);

                actividades.Crear_actividad(miembro_familia, actividades, asignaciones_actividad);
                break;

            case 7:
                cout << "¿De quien quiere saber las actividades?" << endl;
                cin >> miembro_familia;

                actividades.mostrar_actividades(miembro_familia, asignaciones_actividad);

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