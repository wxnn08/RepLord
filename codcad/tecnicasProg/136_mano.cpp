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


int n, m;
const int N = 1e3;
int moeda[N];
int dp[N][15];

bool solve(int val, int qtd){
	if(val<0 or qtd>9) return 0;
	if(val==0) return 1;

	int &r = dp[val][qtd];
	if(r!=-1) return r;
	
	bool res = false;
	for(int i=0; i<n; i++)
		res += solve(val-moeda[i], qtd+1);
	
	return r = res;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n >>m;
	fori(i,0,n) cin >>moeda[i];
	memset(dp, -1, sizeof dp);
    cout <<(solve(m,0)?'S':'N') <<endl;
    
    return 0;
}

