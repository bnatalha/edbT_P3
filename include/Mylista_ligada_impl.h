/**
* @file
* @brief Implementações de Mylista_ligada
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 28/06/2017
* @date 29/06/2017
* @sa std::foward_list (http://www.cplusplus.com/reference/forward_list/forward_list/)
*/

#ifndef MYLISTALIGADA_IMPL_H
#define MYLISTALIGADA_IMPL_H

#include "Mylista_ligada.h"


// Implementação de Sobrecargas

/**
* @brief Sobrecarga do operador "==". Checa se duas listas são iguais.
* @param l_direita Lista a ser comparada
*/
template <typename T>
bool Mylista_ligada<T>::operator== ( Mylista_ligada<T> l_direita)
{
	if(size() != l_direita.size()) // Se as listas forem de tamanhos diferentes
		return false;	// São diferentes
	
	//else	
	myNode *esq = _head;	// Cria ponteiro para o início desta lista
	myNode *dir = l_direita._head;	// Cria ponteiro para o início da lista a ser comparada
		
	while( esq != NULL )	// Enquanto não chegar ao fim da lista*
	{
		if (esq->elemento != dir->elemento) return false;	// Se o conteúdo dos ponteiros forem diferentes entre sí, não são listas iguais

		esq = esq->proximo;	// Movimento o ponteiro para frente
		dir = dir->proximo;	// Movimento o ponteiro para frente
	}

	return true;

	// *Os dois ponteiros andam na mesma velocidade em listas de tamanhos iguais
}

/**
* @brief Sobrecarga do operador "!=". Checa se duas listas são diferente.
* @param l_direita Lista a ser comparada
*/
template <typename T>
bool Mylista_ligada<T>::operator!= ( Mylista_ligada<T> l_direita)
{
	return ( not( *this == l_direita ) );
}

/**
* @brief Sobrecarga do operador "="
* @param copy Lista a ser copiada
*/
template <typename T>
Mylista_ligada<T>& Mylista_ligada<T>::operator= (const Mylista_ligada<T> copy)
{
	if ( *this != copy )
	{
		clear();	// Destroi os elementos da lista que vai ser modificada
		
		myNode * _pointer = copy._head;
		myNode * _builder;
		myNode * _previous;

		for ( int i = 0; _pointer != NULL; i++)
		{
			_builder = new myNode(_pointer->elemento);	//primeiro nó 
			if(i == 0)	_head = _builder;	//head aponta pro primeiro nó
			if(i > 0)	_previous->proximo = _builder ;
			_tail =_builder;
			_previous = _builder ;
			_pointer = _pointer->proximo;
		}
	}

	qtd_elementos = copy.qtd_elementos;

	return *this;
}


// ====================================================================================================
// ======================================== CONST_ITERATOR ============================================
// ====================================================================================================

// Construtor 

/**
* @brief Constroi um iterador constante vazio
*/
template < typename T >
Mylista_ligada<T>::const_iterator::const_iterator()
{
	atual = NULL;	// Aponta o ponteiro para nó interno do iterator para NULL
}

// Acesso

/**
* @brief Sobrecarga do operador '*' para iteradores constantes
* @return Retorna o nó apontado pelo iterator
*/
template < typename T >
const T& Mylista_ligada<T>::const_iterator::operator*() const
{
	return *(atual)->data;
}


// Incremento e Decremento

/**
* @brief Sobrecarga do operador++ para iteradores constantes (pós-incrementação)
* @return Iterator temporário criado dentro da função
* @sa posfix Increment and decrement (http://www.learncpp.com/cpp-tutorial/97-overloading-the-increment-and-decrement-operators/)
*/
template < typename T >
typename Mylista_ligada<T>::const_iterator Mylista_ligada<T>::const_iterator::operator++(int)
{
	const_iterator temp(atual); // Cria um const_iterator temporário com as informações do iterator usado antes da chamada desta função
	atual = atual->proximo; // Aumenta o valor do iterator usado
	return temp;
}

