#pragma once
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "./Utils.cpp"
#include "./Persona.cpp"
#include "./Destino.cpp"
using namespace std;

class Utils;
class Persona;
class Destino;

class Familia
{
private:
    set<Persona *> personas;
    // fecha - destino
    map<string, Destino *> destinos;

public:
    Familia();

    void addPersona();
    void addDestino(pair<string, Destino *> fechaDestino);
    void setDestinos(const map<string, Destino *> &nuevosDestinos);
    map<string, Destino *> getDestinos() const;

    void setPersonas(const set<Persona *> &nuevasPersonas);
    void showPersonas();
    set<Persona *> getPersonas() const;
    Persona *selectPersona();
    pair<Destino *, set<Persona *>> findPersonByDestino();
};

Familia::Familia()
{
}

void Familia::addPersona()
{
    string nombre;
    cout << "Ingrese el nombre del integrante de tu familia: ";
    cin >> nombre;
    nombre = Utils::toLowerCase(nombre);
    personas.insert(new Persona(nombre));
    cout << "Persona agregada" << endl;
}

void Familia::addDestino(pair<string, Destino *> fechaDestino)
{
    if (destinos.find(fechaDestino.first) != destinos.end())
    {
        int opcion = 0;
        cout << "Ya existe un destino para esa fecha" << endl;
        cout << "Desea reemplazarlo? (1/0): ";
        cin >> opcion;
        if (opcion == 1)
        {
            destinos[fechaDestino.first] = fechaDestino.second;
            cout << "Destino reemplazado" << endl;
        }
        return;
    }
    else
    {
        destinos.insert(fechaDestino);
        cout << "Destino agregado a la lista general" << endl;
    }
}
set<Persona *> Familia::getPersonas() const
{
    return personas;
}

void Familia::setPersonas(const set<Persona *> &nuevasPersonas)
{
    personas = nuevasPersonas;
}

map<string, Destino *> Familia::getDestinos() const
{
    return destinos;
}

void Familia::setDestinos(const map<string, Destino *> &nuevosDestinos)
{
    destinos = nuevosDestinos;
}

void Familia::showPersonas()
{
    cout << "Personas en la familia: " << endl;
    int i = 1;
    for (auto persona : personas)
    {
        cout << i << ". " << persona->getNombre() << endl;
        persona->showPersona();
        i++;
    }
}

Persona *Familia::selectPersona()
{
    int opcion = 0;
    cout << "Seleccione una persona: ";
    cin >> opcion;

    int i = 1;
    auto itPersonas = find_if(personas.begin(), personas.end(), [opcion, i](Persona *persona) mutable
                              {if(opcion == i){
                    return true;}
                i++;return false; });
    if (itPersonas == personas.end())
    {
        cout << "No se encontro la persona" << endl;
        return nullptr;
    }
    return *itPersonas;
}

pair<Destino *, set<Persona *>> Familia::findPersonByDestino()
{
    string nombre;
    cout << "Ingrese el nombre del destino: ";
    cin >> nombre;
    nombre = Utils::toLowerCase(nombre);

    set<Persona *> personasPorDestino;
    Destino *destinoBuscado = nullptr;

    for (auto persona : personas)
    {
        for (auto destino : persona->getDestinos())
        {
            if (destino.second->getNombre() == nombre)
            {
                personasPorDestino.insert(persona);
                destinoBuscado = destino.second;
            }
        }
    }

    if (destinoBuscado == nullptr)
    {
        cout << "No se encontro el destino" << endl;
    }

    return {destinoBuscado, personasPorDestino};
}