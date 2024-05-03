#include <iostream>
#include <cstdlib>
#include <stack>
#include "./Familia.cpp"
#include "./Persona.cpp"
#include "./Destino.cpp"
using namespace std;

int main(int argc, char const *argv[])
{

    Familia *familia = new Familia();
    Persona *persona = nullptr;
    pair<string, Destino *> fechaDestino;
    pair<Destino *, stack<Persona *>> personasDestino;

    int opcion = 0;
    do
    {
        cout << "1. Agregar persona" << endl;
        cout << "2. Agregar destino por persona" << endl;
        cout << "3. Agregar destino por familia" << endl;
        cout << "4. Mostrar personas y sus destinos" << endl;
        cout << "5. Busca los destinos de algun integrante de la familia" << endl;
        cout << "6. Busca los integrantes de la familia que tienen un destino en comun" << endl;

        cin >> opcion;
        switch (opcion)
        {
        case 1:
            familia->addPersona();
            break;
        case 2:
            familia->showPersonas();
            persona = familia->selectPersona();
            if (persona != nullptr)
            {
                persona->addDestino();
            }
            break;
        case 3:
            familia->showPersonas();
            cout << "Seleciona la persona la cual escogio un destino para la familia" << endl;
            persona = familia->selectPersona();
            if (persona != nullptr)
            {

                persona->showPersona();
                fechaDestino = persona->selectDestino();
                if (!fechaDestino.first.empty())
                {
                    familia->addDestino(fechaDestino);
                }
            }
            break;
        case 4:
            familia->showPersonas();
            break;
        case 5:
            familia->showPersonas();
            persona = familia->selectPersona();
            if (persona != nullptr)
            {

                persona->showPersona();
            }
            break;
        case 6:
            personasDestino = familia->findPersonByDestino();
            if (personasDestino.first != nullptr)
            {
                cout << "Destino: " << personasDestino.first->getNombre() << endl;
                cout << "Personas: " << endl;
                while (!personasDestino.second.empty())
                {
                    cout << "------ " << personasDestino.second.top()->getNombre() << endl;
                    personasDestino.second.pop();
                }
            }
            break;
        default:
            cout << "Opcion no valida, vuelve a intentarlo" << endl;
            break;
        }

    } while (opcion != 0);

    return 0;
}
