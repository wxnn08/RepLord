/*29/08/2020*/
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
 
int main() {
    ios_base::sync_with_stdio(false);

	int n; cin >>n;
	vector<ll> v;
	set<ll> ans;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.pb(a);
		ans.insert(a);
	}
	
	while(n > 0) {
		int pos = 0;
		for(int i = 0; i < n-1; i++) {
			if(v[i] != v[i+1]) {
				ll gcd = __gcd(v[i], v[i+1]);
				ans.insert(gcd);
				v[pos++] = gcd;
			}
		}
		n = pos;
	}
	cout <<ans.size() <<endl;

	return 0;
}
