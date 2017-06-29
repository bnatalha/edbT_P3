/**
* @file
* @brief Implementações de myLista
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 28/06/2017
* @date 29/06/2017
*/

#ifndef MYLISTA_ALG_H
#define MYLISTA_ALG_H

#include "header.h"
#include "myLista.h"

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
bool Lista_BuscaSequencial(myLista<T>& lista, const T elemento)
{
	return lista.exist(elemento);
}

/*
template <typename T>
bool Lista_BuscaBinaria(myLista<T>& lista, const T elemento)
{
	typename myLista<T>::iterator p = lista.begin();	// Cria iterator apontando para begin
	typename myLista<T>::iterator ini = lista.begin();
	typename myLista<T>::iterator fim = lista.b_end();

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
* @param lista myLista<int> que será ordenada
*/
void myBubbleSort(myLista<int>& lista)
{	
	typename myLista<int>::iterator head = lista.begin();
	typename myLista<int>::iterator tail;
	typename myLista<int>::iterator wall = lista.end();

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
* @param lista myLista<int> que será ordenada
*/
void myInsertSort(myLista<int>& lista){
	if(lista.size() >= 2 )
	{
		typename myLista<int>::iterator ini = lista.begin();
		typename myLista<int>::iterator ini_plus = ini;
		ini_plus++;
		typename myLista<int>::iterator ord;
		typename myLista<int>::iterator ord_minus;

		if(lista.size() == 2)
		{
			if(*(ini) < *(ini_plus))	// condição de ordenação
				mySwap( *(ini), *(ini_plus) );
		}

		if(lista.size() > 2)
		{
			while ( ini_plus != lista.end() )
			{
				ord = ini_plus;
				ord_minus = ord;
				ord_minus--;
				while ( ord != lista.begin() and *(ord) < *(ord_minus) )
				{
					mySwap( *(ord), *(ord_minus) );
					ord--;
					ord_minus = ord;
					ord_minus--;
					
				}
				ini++;
				ini_plus = ini;
				ini_plus++;
			}
		}
	}
}

/**
* @brief Simula o selection sort, ordenando uma lista de int o deixando crescente.
* @param lista myLista<int> que será ordenada
*/
void mySelectionSort(myLista<int>& lista){
	if(lista.size() >= 2 )
	{
		typename myLista<int>::iterator ini = lista.begin();
		typename myLista<int>::iterator ini_plus = ini;
		ini_plus++;
		typename myLista<int>::iterator ord;

		if(lista.size() == 2)
		{
			if(*(ini) < *(ini_plus))	// condição de ordenação
				mySwap( *(ini), *(ini_plus) );
		}

		if(lista.size() > 2)
		{
			while ( ini_plus != lista.end() )
			{
				ord = ini_plus;
				while ( ord != lista.end() )
				{
					if( *(ini) > *(ord) ) mySwap( *(ini), *(ord) );
					ord++;					
				}
				ini++;
				ini_plus = ini;
				ini_plus++;
			}
		}
	}
}

/**
* @brief Cria as partições que serão utilizadas por myQuickSort
* @param lista myLista<int> que será ordenada
*/
typename myLista<int>::iterator myQuickSortPartition(myLista<int>& lista, typename myLista<int>::iterator ini, typename myLista<int>::iterator fim ){
	typename myLista<int>::iterator myPivot = ini;
	typename myLista<int>::iterator myPivot_plus = myPivot;
	myPivot_plus++;
	typename myLista<int>::iterator menor = myPivot_plus;
	typename myLista<int>::iterator Maior = fim;
	typename myLista<int>::iterator Maior_minus = Maior;
	Maior_minus--;

	while ( Maior_minus != menor  )
	{
		if( *(menor)  >=  *(Maior) and menor != Maior ) mySwap( *(menor), *(Maior));
		if( *(myPivot) >=  *(menor) )
		{
			mySwap( *(menor), *(myPivot));
			menor++;
			myPivot++;
		}
		if( *(myPivot) <  *(Maior) ) Maior--; Maior_minus--;
	}

	return myPivot;
}

/**
* @brief Simula o quick sort, ordenando um myLista de int o deixando crescente.
* @param lista myLista<int> que será ordenada
*/
void myQuickSort(myLista<int>& lista, typename myLista<int>::iterator ini, typename myLista<int>::iterator fim ){

	//if(lista.size() >=2 )
	//{
		//typename myLista<int>::iterator ini_plus = ini;
		//ini_
		//if( ini != fim and ini >= 0){
		if( ini != fim and ini != lista.end()){
			typename myLista<int>::iterator p = myQuickSortPartition(lista,ini,fim);

			typename myLista<int>::iterator p_minus = p;
			typename myLista<int>::iterator p_plus = p;
			p_minus--;
			p_plus++;

			myQuickSort(lista, ini, p_minus);
			myQuickSort(lista, p_plus, fim);
		}
	//}
}

#endif