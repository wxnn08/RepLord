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

	const int N = 4e7;
	vector<int> v;
	int val = 4;
	while(val < N) {
		v.pb(val-1);
		val *= 2;
	}

	int q;
	cin >>q;
	while(q--) {
		int n; cin >>n;
		int ans = 0;
		for(int at:v) {
			if(at == n) {
				for(int i = 2; i*i <= n; i++) {
					if(n%i == 0) {
						ans = n/i;
						break;
					}
				}
				if(ans == 0) ans = 1;
			}
		}

		if(ans) {
			cout <<ans <<endl;
			continue;
		}
		
		int pos = lower_bound(v.begin(), v.end(), n)-v.begin();
		cout <<v[pos] <<endl;
		
	}

	return 0;
}
