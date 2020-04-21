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

const int TAM = 1e3+5;
int a[TAM], b[TAM];
int dp[TAM][TAM];

int lcs(int i, int j){
	if(i<0 || j<0) return 0;

	int &r = dp[i][j];
	if(r != -1) return r;

	if(a[i] == b[j]) return 1 + lcs(i-1,j-1);
	return r = max(lcs(i-1,j), lcs(i,j-1));
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
	cin >>n >>m;
	fori(i,0,n) cin >>a[i];
	fori(i,0,m) cin >>b[i];
    
	memset(dp, -1, sizeof dp);
	int v = lcs(n-1, m-1);
	cout <<n-v <<' ' <<m-v <<endl;

    return 0;
}

