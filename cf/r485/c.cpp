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

const int T = 3e3+5;
int n, size[T], cost[T];
int dp[T][T][4];

int lul(int pos, int ult, int qtd){
	
	if(qtd==3) return 0;
	if(dp[pos][ult][qtd]!=-1) return dp[pos][ult][qtd];
	
	int val=INF;
	for(int i=pos; i<n-(2-qtd); i++){
		if(pos==ult || size[i]>size[ult]){
			val = min(val, lul(i+1, i, qtd+1)+cost[i]);
		}
	}
	return dp[pos][ult][qtd] = val;
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n;
	fori(i, 0, n)
		cin >>size[i];
	fori(i, 0, n)
		cin >>cost[i];

	memset(dp, -1, sizeof(dp));
	ll res = lul(0, 0, 0);

	if(res>=INF) cout <<-1;
	else cout <<res;
	cout <<endl;

    return 0;
}

