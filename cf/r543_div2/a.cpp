#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);
	
	const int N = 1e2 + 5;
    int n, m, k;
	cin >>n >>m >>k;
	int g[N], v[N], s[N];
	memset(g, -1, sizeof g);

	for(int i = 1; i <= n; i++) 
		cin >>v[i];
    
	for(int i = 1; i <= n; i++) 
		cin >>s[i];

	for(int i = 1; i <= n; i++) {
		g[s[i]] = max(v[i], g[s[i]]);
	}
	
	int ans = 0;
	for(int i = 0; i < k; i++) {
		int at; cin >>at;
		if(v[at] != g[s[at]]) ans++;
	}

	cout <<ans <<endl;
    return 0;
}

