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

const int N = 1e2+5;
int v[N];
int n;
int dp[N][3];

int lul(int pos, bool seq){
	if(pos>=n) return 0;
	int &r = dp[pos][seq];
	if(r!=-1) return r;
	
	if(seq==true) return r=max(lul(pos+1, true)+(1-v[pos]), accumulate(v+pos, v+n, 0));
	else return r=max(lul(pos+1, true)+(1-v[pos]), lul(pos+1, false)+v[pos]);
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n;
	int soma=0;
	fori(i, 0, n){
		cin >>v[i];
		soma+=v[i];
	}
	
	memset(dp, -1, sizeof(dp));
	if(soma==n) cout <<soma-1;
	else cout <<lul(0, false);
	cout <<endl;
    
    return 0;
}

