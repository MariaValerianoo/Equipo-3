#pragma once
#include <iostream>
#include <stack>
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
    stack<pair<string, Destino *>> destinos;

public:
    Persona();
    Persona(string nombre);

    string getNombre() const;
    void setNombre(const string &nuevoNombre);
    stack<pair<string, Destino *>> getDestinos() const;

    void setDestinos(const stack<pair<string, Destino *>> &nuevosDestinos);
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

stack<pair<string, Destino *>> Persona::getDestinos() const
{
    return destinos;
}

void Persona::setDestinos(const stack<pair<string, Destino *>> &nuevosDestinos)
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

    bool valid = true;
    while (!destinos.empty())
    {
        pair<string, Destino *> destino = destinos.top();
        if (destino.first == fecha)
        {

            int opcion = 0;
            cout << "Ya existe un destino para la fecha " << fecha << endl;
            cout << "Desea remplazar el destino existente? (1/0): ";
            cin >> opcion;
            if (opcion == 1)
            {

                destinos.pop();
                destinos.push({fecha, new Destino(nombre)});
                cout << "Destino remplazado" << endl;
                valid = false;
                break;
            }
            else
            {
                valid = false;
                break;
            }
        }
        destinos.pop();
    }

    if (valid)
    {
        destinos.push({fecha, new Destino(nombre)});
        cout << "Destino agregado" << endl;
    }
}

void Persona::showPersona()
{
    if (!destinos.empty())
    {
        int i = 1;
        cout << "Destinos: " << endl;

        while (!destinos.empty())
        {
            pair<string, Destino *> destino = destinos.top();
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

    while (!destinos.empty())
    {
        pair<string, Destino *> destino = destinos.top();
        if (opcion == i)
        {
            return destino;
        }
        i++;
        destinos.pop();
    }

    {
        cout << "No se encontro el destino" << endl;
        return {"", nullptr};
    }
}