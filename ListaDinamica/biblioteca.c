#include "biblioteca.h"

//Fun��o menu com as op��es
void menu()
{
	printf("\tLista Dinamica\n");
	printf(" 1 - Inserir Numero\n");
	printf(" 2 - Buscar Numero\n");
	printf(" 3 - Imprimir Todos os Numeros\n");
	printf(" 4 - Imprimir Tamanho da Lista\n");
	printf(" 5 - Verifica Numeros Par/Impar\n");
	printf(" 6 - Excluir Numero\n");
	printf(" 0 - Sair\n");
}

//Fun��o que criar a lista 
Dados*criar()
{
	return NULL;
}

//Fun��o para inserir um numero
Dados*inserir(Dados *list, int num)//Recebe a lista criada e o numero que a ser adicionado, como par�metros
{
	Dados*novo = (Dados*)malloc(sizeof(Dados));//Alocando mem�ria para vari�veis do tipo Dados
	novo->num = num;//Novo que aponta pra num recebe o numero passado como par�metro e armazena
	novo->proximo = list;//Novo que aponta pra proximo armazena a lista
	return novo;//Retorna a vari�vel criada

}

//Fun��o para imprimir todos os numeros inseridos na lista
void imprimir(Dados *list)//A fun��o recebe a lista como par�metro
{
	Dados *i;//Vari�vel de controle para o la�o de repeti��o, do tipo Dados
	//i recebe o inicio da lista, repeti enquanto for diferente de NULL, passa para o proximo 
	for(i = list; i != NULL; i = i->proximo)
	{
		printf("Numero: %d \n", i->num);//Imprime o numero
	}

}

//Fun��o para excluir um numero da lista
Dados *excluir(Dados*list, int num)//Recebe a lista criada e o numero que a ser adicionado, como par�metros
{
	Dados *ant = NULL;//declara um variavel anterior para fazer o deslocamento quando um numero for excluido no inicio da lista
	Dados *i = list;//Vari�vel de controle para o la�o de repeti��o, do tipo Dados
	
	while(i != NULL && i->num == num)//vai repetir enquanto i for diferente de NULL, e i que aponta pra num igual a num
	{
		//deslocar uma posicao para tr�s
		ant = i;//anterior recebe o valor de i
		i = i->proximo;//i recebe i que aponta para o proximo
	}
	
	if(i == NULL)//se i for iagual a NULL so vai retornar a lista
	{
		return list;
	}
	if(ant == NULL)//se anterior igual a NULL a lista recebe o proximo numero da lista
	{
		list = i->proximo;
	}
	else//anterior recebe o proximo numero
	{
		ant->proximo = i->proximo;
	}

	free(i);//libera a varialvel i
	printf("Excluido!!!!!\n");
	return list;//retorna a lista

}

//Fun��o que percorre o vetor e mostra se o numero e par ou impar
void verificaParImpar(Dados *list)
{
	Dados *i;//Vari�vel de controle para o la�o de repeti��o, do tipo Dados
	//i recebe o inicio da lista, repeti enquanto for diferente de NULL, passa para o proximo 
	for(i = list; i != NULL; i = i->proximo)
	{
		if(i->num % 2 == 0)//se o resto da divis�o de i que aponta pra num for zero imprime par
		{
			printf("Numero: %d e Par!\n", i->num);
		}
		else//se o resto da divis�o de i que aponta pra num for zero imprime impar
		{
			printf("Numero: %d e Impar!\n",  i->num);
		}
	}
}

//Fun��o para buscar um numero na lista
int buscar(Dados *list, int num)
{
	Dados *i;//Vari�vel de controle para o la�o de repeti��o, do tipo Dados
	//i recebe o inicio da lista, repeti enquanto for diferente de NULL, passa para o proximo
	for(i = list; i != NULL; i = i->proximo)
	{
		if(i->num == num)//comparar um numero digitado com o numero que esta na lista
		{
			return i->num;
			//printf("Numero: %d Encontrado!!\n", i->num);//imprime numero se encontrar
		}
	}
	return 0;
}

//Fun��o para calcular o tamanho da lista
int tamanhoLista(Dados *list)
{

	Dados *i;//Vari�vel de controle para o la�o de repeti��o, do tipo Dados 
	int cont = 0;//variavel contador

	if(list == NULL)//verifica se a lista e valida
	{
		return 0;//retorna 0 se nao estiver nada na lista
	}
	//i recebe o inicio da lista, repeti enquanto for diferente de NULL, passa para o proximo
	for(i = list; i != NULL; i = i->proximo)
	{
		cont++;//soma +1 enquanto a lista for diferente de NULL
	}

	return cont;
}






