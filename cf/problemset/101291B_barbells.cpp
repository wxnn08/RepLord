#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 20;
int n, m;
ll bar[N], w[N];

set<ll> ss, ans;
void solve(int pos, int left, int right) {
	if(left == right) ss.insert(left);
	if(pos >= m) return;
	
	solve(pos+1, left+w[pos], right);
	solve(pos+1, left, right+w[pos]);
	solve(pos+1, left, right);
	return;
}

int main() {
    ios_base::sync_with_stdio(false);

	cin >>n >>m;

	for(int i = 0; i < n; i++) cin >>bar[i];
	for(int i = 0; i < m; i++) cin >>w[i];

	solve(0, 0, 0);
	
	sort(bar, bar+n);
	set<ll>::iterator it;
	for(int i = 0; i < n; i++) {
		for(it = ss.begin(); it != ss.end(); it++) {
			ans.insert(bar[i]+2*(*it));
		}
	}

	for(it = ans.begin(); it != ans.end(); it++) 
		cout <<*it <<endl;
    return 0;
}

