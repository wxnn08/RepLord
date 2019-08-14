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

	int cx, cy, tx, ty, x, y;
	cin >>cx >>cy >>tx >>ty >>x >>y;
	
	int distx = abs(tx-cx);
	int disty = abs(ty-cy);
	
	if(disty%y == 0) {
		if((disty/y)%2 == 0) {
			if(distx%(2*x) == 0) cout <<"YES" <<endl;
			else cout <<"NO" <<endl;
		} else {
			if((distx-x)%(2*x) == 0) cout <<"YES" <<endl;
			else cout <<"NO" <<endl;
		}
	}
	else cout <<"NO" <<endl;

	return 0;
}

