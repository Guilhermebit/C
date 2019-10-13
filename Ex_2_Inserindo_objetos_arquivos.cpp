#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

class Produto
{

private:
	int id;
	string nome_prod;

public:
	string& getNome_prod()
	{
		return nome_prod;
	}
	int getId()
	{
		return id;
	}

	void setNome_prod(string& nome_prod)
	{
		this->nome_prod = nome_prod;
	}
	void setId(int id)
	{
		this->id = id;
	}

	//sobrecarga do operador de insercao de dados
	//ostream = output stream - permite escrever uma sequencia de caracteres
	friend ostream& operator<<(ostream& os, const Produto& p)
	{
		os << "\n\n" << p.id << "\n";
		os << p.nome_prod;
		return os;
	}

	//sobrecarga do operador de extracao de dados
	//istream = input stream
	friend istream& operator>>(istream& is, Produto& p)
	{
		is >> p.id >> p.nome_prod;
		return is;
	}
};

char menu()
{
	char resp;

	cout << "Opcao:";
	cin >> resp;
	return resp;
}

int main(int argc, char *argv[])
{
	char resp;
	static int id = 0;
	string nome_prod;
	int qtd_prod = 0;//quantidade de produtos listagem/pesquisa

	//Recupera a Data atual
	time_t mytime;
	mytime = time(NULL);
	struct tm tm = *localtime(&mytime);

	cout << "# GERENCIADOR DE PRODUTOS (1.0) #\n\n";
	cout << "(1) Inserir produtos\n";
	cout << "(2) Listar os produtos\n";
	cout << "(3) Pesquisar Produto\n";
	cout << "(0) Sair\n";
	cout << "# ------------------------------ #\n";

	while(true)
	{
		resp = menu();

		//INSERIR PRODUTOS
		if(resp == '1')
		{
			id++;//id gerado automaticamente
			
			Produto produto;

			ofstream ofs("arquivo.txt", fstream::app);//app = append - adiciona ao final do arquivo
			/*cout << "Digite o id do Produto: ";
			cin >> id;*/
			cout << "Digite o nome do Produto: ";
			cin >> nome_prod;
			cout << endl;

			produto.setId(id); //Arrumar - id deve ser gerado automaticamente
			produto.setNome_prod(nome_prod);

			ofs << produto;

			ofs.close();

		}

		//LISTAR PRODUTOS
		else if(resp == '2')
		{
			Produto p;
			qtd_prod = 0;

			ifstream ifs("arquivo.txt");

			//verifica se o arquivo existe e se é possivel ler
			if(ifs.good())
			{
				cout << "\nData atual: " << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << "\n";
				cout << "|======================================|\n";
				cout << "| ID  | NOME DO PRODUTO | Data Entrada |\n";
				cout << "|======================================|\n";

				//eof - end of file
				//enquanto NÃO chegar ao final do arquivo
				while(!ifs.eof())
				{
					ifs >> p;//faz a extracao dos dados

					cout << "| " << p.getId();
					cout << "   | " << p.getNome_prod() << "\n";
					qtd_prod++;
				}

				cout << "\nTotal de Registros: " << qtd_prod << "\n";
				cout << "===============================\n\n";

				ifs.close();
			}
			else
			{

				cout << "Falha ao abrir o arquivo!\n\n";
			}
		}
		//PESQUISAR PRODUTOS
		else if(resp == '3')
		{

			Produto prod;
			string pesq_nome_prod;
			qtd_prod = 0;

			ifstream ifst("arquivo.txt");

			cout << "\nInforme o Nome do Produto: ";
			cin >> pesq_nome_prod;
			cout << "\n";

			//verifica se o arquivo existe e se é possivel ler
			if(ifst.good())
			{

				cout << "\nPesquisa: " << pesq_nome_prod << "\n\n";
				cout << "|======================================|\n";
				cout << "| ID  | NOME DO PRODUTO | Data Entrada |\n";
				cout << "|======================================|\n";

				//eof - end of file
				//enquanto NÃO chegar ao final do arquivo
				while(!ifst.eof())
				{
					ifst >> prod;//faz a extracao dos dados

					//verifica se o nome informado existe no arquivo
					if(prod.getNome_prod() == pesq_nome_prod)
					{
						//mostra os dados
						cout << "| " << prod.getId();
						cout << "   | " << prod.getNome_prod() << "\n";
						qtd_prod++;
					}
				}

				if(qtd_prod > 0)
				{

					cout << "\nTotal de Registros: " << qtd_prod << "\n";
					cout << "===============================\n";

				}
				else
				{

					cout << "Nenhum registro encontrado.\n\n";

				}

				//se nao encontrou produto / esta fora do loop poque sennao repete a mensagem para cada produto
				/*if(prod.getNome_prod().compare(pesq_nome_prod) != 0)
				{
					cout << "Nenhum produto foi encontrado.\n";
				}*/

				ifst.close();
			}

		}

		//SAIR DO PROGRAMA
		else if(resp == '0')
		{
			cout << "Saindo do programa...ate logo";
			break;
		}
		else
		{
			cout << "Operacao Invalida.\n";
		}
	}

	return 0;
}

















