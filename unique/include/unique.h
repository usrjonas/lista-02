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
 * @brief Reordena os elementos no range de forma a não ter elementos repetidos.
 * 
 * @tparam InputIt Iterator para o range.
 * @tparam Equal Função que retorna true se o elemento é igual ao segundo, ou falso caso contrário.
 * 
 * @param first Ponteiro para o inicio do range a ser considerado.
 * @param last Ponteiro para a posição de memoria logo após o último elemento do range.
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário.
 * 
 * @return InputIt Um iterator para o elemento logo após o último elemento do range após o reordenamento.
 */
template<class InputIt, class Equal>
InputIt unique( InputIt first, InputIt last, Equal eq )
{
	if ( first >= last )
		return last;
    
    const InputIt begin = first++;
    InputIt aux = first;
    InputIt iterator;

    bool flag;

    while ( first < last )
    {
        flag = true;
        iterator = aux-1;
        
		while( begin <= iterator )
        {
			if( eq( *first, *iterator-- ) )
			{	
				flag = false;
				break;
            }
        }

        if ( flag )
            *aux++ = *first;
        
        first++;
    }
    
    return aux;
}

}
#endif
