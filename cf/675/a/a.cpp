#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

void ans(bool x) {
	cout <<(x?"YES":"NO") <<endl;
	exit(0);
}
 
int main() {
	ios_base::sync_with_stdio(false);

	ll a, b, c;
	cin >>a >>b >>c;

	if(c == 0) ans(a == b);
	if(a < b and c < 0) ans(false);
	if(a > b and c > 0) ans(false);

	if(a > b) swap(a, b);
	c = abs(c);
	ans((b-a)%c == 0);
	
	
	return 0;
}

