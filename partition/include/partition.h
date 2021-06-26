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
 * @brief Função que reordena o range de forma que os elementos que satisfazem um determinado predicado fiquem antes de elementos cujo mesmo predicado não satisfazem.
 * 
 * @tparam ForwardIt Iterator para o range.
 * @tparam UnaryPredicate Um predicado para verificar os elementos.
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. 
 * 
 * @return ForwardIt Um iterator apontando para o elemento logo após o último elemento no range reordenado que satisfaz o predicado.
 */
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
	if ( first >= last )
		return last;
	
    ForwardIt aux;
	alocatePointer(aux);

	ForwardIt iterator = first;

	while ( first < last )
	{
		if ( p( *first ) )
		{
			*aux	    = *iterator;
			*iterator++ = *first;
			*first      = *aux;
		}

		first++;
	}

	delete aux;

	return iterator;
}

}
#endif
