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
    bool tipoCorrecto = true;
    bool cantidadCorrecta = true;

    mesaRuleta.GenerarNumero();
    mesaRuleta.RedimensionarCosas(numeroJugadores);

    do
    {
        for (int i = 0; i < numeroJugadores; i++)
        {
            int tipo = 0;
            int cantidad = 0;
            do
            {
                cout << jugadores[i].getAlias() << ", que tipo de apuesta quiere hacer?" << endl;
                cout << "1.- A Color\n2.- A Paridad\n3.- A Mitades\n4.- A Decenas\n5.- A Numero" << endl;
                cin >> tipo;
                tipo--;
                cout << "De acuerdo, y cuanto quieres apostar?" << endl;
                cin >> cantidad;

                if (tipo < 0 || tipo > 4)
                    tipoCorrecto = false;
                else if (cantidad > jugadores[i].getSaldo())
                {
                    cantidadCorrecta = false;
                    jugadores[i].setApuesta(cantidad);
                }

                else if (tipoCorrecto && cantidadCorrecta)
                    mesaRuleta.Apostar(i, tipo, cantidad);

                int nuevoSaldo = jugadores[i].getSaldo() - cantidad;
                jugadores[i].setSaldo(nuevoSaldo);

            } while (!tipoCorrecto && !cantidadCorrecta);

        }

        cout << mesaRuleta;

        for (int i = 0; i < numeroJugadores; i++)
        {
            bool haGanado = false;

            haGanado = mesaRuleta.ComprobarApuestas(i);

            if (haGanado)
            {
                int saldoActual = jugadores[i].getSaldo();
                int apuestaRealizada = jugadores[i].getApuesta();
                int nuevoSaldo = saldoActual + (2 * apuestaRealizada);

                jugadores[i].setSaldo(nuevoSaldo);
            }
        }

    //    mesaRuleta.RecogerApuesta();
    //    seguirJugando = mesaRuleta.Seguir();

        int seguir = 1;
        cout << "Desea seguir jugando?" << endl;
        cout << "[1 = SI, 0 = NO]\t>> ";
        cin >> seguir;

        if (seguir == 0)
            seguirJugando = false;

    } while (seguirJugando);

}

