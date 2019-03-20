#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;

	while(tc--) {
		int n;
		cin >>n;
		vector<int> v;
		v.pb(0);
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			v.pb(a);

		}

		int ans = 0;
		for(int i = n; i > 0; i-=2) {
			ans ^= v[i]-v[i-1]-1;
		}

		if(ans) {
			cout <<"Mary wins" <<endl;
			// Winning move:
			ii move;
			for(int i = n; i > 0; i-=2) {
				int size = v[i]-v[i-1]-1;
				int nsize = ans^size;
				if(i > 1 and nsize > size and v[i-1]-(nsize-size) > v[i-2]) {
					move.fi = v[i-1];
					move.sec = v[i-1]-(nsize-size);
				}
				if(nsize < size and v[i]-(size-nsize) > v[i-1]) {
					move.fi = v[i];
					move.sec = v[i]-(size-nsize);
				}
			}
			cout <<"Move " <<move.fi <<" to " <<move.sec <<endl;
		} else {
			cout <<"Johnny wins" <<endl;
		}
		cout <<endl;
	}
    
    return 0;
}

