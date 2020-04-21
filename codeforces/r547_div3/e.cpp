#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);
	
	ll h, n, minh = 0, sum = 0;
	cin >>h >>n;
	vector<ll> v;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		sum += a;
		if(h+sum <= 0) {
			cout <<i+1 <<endl;
			return 0;
		}
		minh = min(sum, minh);
		v.pb(a);
	}

	if(sum >= 0) {
		cout <<-1 <<endl;
		return 0;
	} 

	ll ans = (h+minh)/(-sum) + ((h+minh)%sum != 0? 1:0);
	h += ans*sum;
	ans *= n;

	for(int i = 0; i < n; i++) {
		h += v[i];
		if(h <= 0) {
			cout <<ans+i+1 <<endl;
			return 0;
		}
	}
	return 0;
}

