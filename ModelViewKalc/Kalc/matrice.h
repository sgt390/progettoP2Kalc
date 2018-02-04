#ifndef MATRICE_H
#define MATRICE_H
#include <qvector.h>
#include <qmath.h>
#include <iostream>
#include <qstring.h>
#include <error.h>
#include "kalcerrors.h"

template<class T>
class Matrice
{
private:
    int x;
    int y;
    QVector<T*> matrix;

public:
    Matrice(int=0, int=0);
    virtual ~Matrice();

    virtual void inserisci(const T&, int, int);
    virtual void rimuovi(const T &);
    virtual void ridimensiona(int,int);
    void aggiungiColonna(int=1);
    void aggiungiRiga(int=1);
    void rimuoviColonna(int=1);
    void rimuoviRiga(int=1);
    virtual void svuota();
    int getDimX() const;
    int getDimY() const;
    T* elementoInPosizione(int,int) const;
    T* elementoInPosizione(int, int);
    typename QVector<T*>::const_iterator& iteratoreInPosizione(int,int) const;
    typename QVector<T*>::iterator iteratoreInPosizione(int,int);
    void riempiSpaziVuoti(const T&);

    Matrice<T>& operator= (const Matrice<T>&);
    bool operator== (const Matrice<T>&) const;

};

template<class T>
Matrice<T>::Matrice(int _x,int _y): x(_x), y(_y)
{
    if(x<0 || y<0){
        x=0;
        y=0;
        throw eccezione_costruzione_matrice();
    }
    for(int i=0; i<_x; ++i)
        for(int j=0; j<_y; ++j)
            matrix.push_back(new T());
}

template<class T>
Matrice<T>::~Matrice(){
    for(auto it=matrix.begin(); it != matrix.end(); ++it )
        delete *it;
}


template<class T>
void Matrice<T>::inserisci(const T& t, int _x, int _y){
    if(_x*y+_y < matrix.size()){
        matrix.replace(_x*y+_y, new T(t));
    }
    else throw eccezione_parametro_dimensioneErrata();
}

template<class T>
void Matrice<T>::rimuovi(const T& elemento){
    bool trovato=false;
    QVector<T*> delElements;
    for(auto it = matrix.begin(); it != matrix.end(); ++it){
        if(**it == elemento){
            delElements.push_back(*it);
            delete *it;
            trovato = true;
        }
    }
    for(auto it = delElements.begin(); it != delElements.end(); ++it)
        matrix.removeAll(*it);
    while(x*y > matrix.size()){
        if(x*(y-1) >= matrix.size())
            y--;
        if((x-1)*y >=matrix.size())
            x--;
    }
    if(!trovato)
        throw eccezione_parametro_ElementoNonTrovato();
}


template<class T>
int Matrice<T>::getDimX() const{
    return x;
}
template<class T>
int Matrice<T>::getDimY() const{
    return y;
}


template<class T>
void Matrice<T>::ridimensiona(int _x, int _y){
    if(_x<0 || _y<0)
        throw eccezione_parametro_dimensioneErrata();
    x = _x;
    y = _y;
    for(int i = x*y; i<matrix.size(); ++i)
        delete matrix[i];
    matrix.resize(x*y);

    for(int i=matrix.size(); i<_x*_y; ++i)
        matrix.push_back(new T());
}
template<class T>
void Matrice<T>::aggiungiColonna(int n){
    if(n<0)
        throw eccezione_parametro_dimensioneErrata();
    ridimensiona(x,y+n);
}
template<class T>
void Matrice<T>::aggiungiRiga(int n){
    if(n<0)
        throw eccezione_parametro_dimensioneErrata();
    ridimensiona(x+n,y);
}
template<class T>
void Matrice<T>::rimuoviColonna(int n){
    if(n<0)
        throw eccezione_parametro_dimensioneErrata();
    ridimensiona(x,y-n);
}
template<class T>
void Matrice<T>::rimuoviRiga(int n){
    if(n<0)
        throw eccezione_parametro_dimensioneErrata();
    ridimensiona(x-n, y);
}

template<class T>
void Matrice<T>::svuota(){
    x = 0;
    y = 0;
    for(auto it = matrix.begin(); it != matrix.end(); ++it)
        delete *it;
    matrix.clear();
}

template<class T>
T* Matrice<T>::elementoInPosizione(int _x, int _y){
    if(_x*_y < matrix.size())
        return matrix[_x*y + _y];
    throw eccezione_parametro_dimensioneErrata();
}

template<class T>
T* Matrice<T>::elementoInPosizione(int _x, int _y) const{
    if(_x*y+_y < matrix.size())
        return matrix[_x*y + _y];
    throw eccezione_parametro_dimensioneErrata();
}
template<class T>
typename QVector<T*>::const_iterator& Matrice<T>::iteratoreInPosizione(int _x, int _y) const{
    if(_x<0 || _y<0 || _x>=getDimX() || _y>=getDimY())
        throw eccezione_parametro_dimensioneErrata();
    return matrix.begin() + _x*y + _y;
}
template<class T>
typename QVector<T*>::iterator Matrice<T>::iteratoreInPosizione(int _x, int _y){
    if(_x<0 || _y<0 || _x>=getDimX() || _y>=getDimY())
        throw eccezione_parametro_dimensioneErrata();
    return (matrix.begin() + _x*y + _y);
}

template<class T>
void Matrice<T>::riempiSpaziVuoti(const T& t){
    for(int i=0; i<x*y; ++i)
        if(!matrix[i])
            matrix[i] = new T(t);
}

template<class T>
Matrice<T>& Matrice<T>::operator= (const Matrice<T>& m){
    if(this == &m)
        return *this;
    svuota();
    x = m.x;
    y = m.y;
    ridimensiona(x,y);
    for(int i=0; i<m.matrix.size(); ++i)
        if(m.matrix[i])
          matrix[i] = new T(*m.matrix[i]);

    return *this;
}

template<class T>
bool Matrice<T>::operator ==(const Matrice<T>& m) const{
    if(this == &m)
        return true;
    if(x != m.x || y != m.y || matrix.size() != m.matrix.size())
        return false;
    bool diverso = false;
    for(int i=0; !diverso && i<matrix.size(); ++i)
            if(!(*matrix[i] == *(m.matrix[i])))
                diverso = true;
    if(diverso)
        return false;
    return true;
}

template<class T>
std::ostream& operator<< (std::ostream& os,const Matrice<T>& m){
    for(int i=0; i<m.getDimX(); ++i){
        for(int j=0; j<m.getDimY(); ++j)
            os<<*m.elementoInPosizione(i,j)<<";";
    os<<std::endl;
    }
    return os;
}

#endif // MATRICE_H
