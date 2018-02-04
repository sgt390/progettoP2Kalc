#ifndef ECCEZIONI_H
#define ECCEZIONI_H

#include<exception>

class eccezione_dimensioneDisplay: public std::exception{};
class eccezione_OperandoGui: public std::exception{};
class eccezione_displayNonEsistente: public std::exception{};
#endif // ECCEZIONI_H
