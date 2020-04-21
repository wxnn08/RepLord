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

const int TAM = 1e3+5;
vector<pair<int, int>> v;
int dp[TAM][TAM];
int n;

int lul(int pos, int pilha){
	
	if(pilha==0) return 0; //peso minimo pra uma pilha de tamanho 0
	if(pos>=n) return INF;

	int &r = dp[pos][pilha];
	if(r!=-1) return r;

	int L = lul(pos+1, pilha);
	int R = lul(pos+1, pilha-1) + v[pos].fi;

	if(v[pos].sec < R){
		R = INF;
	}

	return r = min(L, R);
}

bool comp(pair<int,int> a, pair<int,int> b){
	return a.sec>b.sec;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n;
	fori(i, 0, n){
		int a, b;
		cin >>a >>b;
		v.pb(mk(a,b));
	}

	memset(dp, -1, sizeof dp);
	sort(v.begin(), v.end(), comp);

	for(int i=n; i>=0; i--){
		if(lul(0,i)<INF){
			cout <<i <<endl;
			return 0;
		}
	}
    return 0;
}

