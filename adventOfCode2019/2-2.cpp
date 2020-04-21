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

	const int ANS = 19690720;
	int n;
	vector<int> t;
	while(cin >>n) {
		char c; cin >>c;
		t.pb(n);
	}

	for(int k = 0; k < 100; k++) {
		for(int j = 0; j < 100; j++) {
			t[1] = k;
			t[2] = j;
			vector<int> v = t;
			for(int i = 0; i < v.size(); i += 4) {
				if(v[i] == 99) break;
				if(v[i] == 1) {
					v[v[i+3]] = v[v[i+1]] + v[v[i+2]];
				} else {
					v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
				}
			}

			if(v[0] == ANS) {
				cout <<100*v[1] + v[2] <<endl;
				return 0;
			}
		}
	}

	return 0;
}

