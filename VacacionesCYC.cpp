#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Destino // clase destino
{
private:
    string nombre; // nombre del destino
public:
    // constructores
    Destino(string &n)
    {
        nombre = n;
    }

    Destino() {}

    // sets, gets
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

    // metodos
    void Agregar_Destino(Destino &destino, set<Destino> &destinos) // Agregar destinos a la lista general de la familia y como es un conjunto, se
    // Asegura que los destinos no se repitan.
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

// clase actividades
class Actividades
{
private:
    string actividad;
    string hora;
    string lugar;
    string descripcion;
    vector<Actividades> actividades;

public:
    // constructores
    Actividades() {}
    Actividades(string nombre_actividad, string hora_actividad, string lugar_actividad, string descripcion_actividad)
    {
        this->actividad = actividad;
        this->hora = hora;
        this->lugar = lugar;
        this->descripcion = descripcion;
    }

    // sets, gets
    string getActividad() const
    {
        return actividad;
    }
    string getHora() const
    {
        return hora;
    }
    string getLugar() const
    {
        return lugar;
    }
    string getDescripcion() const
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

    vector<Actividades> getActividades() // es vector porque von este se va a realizar ls lista
    {
        return actividades;
    }

    // metodos
    void agregaractividad(const Actividades &actividad) // agrega las actividades
    {
        actividades.push_back(actividad);
    }

    // crear actividad: hace que el familiar cree una actividad
    /*toma tres parametros
    miembro_familiar: el familiar del cual se quiere saber la actividades
    actividades: es un objeto de la clase actividades
    asignaciones_actividad: es un mapa que relaciona las actividades con cada miembro de la familia
    */

    void Crear_actividad(string miembro_familia, Actividades actividades, map<string, Actividades> &asignaciones_actividad)
    {
        auto iterador = asignaciones_actividad.find(miembro_familia);
        if (iterador != asignaciones_actividad.end())
        {
            iterador->second.actividades.push_back(actividades);
            cout
                << "La actividad ya esta en la lista" << endl;
            return;
        }
        else
        {
            asignaciones_actividad.insert(make_pair(miembro_familia, actividades));
            cout << "Actividad agregado" << endl;
            cout << "" << endl;
        }
    }

    /*MUESTRA LA ACTIVIDAD
    toma dos parametros
    miembro_familiar: el familiar del cual se quiere saber la actividades
    asignaciones actividad: es un mapa que relaciona las actividades con cada miembro de la familia*/

    void mostrar_actividades(string miembro_familiar, map<string, Actividades> &asignaciones_actividad)
    {
        auto iterador = asignaciones_actividad.find(miembro_familiar); // se crea el iterador que apunta al familiar que contiene esa actividad
        if (iterador != asignaciones_actividad.end())                  // si el iterrador es diferente a asignaciones_actividad.end() significa que encpntro al informacion
        {
            cout << "Las actividades de " << miembro_familiar << " son: " << endl;
            for (const auto &actividades : iterador->second.getActividades())
            {

                cout << "Actividad: " << actividades.getActividad() << endl;
                cout << "Hora: " << actividades.getHora() << endl;
                cout << "Lugar: " << actividades.getLugar() << endl;
                cout << "Descripcion: " << actividades.getDescripcion() << endl;
                return;
            }
        }

        cout << "no hay viajes asignados para este familia " << endl;
        return;
    }
};

// clase viaje
class Viaje
{
private:
    string destino;
    string fecha_salida;
    string fecha_devuelta;

public:
    // constructores
    Viaje() {}
    Viaje(string &destino, string &fecha_salida, string &fecha_devuelta)
    {
        this->destino = destino;
        this->fecha_salida = fecha_salida;
        this->fecha_devuelta = fecha_devuelta;
    }
    // sets, gets
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

// clase planeacion_viaje
class Planeacion_viaje
{
private:
    string miembro_familia;
    map<string, Viaje> asignaciones_familia;

public:
    // constructores
    Planeacion_viaje() {}

    Planeacion_viaje(string miembro_familia)
    {
        this->miembro_familia = miembro_familia;
    }

    // sets, gets
    string getMiembro_Familia(string miembro_familia)
    {
        return miembro_familia;
    }

    void setMiembro_Fmilia(string miembro_familia)
    {
        this->miembro_familia = miembro_familia;
    }

    // metodos
    // asignar viajes:  se encarga de asignar un viaje a un miembro de la familia
    // 1. se verifica que el miembro de la familia no tenga un viaje asignado
    // 2. se verifica que el viaje no coincida con el de otro miembro de la familia
    // 3. se asigna el viaje al miembro de la familia
    // 4. se imprime el mensaje de que el viaje fue asignado
    // 5. se imprime el mensaje de que el miembro de la familia ya tiene un viaje asignado
    // 6. se imprime el mensaje de que el viaje coincide con el de otro miembro de la familia

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

// consultar destinos: se encarga de consultar los destinos de los viajes de un miembro de la familia
// 1. se verifica que el miembro de la familia tenga un viaje asignado
// 2. se imprime el mensaje de que el miembro de la familia no tiene un viaje asignado
// 3. se imprime el destino del viaje del miembro de la familia

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

// destino especifico: se encarga de Consultar todos los destinos planificados para unmiembro específico
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

// clase de interfaz: Menu
class Interfaz
{
private:
    Destino destino;
    Planeacion_viaje planeacion_viaje;
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
    // Planeacion_viaje actividad;
    set<Destino> destinos;
    map<string, Viaje> asignaciones_familia;
    Actividades actividades;
    map<string, Actividades> asignaciones_actividad;
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
            case 8:
                shutdown = 1;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            }
        }
    }
};

