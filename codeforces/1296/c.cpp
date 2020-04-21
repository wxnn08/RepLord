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
 
void move(int &x, int &y, char c) {
	if(c == 'L') x--;
	if(c == 'R') x++;
	if(c == 'U') y++;
	if(c == 'D') y--;
}
 
int main() {
    ios_base::sync_with_stdio(false);
 
	int tc; cin >>tc;
	while(tc--) {
		int x = 0, y = 0;
		map<ii, int> hist;
		hist[ii(x,y)] = 0;
		int ans = -1; 
		int l = -1, r = -1;
 
		int n; cin >>n;
		for(int i = 0; i < n; i++) {
			char c; cin >>c;
			move(x, y, c);
			ii pos = ii(x,y);
			if(hist.count(pos)){
				int len = i-hist[pos]+1;
				if(ans == -1) {
					ans = len;
					l = hist[ii(x,y)];
					r = i+1;
				}
				else if(ans > len) {
					ans = len;
					l = hist[ii(x,y)];
					r = i+1;
				}
			}
			hist[pos] = i+1;
		}
		if(~ans) cout <<l+1 <<' ' <<r <<endl;
		else cout <<-1 <<endl;
	}
 
    return 0;
}
