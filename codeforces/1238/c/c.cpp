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
 
int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		int h, n;
		cin >>h >>n;
		vector<int> v;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			v.pb(a);
		}
		v.pb(0);
		v.pb(0);
		v.pb(0);
		int ans = 0;
		int pos = 1;
		while(h > 2) {
			if(h == v[pos]+1 and h != v[pos+1]+2) {
				ans++;
			} 
			h = v[pos+1]+1;
			pos++;
		}
		cout <<ans <<endl;
		
	}
	
	return 0;
}

