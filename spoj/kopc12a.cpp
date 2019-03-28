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

const int N = 1e4 + 5;
ll h[N], cost[N];
int n; 

ll f(int t) {
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (abs(h[i]-t)*cost[i]);
	}
	return ans;
}

ll tsearch(int l, int r) {

	while(r-l > 1) {
		int mid = (l+r)>>1;
		if(f(mid) < f(mid+1)) r = mid;
		else l = mid;
	}
	
	return f(l+1);
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;

	while(tc--) {
		cin >>n;
		ll r = 0;
		for(int i = 0; i < n; i++) {
			cin >>h[i];
			r = max(r, h[i]);
		}
		for(int i = 0; i < n; i++) {
			cin >>cost[i];
		}

		cout <<tsearch(-1, N) <<endl;
	}
    
    return 0;
}

