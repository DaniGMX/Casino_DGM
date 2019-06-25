#include "UI.h"

/// Constructor
UI::UI()
{
}

/// Imprimir Cosas

// Jugador
void UI::ImprimirJugador(Jugador _jugador)
{
    int tamDato, blanks;

    EncabezadoJugador();
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
            case 0:
            {
                tamDato = _jugador.getAlias().length();
                blanks = TAM - 12 - tamDato;

                cout << (char)V << (char)BLANK;
                cout << "Alias\t>> " << _jugador.getAlias();
                for (int j = 0; j < blanks; j++)
                {
                    cout << (char)BLANK;
                }
                cout << (char)V << endl;
            }break;

            case 1:
            {
                tamDato = 2;
                blanks = TAM - 12 - tamDato;

                cout << (char)V << (char)BLANK;
                cout << "Edad\t>> " << _jugador.getEdad();
                for (int j = 0; j < blanks; j++)
                {
                    cout << (char)BLANK;
                }
                cout << (char)V << endl;
            }break;

            case 2:
            {
                tamDato = log10(_jugador.getSaldo()) + 1;
                blanks = TAM - 12 - 1 - tamDato;
                cout << (char)V << (char)BLANK;
                cout << "Saldo\t>> " << _jugador.getSaldo() << (char)USD;
                for (int j = 0; j < blanks; j++)
                {
                    cout << (char)BLANK;
                }
                cout << (char)V << endl;
            }break;
        }
    }
    LineaInferior();
}

/// Puro UI
void UI::LineaSuperior()
{
    for (int i = 0; i < TAM; i++)
    {
        if (i == 0)
            cout << (char)Q;
        else if (i == TAM - 1)
            cout << (char)E << endl;
        else
            cout << (char)H;
    }
}

void UI::EncabezadoJugador()
{
    int lineas = 3;
    int strTam = 7;
    char strJugador[strTam] = {'J', 'U', 'G', 'A', 'D', 'O', 'R'};

    for (int i = 0; i < lineas; i++)
    {
        switch (i)
        {
            case 0:
                cout << (char)Q;
                for (int j = 0; j < strTam; j++)
                {
                    cout << (char)H;
                }
                cout << (char)E << endl;
                break;

            case 1:
                cout << (char)V;
                for (int j = 0; j < strTam; j++)
                {
                    cout << strJugador[j];
                }
                cout << (char)V << endl;
                break;

            case 2:
                for (int j = 0; j < TAM; j++)
                {
                    if (j == 0)
                        cout << (char)A;
                    else if (j == strTam + 1)
                        cout << (char)X;
                    else if (j == TAM - 1)
                        cout << (char)E << endl;
                    else
                        cout << (char)H;
                }
                break;
        }
    }
}

void UI::LineaInferior()
{
    for (int i = 0; i < TAM; i++)
    {
        if (i == 0)
            cout << (char)Z;
        else if (i == TAM - 1)
            cout << (char)C << endl;
        else
            cout << (char)H;
    }
}
