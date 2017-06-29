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
#include "myLista.h"
#include "myLista_alg.h"
#include "myTAD_stats.h"

int Dimensions = 10;


void fill_lista(myLista<int>& test, int N);	/**< Preenche um myLista de inteiros com valores aleatórios entre 0 e 30. */

template< typename T>
void print_lista(myLista<T>& test);

void sort_test(int count, myLista<int>& test, const int N, myTiming **Time_saver, void (*alg_sort) (myLista<int>&));	/**< Preenche um myLista de inteiros com valores aleatorios e depois os ordena utilizando uma função sort */


/**
* @brief Testa os algoritmos de ordenação com listas de interios gerados aleatoriamente e alocados dinamicamente
*/
void testar_ordenacao_lista( )	
{

	// Teste com listas de tamanho 0, 1, 2, 3, 16 e 17.
	
	cout << "(02) Creating array 'sizes' with 10 dimensions...";
	int sizes[10] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};	/*< Arranjo de inteiros que armazenará o tamanho dos listas apontados por 'arrays' */
	//				         1  2  3   4   5   6   7    8    9     10
	
	cout << "(03) Creating myLista...";
	myLista<int> lista;	/**< Ponteiro para myLista de inteiros dinamicamente alocado de tamanho '6' */

	// Criando vetores que armazenaram tempos de execuções
	cout << "(04) Allocating **myTiming...";
	myTiming **TemposmyBubbleSort = new myTiming*[Dimensions];
	myTiming **TemposmyInsertSort = new myTiming*[Dimensions];
	myTiming **TemposmySelectionSort = new myTiming*[Dimensions];

	for (int i = 0; i < Dimensions; ++i)	{	// Para cada dimensão disponivel:
		TemposmyBubbleSort[i] = new myTiming[N_EXECUCOES];	// Cria vetor de durações com tamanho 20.
		TemposmyInsertSort[i] = new myTiming[N_EXECUCOES];
		TemposmySelectionSort[i] = new myTiming[N_EXECUCOES];
	}
	cout << "Done" << endl;
	

	for(auto i = 0; i < Dimensions; i++)
	{
		cout << "=======================================================================================" << endl;
		cout << " Testes com lista de tamanho: ( " << sizes[i] << " )" << endl;
		cout << "---------------- myBubbleSort----------------" << endl;
		sort_test(i,lista, sizes[i],TemposmyBubbleSort, myBubbleSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- myInsertSort----------------" << endl;
		sort_test(i,lista, sizes[i],TemposmyInsertSort, myInsertSort);
		cout << "---------------------------------------------" << endl;
		cout << "---------------- mySelectionSort----------------" << endl;
		sort_test(i,lista, sizes[i],TemposmySelectionSort, mySelectionSort);
		cout << "---------------------------------------------" << endl;
		cout << "=======================================================================================" << endl;
		cout << "\n\t\tV--------------------------------V--------------------------------V\n\n\n";
		cout << "Dimensão finalizada.\n\n";
	}

	// Criando vetores que armazenarão estatisticas sobre tempos de execuções
	cout << "(07) Allocating *myTAD_stats...";
	myTAD_stats *stats_bubble = new myTAD_stats[Dimensions];
	myTAD_stats *stats_insert = new myTAD_stats[Dimensions];
	myTAD_stats *stats_select = new myTAD_stats[Dimensions];
	cout << "Done" << endl;

	// Gerando estatisticas
	cout << "(08) Calculating and storing statistcs at *myTAD_stats...";
	for (int i = 0; i < Dimensions; ++i)
	{
		stats_bubble[i].min = time_peaks(TemposmyBubbleSort[i],Menor);
		stats_insert[i].min = time_peaks(TemposmyInsertSort[i],Menor);
		stats_select[i].min = time_peaks(TemposmySelectionSort[i],Menor);

		stats_bubble[i].max = time_peaks(TemposmyBubbleSort[i],Maior);
		stats_insert[i].max = time_peaks(TemposmyInsertSort[i],Maior);
		stats_select[i].max = time_peaks(TemposmySelectionSort[i],Maior);

		stats_bubble[i].media = sum_times(TemposmyBubbleSort[i]) / N_EXECUCOES;
		stats_insert[i].media = sum_times(TemposmyInsertSort[i]) / N_EXECUCOES;
		stats_select[i].media = sum_times(TemposmySelectionSort[i]) / N_EXECUCOES;

		stats_bubble[i].desvp = desvp_times(TemposmyBubbleSort[i], stats_bubble[i].media);
		stats_insert[i].desvp = desvp_times(TemposmyInsertSort[i], stats_insert[i].media);
		stats_select[i].desvp = desvp_times(TemposmySelectionSort[i], stats_select[i].media);
	}
	cout << "Done" << endl;

	cout << ">>>\tstats:" << endl;
	for (int i = 0; i < Dimensions; ++i)
	{
		cout << "Bubble\t" 
			<< "N = " << sizes[Dimensions] 
			<< ": min=" << stats_bubble[i].min
			<< " max=" << stats_bubble[i].max 
			<< " media=" << stats_bubble[i].media
			<< " desvp=" << stats_bubble[i].desvp << endl;
		cout << "Insert\t" 
			<< "N = " << sizes[Dimensions]
			<< ": min=" << stats_insert[i].min
			<< " max=" << stats_insert[i].max 
			<< " media=" << stats_insert[i].media
			<< " desvp=" << stats_insert[i].desvp << endl;
		cout << "Select\t" 
			<< "N = " << sizes[Dimensions]
			<< ": min=" << stats_select[i].min
			<< " max=" << stats_select[i].max 
			<< " media=" << stats_select[i].media
			<< " desvp=" << stats_select[i].desvp << endl;

	}

	// Gravando estatisticas
	cout << "\n(09) Recording stats files...";
	save_times(stats_bubble, Dimensions, sizes, "data/stats-bubble-l.dat");
	save_times(stats_insert, Dimensions, sizes, "data/stats-insert-l.dat");
	save_times(stats_select, Dimensions, sizes, "data/stats-select-l.dat");
	cout << "Done" << endl;

	// Deletando vA, vB, vC, TempoR, TempoI, stats_bubble, stats_insert e sizes 
	cout << "\nDeleting alocated memory...";
	for (int i = 0; i < Dimensions; ++i)
	{
		delete[] TemposmyBubbleSort[i];
		delete[] TemposmyInsertSort[i];
	}
	delete[] TemposmyBubbleSort;
	delete[] TemposmyInsertSort;
	delete[] stats_bubble;
	delete[] stats_insert;
	cout << "Done" << endl<<endl;
}

