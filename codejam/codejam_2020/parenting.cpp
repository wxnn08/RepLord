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

struct act {
	int hi, hf, id;

	bool operator < (const act &t) const {
		if(hi != t.hi) return hi < t.hi;
		else if(hf != t.hf) return hf < t.hf;
		return id < t.id;
	}
};

void read_input(vector<act> &v, int n) {
	for(int i = 0; i < n; i++) {
		int a, b; cin >>a >>b;
		v.pb({a,b,i});
	}
}

string schedule(const vector<act> &v) {
	int lastC = 0;
	int lastJ = 0;
	vector<pair<int, char>> t;
	for(auto curr:v) {
		if(curr.hi >= lastC) {
			t.eb(curr.id, 'C');
			lastC = curr.hf;
		} else if(curr.hi >= lastJ) {
			t.eb(curr.id, 'J');
			lastJ = curr.hf;
		} else {
			return "IMPOSSIBLE";
		}
	}
	sort(t.begin(), t.end());
	string ans = "";
	for(auto curr:t) ans += curr.se;
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	int tcs; cin >>tcs;
	for(int tc = 1; tc <= tcs; tc++) {
		int n; cin >>n;
		vector<act> v;
		read_input(v, n);
		sort(v.begin(), v.end());
		cout <<"Case #" <<tc <<": ";
		cout <<schedule(v) <<endl;
	}

    return 0;
}
