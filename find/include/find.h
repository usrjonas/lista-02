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
 * @brief Função procura o primeiro elemento no range igual ao value.
 * 
 * @tparam InputIt Iterator para o range.
 * @tparam T Tipo do objeto a ser procurado.
 * @tparam Equal Função que retorna true se o elemento é igual ao segundo, ou falso caso contrário. 
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param value Valor a ser procurado no range.
 * @param eq Função que retorna true se o elemento é igual ao segundo, ou falso caso contrário. 
 * 
 * @return InputIt Um iterator para o primeiro elemento no range igual ao value.
 */
template<class InputIt, class T, class Equal>
InputIt find(InputIt first, InputIt last, const T& value, Equal eq)
{
    while ( first < last )
	{
		if (eq(*first, value))
			return first;

	    first++;
    }

    return first;
}

}
#endif
