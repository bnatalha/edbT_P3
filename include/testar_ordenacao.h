/**
* @file
* @brief Implementação das funções que testam os algoritmos de ordenação do namespace edb1
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 26/03/2017
* @date 20/06/17
*/

#ifndef TESTAR_ORDENACAO_H
#define TESTAR_ORDENACAO_H

#include <ctime>
#include "header.h"
#include "Mylista_ligada_alg.h"


void fill_lista(Mylista_ligada<int>& test, int N);	/**< Preenche um Mylista_ligada de inteiros com valores aleatórios entre 0 e 30. */

template< typename T>
void print_lista(Mylista_ligada<T>& test);

void sort_test(Mylista_ligada<int>& test, const int N, void (*alg_sort) (Mylista_ligada<int>&));	/**< Preenche um Mylista_ligada de inteiros com valores aleatorios e depois os ordena utilizando uma função sort */

/**
* @brief Testa os algoritmos de ordenação com listas de interios gerados aleatoriamente e alocados dinamicamente
*/
void testar_ordenacao( )	
{

	// Teste com listas de tamanho 0, 1, 2, 3, 16 e 17.
	
	int sizes[6] = {0, 1, 2, 3, 16, 17};	/*< Arranjo de inteiros que armazenará o tamanho dos listas apontados por 'arrays' */
	//				0  1  2  3   4   5
	
	Mylista_ligada<int> lista;	/**< Ponteiro para Mylista_ligada de inteiros dinamicamente alocado de tamanho '6' */

	for(auto i = 0; i < 6; i++)
	//for(auto i = 0; i <= 4; i++)
	{
		cout << "=======================================================================================" << endl;
		cout << " Testes com vetor de tamanho: ( " << sizes[i] << " )" << endl;
		cout << "---------------- myBubbleSort----------------" << endl;
		sort_test(lista, sizes[i], myBubbleSort);
		cout << "---------------------------------------------" << endl;
	/*	cout << "---------------- myInsertSort----------------" << endl;
		sort_test(lista, sizes[i], myInsertSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- mySelectionSort----------------" << endl;
		sort_test(lista, sizes[i], mySelectionSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- myQuickSort----------------" << endl;
		sort_test(lista, sizes[i], myQuickSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- mySplitSort----------------" << endl;
		sort_test(lista, sizes[i], mySplitSort);
		cout << "---------------------------------------------" << endl;
	*/	cout << "=======================================================================================" << endl;
	}
}

/**
* @param v Mylista_ligada de inteiros a ser preenchida
* @param N tamanho do Mylista_ligada a ser preenchida
*/
void fill_lista(Mylista_ligada<int>& test, int N)
{	
	test.clear();	// limpa a lista antes de preenche-la
	int x;

	srand (time(NULL));		// Usa o tempo de máquina atual como semente para gerar rand()

	for (int i = 0; i < N; ++i)
	{
		x = rand() % 31;
		test.push_front(x);	// Atribui a cada posição 'i' um valor aleatório que pertença a [0,30]
	}
}

/**
* @brief Imprime o conteúdo de um objeto Mylista_ligada no terminal
* @param test Mylista_ligada a ser impresso
* @param list_name nome da variável que guarda 'test'
*/
template< typename T>
void print_lista(Mylista_ligada<T>& test)
{
	cout << "Conteúdo: [ ";
	for (auto &e : test)
		cout << e << " ";
	cout << "]" << endl;
}

/**
* @param v Mylista_ligada de inteiros
* @param alg_sort ponteiro para a função de ordenação a ser utilizada
*/
void sort_test(Mylista_ligada<int>& test, const int N, void (*alg_sort) (Mylista_ligada<int>&) )
{
	cout << "Preenchendo meu Mylista_ligada de inteiros com valores aleatorios...";
	fill_lista(test,N);	// Preenche Mylista_ligada com valores aleatorios entre 0 e 30.

	cout << "Pronto." << endl;
	print_lista(test);	// Mostra o conteudo do Mylista_ligada gerado aleatoriamente no terminal.

	cout << endl << "Ordenando Mylista_ligada...";
	alg_sort(test);	// Ordena o Mylista_ligada usando o algoritmo escolhido.

	cout << "Pronto." << endl;
	print_lista(test);	// Mostra o conteudo do Mylista_ligada após ter sido oredenado.
	cout << endl;
}

#endif