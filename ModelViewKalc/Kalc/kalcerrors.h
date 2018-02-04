#ifndef KALCERRORS_H
#define KALCERRORS_H
#include <exception>

class eccezione_parametro_colore: public std::exception{};
class eccezione_parametro_percentuale: public std::exception{};
class eccezione_parametro_dimensioneErrata: public std::exception{};
class eccezione_parametro_ElementoNonTrovato: public std::exception{};
class eccezione_costruzione_matrice: public std::exception{};
class eccezione_costruzione_colore: public std::exception{};
class eccezione_costruzione_raster: public std::exception{};
#endif // KALCERRORS_H
