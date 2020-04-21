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
 
int n;
vector<pair<int,int>> v;
const int TAM = 2e3+5;
int dp[TAM][TAM];

int solve(int peso, int pos) {
	if(peso<0) return -INF;
	if(pos>=n) return 0;
	
	int &r = dp[peso][pos];
	if(r != -1) return r;

	int L = v[pos].sec + solve(peso-v[pos].fi, pos+1);
	int R = solve(peso, pos+1);

	return r = max(L,R);
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int p;
	cin >>p >>n;
	
	memset (dp, -1, sizeof dp);
	fori(i, 0, n) {
		pair<int,int> aux;
		cin >>aux.fi >>aux.sec;
		v.pb(aux);
	}
	
	cout <<solve(p, 0) <<endl;
    
    return 0;
}

