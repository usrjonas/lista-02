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
 * @brief Função verifica se todos os elementos satisfazem um determinado predicado.
 * 
 * @tparam InputIt Iterator para o range.
 * @tparam UnaryPredicate Um predicado para verificar todos os elementos.
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário.
 * 
 * @return true Retorna verdadeiro quando o predicado p é verdadeiro para todos os elementos do range.
 * @return false Retorna falso caso contrario.
 */
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    if ( first >= last )
		return false;
	
    while ( first < last )
		if ( ! p(*first++) ) return false;

    return true;
}

/**
 * @brief Função verifica se pelo menos um elemento satisfaz um determinado predicado.
 * 
 * @tparam InputIt Iterator para o range.
 * @tparam UnaryPredicate Um predicado para verificar os elementos.
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário.
 * 
 * @return true Retorna verdadeiro quando o predicado p é verdadeiro para pelo menos um elemento do range.
 * @return false Retorna falso caso contrario.
 */
template<class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
    while ( first < last )
		if ( p(*first++) ) return true;

    return false;
}

/**
 * @brief Função verifica se nenhum elemento satisfaz um determinado predicado.
 * 
 * @tparam InputIt Iterator para o range.
 * @tparam UnaryPredicate Um predicado para verificar os elementos.
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário.
 * 
 * @return true Retorna verdadeiro quando o predicado p é falso para todos os elementos do range.
 * @return false Retorna falso caso contrario.
 */
template<class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{
    while ( first < last )
		if ( p(*first++) ) return false;

    return true;
}

}
#endif