/**
* @param test myLista de inteiros a ser preenchida
* @param N tamanho do myLista a ser preenchida
*/
void fill_lista(myLista<int>& test, int N)
{	
	if(test.empty() == false)test.clear();	// limpa a lista antes de preenche-la
	int x;

	srand (time(NULL));		// Usa o tempo de máquina atual como semente para gerar rand()

	for (int i = 0; i < N; ++i)
	{
		x = rand() % 31;
		test.push_front(x);	// Atribui a cada posição 'i' um valor aleatório que pertença a [0,30]
	}
}

/**
* @brief Imprime o conteúdo de um objeto myLista no terminal
* @param test myLista a ser impresso
* @param list_name nome da variável que guarda 'test'
*/
template< typename T>
void print_lista(myLista<T>& test)
{
	cout << "Conteúdo: [ ";
	for (auto &e : test)
		cout << e << " ";
	cout << "]" << endl;
}

/**
* @param test myLista de inteiros
* @param alg_sort ponteiro para a função de ordenação a ser utilizada
*/
void sort_test(int count, myLista<int>& test, const int N, myTiming **Time_saver, void (*alg_sort) (myLista<int>&) )
{
	for(int i = 0; i < 20; i++)
	{
		cout << "Ciclo: " << i-1 << endl;

		cout << "Preenchendo meu myLista de inteiros com valores aleatorios...";
		fill_lista(test,N);	// Preenche myLista com valores aleatorios entre 0 e 30.

		cout << "Pronto." << endl;
		print_lista(test);	// Mostra o conteudo do myLista gerado aleatoriamente no terminal.

		cout << endl << "Ordenando myLista...";
		
		auto start = std::chrono::steady_clock::now();	// Salva o tempo atual do sistema em 'start'
		// CONTAGEM INICIADA =============================================================================

		alg_sort(test);	// Ordena o myLista usando o algoritmo escolhido.

		// CONTAGEM INICIADA =============================================================================
		auto end = std::chrono::steady_clock::now();	// Salva o tempo atual do sistema em 'end'
		auto timing = end - start;	// Salva o tempo que passou entre 'start' e 'end'

		Time_saver[i][count] = std::chrono::duration<double,std::centi> (timing);

		cout << "Pronto." << endl;
		print_lista(test);	// Mostra o conteudo do myLista após ter sido oredenado.
		cout << endl;

		if( count  == 0 ) cout << "\t\t\t\t\t";
			cout << "\t...Ciclo completado"
				<< std::chrono::duration<double,std::centi> (timing).count() <<"cs) ("// << endl;
				<< std::chrono::duration<double,std::deci> (timing).count() <<"ds) ("
				<< std::chrono::duration_cast<std::chrono::seconds> (timing).count() <<"s)" << endl;
	}
}

/**
* @param test myLista de inteiros
* @param alg_search ponteiro para a função de busca a ser utilizada
*/
/*
void search_test(myLista<int>& test, const int N, void (*alg_sort) (myLista<int>&) )
{
	cout << "Preenchendo meu myLista de inteiros com valores aleatorios...";
	fill_lista(test,N);	// Preenche myLista com valores aleatorios entre 0 e 30.

	cout << "Pronto." << endl;
	print_lista(test);	// Mostra o conteudo do myLista gerado aleatoriamente no terminal.

	cout << endl << "Ordenando myLista...";
	alg_sort(test);	// Ordena o myLista usando o algoritmo escolhido.

	cout << "Pronto." << endl;
	print_lista(test);	// Mostra o conteudo do myLista após ter sido oredenado.
	cout << endl;
}
*/

#endif



/*

cout << "---------------- myBinarySearch----------------" << endl;
		cout << (myBuscaBinaria(lista,0)? "Achou ":"Não achou ") << 0 <<endl;
		cout << "---------------------------------------------" << endl;

*/