/**
* @brief Sobrecarga do operador++ para iteradores constantes (pré-incrementação)
* @return Iterator atualizado com a incrementação
* @sa prefix Increment and decrement (http://en.cppreference.com/w/cpp/language/operators)
*/
template < typename T >
typename Mylista_ligada<T>::const_iterator& Mylista_ligada<T>::const_iterator::operator++()
{
	atual = atual->proximo; // iterator usado aponta para o próximo nó da lista
	return *this;
}

// Comparação

/**
* @brief Sobrecarga do operador== para iteradores constantes
* @return Verifica se os iterators estam apontando para o mesmo nó
*/
template < typename T >
bool Mylista_ligada<T>::const_iterator::operator== (const const_iterator& it_direita) const
{
	return (atual == it_direita.atual); 
}

/**
* @brief Sobrecarga do operador!= para iteradores constantes
* @return Verifica se os iterators estam apontando para nós doferentes
*/
template < typename T >
bool Mylista_ligada<T>::const_iterator::operator!= (const const_iterator& it_direita) const
{
	return (atual != it_direita.atual); // Retorne true se os dois atuals são diferentes
}

// ====================================================================================================
// ============================================ ITERATOR ==============================================
// ====================================================================================================

// Acesso

/**
* @brief Sobrecarga do operador* para iteradores não constantes em listas constantes
* @return Valor/elemento armazenado no nó apontado pelo iterator
*/
template < typename T >
const T & Mylista_ligada<T>::iterator::operator* () const
{
	return (this->atual)->elemento; 
}

/**
* @brief Sobrecarga do operador* para iteradores não constantes
* @return Valor/elemento armazenado no nó apontado pelo iterator
*/
template < typename T >
T & Mylista_ligada<T>::iterator::operator* ()
{
	return (this->atual)->elemento;
}

// Incremento e Decremento

/**
* @brief Sobrecarga do operador++ para iteradores constantes (pós-incrementação)
* @return Iterator temporário criado dentro da função
* @sa posfix Increment and decrement (http://www.learncpp.com/cpp-tutorial/97-overloading-the-increment-and-decrement-operators/)
*/
template < typename T >
typename Mylista_ligada<T>::iterator Mylista_ligada<T>::iterator::operator++(int)
{
	iterator temp(this->atual); // Cria um const_iterator temporário com as informações do iterator usado antes da chamada desta função
	this->atual = (this->atual)->proximo; // Aumenta o valor do iterator usado
	return temp;
}

/**
* @brief Sobrecarga do operador++ para iteradores constantes (pré-incrementação)
* @return Iterator atualizado com a incrementação
* @sa prefix Increment and decrement (http://en.cppreference.com/w/cpp/language/operators)
*/
template < typename T >
typename Mylista_ligada<T>::iterator& Mylista_ligada<T>::iterator::operator++()
{
    this->atual = (this->atual)->proximo; // iterator usado aponta para o próximo nó da lista
    return *this;
}

/**
* @brief Sobrecarga do operador= (atribuição)
* @return Valor/elemento armazenado no nó apontado pelo iterator
*/
template < typename T >
typename Mylista_ligada<T>::iterator& Mylista_ligada<T>::iterator::operator=( const iterator& it_direita )
{
	this->atual = it_direita.atual;
	return *this;
}

// ====================================================================================================
// ======================================= ITERATOR_METODOS ===========================================
// ====================================================================================================

/**
* @brief Constrói um const_iterator que aponta para o início da lista (primeiro elemento)
*/
template < typename T>
typename Mylista_ligada<T>::const_iterator Mylista_ligada<T>::begin() const
{
	typename Mylista_ligada<T>::const_iterator cit(_head);
	return cit;
}

/**
* @brief Constrói um iterator que aponta para o início da lista (primeiro elemento)
*/
template < typename T>
typename Mylista_ligada<T>::iterator Mylista_ligada<T>::begin()
{
	typename Mylista_ligada<T>::iterator cit(_head);
	return cit;
}

/**
* @brief Constrói um const_iterator que aponta para o elemento após o último
*/
template < typename T>
typename Mylista_ligada<T>::const_iterator Mylista_ligada<T>::end() const
{
	typename Mylista_ligada<T>::const_iterator cit(NULL);	// NULL = _tail->proximo
	return cit;
}

