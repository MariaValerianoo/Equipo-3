#pragma once
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Destino
{
private:
    string nombre;

public:
    Destino();
    Destino(string nombre);
    string getNombre() const;
    void setNombre(const string &nombre);
};

Destino::Destino()
{
}

Destino::Destino(string nombre)
{
    this->nombre = nombre;
}

string Destino::getNombre() const
{
    return nombre;
}

void Destino::setNombre(const string &nombre)
{
    this->nombre = nombre;
}