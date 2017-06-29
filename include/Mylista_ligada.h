/**
* @file
* @brief Definição de Mylista_ligada
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 28/06/2017
* @date 29/06/2017
* @sa std::foward_list (http://www.cplusplus.com/reference/forward_list/forward_list/)
*/

#ifndef MYLISTALIGADA_H
#define MYLISTALIGADA_H

#include "header.h"

/**
* @class Mylista_ligada
* @brief Classe criada para simular a classe std::list da STL do C++, só que já ordenada 
* (neste exemplo, na ordem decrescente)
* @tparam T Tipo dos elementos da lista
*/
template < typename T >
class Mylista_ligada
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
			myNode(const T& data, myNode* nextNode = NULL)
				:	elemento(data), proximo(nextNode)
			{}

			/**
			* @brief Construtor de myNode
			*/
			myNode(T& data, myNode* nextNode = NULL)
				:	elemento(data), proximo(nextNode)
			{}
		};

		myNode *_head;	/**< Ponteiro para o nó do início (head) da lista */
		myNode *_tail;	/**< Ponteiro para o nó do fim (tail) da lista */
		int qtd_elementos;	/**< A quantidade de elementos armazenados na lista */

	public:

		/**
		* @class const_iterator
		* @brief iterator constante de Mylista_ligada
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
				friend class Mylista_ligada<T>;
		};

		/**
		* @class iterator
		* @brief iterator "modificável" de Mylista_ligada
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
						
				// Atribuição
				iterator & operator= ( const iterator& it_direita );

			protected:
				// Construtor
				iterator ( myNode *ponteiro)
					: const_iterator(ponteiro)
				{}

				// Permissão
				friend class Mylista_ligada<T>;	
		};

		// Construtor
		Mylista_ligada();
		Mylista_ligada( const Mylista_ligada & copy );
			
		// Destrutor
		~Mylista_ligada();

		// Iterator
		const_iterator begin() const;
		iterator begin();
		const_iterator end() const;
		iterator end();
		const_iterator before_end() const;
		iterator before_end();

		// Acesso a elementos
		T& front();
		T& back();
			
		// Capacidade
		int size();
		bool empty();

		// Modificadores
		void push_front( const T& elem );
		void pop_front();
		void clear();
		iterator erase_after( iterator &it );
		iterator insert_after( iterator &it, T elem );

		// Operações
		//void remove(const T& val);
		//void unique();
		bool exist(const T& elem);
		//sort();

		// Sobrecarga de operadores
		bool operator== ( Mylista_ligada<T> l_direita);
		bool operator!= ( Mylista_ligada<T> l_direita);
		Mylista_ligada<T>& operator= (const Mylista_ligada<T> copy);

		//===============================================================================

		//auxiliares
		//iterator before_end();
		void advance(iterator& it, const int x);

		//amigos
		//friend bool Lista_BuscaBinaria(Mylista_ligada<T>& lista, const T elemento);
};

#include "Mylista_ligada_impl.h"

#endif