/**
* @brief Constrói um iterator que aponta para o elemento após o último
*/
template < typename T>
typename Mylista_ligada<T>::iterator Mylista_ligada<T>::end()
{
	typename Mylista_ligada<T>::iterator cit(NULL);	// NULL = _tail->proximo
	return cit;
}

/**
* @brief Constrói um const_iterator que aponta para o elemento após o último
*/
template < typename T>
typename Mylista_ligada<T>::const_iterator Mylista_ligada<T>::before_end() const
{
	typename Mylista_ligada<T>::const_iterator cit(_tail);	// NULL = _tail->proximo
	return cit;
}

/**
* @brief Constrói um iterator que aponta para o último elemento
*/
template < typename T>
typename Mylista_ligada<T>::iterator Mylista_ligada<T>::before_end()
{
	typename Mylista_ligada<T>::iterator cit(_tail);	// NULL = _tail->proximo
	return cit;
}

/**
* @brief ----
*/
template < typename T>
void advance(typename Mylista_ligada<T>::iterator& it, const int x)
{
	if (x >= 0 )
		for(int i=0; i < x; i++) it++;
}


// ====================================================================================================
// ========================================== COSTRUTORES =============================================
// ====================================================================================================

/**
* @brief Constrói uma lista vazia
*/
template < typename T>
Mylista_ligada<T>::Mylista_ligada()
	: _head(NULL), _tail(NULL), qtd_elementos(0)
{}

/**
* @brief Constrói uma lista a partir de uma lista já existente
* @param copy Lista a ser copiada
*/
template < typename T>
Mylista_ligada<T>::Mylista_ligada( const Mylista_ligada & copy )
	: _head(NULL), _tail(NULL), qtd_elementos(copy.qtd_elementos)
{
	myNode * _pointer = copy._head;
	myNode * _builder;
	myNode * _previous;
	
	for ( int i = 0; _pointer != NULL; i++)
	{
		_builder = new myNode(_pointer->elemento);	//primeiro nó 
		if(i == 0)	_head = _builder;	//head aponta pro primeiro nó
		if(i > 0)	_previous->proximo = _builder ;
		_tail =_builder;
		_previous = _builder ;
		_pointer = _pointer->proximo;
	}

}

// ====================================================================================================
// ============================================ DESTRUTOR =============================================
// ====================================================================================================

/**
* @brief Destroi a lista, destruindo seus elementos.
*/
template < typename T>
Mylista_ligada<T>::~Mylista_ligada()
{
	clear();
}

// ====================================================================================================
// ============================================= ACESSO ===============================================
// ====================================================================================================

/**
* @brief Acessa o elemento mais a frente na lista
* @return O elemento do nó apontado pela cabeça;
*/
template < typename T>
T& Mylista_ligada<T>::front()
{
	// exceção caso lista esteja vazia
	if(empty())
		throw std::out_of_range ("[EXCEPTION] front(): Não há elementos na lista");

	return (_head->elemento);
}

/**
* @brief Acessa o elemento no último nó da lista
* @return O elemento do nó apontado pela cauda;
*/
template < typename T>
T& Mylista_ligada<T>::back()
{
	if(empty())
		throw std::out_of_range ("[EXCEPTION] back(): Não há elementos na lista");

	return (_tail->elemento);
}

// ====================================================================================================
// =========================================== CAPACIDADE =============================================
// ====================================================================================================

/**
* @brief Checa se a quantidade de nós da lista
* @return atributo qtd_elementos
*/
template < typename T>
int Mylista_ligada<T>::size()
{
	return qtd_elementos;
}

/**
* @brief Checa se a lista está vazia
*/
template < typename T>
bool Mylista_ligada<T>::empty()
{
	return ( size() == 0 );
}

/**
* @brief Remove todos os elementos da lista, a deixando com tamanho = 0.
*/
template < typename T>
void Mylista_ligada<T>::clear()
{
	while ( !empty() )	// Se tiver mais de um elemento na lista,
	{
		pop_front();
	}
}

// ====================================================================================================
// ======================================== MODIFICADORES =============================================
// ====================================================================================================

