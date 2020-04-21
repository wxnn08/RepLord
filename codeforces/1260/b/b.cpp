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

	int tc; cin >>tc;
	while(tc--) {
		ll a, b; cin >>a >>b;
		if(a > b) swap(a, b);
		ll t = b-a;
		b -= 2*t;
		a -= t;
		if(a != b or a < 0 or b < 0) {
			cout <<"NO" <<endl;
			continue;
		}
		if(a%3 == 0) cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
	
	return 0;
}

