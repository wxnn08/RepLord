#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<dd> v;

double dist(double x, int i) {
	x = abs(v[i].fi-x);
	double y = abs(v[i].se);
	return sqrt(pow(x,2) + pow(y,2));
}

double f(double x) {
	double ans = 0;
	for(int i = 0; i < v.size(); i++) {
		ans = max(ans, dist(x, i));
	}
	return ans;
}

dd search() {
	double r = 2e5;
	double l = -2e5;
	while(r-l > 1e-7 or abs(f(r)-f(l)) > 1e-7) {
		double m1 = l + (r-l)/3;
		double m2 = r - (r-l)/3;
		if(f(m1) < f(m2)) r = m2;
		else l = m1;
	}
	return dd(r, f(r));
}

int main() {
	
	while(true) {
		int n;
		cin >>n;
		if(n == 0) break;
		v.clear();
		for(int i = 0; i < n; i++) {
			double a, b;
			cin >>a >>b;
			v.pb(mk(a,b));
		}

		dd ans = search();
		printf("%.7f %.7f\n", ans.fi, ans.se);
	}
   
    return 0;
}

