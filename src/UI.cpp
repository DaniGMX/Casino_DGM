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

    LineaSuperior();
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
