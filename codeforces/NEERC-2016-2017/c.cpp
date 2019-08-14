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
#define each(x, xs) for(auto& x : xs)

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);

	#ifndef STEVE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int h, w;
	cin >> h >> w;
	bool p = false;
	int x = h - 1, y;
	if (h > w) swap(h, w), p = true;
	if (h == 1) {cout << 0 << endl; return 0;}
	vector<ii> icos;
	if (h & 1) {
		x--;
		for (int i = 1;i < w;i += 2) icos.eb(h - 1, i);
	}
	for (int i = 1;i < h;i += 2) {
		for (int j = 1;j <= w - 2;j++) icos.eb(i, j);
	}
	for (int i = 1;i <= x;i++) icos.eb(i, w - 1);
	cout << icos.size() << endl;
	each(k, icos) {
		tie(x, y) = k;
		if (p) swap(x, y);
		cout << x << " " << y << endl;
	}
	return 0;
}

