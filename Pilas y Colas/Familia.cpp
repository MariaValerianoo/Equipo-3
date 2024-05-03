#pragma once
#include <iostream>
#include <queue>
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
    queue<Persona *> personas;
    // fecha - destino
    stack<pair<string, Destino *>> destinos;

public:
    Familia();

    void addPersona();
    void addDestino(pair<string, Destino *> fechaDestino);
    void setDestinos(const stack<pair<string, Destino *>> &nuevosDestinos);
    stack<pair<string, Destino *>> getDestinos() const;

    void setPersonas(const queue<Persona *> &nuevasPersonas);
    void showPersonas();
    queue<Persona *> getPersonas() const;
    Persona *selectPersona();
    pair<Destino *, stack<Persona *>> findPersonByDestino();
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
    personas.push(new Persona(nombre));
    cout << "Persona agregada" << endl;
}

void Familia::addDestino(pair<string, Destino *> fechaDestino)
{
    while (!destinos.empty())
    {
        pair<string, Destino *> destino = destinos.top();
        if (destino.first == fechaDestino.first)
        {
            int opcion = 0;
            cout << "Ya existe un destino para esa fecha" << endl;
            cout << "Desea reemplazarlo? (1/0): ";
            cin >> opcion;
            if (opcion == 1)
            {
                destinos.pop();
                destinos.push(fechaDestino);
                cout << "Destino reemplazado" << endl;
                return;
            }
        }
    }

    destinos.push(fechaDestino);
    cout << "Destino agregado a la lista general" << endl;
}

queue<Persona *> Familia::getPersonas() const
{
    return personas;
}

void Familia::setPersonas(const queue<Persona *> &nuevasPersonas)
{
    personas = nuevasPersonas;
}

stack<pair<string, Destino *>> Familia::getDestinos() const
{
    return destinos;
}

void Familia::setDestinos(const stack<pair<string, Destino *>> &nuevosDestinos)
{
    destinos = nuevosDestinos;
}

void Familia::showPersonas()
{
    cout << "Personas en la familia: " << endl;
    int i = 1;
    while (!personas.empty())
    {
        Persona *persona = personas.front();
        cout << i << ". " << persona->getNombre() << endl;
        persona->showPersona();
        i++;
        personas.pop();
    }
}

Persona *Familia::selectPersona()
{
    int opcion = 0;
    cout << "Seleccione una persona: ";
    cin >> opcion;

    int i = 1;

    while (!personas.empty())
    {
        Persona *persona = personas.front();
        if (opcion == i)
        {
            return persona;
        }
    }

    cout << "No se encontro la persona" << endl;
    return nullptr;
}

pair<Destino *, stack<Persona *>> Familia::findPersonByDestino()
{
    string nombre;
    cout << "Ingrese el nombre del destino: ";
    cin >> nombre;
    nombre = Utils::toLowerCase(nombre);

    stack<Persona *> personasPorDestino;
    Destino *destinoBuscado = nullptr;

    while (!personas.empty())
    {
        Persona *persona = personas.front();
        while (!persona->getDestinos().empty())
        {
            pair<string, Destino *> destino = persona->getDestinos().top();
            if (destino.second->getNombre() == nombre)
            {
                personasPorDestino.push(persona);
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