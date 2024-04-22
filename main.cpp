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
        for (const auto &dest : destinos)
        {
            if (destino.getNombre() == dest.getNombre())
            {
                cout << "el destino ya esta en la lista" << endl;
                return;
            }
        }
        destinos.insert(destino);

        cout << "Destino agregado" << endl;
        cout << "" << endl;
    }
};

class Actividades
{
private:
    string actividad;
    // string fecha;
    string hora;
    string lugar;
    string descripcion;

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
};

class Viaje
{
private:
    string destino;
    string fecha_salida;
    string fecha_devuelta;
    vector<Actividades> actividades;

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

    vector<Actividades> getActividades()
    {
        return actividades;
    }

    void agregaractividad(const Actividades &actividad)
    {
        actividades.push_back(actividad);
    }

    void Crear_actividad(string miembro_familiar, map<string, Viaje> &asignaciones_familia)
    {
        string nombre_actividad;
        string hora_actividad;
        string lugar_actividad;
        string describ_actividad;

        cout << "Ingrese el nombre de la actividad: " << endl;
        cin >> nombre_actividad;

        cout << "Ingrese la hora de la actividad: " << endl;
        cin >> hora_actividad;

        cout << "Ingrese el lugar de la actividad: " << endl;
        cin >> lugar_actividad;

        cout << "Ingrese la descripcion de la actividad: " << endl;
        cin >> describ_actividad;

        auto iterador = asignaciones_familia.find(miembro_familiar);
        if (iterador == asignaciones_familia.end())
        {
            cout << "no hay viajes asignados para este familiar: " << endl;
            return;
        }

        iterador->second.agregaractividad(Actividades(nombre_actividad, hora_actividad, lugar_actividad, describ_actividad));
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

    void Asignar_viaje(string miembro_familia, map<string, Viaje> &asignaciones_familia, Viaje viaje)
    {

        if (asignaciones_familia.find(miembro_familia) != asignaciones_familia.end())
        {
            cout << " el familiar ya tiene un viaje asignado" << endl;
            return;
        }

        for (const auto &par : asignaciones_familia)
        {
            if (par.first == miembro_familia)
            {
                if (viaje.getFecha_Salida() == par.second.getFecha_Salida() || viaje.getFecha_Devuelta() == par.second.getFecha_Devuelta())
                {
                    cout << "CONFLICO DE FECHAS!!! El usuario ya tiene un viaje para la misma fecha" << endl;
                }
            }
        }

        asignaciones_familia.insert(pair<string, Viaje>(miembro_familia, viaje));
        cout << "Viaje asignado" << endl;
    }
};

// void Actividad(string miembro_familiar, map<string, Viaje> &asignaciones_familia)
// {
//     string nombre_actividad;
//     string hora_actividad;
//     string lugar_actividad;
//     // string descrip_actividad;

//     cout << "Ingrese el nombtre de la actividad: " << endl;
//     cout << nombre_actividad;
//     cout << "Ingrese la hora de la actividad: " << endl;
//     cout << hora_actividad;
//     cout << "Ingrese el lugar de la actividad: " << endl;
//     cout << lugar_actividad;

//     auto iterador = asignaciones_familia.find(miembro_familiar);
//     if (iterador != asignaciones_familia.end())
//     {
//         cout << "Ano hay viajes asignados para este familiar: " << endl;
//         return;
//     }

//     iterador.second.agregaractividad(Actividades(nombre_actividad, hora_actividad, lugar_actividad));
//     cout << "Actividad agregada con éxito al viaje del familiar " << miembro_familiar;
// }

void Consultar_Destino(string miembro, map<string, Viaje> &asignaciones_familia)
{
    auto iterador = asignaciones_familia.find(miembro);

    if (iterador != asignaciones_familia.end())
    {
        cout << "Destino planificado para el miembro:  " << miembro << ", " << iterador->second.getDestino() << endl;
    }
    else
    {
        cout << "No se encontró ningun destino para el miemro " << miembro << endl;
    }
}

void destino_especifico(string &destino_bucar, map<string, Viaje> &asignaciones_familia)
{
    cout << "Ingrese el destino que desea buscar: " << endl;
    cin >> destino_bucar;

    bool encontrado = false;

    for (const auto &par : asignaciones_familia)
    {
        if (par.second.getDestino() == destino_bucar)
        {
            cout << "los miembros " << par.first << " tienen planificado visitar" << par.second.getDestino() << endl;
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
    // Planeacion_viaje actividad;
    string destino_bucar;
    set<Destino> destinos;
    map<string, Viaje> asignaciones_familia;
    Viaje viaje;
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
        cout << "danos la oportunidad de descubrir el mundo a tu lado y generar experiencias." << endl;
        cout << " " << endl;
        cout << "Es hora de viajar :D, adelante y buen viaje." << endl;
        cout << " " << endl;

        while (shutdown == 0)
        {

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
                for (const auto &destino : destinos)
                {
                    cout << " - " << destino.getNombre() << endl;
                }
                break;
            case 3:
                cout << "Ingrese su familiar: " << endl;
                cin >> miembro_familia;

                cout << "Ingrese su destino: " << endl;
                cin >> destino_llegada;

                cout << "Ingrese la fecha del vuelo de ida al pais(dd/mm): " << endl;
                cin >> fecha_llegada;

                cout << "Ingrese la fecha del vuelo de salida del pais(dd/mm): " << endl;
                cin >> fecha_salida;

                viaje.setDestino(destino_llegada);
                viaje.setFecha_Salida(fecha_llegada);
                viaje.setFecha_Devuelta(fecha_salida);

                planeacion_viaje.Asignar_viaje(miembro_familia, asignaciones_familia, viaje);

                break;

            case 4:
                cout << "Ingrese el familiar al cual quiere saver los destinos: " << endl;
                cin >> miembro_familia;

                Consultar_Destino(miembro_familia, asignaciones_familia);

                break;
            case 5:

                destino_especifico(destino_bucar, asignaciones_familia);
                break;
            case 6:
                cout << "Ingresar el familiar: " << endl;
                cin >> miembro_familia;
                actividad.Crear_actividad(miembro_familia, asignaciones_familia);
                break;

            case 7:
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
