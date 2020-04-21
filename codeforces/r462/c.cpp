#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e3+5;
int dp[N][10];
int n;
int v[N];

int lis(int pos, int cont) {
	if(pos >= n) return 0;

	int &r = dp[pos][cont];
	if(r != -1) return r;
	
	int L = 0;
	if(cont < 3) {
		if(v[pos] == (2 - (cont % 2))) 
			L = 1 + lis(pos+1, cont+1);
		else 
			L = 1 + lis(pos+1, cont);
	} else {
		if(v[pos] == 2) L = 1 + lis(pos+1, cont);
	}

	int R = lis(pos+1, cont);

	return r = max(L, R);
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n;
	fori(i,0,n) cin >>v[i];
    
	memset(dp, -1, sizeof dp);
	cout <<lis(0, 0) <<endl;
    return 0;
}

