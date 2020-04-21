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

void buildSG() { // observe rule
	int mex[1024] = {}, SG[50];
	SG[0] = 0;
	for (int i = 1; i < 50; i++) {
		memset(mex, 0, sizeof(mex));
		for (int j = 1; j <= i/2; j++)
			mex[SG[i - j]] = 1;
		int sg = 0;
		for (sg = 0; mex[sg]; sg++);
		SG[i] = sg;
		printf("%d : %d\n", i, SG[i]);
	}
}

ll sg(ll t) {
	return (t%2 == 1? sg(t/2) : t/2);
}

int main() {
    ios_base::sync_with_stdio(false);
	
    int tc;
	cin >>tc;
	while(tc--) {
		int n; cin >>n;
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			ll t; cin >>t;
			ans ^= sg(t);
		}
		cout <<(ans? "YES":"NO") <<endl;
	}
    
    return 0;
}

