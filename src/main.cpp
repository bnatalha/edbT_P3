/**
* @file
* @brief Onde fica a função principal.
* @author Natália Azevedo de Brito (https://github.com/bnatalha)
* @since 13/06/2017
* @date 20/06/17
*/

#include "header.h"
#include "testar_ordenacao.h"
//#include "testar_lista.h"

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

	auto comeco = std::chrono::steady_clock::now();


	cout << "Testando TADS:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "================ Mylista_ligada =================" << endl;
	cout << "Testando algoritmos de ordenação:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	testar_ordenacao_lista();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------FIM-------------------------------------" << endl << endl;
	
	auto fim = std::chrono::steady_clock::now();

	auto total = fim - comeco;

	auto tempo = std::chrono::duration_cast<std::chrono::minutes> (total);

	if(tempo.count() > 0 ) cout << tempo.count() << "minutes and";
	cout << std::chrono::duration_cast<std::chrono::seconds> (total).count() % 60 << "seconds." << endl;
	
	cout << "Saindo do programa de testes..." << endl;
	return 0;
}