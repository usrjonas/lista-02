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
 * @brief Função que copia os valores de um range para dentro de um novo range.
 * 
 * @tparam InputIt Iterator para o range.
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param d_first Ponteiro para o início do range onde os elementos vão ser copiados.
 * 
 * @return Um iterator apontando para a posição de memória logo após o último elemento copiado
 */
template<class InputIt>
InputIt copy(InputIt first, InputIt last, InputIt d_first)
{
    while ( first < last )
		*d_first++ = *first++;

  	return d_first;
}

}
#endif
