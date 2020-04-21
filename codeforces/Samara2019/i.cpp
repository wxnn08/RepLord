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
	ios_base::sync_with_stdio(false);

	ll a, b;
	cin >>a >>b;

	ll ans = a-b;
	ll v = a-b;
	while(v > 0) {
		ans += 2*v;
		v -= b;
	}
	cout <<ans <<endl;
	
	return 0;
}

