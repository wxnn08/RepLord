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

const int N = 5e5 + 5;

int main() {
	ios_base::sync_with_stdio(false);

	
	int n; cin >>n;
	vector<int> in;
	for(int i = 0; i < n; i++) {
		int a; cin >>a; 
		in.pb(a);
	}

	int last[N];
	memset(last, -1, sizeof last);
	int sizeAvailable = 0;

	int ans[N];
	for(int i = n-1; i >= 0; i--) {
		if(in[i] > 0) {
			last[in[i]] = n-i;
		} else {
			sizeAvailable = max(sizeAvailable, last[abs(in[i])]);
		}
		ans[i] = n-i-sizeAvailable;
	}

	for(int i = 0; i < n; i++) cout <<ans[i] <<' ';
	cout <<endl;

	return 0;
}

