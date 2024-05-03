#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

/*registre los miembros de la famila con la edad y ordenar del mas viejo al mas joven*/
struct Miembros_familia
{
    string miembro_familia;
    int edad;
}

void
registrar_miembros(string familiar, int edad, map<string, int> miembros)
{
    cout << "Ingrese usted que mimbro de la familia es: " << endl;
    cin >> familiar;
    cout << "Ingrese la edad de " << familiar << endl;
    cin >> edad;

    miembros.insert(pair<string, int>(familiar, edad));

    cout << "familiar registrado" << endl;
}

void mostrar_familiares(string miembro_familiar, string edad)
{
    cout << "Los miembros de la familia son: " << endl;
    for (auto it = miembros.begin(); it != miembros.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

int main()
{
    map<string, int> miembros;
    string miembro_familia;
    string edad;
    registrar_miembros(miembro_familia, edad, miembros);
}