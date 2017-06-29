#ifndef MYVECTOR_INL
#define MYVECTOR_INL

#include "myvector.h"

template<typename Object>
Myvetor<Object>::Myvetor(const int &_size) : capacidade(_size), limite(0)
{
	vetor = new Object[capacidade];
}

template<typename Object>
Myvetor<Object>::~Myvetor()
{
	delete[] vetor;
}

template<typename Object>
Object Myvetor<Object>::front()
{
	return vetor[0];
}

template<typename Object>		
Object Myvetor<Object>::back()
{
	return vetor[ limite -1 ];
}

template<typename Object>
void Myvetor<Object>::push_back( const Object& elem )
{
	if (limite == capacidade)
		resize();

		vetor[limite] = elem;
		limite++;

}

template<typename Object>
void Myvetor<Object>::pop_back()
{
	limite--;
}

template<typename Object>		
void Myvetor<Object>::push_front( const Object& elem )
{ 
	if ( limite == capacidade ) 
		resize();
	for(int i = limite; i >=0; i-- )
		vetor[i] = vetor[i-1];
	vetor[0] = elem;
	limite++;		 
}

template<typename Object>	
void Myvetor<Object>::pop_front()
{
	//retira o primeiro elemento
	for (int i = 0;i<limite-1;i++)
		vetor[i] = vetor[i+1];
	limite--;
}

template<typename Object>		
void Myvetor<Object>::clear()
{
	limite = 0;
}

template<typename Object>
void Myvetor<Object>::resize(){
         	Object *pt = new Object[2*capacidade];
         	for ( auto i(0); i< capacidade ; i++){
            		pt[i] = vetor[i];
         	}
	 		capacidade = 2*capacidade ;
         	delete [] vetor; 
         	vetor = pt;
}

template<typename Object>
int Myvetor<Object>::size()
{
	return capacidade;
}

template<typename Object>		
bool Myvetor<Object>::empty()
{
	return limite == 0;
}
template<typename Object>
void Myvetor<Object>::print ()
{
	cout<< "V = [ ";
	for (int i = 0; i < limite; i++ )
		cout << vetor[i] << " ";
	cout << "]" << endl;
}

#endif