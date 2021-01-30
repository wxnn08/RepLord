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

	int n; cin >>n;
	while(n--) {
		int c, sum;
		cin >>c >>sum;
		int v = sum/c;
		int r = sum%c;
		cout <<(c-r)*v*v + r*(v+1)*(v+1) <<endl;
	}
	
	return 0;
}

