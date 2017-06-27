/**
* @file
* @brief Definição de myLista
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 15/06/2017
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/, http://en.cppreference.com/w/cpp/container/list)
*/

#ifndef MYLISTA_H
#define MYLISTA_H

/**
* @class myLista
* @brief Classe criada para simular a classe std::list da STL do C++, só que já ordenada 
* (neste exemplo, na ordem decrescente)
* @tparam T Tipo dos elementos da lista
*/
template < typename T >
class myLista
{
	private:

		/**
		* @struct myNode
		* @brief Estrutura que define um nó dá lista
		*/
		struct myNode
		{
			T elemento;	/**< Elemento que o nó guarda */
			myNode* anterior; /**< Ponteiro para o nó anterior (no sentido do início) da lista */
			myNode* proximo; /**< Ponteiro para o próximo nó (no sentido do fim) da lista */

			/**
			* @brief Construtor de myNode
			*/
			myNode(const T& data, myNode* prevNode = NULL, myNode* nextNode = NULL)
				:	elemento(data), anterior(prevNode), proximo(nextNode)
			{}

			/**
			* @brief Construtor de myNode
			*/
			myNode(T& data, myNode* prevNode = NULL, myNode* nextNode = NULL)
				:	elemento(data), anterior(prevNode), proximo(nextNode)
			{}
		};

		myNode *sentinela_head;	/**< Ponteiro para o nó do início (head) da lista */
		myNode *sentinela_tail;	/**< Ponteiro para o nó do fim (tail) da lista */
		int qtd_elementos;	/**< A quantidade de elementos armazenados na lista */

	public:

		/**
		* @class const_iterator
		* @brief iterator constante de myLista
		* @sa const no fim da assinatura (https://stackoverflow.com/questions/1549869/)
		*/
		class const_iterator
		{
			public:
				// Construtor
				const_iterator();

				// Acesso
				const T& operator*() const;

				// Movimentação
				const_iterator& operator++ ();	// pré-incrementação
				const_iterator operator++ (int);	// pós-incrementação
				const_iterator& operator-- ();	// pré-decrementação
				const_iterator operator-- (int);	// pós-decrementação

				// Comparação
				bool operator==( const const_iterator & it_direita ) const;
				bool operator!=( const const_iterator & it_direita ) const;

			protected:
				// Construtor
				const_iterator( myNode *ponteiro )
					: atual (ponteiro)
				{} 

				// Atributos
				myNode * atual;	/**< Ponteiro para um nó */

				// Permissão
				friend class myLista<T>;
		};

		/**
		* @class iterator
		* @brief iterator "modificável" de myLista
		* @sa const no fim da assinatura (https://stackoverflow.com/questions/1549869/)
		*/
		class iterator : public const_iterator
		{
			public:
				// Construtor
				iterator()
					: const_iterator()
				{}

				// Acesso ao conteudo do iterator
				const T& operator*() const;
				T& operator*();

				// Movimentação
				iterator& operator++ ();	// pré-incrementação
				iterator operator++ (int);	// pós-incrementação
				iterator& operator-- ();	// pré-decrementação
				iterator operator-- (int);	// pós-decrementação
						
				// Atribuição
				iterator & operator= ( const iterator& it_direita );

			protected:
				// Construtor
				iterator ( myNode *ponteiro)
					: const_iterator(ponteiro)
				{}

				// Permissão
				friend class myLista<T>;	
		};

		// Construtor
		myLista();
		myLista( const myLista & copy );
			
		// Destrutor
		~myLista();

		// Iterator
		const_iterator begin() const;
		iterator begin();
		const_iterator end() const;
		iterator end();

		// Acesso a elementos
		T& front();
		T& back();
			
		// Capacidade
		int size();
		bool empty();

		// Modificadores
		//void push_sorted(const T& elem );
		void push_sorted( T elem );
		void push_back( const T& elem );
		void pop_back();
		void push_front( const T& elem );
		void pop_front();
		void clear();
		void erase( iterator &it );
		//insert()	iterator

		// Operações
		void remove(const T& val);
		void unique();
		// > Auxiliares dos modificadores
		bool exist(const T& elem);
		//sort();

		// Sobrecarga de operadores
		bool operator== ( myLista<T> l_direita);
		bool operator!= ( myLista<T> l_direita);
		myLista<T>& operator= (const myLista<T> copy);
};

#include "myLista_impl.h"

#endif