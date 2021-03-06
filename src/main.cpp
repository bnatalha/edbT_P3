/**
* @file
* @brief Onde fica a função principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 13/06/2017
* @date 20/06/17
*/

#include "header.h"
#include "testar_ordenacao.h"
//#include "testar_ord_dupla.h"
#include "testar_lista.h"

/**
* @brief Solicita ao usuário se ele deseja proceder com um determinado teste do namespace edb1;
* @param testname Nome da estrutura/classe/algoritmo que será testado
*/
bool proceder(const char* testname)
{
	char answer = 'x';
	cout << "Proceder com teste de "<< testname <<"? ";
	do
	{
		if( answer != 'y' and answer != 'n' ) cout << "Digite 'y' para sim e 'n' para não. >>";
		cin >> answer;
	}while (answer != 'y' and answer != 'n' );
	
	if(answer == 'y') return true;
	else return false;
}

/**
* @brief Realiza testes com os objetos/algoritmos do namespace edb1
*/
int main(int argc, char const *argv[])
{	
	cout << "Testando TADS:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	/*if( proceder("myLista") )
	{
		cout << "================ Mylista_ligada =================" << endl;
		testar_lista();
		cout << "=======================================fim" << endl;
	}
	
	if( proceder("algoritmos de ordenação") )
	{
	*/	cout << "Testando algoritmos de ordenação:" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		testar_ordenacao();
		//testar_ordenacao_dupla();
	//}
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------FIM-------------------------------------" << endl << endl;
	
	cout << "Saindo do programa de testes..." << endl;
	return 0;
}