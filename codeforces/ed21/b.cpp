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
	
	double ans = 0;
	for(ll i = 0; i < n; i++) {
		double v; cin >>v;
		ans += (v * min({k, n-k+1, i+1, n-i}));
	}

	cout <<fixed <<setprecision(7) <<(ans/(n-k+1)) <<endl;

	return 0;
}

