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
		int n, x; cin >>n >>x;
		int ans = INT_MAX;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;

			int vat;
			if(x%a == 0) vat = x/a;
			else vat = max(0, (x/a)-1)+2;
			ans = min(ans, vat);
		}
		cout <<ans <<endl;
	}

    return 0;
}

