#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;
int in[N];
int val[N];
int pai[N];
ii filho[N];

void add(int at, int id) {
	if(in[at] < in[id]) {
		if(filho[at].se == -1) {
			filho[at].se = id;
			filho[id].fi = -1;
			filho[id].se = -1;
			pai[id] = at;
		} else {
			add(filho[at].se, id);
		}
	} else {
		if(filho[at].fi == -1) {
			filho[at].fi = id;
			filho[id].fi = -1;
			filho[id].se = -1;
			pai[id] = at;
		} else {
			add(filho[at].fi, id);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);

	int n; cin >>n;
	cin >>in[0];
	filho[0].se = -1;
	filho[0].fi = -1;

	for(int i = 1; i < n; i++) {
		cin >>in[i];
		add(0, i);
	}

	for(int i = 1; i < n; i++) {
		cout <<in[pai[i]] <<' ';
	}
	cout <<endl;
	
	return 0;
}

