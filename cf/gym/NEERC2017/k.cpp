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

vector<ii> v;

int solve() {
	int ant = -1;
	int p = 0;
	map<ii, int> cost;
	for(auto at:v) {
		ii r = ii(min(at.fi, at.se), max(at.fi, at.se));
		if(ant != at.fi) p += a, cost[r] += a;
		else p += b, cost[r] += b;
		ant = at.se;
	}
	
	vector<int> q;
	for(auto at:cost) 
		q.pb(at.se);
	
	
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, a, b, k, f;
	cin >>n >>a >>b >>k >>f;
	map<string, int> m;
	
	int cont = 1;
	for(int i = 0; i < n; i++) {
		string s, t; cin >>s >>t;
		if(!m.count(s)) m[s] = cont++;
		if(!m.count(t)) m[t] = cont++;
		v.eb(m[s], m[t]);
	}
	
	cout <<solve() <<endl;
	
	return 0;
}

