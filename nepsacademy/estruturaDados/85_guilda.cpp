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

const int MAX = 1e5+5;
int qtd[MAX], pai[MAX], peso[MAX];

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);

	if(x == y) return;

	if(peso[x] > peso[y]) {
		pai[y] = x;
		qtd[x] += qtd[y];
	}
	else if(peso[x] < peso[y]) {
		pai[x] = y;
		qtd[y] += qtd[x];
	}
	else {
		pai[x] = y;
		peso[y]++;
		qtd[y] += qtd[x];
	}
	return;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
	cin >>n >>m;
	while(n!=0 || m!=0) {
		fori(i,1,n+1) cin >>qtd[i];
		fori(i,1,n+1) pai[i] = i;
		memset(peso, 0, sizeof peso);
		int win = 0;

		fori(i, 0, m) {
			int op, x, y;
			cin >>op >>x >>y;
			if(op == 1) join(x, y);
			if(op == 2) {
				x = find(x);
				y = find(y);
				int jog = find(1);
				if((jog == x && qtd[x] > qtd[y]) or (jog == y && qtd[y] > qtd[x])){
					win++;
				}
			}
		}

		cout <<win <<endl;

		cin >>n >>m;
	}
    
    return 0;
}

