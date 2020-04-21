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

const int A = 1e6 + 5;
const int N = 1e5 + 5;
 
int main() {
    ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		vector<int> v;
		int q[A];
		memset(q, 0, sizeof q);

		int n; cin >>n;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			v.pb(a);
			q[a]++;
		}
		
		for(int i = 0; i < log2(n) + 1; i++) {
			for(int mask = 0; mask < n; mask++) {
				if(mask & (1<<i)) q[mask] += q[mask^(1<<i)];
			}
		}

		int ans = 0;
		for(auto curr:v) {
			int t = 0;
			for(int i = 0; i < 
			ans += q[t];
		}
		cout <<ans <<endl;
	}

    return 0;
}

