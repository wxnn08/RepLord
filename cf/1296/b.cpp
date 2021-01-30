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

	int tc; cin >>tc;
	while(tc--) {
		ll curr;
		cin >>curr;
		ll ans = 0;
		while(curr > 9) {
			ll maxSpend = (curr/10LL)*10LL;
			ans += maxSpend;
			ll cb = maxSpend/10LL;
			curr = curr-maxSpend+cb;
		}
		ans += curr;
		cout <<ans <<endl;
	}

    return 0;
}

