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
	vector<ll> y1, y2;

	//Impar - Par
	int n, y;
	cin >>n >>y;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		y1.pb(a);
	}
	cin >>n >>y;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		y2.pb(a);
	}

	int ans = 0;
	{
		unordered_map<ll,int> qtd;
		for(auto &t:y1) ans = max(ans, ++qtd[t]);
		for(auto &t:y2) ans = max(ans, ++qtd[t]);
	}

	ll div = 2;
	for(ll i = 0; i < 32; i++) {
		unordered_map<ll,int> qtd;
		for(auto &t:y1) 
			ans = max(ans, ++qtd[(t+(div/2))%div]);
		for(auto &t:y2) 
			ans = max(ans, ++qtd[t%div]);
		div*=2;
	}
	cout <<ans <<endl;
	
	return 0;
}

