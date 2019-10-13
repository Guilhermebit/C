#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAX 50

using namespace std;

//prototipo das funcoes
int menu();
int mystrlen(char *s);
int stringsIguais(char *str1, char *str2);

int main(int argc, char *argv[])
{
	int op, n;
	char str1[MAX], str2[MAX];

	cout << "##### Menu de Operacoes com Strings #####\n\n";
	cout << "(1) - Determinar o comprimento de uma String\n";
	cout << "(2) - Verificar se duas strings sao iguais\n";
	cout << "(0) - Sair\n\n";
	cout << "#########################################\n";

	do
	{
		op = menu();
		switch(op)
		{
		case 1:
			cout << "\nDigite a String: ";
			cin.getline(str1, MAX);
			n = mystrlen(str1);
			cout << "A String tem " << n << " caracteres\n";
			break;
		case 2:
			cout << "\nDigite a String 1: ";
			cin.getline(str1, MAX);
			cout << "\nDigite a String 2: ";
			cin.getline(str2, MAX);
			n = stringsIguais(str2, str1);
			if(n == 1)
				cout << "As strings sao iguais\n";
			else
				cout << "As strings sao diferentes";
			break;
		}
		/*if(op != 0 || op == 0)
			cout << "\nSaindo do programa....ate logo\n";*/
	}
	while(op != 0);

	return 0;
}

int menu()
{

	int op;
	char buffer[MAX];

	do
	{
		cout << "\nDigite a Opcao: ";
		cin.getline(buffer, MAX);
		op = atoi(buffer);//string para int

	}
	while(op < 0 || op > 8);
	return op;
}

int mystrlen(char *s)
{

	int i = 0;
	if(s != NULL)
	{
		while(s[i] != '\0')
			i++;
	}
	return i;
}

int stringsIguais(char *s1, char *s2)
{

	int i, x, y;

	x = mystrlen(s1);
	y = mystrlen(s2);

	if(x != y)
		return 0;
	for(i = 0; i < x; i++)
		if(s1[i] != s2[i])
			return 0;
	return 1;//strings iguais

}










