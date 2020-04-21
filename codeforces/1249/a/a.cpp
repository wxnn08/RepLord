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

	int tc;
	cin >>tc;
	while(tc--) {
		int n; cin >>n;
		vector<int> v;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			v.pb(a);
		}
		sort(v.begin(), v.end());

		bool ans = 0;
		for(int i = 0; i < v.size()-1; i++) {
			if(abs(v[i] - v[i+1]) <= 1) {
				ans = true;
			}
		}
		cout <<(ans?2:1) <<endl;
	}
	
	return 0;
}

