#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <iostream>

using namespace std;

class Excepciones : public exception
{
    public:
        const char* what() const throw()
        {
        return "String mal introducida.";
        }
};

#endif // EXCEPCIONES_H
