#ifndef MYLISTA_H
#define MYLISTA_H
#include <iostream>
#include <algorithm>
using namespace std;


template <typename Object>
class Myvetor {

	public:
		Myvetor( const int &_size);
		~Myvetor();

		Object front();
		
		Object back();
				
		// Capacidade
		int size();
		
		bool empty();
		// Modificadores
		
		
		void push_back( const Object& elem );
		
		void pop_back();
		
		void push_front( const Object& elem );
		
		void pop_front();
		
		void clear();
		
		void resize();

		void print();

		//void erase( iterator &it );
	private:
		Object *vetor;
		int capacidade;
		int limite;			


};

#include "myvector.inl"
#endif