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

	int n;
	vector<int> v;
	while(cin >>n) {
		char c; cin >>c;
		v.pb(n);
	}

	v[1] = 12;
	v[2] = 2;
	for(int i = 0; i < v.size(); i += 4) {
		if(v[i] == 99) break;
		if(v[i] == 1) {
			v[v[i+3]] = v[v[i+1]] + v[v[i+2]];
		} else {
			v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
		}
	}

	cout <<v[0] <<endl;
	return 0;
}

