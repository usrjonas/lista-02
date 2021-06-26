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
 * @brief Função que verifica se todos os elemento do primeiro range são iguais ao do segundo range.
 * 
 * @tparam InputIt1 Iterator para o range1.
 * @tparam InputIt2 Iterator para o range2.
 * @tparam Equal Uma função que verifica se o elemento é igual ao segundo.
 * 
 * @param first1 Ponteiro para o inicio do range1 a ser considerado.
 * @param last1 Ponteiro para a posição de memoria logo após o último elemento do range1.
 * @param first2 Ponteiro para o inicio do range2 a ser considerado.
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário.
 * 
 * @return true Retorna verdadeio se todos os elementos do primeiro range são iguais aos do range [rist2, first2+(last1-first1)).
 * @return false Retorna falso caso contrário.
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq)
{
    while ( first1 < last1 )
		if ( ! eq( *first1++, *first2++) ) return false;
	
    return true;
}

/**
 * @brief Função que verifica se todos os elemento do primeiro range são iguais ao do segundo range.
 * 
 * @tparam InputIt1 Iterator para o range1.
 * @tparam InputIt2 Iterator para o range2.
 * @tparam Equal Equal Uma função que verifica se o elemento é igual ao segundo.
 * 
 * @param first1 Ponteiro para o inicio do range1 a ser considerado.
 * @param last1 Ponteiro para a posição de memoria logo após o último elemento do range1.
 * @param first2 Ponteiro para o inicio do range2 a ser considerado.
 * @param last2 Ponteiro para a posição de memoria logo após o último elemento do range2.
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário.
 * 
 * @return true Retorna verdadeio se todos os elementos do primeiro range são iguais aos do range [rist2, first2+(last1-first1)).
 * @return false Retorna falso caso contrário.
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, InputIt2 last2,
           Equal eq )
{
	while ( first1 < last1 )
	{
		if ( first2 >= last2 ) return false;

	  	if ( ! eq( *first1++, *first2++) ) return false;
	}
  
	return true;
}

}
#endif
