/* Feito por wxn_ em 02/10/2020*/
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
typedef pair<double,double> dd;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<dd> coord;
double eta[12];

double dist(int ori, int dest) {
	double x1 = coord[ori].fi;
	double y1 = coord[ori].se;
	double x2 = coord[dest].fi;
	double y2 = coord[dest].se;
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double solve(int n, int visited, int curr, double time) {
	bool f = true;
	double delayCurr = max(0.0, time-eta[curr]);
	double minDelay = 0.0;
	for(int i = 0; i < n; i++) {
		if(visited & (1 << i)) continue;
		if(f) {
			minDelay = solve(n, visited|(1<<i), i, time+dist(curr, i));
			f = false;
		} else {
			minDelay = min(minDelay, solve(n, visited|(1<<i), i, time+dist(curr, i)));
		}
	}
	return minDelay+delayCurr;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	
	int n; cin >>n;

	coord.eb(0, 0);
	eta[0] = 0.0;
	for(int i = 1; i <= n; i++) {
		cin >>eta[i];
		double x, y; cin >>x >>y;
		coord.eb(x, y);
	}
	
	cout <<fixed <<setprecision(3) <<solve(n+1, 1, 0, 0.0) <<endl;

    return 0;
}
