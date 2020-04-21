#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define all(x) x.begin(), x.end()
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 60;
int mat[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	
	vector<ii> v;
	vector<int> p;
	for(int i = 0; i < 6; i++) {
		int a, b; cin >>a >>b;
		a *= 2;
		b *= 2;
		p.pb(a); p.pb(b);
		p.pb(a+1); p.pb(b+1);
		p.pb(a-1); p.pb(b-1);
		v.eb(a, b);
	}

	sort(all(p));
	p.resize(unique(all(p)) - p.begin());
	map<int, int> id;
	for(int i = 0; i < (int)p.size(); i++) 
		id[p[i]] = i;
	for(auto &at:v) {
		at.fi = id[at.fi];
		at.se = id[at.se];
	}

	for(int k = 0; k < 6; k += 2) {
		for(int i = v[k].fi; i < v[k+1].fi; i++) {
			for(int j = v[k].se; j < v[k+1].se; j++) {
				mat[i][j] = k < 2;
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(mat[i][j] == 1) {
				cout <<"YES" <<endl;
				return 0;
			}
		}
	}

	cout <<"NO" <<endl;
	return 0;
}

