#include "Casino.h"

/// Constructores & destructores
Casino::Casino()
{
    numeroJugadores = 0;
    mesaRuleta = Ruleta();
    salaActual = 0;
}

Casino::~Casino()
{
    //dtor
}


/// Sobrecargas


/// Metodos

void Casino::AddJugador()
{
    Jugador* nuevoJugador = new Jugador();

    numeroJugadores++;

    jugadores.push_back(*nuevoJugador);
}

int Casino::Menu()
{
    int jugadorActivo = 0;

    cout << "\nQue desea hacer?\n" << endl;

    if (salaActual == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            switch(i)
            {
            case 0:
                cout << (i + 1) << ".- Jugar a la Ruleta." << endl;
                break;

            case 1:
                cout << (i + 1) << ".- Introducir nuevo Jugador." << endl;
                break;

            case 2:
                cout << (i + 1) << ".- Salir del programa." << endl;
                break;
            }
        }

        cout << "\n>> ";
        cin >> eleccion;
        eleccion--;

        switch (eleccion)
        {
            case 0:
                JugarRuleta();
                break;
            case 1:
                AddJugador();
                break;

            case 2:
                cout << "\nHasta la proxima!" << endl;
                eleccion = -1;
                break;

        }

        system("cls");
    }

    else if (salaActual == 1)   // Estamos jugando a la ruleta
    {
        mesaRuleta.PedirJugadores(jugadores);

        for (int i = 0; i < 2; i++)
        {
            switch(i)
            {
            case 0:
                cout << (i + 1) << ".- Apostar" << endl;
                break;

            case 1:
                cout << (i + 1) << ".- Levantarse de la mesa" << endl;
                break;
            }
        }

        cout << "\n>> ";
        cin >> eleccion;
        eleccion--;

        switch (eleccion)
        {
            case 0:
                cout << "TODO: apostar" << endl;
                break;
            case 1:
                salaActual = 0;
                break;
        }
        system("cls");
    }

    else if (salaActual == 1)
    {
        cout << "\n>> ";
        cin >> eleccion;
        eleccion--;
    }

    return eleccion;
}

void Casino::JugarRuleta()
{
    bool seguirJugando;

    mesaRuleta.PedirJugadores(jugadores);
    // mesaRuleta.GenerarHistorial();

    //do
    //{
    //    mesaRuleta.Apostar();
    //    mesaRuelta.GenerarResultado();
    //    mesaRuleta.RecogerApuesta();
    //    seguirJugando = mesaRuleta.Seguir();
    //} while (seguirJugando);

}
