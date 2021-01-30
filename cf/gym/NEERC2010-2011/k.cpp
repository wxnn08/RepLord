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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int rk[255];
 
int main() {
	rk['D'] = 0;
	rk['U'] = 1;
	rk['R'] = 2;
	rk['L'] = 3;
 
	int n, m;
	cin >> n >> m;
 
	int x, y;
	x = 1;
	y = 1;
 
	int lx = 1, ly = 1;
	int rx = n, ry = m;
	int cdx = 0, cdy = 0;
	while (1) {
		while (1) {
			if (lx <= x && x <= rx && ly <= y && y <= ry) {
				break;
			}
			y++;
			if (y == m + 1) {
				y = 1;
				x++;
			}
			assert(x <= n);
		}
		cout << x + cdx << " " << y + cdy << endl;
		string s;
		cin >> s;
		if (s == "DETECTED") break;
 
		int k = rk[s[0]];
		cdx += dx[k];
		cdy += dy[k];
 
		rx = min(rx, n - cdx);
		lx = max(lx, 1 - cdx);
		ry = min(ry, m - cdy);
		ly = max(ly, 1 - cdy);
 
		y++;
		if (y == m + 1) {
			y = 1;
			x++;
		}
		assert(x <= n);
	}
 
	return 0;
}
