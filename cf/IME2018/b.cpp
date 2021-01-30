#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int W = 2e3+5;
const int N = 1e3+5;

int wk, m, n;
vector<pair<int, string>> v;
vector<int> itens;

int dp[N][W];
int solve(int at, int wat) {
	if(wat <= 0) return abs(wat);
	if(at >= m) return INF;

	int &r = dp[at][wat];
	if(r != -1) return r;

	int L = solve(at+1, wat-v[at].fi);
	int R = solve(at+1, wat);

	return r = min(L, R);
}

void build(int at, int wat) {
	if(wat <= 0) return;
	if(at >= m) return;

	int L = solve(at+1, wat-v[at].fi);
	int R = solve(at+1, wat);

	if(L < R) {
		itens.pb(at);
		build(at+1, wat-v[at].fi);
	} else {
		build(at+1, wat);
	}

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	
	cin >>wk >>m;
	for(int i = 0; i < m; i++) {
		pair<int, string> aux;
		cin >>aux.se >>aux.fi;
		v.pb(aux);
	}

	cin >>n;
	vector<int> q;
	for(int i = 0; i < n; i++) {
		int aux; cin >>aux;
		aux += aux%2;
		aux /= 2;
		aux -= wk;
		q.pb(aux);
	}
	
	sort(v.begin(), v.end());

	memset(dp, -1, sizeof dp);

	for(int at:q) {
		int ans = solve(0, at);
		if(ans >= INF) {
			cout <<-1 <<endl;
			continue;
		}
		itens.clear();
		build(0, at);
		cout <<itens.size() <<' ';
		for(int it:itens) cout <<v[it].se <<' ';
		cout <<endl;
	}

	return 0;
}

