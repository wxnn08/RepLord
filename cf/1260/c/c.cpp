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
		ll r, b, k;
		cin >>r >>b >>k;
		if(r == b) {
			cout <<"OBEY" <<endl;
			continue;
		}
		if(r > b) swap(r, b);
		ll qtd;
		if(b%r == 0) qtd = b/r - 1;
		else qtd = 1 + (b-(__gcd(b, r))-r)/r;
		cout <<(qtd >= k? "REBEL" : "OBEY") <<endl;
	}
	
	return 0;
}

