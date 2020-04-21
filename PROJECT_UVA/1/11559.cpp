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
 
int main() {
    ios_base::sync_with_stdio(false);

	int n, b, h, w; 
	while(cin >>n >>b >>h >>w) {
		int ans = -1;
		for(int i = 0; i < h; i++) {
			int p; cin >>p;
			for(int j = 0; j < w; j++) {
				int a; cin >>a;
				if(a >= n and n*p <= b) {
					ans = (ans == -1?n*p:ans);
					ans = min(ans, n*p);
				}
			}
		}

		if(!~ans) cout <<"stay home" <<endl;
		else cout <<ans <<endl;
	}

    return 0;
}

