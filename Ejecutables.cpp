#include <iostream>
#include "VacacionesCYC.cpp"
#include "VacacionesPYC.cpp"
using namespace std;

int main()
{
  int opcion;
  TioSobrio persona;
  Interfaz interfaz1;
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

  while (true)
  {
    cout << "1.para la version con conjuntos y mapas \n 2. para la version con pilas y colas \n 3. para salir" << endl;
    cin >> opcion;

    if (opcion == 1)
    {
      interfaz1.Menu();
    }
    else if (opcion == 2)
    {
      persona.menu();
    }
    else if (opcion == 3)
    {
      cout << "Saliendo del sistema" << endl;
      break;
    }
    else
    {
      cout << "Opcion invalida" << endl;
    }
  }
  return 0;
}
