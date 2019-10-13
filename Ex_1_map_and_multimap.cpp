#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, string> mapa;
	
	mapa[1] = "joao";
	mapa[2] = "joao";
		
	if(mapa.empty())
		cout << "Mapa Vazio!!\n" << endl;
	else
	    cout << "Mapa NAO vazio!!\n" << endl;
	
	if(mapa.count(1) > 0)
	    cout << "1 eh elemento do mapa\n";
	else
	
	    cout << "1 NAO eh elemento do mapa\n";
	
    cout << "\nUtilizando map\n";
	map<int, string>::iterator it;
	for(it = mapa.begin(); it != mapa.end(); ++it) 
		cout << "A chave " << it->first << " => " << it->second << endl;
	
	//utilizando multimap
	multimap<int, string> mm;
	
	cout << "\nUtilizando multimap\n";
	mm.insert(pair<int, string>(1, "python 2"));
	mm.insert(pair<int, string>(1, "python 3"));
	mm.insert(pair<int, string>(2, "C"));
	mm.insert(pair<int, string>(3, "C++"));
	
	multimap<int, string>::iterator it2 = mm.begin();
	
	while(it2 != mm.end()) {
		cout << (*it2).first << " => " << (*it2).second << endl;
		it2++;
	}
	
	
	return 0;
}
