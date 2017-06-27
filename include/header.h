/**
* @file
* @brief Cabeçário principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 13/06/2017
* @date 20/06/17
*/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>	//	para cout(), cin(), endl(), cerr();
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#include <cstdlib>	//	para exit(), srand(), rand();

#include <string>	
using std::string;

#include <ostream>
using std::ostream;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <stdexcept>


// Algoritmos de ordenação

void mySwap( int &a, int &b);

bool maiorque(int a, int b);
bool menorque(int a, int b);

void myBubbleSort (int *v, int ini, int fim);	// crescente
	
void myInsertSort (int *v, int ini, int fim);	// crescente

void mySelectionSort (int *v, int ini, int fim);	//
	
int myQuickSortPartition(int *v, int ini, int fim);
void myQuickSort (int *v, int ini, int fim);
	
void mySplitSort (int *v, int ini, int fim);
void myMergeSort (int *dir, int d_size, int *esq, int e_size, int *v, int fim);


#endif
