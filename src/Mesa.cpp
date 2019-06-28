#include "Mesa.h"

/// Constructor & Destructor

Mesa::Mesa()
{
    //ctor
}

Mesa::~Mesa()
{
    //dtor
}



/// Metodos

void Mesa::PedirJugadores(vector<Jugador> _jugadoresPosibles)
{
    for (int i = 0; i < _jugadoresPosibles.size(); i++)
    {
        if (i == 0)
        {
            Asiento nuevoAsiento = Asiento(&_jugadoresPosibles[i]);

            asientos.push_back(nuevoAsiento);

            cout << "\nEl jugador " << asientos[i].getPropietario().getAlias() << " se ha sentado en la mesa." << endl;
        }
        else
        {
            int jugara = 0;
            cout << "\nVa a jugar tambien el jugador " << _jugadoresPosibles[i].getAlias() << "?" << endl;
            do
            {
                cout << "[0 = NO, 1 = SI]\t>> ";
                cin >> jugara;
            } while (jugara != 0 && jugara != 1);

            if (jugara == 1)
            {
                Asiento otroAsiento = Asiento(&_jugadoresPosibles[i]);

                asientos.push_back(otroAsiento);

                cout << "\nDe acuerdo! El jugador " << asientos[i].getPropietario().getAlias() << " se ha sentado en la mesa." << endl;
            }
        }
    }
}
