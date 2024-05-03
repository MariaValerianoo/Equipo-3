#pragma once
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "./Utils.cpp"
#include "./Destino.cpp"
using namespace std;

class Utils;
class Destino;

class Persona
{
private:
    string nombre;
    // fecha - destino
    map<string, Destino *> destinos;

public:
    Persona();
    Persona(string nombre);

    string getNombre() const;
    void setNombre(const string &nuevoNombre);
    map<string, Destino *> getDestinos() const;

    void setDestinos(const map<string, Destino *> &nuevosDestinos);
    void addDestino();
    void showPersona();
    pair<string, Destino *> selectDestino();
};

Persona::Persona()
{
}

Persona::Persona(string nombre)
{
    this->nombre = nombre;
}

string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const string &nuevoNombre)
{
    nombre = nuevoNombre;
}

map<string, Destino *> Persona::getDestinos() const
{
    return destinos;
}

void Persona::setDestinos(const map<string, Destino *> &nuevosDestinos)
{
    destinos = nuevosDestinos;
}

void Persona::addDestino()
{
    string fecha;
    string nombre;

    cout << "Ingrese la fecha del destino: ";
    cin >> fecha;
    while (!Utils::isDate(fecha))
    {
        cout << "Fecha invalida, intente de nuevo: " << endl;
        cin >> fecha;
    }

    cout << "Ingrese el nombre del destino: ";
    cin >> nombre;
    nombre = Utils::toLowerCase(nombre);

    if (destinos.find(fecha) == destinos.end())
    {
        destinos[fecha] = new Destino(nombre);
        cout << "Destino agregado" << endl;
    }
    else
    {
        int opcion = 0;
        cout << "Ya existe un destino para la fecha " << fecha << endl;
        cout << "Desea remplazar el destino existente? (1/0): ";
        cin >> opcion;
        if (opcion == 1)
        {
            destinos[fecha] = new Destino(nombre);
            cout << "Destino remplazado" << endl;
        }
    };
}

void Persona::showPersona()
{
    if (!destinos.empty())
    {
        int i = 1;
        cout << "Destinos: " << endl;
        for (auto &destino : destinos)
        {
            cout << "------ " << i << ". Fecha: " << destino.first << " Destino: " << destino.second->getNombre() << endl;
            i++;
        }
    }
}

pair<string, Destino *> Persona::selectDestino()
{
    int opcion = 0;
    cout << "Seleccione un destino: ";
    cin >> opcion;

    int i = 1;
    auto itDestinos = find_if(destinos.begin(), destinos.end(), [opcion, i](pair<string, Destino *> fechaDestino) mutable
                              {if(opcion == i){
                    return true;}
                i++;return false; });

    if (itDestinos == destinos.end())
    {
        cout << "No se encontro el destino" << endl;
        return {"", nullptr};
    }
    return *itDestinos;
}