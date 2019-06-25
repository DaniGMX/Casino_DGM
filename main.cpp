#include <iostream>
#include <cstdlib>

#include "Casino.h"
#include "UI.h"
#include "Jugador.h"
#include "Ruleta.h"


using namespace std;

int main()
{
    int infinite = 1;
    cout << "- BIENVENIDO AL CASINO USJ -" << endl;

    Casino miCasino = Casino();
    UI miUI = UI();

    miCasino.AddJugador();

    while (infinite > -1)
    {
        for (int i = 0; i < miCasino.getNumeroJugadores(); i++)
        {
            miUI.ImprimirJugador(miCasino.getJugador(i));
        }
        infinite = miCasino.Menu();
    }

    return 0;
}
