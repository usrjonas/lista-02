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
 * @brief Função procura o primeiro elemento no range em que um determinado predicado é verdadeiro.
 * 
 * @tparam InputIt Iterator para o range.
 * @tparam UnaryPredicate Uma função para procurar o primeiro elemento.
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. 
 * 
 * @return InputIt Um iterator para o primeiro elemento no range em que um determinado predicado é verdadeiro.
 */
template<class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
{
    while ( first < last )
	{
        if (p(*first))
		    return first;

	    first++;
    }

    return first;
}

}
#endif
