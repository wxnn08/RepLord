#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int TAM = 1e5+5;
vector<int> v[TAM];
int visitados[TAM];

int solve(int x){
	visitados[x] = 1;
	int maior = 0;
	for(int i=0; i<v[x].size(); i++){
		if(visitados[v[x][i]]==0)
			maior = max(maior, solve(v[x][i]));
	}
	return 1+maior;
}

int main(){
    ios_base::sync_with_stdio(false);
	
    int n, a;
	cin >>n >>a;
	fori(i,1,n){
		int u,p;
		cin >>u >>p;
		v[u].pb(p);
		v[p].pb(u);
	}
    memset(visitados, 0, sizeof visitados);
	cout <<solve(a) <<endl;

    return 0;
}