/**
* @brief Adiciona um elemento ao início da lista
* @param elem Elemento a ser adicionado ao início da lista
*/
template < typename T>
void Mylista_ligada<T>::push_front( const T& elem )
{
	myNode *new_node;

	//tenta alocar um novo nó
	try	{
		new_node = new myNode(elem, _head);	// Cria um novo nó dinamicamente com o elemento adicionado, com o próximo dele sendo o primeiro atual (apontado pela cabeça)
	}catch (std::bad_alloc& ba)		{
		cout << "bad_alloc caught: " << ba.what() << endl;
	}

	if ( empty() ) 
		_tail = new_node;

	//new_node->proximo = _head;
	_head = new_node;

	qtd_elementos++;	// Total de elementos da lista aumenta	
}

/**
* @brief Remove um elemento do início lista, se está não estiver vazia
* @retval true Se um elemento foi retirado
* @retval false Se a lista for vazia
*/
template < typename T>
void Mylista_ligada<T>::pop_front()
{
	if (empty())
		throw std::length_error ("[EXCEPTION] pop_back(): Não pode remover elementos de uma lista vazia");

	myNode *_destruir = _head;	// Atribui o endereço apontado pela cabeça a um ponteiro
	_head = _head->proximo;	// A cabeça agora aponta para o *segundo* nó (ou null, se tamanho da lista for 1)

	if (size() == 1 )	// Se a lista possuir apenas um elemento
		_tail = NULL;	// Aponta a cauda para NULL
	
	delete _destruir;	// Deleta o elemento que era o primeiro da lista

	qtd_elementos--;	// Total de elementos da lista diminui	
}

// ====================================================================================================
// ========================================== OPERAÇÕES ===============================================
// ====================================================================================================

/**
* @brief Destroi o nó apontado por um iterator
* @param it iterator da lista que aponta qual nó será destruído
*/
template < typename T>
typename Mylista_ligada<T>::iterator Mylista_ligada<T>::erase_after( Mylista_ligada<T>::iterator &it )
{
	myNode *_pointer = (it.atual);	// _pointer aponta para o mesmo nó que o iterator it;
	myNode *_destruir;	// Ponteiro para o nó a ser destruído.
	typename Mylista_ligada<T>::iterator _retorno = it;
		
	if(_pointer->proximo != NULL)		
	{
		_destruir = _pointer->proximo;
		_pointer->proximo = _pointer->proximo->proximo;
		delete _destruir;
		
		qtd_elementos--; // Diminui o contador de elementos da lista
		
		_retorno++;
		
	}
	return _retorno;	// retorna o iterator avançado

}

template < typename T>
typename Mylista_ligada<T>::iterator Mylista_ligada<T>::insert_after( Mylista_ligada<T>::iterator &it, T elem )
{

	Mylista_ligada<T>::iterator _retorno = it;	// Cria iterator a partir do passado

	if( empty() )	// Se a lista estiver vazia
	{
		push_front(elem);
		return begin();
	}
	
	myNode * new_node;

	try	{
		new_node = new myNode(elem);	// Cria um novo nó dinamicamente com o elemento a ser adicionado
	}catch (std::bad_alloc& ba)		{
		cout << "bad_alloc caught: " << ba.what() << endl;
	}

	//Ligar novo nó a lista
	new_node->proximo = _retorno.atual->proximo;
	_retorno.atual->proximo = new_node;
	_retorno++;	

	// Aumenta tamanho da lista
	qtd_elementos++;

	return _retorno;	// Retorna iterator que aponta pro nó do elemento inserido
	
}

/**
* @brief Verifica se um elemento já existe na lista
* @param elem Valor buscado para ser removido
*/
template < typename T>
bool Mylista_ligada<T>::exist(const T& elem)
{
	myNode * _pointer = _head;	// Cria ponteiro para o início da lista, a partir da sentinela da cabeça

	while(_pointer != NULL)	// Percorre toda a lista
	{
		if(_pointer->elemento == elem) return true;	// Se encontrar o valor, retorna true
		_pointer = _pointer->proximo;	// Avança para o próximo nó em direção a cauda da lista
	}

	return false;	// Se não encontrar o valor, retorna falso
}

#endif