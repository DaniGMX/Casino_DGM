#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

class Jugador
{
    public:
        /// Constructores
        Jugador();
        Jugador(string _name, int _edad, int _saldo);
        Jugador(const Jugador &_jugador);

        /// Destructores
        ~Jugador();

        /// Getters & Setters
        string getAlias(){ return this->alias; }
        int getEdad(){ return this->edad; }
        int getSaldo(){ return this->saldo; }
        int getApuesta() { return this->apuesta; }

        void setSaldo(int _saldo) { this->saldo = _saldo; }
        void setApuesta(int _apuesta) {this->apuesta = _apuesta; }

        /// Metodos

    private:
        /// Variables
        string alias;
        int edad;
        int saldo;
        int apuesta;

        /// Sobrecargas


        /// Metodos
        void ImprimirJugador();
        bool JugadorCorrecto();
};

#endif // JUGADOR_H
