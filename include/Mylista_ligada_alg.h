/**
* @file
* @brief Implementações de Mylista_ligada
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 28/06/2017
* @date 29/06/2017
*/

#ifndef MYLISTALIGADA_ALG_H
#define MYLISTALIGADA_ALG_H

#include "header.h"
#include "Mylista_ligada.h"

// =====================================================================================================
// ========================================== Busca na lista ===========================================
// =====================================================================================================

/**
* @brief Checa se o primeiro T passado é maior do que o segundo
* @param a primeiro T
* @param b segundo T
* @return 'true' se a' for maior do que 'b' e 'false' caso contrário
*/
template <typename T>
bool maiorque(T a, T b) { return (a > b); }

/**
* @brief Checa se o primeiro T passado é menor do que o segundo
* @param a primeiro T
* @param b segundo T
* @return 'true' se a' for menor do que 'b' e 'false' caso contrário
*/
template <typename T>
bool menorque(T a, T b) { return (a < b); }

template <typename T>
bool Lista_BuscaSequencial(Mylista_ligada<T>& lista, const T elemento)
{
	return lista.exist(elemento);
}

/*
template <typename T>
bool Lista_BuscaBinaria(Mylista_ligada<T>& lista, const T elemento)
{
	typename Mylista_ligada<T>::iterator p = lista.begin();	// Cria iterator apontando para begin
	typename Mylista_ligada<T>::iterator ini = lista.begin();
	typename Mylista_ligada<T>::iterator fim = lista.b_end();

	advance(p , size()/2);

	for( ; ( *(ini) <= *(fim) ; p = (ini+fim)/2 ){
		if ( x == v[p]) return true;
		if( x > v[p] ) ini = p+1;
		if( x < v[p] ) fim = p-1;
	}

}
*/

// =====================================================================================================
// ======================================== Ordenação na lista =========================================
// =====================================================================================================

/*
void swap (myNode * anterior, myNode * primeiro, myNode * segundo)
{
	anterior->proximo = segundo;
	primeiro->proximo = segundo->proximo;
	segundo->proximo = primeiro;
}
*/

/**
* @brief Pega duas variáveis int por referência os valores delas entre sí
* @param a variável a ter seu valor trocado
* @param b variável a ter seu valor trocado
*/
void mySwap( int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

/**
* @brief Simula o bubble sort, ordenando uma lista de int a deixanda crescente.
* @param lista Mylista_ligada<int> que será ordenada
*/
void myBubbleSort(Mylista_ligada<int>& lista)
{	
	typename Mylista_ligada<int>::iterator head = lista.begin();
	typename Mylista_ligada<int>::iterator tail;
	typename Mylista_ligada<int>::iterator wall = lista.end();

	if(lista.size() == 2)
	{
		tail = head;
		head++;
		if(*(head) < *(tail))	// condição de ordenação
			mySwap( *(head), *(tail) );
	}

	if(lista.size() > 2)
	{
		while ( head != wall )
		{			
			tail = head;
			head++;

			while ( head != wall )
			{
				if(*(head) < *(tail))	// condição de ordenação
					mySwap( *(head), *(tail) );
				
				head++;
				tail++;
			}
			head = lista.begin();
			wall = tail;
		}
	}
}

/**
* @brief Simula o insertion sort, ordenando uma lista de int a deixanda crescente.
* @param lista Mylista_ligada<int> que será ordenada
*/
/*
void myInsertSort(Mylista_ligada<int>& lista){ //Insert na head
	// ini+1 > fim 	(vazio)
	// fim == ini+1 	(um elemento)

	typename Mylista_ligada<int>::iterator tail = lista.begin();
	typename Mylista_ligada<int>::iterator head;
	typename Mylista_ligada<int>::iterator wall = lista.end();

	if(lista.size() == 2)
	{
		tail = head;
		head++;
		if(*(head) < *(tail))	// condição de ordenação
			mySwap( *(head), *(tail) );
	}

	if(lista.size() > 2)
	{
		while ( head != lista.end() )
		{			
			head++;

			while ( head != wall )
			{
				if(*(head) < *(tail))	// condição de ordenação
					mySwap( *(head), *(tail) );
				
				head++;
				tail++;
			}
			head = lista.begin();
			wall = tail;
		}
	}

	for ( 	; ini+1 <= fim ; ini++)
		for (int ord = ini+1;	ord > 0 and v[ord] < v[ord-1];	 ord--)
			mySwap( v[ord], v[ord-1]);
}
*/
#endif