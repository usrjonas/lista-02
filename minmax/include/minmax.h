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
 * @brief Função que encontra e retorna a primeira ocorrencia do menor e maior elmentos em um range [first,last).
 *
 * @tparam Itr Iterator para o range.
 * @tparam Compare o tipo de uma função bool(const T &a, const T &b).
 *
 * @param first Ponteiro para o primeiro elemento do range.
 * @param last Ponteiro para a posição logo após o último elemento do range.
 * @param cmp A função de comparação que retorna true quando o primeiro parâmetro é menor do que o segundo.
 *
 * @return Um std::pair contendo o menor e maior elemento, nesta ordem.
 */
template <typename Itr, typename Compare >
std::pair<Itr, Itr> minmax( Itr first, Itr last, Compare cmp )
{
    if ( first >= last )
        return std::make_pair( first, first );

    Itr smaller = first;
    Itr biggest = first;

    while ( ++first < last )
    {
        if ( cmp( * first, * smaller ) )
            smaller = first;
        else if ( ! cmp( * first, * biggest ) )
            biggest = first;
    }

    return std::make_pair( smaller, biggest );
}

}
#endif
