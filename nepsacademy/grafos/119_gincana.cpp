#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int TAM = 1e3 + 5;
vector<int> alunos[TAM]; 
int visitados[TAM];

void dfs(int no){
	
	visitados[no]=1;
	for(int i=0; i<alunos[no].size(); i++){
		if(visitados[alunos[no][i]]==0){
			dfs(alunos[no][i]);
		}
	}
	return;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
	cin >>n >>m;
	int aux1, aux2;
	fori(i, 0, m){
		cin >>aux1 >>aux2;
		alunos[aux1].pb(aux2);
		alunos[aux2].pb(aux1);
	}
	
	int cont=0;
	memset(visitados, 0, sizeof(visitados));
	for(int i=1; i<=n; i++){
		if(visitados[i]==0){
			dfs(i);
			cont++;
		}
	}

	cout <<cont <<endl;
    
    return 0;
}

