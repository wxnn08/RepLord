#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;

set<int> ans;
vector<int> g[N];

 
int main() {
    ios_base::sync_with_stdio(false);

	int n, m, d; cin >>n >>m >>d;
	unordered_set<int> affect;
	for(int i = 0 ; i < m; i++) {
		int a; cin >>a;
		affect.insert(a);
	}
	
	for(int i = 0; i < n-1; i++) {
		int u, v; cin >>u >>v;
		g[u].pb(v);
		g[v].pb(u);
	}



	cout <<ans.size() <<endl;

    return 0;
}

