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
		int n; cin >>n;
		vector<ll> v(n);
		for(int i = 0; i < n; i++) cin >>v[i];

		sort(v.begin(), v.end());
		ll ans = 0;
		for(int k = 0; k < n; k++) {
			int i = k+1, j = n-1;
			ll sum = 0;
			while(i < j) {
				if(v[i]+v[j] > v[k]) j--;
				else i++;
				if(v[i]+v[j] == v[k]) ans++;
			}
		}
		cout <<ans <<endl;
	}

    return 0;
}

