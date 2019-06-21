#include <iostream>

#include "UI.h"
#include "Jugador.h"


using namespace std;

int main()
{
    cout << "- BIENVENIDO AL CASINO USJ -" << endl;

    UI myUI = UI();
    Jugador player = Jugador();
    myUI.ImprimirJugador(player);

    return 0;
}
