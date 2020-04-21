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

const int N = 2e5 + 5;
struct node {
	int a, b, tp, id;
	bool operator < (const node &t) const {
		if(a != t.a) return a > t.a;	
		if(tp != t.tp) return tp > t.tp;
		return b > t.b;
	}
};

vector<node> v;
set<ii> s;
int ans[N];

int main() {
	int n;
	scanf(" %d", &n);
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		v.pb({a, b, 0, i});
	}
	int m;
	scanf(" %d", &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf(" %d %d", &a, &b);
		v.pb({a, b, 1, i});
	}

	sort(v.begin(), v.end());
	
	for(auto at:v) {
		if(at.tp == 0) {
			auto x = s.lower_bound(ii(at.b, 0));
			if(x == s.end()) {
				printf("-1\n");
				return 0;
			}
			ans[at.id] = (*x).se+1;
			s.erase(x);
		}
		if(at.tp == 1) {
			s.insert(ii(at.b, at.id));
		}
	}

	for(int i = 0; i < n; i++) printf("%d ", ans[i]);
	printf("\n");

	return 0;
}

