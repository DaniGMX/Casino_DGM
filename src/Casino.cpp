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
    Jugador nuevoJugador = Jugador();

    if (numeroJugadores > 0)
    {
        Jugador* jugadoresAnteriores;
        jugadoresAnteriores = jugadores;

        numeroJugadores++;
        redimensionarJugadores();

        for (int i = 0; i < numeroJugadores; i++)
        {
            if (i == numeroJugadores - 1)
                jugadores[i] = nuevoJugador;
            else
                jugadores[i] = jugadoresAnteriores[i];
        }
    }

    else
    {
        numeroJugadores++;
        redimensionarJugadores();
        jugadores[numeroJugadores - 1] = nuevoJugador;
    }

    system("cls");
}

void Casino::redimensionarJugadores()
{
    jugadores = (Jugador*)malloc(sizeof(Jugador) * numeroJugadores);
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
                salaActual = 1;
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
