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

const int MAXN = 10;
int s1[MAXN], s2[MAXN], dp[MAXN][MAXN];

int lcs(int a, int b){ 

	if(a<0 || b<0) return 0;
	
	int &r = dp[a][b];
	if(r!=-1) return r; 
	
	if(s1[a]==s2[b]) return lcs(a-1, b-1)+1; 

	int L = lcs(a-1, b);
	int R = lcs(a, b-1);
	
	return r = max(L, R);
} 
int main(){
    ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >>n >>m;
	
	memset(dp, -1, sizeof dp);
	fori(i, 0, n) {
		cin >>s1[i];
	}
    
	fori(i, 0, m) {
		cin >>s2[i];
	}
	
	cout <<lcs(n-1, m-1) <<endl;

    return 0;
}

