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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const double N = 100000;
vector<double> v;

double weak(double x) {
	double ans = 0;
	double cont = 0;
	
	for(int at:v) {
		cont = max(0.0, cont+at-x);
		ans = max(ans, abs(cont));
	}
	cont = 0;
	for(int at:v) {
		cont = min(0.0, cont+at-x);
		ans = max(ans, abs(cont));
	}

	return ans;
}

double search(double l, double r) {
	
	int it = 200;
	while(it--) {
		double m1 = l + (r-l)/3;
			double m2 = r - (r-l)/3;

		if(weak(m1) < weak(m2)) r = m2;
		else l = m1;
	}

	return weak(r);
}

int main() {
    ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	for(int i = 0; i < n; i++) {
		double a; cin >>a;
		v.pb(a);
	}
	
	//cout <<weak(0) <<endl;
	printf("%.6f\n", search(-N, N));

    return 0;
}

