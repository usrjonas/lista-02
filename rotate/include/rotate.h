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
 * @brief Função que rotaciona o range a esquerda de forma que n_first se torne o primeiro elemento.
 * 
 * @tparam ForwardIt Iterator para o range.
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param n_first Ponteiro para o elemento que deve aparecer no inicio do range após a rotação.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * 
 * @return ForwardIt Retorna um iterator para a posição onde se encontra o primeiro elemento do range antes da rotação.
 */
template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{
    int movesRotate = n_first - first;
	int size = last - first;
	int lastIndex = size - 1;
	
	ForwardIt aux;
	alocatePointer(aux);
	*aux = *n_first;
	

	for (int j=0; j<movesRotate; j++)
	{
		aux[0] = first[0];

		for ( int i=0; i<lastIndex; i++ )
			first[ i ] = first[ (1 + i)%size ];

		first[lastIndex] = aux[0];
	}

    delete aux;

    return n_first;
}

}
#endif
