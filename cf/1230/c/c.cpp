#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	int g[8];
	memset(g, 0, sizeof g);

	for(int i = 0; i < m; i++) {
		int u, v; cin >>u >>v;
		g[u]++; g[v]++;
	}

	sort(g+1, g+8);

	if(n < 7) 
		cout <<m <<endl;
	else {
		cout <<min(16, m-g[1]+(g[1]!=0)) <<endl;
	}
	
	return 0;
}

