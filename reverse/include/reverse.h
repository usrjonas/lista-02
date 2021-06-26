#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal {

/**
 * @brief Função que aloca um ponteiro.
 * 
 * @tparam T É o tipo do iterador 'BidirIt'.
 * @param pointer Ponteiro a ser alocado.
 */
template<class T>
void alocatePointer ( T * & pointer )
{
    pointer = new T;
}

/**
 * @brief Função que inverte a ordem de cada elemento em um range [first, last).
 * 
 * @tparam BidirIt Iterator para o range.
 * 
 * @param first Ponteiro para o primeiro elemento do range.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 */
template<class BidirIt>
void reverse(BidirIt first, BidirIt last)
{
    BidirIt aux;
    alocatePointer ( aux );

    last--;

    while ( first <= last )
    {
      	*aux     = *first;
        *first++ = *last;
        *last--  = *aux;
    }

    delete aux;

    return;
}

}
#endif
