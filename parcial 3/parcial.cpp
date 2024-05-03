#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

void registrar_miembros(string familiar, int edad, map<string, int> miembros)
{
    cout << "Ingrese usted que mimbro de la familia es: " << endl;
    cin >> familiar;
    cout << "Ingrese la edad de " << familiar << endl;
    cin >> edad;

    miembros.insert(pair<string, int>(familiar, edad));

    auto iterador = miembros.find(edad);
    for (const auto edades : miembros)
    {
        if (edades > miembros)
        {
            cout << "El familiar " << familiar << " es el mas viejo" << endl;
        }
    }

    cout << "familiar registrado" << endl;
}
int main()
{
    map<string, int> miembros;
    string miembro_familia;
    int edad;
    // Miembros_familia *head;
    registrar_miembros(miembro_familia, edad, miembros);
    // sortbyYear(head);
}
