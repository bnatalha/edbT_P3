/**
* @file
* @brief Testes com myPilha.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 18/06/2017
* @date 20/06/17
*/

#ifndef TESTAR_LISTA_H
#define TESTAR_LISTA_H

#include "Mylista_ligada.h"

template< typename T>
void print_lista(Mylista_ligada<T>& test, const char list_name);

template <typename T >
void test_size_empty(Mylista_ligada<T>& test, const char list_name);

template <typename T >
void try_back(Mylista_ligada<T>& test, const char list_name);

template <typename T >
void try_front(Mylista_ligada<T>& test, const char list_name);

template <typename T >
void try_pop_front(Mylista_ligada<T>& test, const char list_name);

template <typename T >
void try_push_front(Mylista_ligada<T>& test, const char list_name, const T element);

/**
* @brief Realiza testes com objetoss da classe myPilha
*/
void testar_lista()
{
	
	//Criando listas
	cout << "Criando listas A, B, C e D (todas vazias).";
	Mylista_ligada<int> A;
	Mylista_ligada<int> B;
	Mylista_ligada<int> C;
	Mylista_ligada<int> D;
	cout << "Pronto." << endl;

	cout << "------------------------------------------------------------------" << endl;
	cout << "Iniciando testes com listas vazias..." << endl;
	test_size_empty(A, 'A');
	try_front(A,'A');
	try_back(A,'A');
	try_pop_front(A,'A');

	cout << "------------------------------------------------------------------" << endl;
	cout << "Iniciando testes com push_front() e pop_front()..." << endl;
	for (int i = 0; i < 5; i++)
	{
		print_lista(A,'A');
		(try_push_front(A,'A',i));
		i%4 != 0 ? try_front(A,'A') : try_back(A,'A');
	}
	test_size_empty(A,'A');

	cout << "------------------------------------------------------------------" << endl;
	
	// preenchendo listas
	cout << "Preenchendo listas A, D e B para testes..." << endl;
	for (int i = 0; i <= 10; ++i)
	{
		A.push_front(i);
		if(i != 0 )	D.push_front(i);
		else D.push_front(34);
		if(i%2 == 0) B.push_front(i);
	}
	cout << "Pronto." << endl << endl;

	cout << "Atribuindo a lista A à lista C..." << endl;
	C = A;
	cout << "Pronto." << endl;

	cout << "Criando Mylista_ligada E de A usando contrutor...";
	Mylista_ligada<int> E(A);
	cout << "Pronto." << endl; 	

	// imprimindo listas
	cout << "\nConteúdo das listas: " << endl;
	print_lista(A, 'A');
	print_lista(B, 'B');
	print_lista(C, 'C');
	print_lista(D, 'D');
	print_lista(E, 'E');

	//comparando listas
	cout << "------------------------------------------------------------------" << endl;
	cout << "\nComparando as listas:" << endl;
	cout << "A e B" << (A == B?" ":" não ") << "são iguais" << endl;
	cout << "A e C" << (A == C?" ":" não ") << "são iguais" << endl;
	cout << "A e D" << (A == D?" ":" não ") << "são iguais" << endl;	
	cout << "A e E" << (A == E?" ":" não ") << "são iguais" << endl;
	cout << "Direção oposta:" << endl;
	cout << "B e A" << (B == A?" ":" não ") << "são iguais" << endl;
	cout << "C e A" << (C == A?" ":" não ") << "são iguais" << endl;
	cout << "D e A" << (D == A?" ":" não ") << "são iguais" << endl;	
	cout << "E e A" << (E == A?" ":" não ") << "são iguais" << endl;

	// Testando erase e insert

	Mylista_ligada<int>::iterator it = C.begin();
	for (int i = 0; i < 4; i++, it++);

	cout << (*it) << endl;
	it = C.erase_after(it);
	print_lista(C, 'C');
	cout << (*it) << endl;
	it = C.insert_after(it,25);
	print_lista(C, 'C');
	cout << (*it) << endl;

	cout << "Inicio" << endl;
	it = C.begin();
	cout << (*it) << endl;
	it = C.erase_after(it);
	print_lista(C, 'C');
	cout << (*it) << endl;
	it = C.insert_after(it,53);
	print_lista(C, 'C');
	cout << (*it) << endl;

	cout << "Antes do fim" << endl;
	it = C.before_end();
	cout << (*it) << endl;
	it = C.insert_after(it,1234);
	print_lista(C, 'C');
	cout << (*it) << endl;
	it = C.erase_after(it);
	print_lista(C, 'C');
	cout << (*it) << endl;
/*
	cout << "Fim" << endl;
	it = C.end();
	//cout << (*it) << endl;
	it = C.insert_after(it,1234);
	print_lista(C, 'C');
	cout << (*it) << endl;
	it = C.erase_after(it);
	print_lista(C, 'C');
	cout << (*it) << endl;

*/
}


/**
* @brief Imprime o conteúdo de um objeto Mylista_ligada no terminal
* @param test Mylista_ligada a ser impresso
* @param list_name nome da variável que guarda 'test'
*/
template< typename T>
void print_lista(Mylista_ligada<T>& test, const char list_name)
{
	cout << list_name <<": [ ";
	for (auto &e : test)
		cout << e << " ";
	cout << "]" << endl;
}

/**
* @brief Imprime no terminal o tamanho de um objeto Mylista_ligada e se ele está vazio ou não.
* Testa Mylista_ligada<T>::size() e Mylista_ligada<T>::empty()
* @param test Referência para um objeto Mylista_ligada
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void test_size_empty(Mylista_ligada<T>& test, const char list_name)
{
	cout << list_name << ".size(): " << test.size() << "\t";
	cout << "'" << list_name <<"'" << (test.empty()? "":" não") << " está vazia." << endl;
}

/**
* @brief Imprime no terminal o primeiro de um objeto Mylista_ligada, se não cair em uma exceção.
* Testa Mylista_ligada<T>::front().
* @param test Referência para um objeto Mylista_ligada
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_front(Mylista_ligada<T>& test, const char list_name)
{
	// tenta acessar elemento da frente da lista
	try	{
		cout << "Tentando fazer "<< list_name <<".front(): ";
		cout << test.front() << ". ";
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Imprime no terminal o ultimo elemento de um objeto Mylista_ligada, se não cair em uma exceção.
* Testa Mylista_ligada<T>::back().
* @param test Referência para um objeto Mylista_ligada
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_back(Mylista_ligada<T>& test, const char list_name)
{
	// tenta acessar elemento do fim da lista
	try	{
		cout << "Tentando fazer " << list_name <<".back(): ";
		cout << test.back() << "." << endl;
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa Mylista_ligada<T>::pop_front()
* @param test Referência para um objeto Mylista_ligada
* @param list_name Nome da variável que guarda 'test'
*/
template <typename T >
void try_pop_front(Mylista_ligada<T>& test, const char list_name)
{
	// tenta remover o elemento do início da lista
	try	{
		cout << "Tentando fazer "<< list_name << ".pop_front();";
		test.pop_front();
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}

/**
* @brief Testa Mylista_ligada<T>::push_front()
* @param test Referência para um objeto Mylista_ligada
* @param list_name Nome da variável que guarda 'test'
* @param element Elemento a ser acrescentado em 'test'
*/
template <typename T >
void try_push_front(Mylista_ligada<T>& test, const char list_name, const T element)
{
	// tenta colocar um elemento no início da lista
	try	{
		cout << "Tentando fazer " << list_name << ".push_front("<< element << ");" << endl;
		test.push_front(element);
	}
	catch (std::exception &e){
		cout << e.what() << endl;
	}
}


#endif