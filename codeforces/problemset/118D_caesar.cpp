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

int n1, n2, k1, k2;
const int N = 1e2+3;
const int MOD = 1e8;
int dp[N][N][11][11];

//0 - soldado, 1 - cavalo
int lul(int totalS, int totalC, int qtdS, int qtdC){
	if(totalC+totalS==0) return 1;

	int &r = dp[totalS][totalC][qtdS][qtdC];
	if(r!=-1) return r;
	
	ll soma=0;
	if(qtdS<k1 && totalS>0) soma+=lul(totalS-1, totalC, qtdS+1, 0);
	if(qtdC<k2 && totalC>0)	soma+=lul(totalS, totalC-1, 0, qtdC+1);
	
	return r=soma%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >>n1 >>n2 >>k1 >>k2;
	memset(dp, -1, sizeof(dp));

	cout <<lul(n1,n2,0,0) <<endl;
	return 0;
}
