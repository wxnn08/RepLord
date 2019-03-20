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
	
	int n, k;
	cin >>n >>k;
	vector<ii> v;
	for(int i = 0; i < n; i++) {
		int a, b; cin >>a >>b;
		v.eb(a, 0);
		v.eb(b, 1);
	}
	
	sort(v.begin(), v.end());
	
	vector<int> ans;
	int seq = 0;
	bool f = true;
	for(auto at:v) {
		if(at.se == 0) {
			seq++;
			if(seq >= k and f) {
				f = false;
				ans.pb(at.fi);
			}
		}
		else {
			seq--;
			if(seq < k and !f) {
				ans.pb(at.fi);
				f = true;
			}
		}
	}

	cout <<ans.size()/2 <<endl;
	for(int i = 0; i < ans.size(); i+=2) {
		cout <<ans[i] <<' ' <<ans[i+1] <<endl;
	}
    return 0;
}

