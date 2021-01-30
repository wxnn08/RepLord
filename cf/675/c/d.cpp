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
int v[4*N+5];
int pai[N];
 
void add(int at, int t) {
	if(v[at] == -1) {
		v[at] = t;
		return;
	}
	pai[t] = v[at];
	if(t > v[at]) add(2*at+1, t);
	else add(2*at+1, t);
}

int main() {
	ios_base::sync_with_stdio(false);

	int n; cin >>n;
	memset(v, -1, sizeof v);
	for(int i = 0; i < n; i++) {
		int t; cin >>t;
		add(1, t);
	}

	for(int i = 2; i <= n; i++) 
		cout <<pai[i] <<' ';
	cout <<endl;
	
	return 0;
}

