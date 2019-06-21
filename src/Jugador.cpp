#include <iostream>

#include "Jugador.h"

using namespace std;

/// Constructores & Destructor

Jugador::Jugador()
{
    bool correcto = false;
    do
    {
        cout << "\nNUEVO JUGADOR - ";
        cout << "Por favor, introduzca sus datos a continuacion:" << endl;

        // Nombre
        cout << "- Alias\t[Sin espacios]\t>> ";
        cin >> alias;

        // Edad
        cout << "- Edad\t[18 - 99]\t>> ";
        cin >> edad;

        // Saldo
        cout << "- Saldo\t[1000 - 9999]\t>> ";
        cin >> saldo;

        // Checkear si es correcto
        correcto = JugadorCorrecto();

    } while (!correcto);
}

Jugador::Jugador(string _alias, int _edad, int _saldo)
{
    alias = _alias;
    edad = _edad;
    saldo = _saldo;
}

Jugador::~Jugador()
{
    //dtor
}


/// Sobrecargas


/// Metodos
bool Jugador::JugadorCorrecto()
{
    if (edad < 18 || edad > 99)
    {
        cout << "Por favor, introduzca una edad valida.\n";
        return false;
    }
    else if (saldo < 1000 || saldo > 9999)
    {
        cout << "Por favor, introduzca un saldo valido.\n";
        return false;
    }
    else
    {
        return true;
    }
}


