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
 * @brief Função que ordena os elementos de um range.
 * 
 * @tparam ForwardIt Iterator para o range.
 * @tparam Comparison Uma função que verifica se um elemento é menor que outro. 
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param cmp Uma função que retorna true se o elemento é menor do que o segundo, ou falso caso contrário. 
 */
template<class ForwardIt, class Comparison>
void sort(ForwardIt first, ForwardIt last, Comparison cmp)
{
    if ( first >= last )
		return;

	const ForwardIt begin = first++;
	
	ForwardIt aux;
	alocatePointer(aux);

	ForwardIt iterator;

	int counter;

	while ( first < last )
	{
		iterator = first-1;
		counter = 0;

		while( begin <= iterator )
		{
			if( cmp( *(first-counter), *iterator ) )
			{
				*aux		            = *(first-counter);
				*(first-counter)    = *iterator;
				*iterator           = *aux;
			}
			else
				break;

			counter++;
			iterator--;
		} 
			
		first++;
	}
	
	delete aux;

	return;
}

}
#endif
