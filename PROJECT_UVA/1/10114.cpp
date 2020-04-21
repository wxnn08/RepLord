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
		int qtm, n; double d, l;
		cin >>qtm >>d >>l >>n;

		int currMonth = 0;
		double car = d + l;

		vector<double> v;
		int m; double p;
		cin >>m >>p;
		v.eb(p);
		for(int i = 1; i < n; i++) {
			cin >>m >>p;
			while(v.size() < m) v.eb(v.back());
			v.eb(p);
		}

		for(auto at:v) cout <<at<<endl;

		
	}

    return 0;
}

