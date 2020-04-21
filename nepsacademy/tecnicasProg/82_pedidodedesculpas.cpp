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

int n, qtd;
const int TAM = 1e3+5;

int tam[52];
int des[52];
int dp[TAM][52];

int solve (int resto, int pos) {
	if(resto<0) return -INF;
	if(pos>=qtd) return 0;

	int &r = dp[resto][pos];
	if(r != -1) return r;

	int L = des[pos] + solve(resto-tam[pos], pos+1);
	int R = solve(resto, pos+1);
	
	return r = max(L, R);
}
 
int main(){
    ios_base::sync_with_stdio(false);

	cin >>n >>qtd;
	int TC = 0;

	while(n!=0 || qtd!=0){
		
		memset(dp, -1, sizeof dp);
		memset(tam, 0, sizeof tam);
		memset(des, 0, sizeof des);
		fori(i, 0, qtd){
			cin >>tam[i] >>des[i];
		}

		cout <<"Teste " <<++TC <<endl;
		cout <<solve(n, 0)<<endl;
		cout <<endl;

		cin >>n >>qtd;
	}
    
    return 0;
}

