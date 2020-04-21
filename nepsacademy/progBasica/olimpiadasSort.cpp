#include <bits/stdc++.h>
using namespace std;

struct Pais{
	int id, ouro = 0, prata = 0, bronze = 0;
};

bool ordena_pais(Pais a, Pais b){

	if(a.ouro != b.ouro)
		return a.ouro>b.ouro;

	if(a.prata != b.prata)
		return a.prata>b.prata;
	
	if(a.bronze != b.bronze) return a.bronze>b.bronze; return a.id<b.id;
}

int main(){
	int n, m;
	cin >>n >>m;

	Pais pais[110];
	int aux;
	
	for(int i=0; i<n; i++)
		pais[i].id = i;

	for(int i=0; i<m; i++){
		cin >>aux;
		pais[aux-1].ouro++;
		cin >>aux;
		pais[aux-1].prata++;
		cin >>aux;
		pais[aux-1].bronze++;
	}
	
	sort(pais, pais+n, ordena_pais);

	for (int i=0; i<n; i++)
		cout << pais[i].id+1 << " ";

	cout <<endl;

	return 0;
}
