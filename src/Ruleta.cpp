#include "Ruleta.h"

/// Constructores & Destructor
Ruleta::Ruleta()
{
    // Ultimo numero
    ultimoNumero = rand()%37;

    // Numeros
    for (int i = 0; i < 37; i++)
    {
        numeros[i] = i;
    }

    // Colores
    for (int i = 0; i < 37; i++)
    {
        if (i == 0)
        {
            colores[i] = VERDE;
        }
        else
        {
            if (i <= 10 || (i > 18 && i <= 28))
            {
                if (i % 2 == 1)
                    colores[i] = ROJO;
                else
                    colores[i] = NEGRO;
            }
            else
            {
                if (i % 2 == 1)
                    colores[i] = NEGRO;
                else
                    colores[i] = ROJO;
            }
        }
    }
}

Ruleta::~Ruleta()
{
    //dtor
}

/// Sobrecargas
ostream & operator << (ostream &out, const Ruleta &r)
{
    out << "La bola ha caido en ";
    out << r.ultimoNumero << endl;

    return out;
}

/// Metodos
void Ruleta::Apostar(int indice, int tipo, int cantidad)
{
    tipoApuesta[indice] = tipo;
    cantidadApuesta[indice] = cantidad;

    string ap;
    int num = 0;

    switch (tipo)
    {
    case COLORES:
        cout << "A que color quiere apostar?" << endl;
        cout << "[ROJO, NEGRO]\t>> ";
        do
        {
            try
            {
                cin >> ap;
                if (ap != "ROJO" && ap != "NEGRO")
                    throw new Excepciones();
            } catch(Excepciones e)
            {
                cout << e.what();
            }
        } while (ap != "ROJO" && ap != "NEGRO");

        if (ap == "ROJO")
            apuesta[indice] = ROJO;

        else if (ap == "NEGRO")
            apuesta[indice] = NEGRO;

        break;

    case PARIDAD:
        cout << "A que paridad quieres apostar?" << endl;
        cout << "[PAR, IMPAR]\t>> ";
        do
        {
            try
            {
                cin >> ap;
                if (ap != "PAR" && ap != "IMPAR")
                    throw new Excepciones();
            } catch(Excepciones e)
            {
                cout << e.what();
            }
        } while (ap != "PAR" && ap != "IMPAR");

        if (ap == "PAR")
            apuesta[indice] = PAR;

        else if (ap == "IMPAR")
            apuesta[indice] = IMPAR;
        break;

    case MITADES:
        cout << "A que mitad quieres apostar?" << endl;
        cout << "[PRIMERA, SEGUNDA]\t>> ";
        do
        {
            try
            {
                cin >> ap;
                if (ap != "PRIMERA" && ap != "SEGUNDA")
                    throw new Excepciones();
            } catch(Excepciones e)
            {
                cout << e.what();
            }
        } while (ap != "PRIMERA" && ap != "SEGUNDA");

        if (ap == "PRIMERA")
            apuesta[indice] = PRIMERAMITAD;

        else if (ap == "IMPAR")
            apuesta[indice] = SEGUNDAMITAD;
        break;

    case DOCENAS:
        cout << "A que docena quieres apostar?" << endl;
        cout << "[PRIMERA, SEGUNDA, TERCERA]\t>> ";
        do
        {
            try
            {
                cin >> ap;
                if (ap != "PAR" && ap != "IMPAR" && ap != "TERCERA")
                    throw new Excepciones();
            } catch(Excepciones e)
            {
                cout << e.what();
            }
        } while (ap != "PRIMERA" && ap != "SEGUNDA" && ap != "TERCERA");

        if (ap == "PRIMERA")
            apuesta[indice] = PRIMERADOCENA;

        else if (ap == "SEGUNDA")
            apuesta[indice] = SEGUNDADOCENA;

        else if (ap == "TERCERA")
            apuesta[indice] = TERCERADOCENA;
        break;

    case NUMEROS:
        cout << "A que numero quieres apostar?" << endl;
        cout << "[0 - 36]\t>> ";

        do
        {
            cin >> num;
        } while(num < 0 && num > 36);

        apuesta[indice] = num;

        break;
    }
}

void Ruleta::GenerarNumero()
{
    srand(time(NULL));

    int numeroGenerado = rand()%37;

    ultimoNumero = numeroGenerado;
    // cout << ultimoNumero << endl;
}

bool Ruleta::ComprobarApuestas(int indice)
{
    bool rojo = true;
    bool par = true;
    bool primera = true;
    int docena = PRIMERADOCENA;

    if (colores[ultimoNumero] == NEGRO)
        rojo = false;

    else if (ultimoNumero % 2 == 1)
        par = false;

    else if (ultimoNumero > 18)
        primera = false;

    else if (ultimoNumero > 12)
    {
        if (ultimoNumero > 24)
            docena = TERCERADOCENA;
        else
            docena = SEGUNDADOCENA;
    }

    switch (tipoApuesta[indice])
    {
    case COLORES:
        if (apuesta[indice] == ROJO && rojo)
            return true;
        else
            return false;

        break;

    case PARIDAD:
        if (apuesta[indice] == PAR && par)
            return true;
        else
            return false;
        break;

    case MITADES:
        if (apuesta[indice] == PRIMERAMITAD && primera)
            return true;
        else
            return false;
        break;

    case DOCENAS:
        if (apuesta[indice] == PRIMERADOCENA && docena == PRIMERADOCENA)
            return true;
        if (apuesta[indice] == SEGUNDADOCENA && docena == SEGUNDADOCENA)
            return true;
        if (apuesta[indice] == TERCERADOCENA && docena == TERCERADOCENA)
            return true;
        else
            return false;
        break;

    case NUMEROS:
        if (apuesta[indice] == ultimoNumero)
            return true;
        else
            return false;
        break;
    }
}

void Ruleta::RedimensionarCosas(int numeroJugadores)
{
    numeroCosas = numeroJugadores;
    tipoApuesta = (int*) malloc(sizeof(int) * numeroCosas);
    cantidadApuesta = (int*) malloc(sizeof(int) * numeroCosas);
    apuesta = (int*) malloc(sizeof(int) * numeroCosas);
}
