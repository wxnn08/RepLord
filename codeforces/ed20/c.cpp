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
 
int main() {
	ios_base::sync_with_stdio(false);

	ll n, k;
	cin >>n >>k;
	ll sum = (k*k + k)/2;

	if(k > 2e5 or sum > n) {
		cout <<-1 <<endl;
		return 0;
	}
	
	set<ll> s;
	for(ll i = 1; i*i <= n ; i++) {
		if(n%i == 0) {
			s.insert(i);
			s.insert(n/i);
		}
	}
	
	ll ans = 0;
	for(auto at:s) {
		if((at)*sum <= n) ans = at;
		else break;
	}
	
	ll ac = 0;
	for(int i = 1; i <= k; i++) {
		if(i < k) cout <<ans*i <<' ';
		else cout <<(n-ac) <<endl;
		ac += ans*i;
	}
	
	return 0;
}

