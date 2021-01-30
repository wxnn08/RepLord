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

ll pot(ll a, ll b) {
	if(b < 0) return 0;
	ll ans = 1;
	for(int i = 0; i < b; i++) {
		ans *= a;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	ll a, b;
	cin >>a >>b;
	
	if(b%a != 0) {
		cout <<-1 <<endl;
		return 0;
	}
	
	if(a == b) {
		cout <<0 <<endl;
		return 0;
	}

	ll v = b/a;
	for(int i = -1; i <= 32; i++) {
		ll pota = pot(2, i);
		for(int j = -1; j <= 32; j++) {
			if(pota * pot(3, j) == v) {
				cout <<i + j <<endl;
				return 0;
			}
		}
	}
	
	cout <<-1 <<endl;
	return 0;
}
