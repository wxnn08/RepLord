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

ll escolhe(ll n, ll p) {
	
	if(p == 1) return n;
	if(p == 2) return (n*(n-1))/2;
	return (n*(n-1)*(n-2))/6;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	map<ll, ll> m;
	for(int i = 0; i < n; i++) {
		ll num; cin >>num;
		m[num]++;
	}
	
	ll qtd = 0;
	vector<ll> chs;
	for(auto at:m) {
		if(qtd >= 3) break;
		qtd += at.se;
		chs.pb(at.fi);
	}
	
	ll cont = 0;
	int tam = chs.size();
	for(int i = 0; i < tam-1; i++) 
		cont += m[chs[i]];

	cout <<escolhe(m[chs[tam-1]], 3LL-cont) <<endl;

	return 0;
}

