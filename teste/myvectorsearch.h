#ifndef _MYVECTORSEARCH_h_
#define _MYVECTORSEARCH_h_
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

template<typename Object>
long int busca_sequencial_iterativa(vector<Object> *vetor, const Object key, long int left, long int rigth )
{
	for (int i = left; i<rigth; i++)
	{
		if( vetor[i] == key ) return i;

	}
	return -1;

	/*
	 * >>> Algoritmo implementado para busca binária iterativa
 	 */
}

template<typename Object>
long int busca_binaria_recursiva(vector<Object> *vetor, const Object key, long int left, long int rigth )
{
	long int media = (left+rigth)/2;
	if (vetor[media] == key ) return media;
	if ( vetor[media] > key ) return busca_binaria_iterativa( vetor, key, left, media-1);
	if ( vetor[media] < key ) return busca_binaria_iterativa( vetor, key, media+1, rigth);
	return -1;

}

template <typename  Object>
void randomFill(vector<Object> &V, const int size, const int seed )
{
    //unsigned int small = 0, bigger = 1000;
    default_random_engine eng(seed);
    uniform_real_distribution <double> distr(0, 1000);
    for(int x=0;x<size;x++)
        V[x] = distr(eng);

}

template <typename  Object>
void print (vector<Object> &V)
{
	cout << "V = [ ";
	for ( auto &e : V )
		cout << e << " ";
	cout << "]";
}


#endif