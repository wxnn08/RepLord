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

	int tc; cin >>tc;

	while(tc--) {
		int n; cin >>n;
		int odd = 0, even = 0;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			if(a&1) odd++;
			else even++;
		}
		if(odd&1) cout <<"YES" <<endl;
		else {
			if(!odd) cout <<"NO" <<endl;
			else {
				if(even > 0) cout <<"YES" <<endl;
				else cout <<"NO" <<endl;
			}
		}
	}

    return 0;
}

