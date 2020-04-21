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
 
int cont(int pos, int v, int &d) {
	for(int i = 0; i <= v; i++) {
		if(i*pos > d) {
			d -= ((i-1)*pos);
			return i-1;
		}
	}
	d -= pos*v;
	return v;
}

int main() {
    ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		int n, d; cin >>n >>d;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			ans += cont(i, a, d);
		}
		cout <<ans <<endl;
	}

    return 0;
}

