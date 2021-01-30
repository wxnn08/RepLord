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

const int N = 112;
bool ch[N];
int n, k;

int solve(int t, int qtd, int leader) {
	t = t%qtd;
	int at = leader;
	while(t--) {
		at++;
		if(!ch[at%n]) t++;
	}
	return at%n;
}

int main() {
    ios_base::sync_with_stdio(false);

	cin >>n >>k;
	memset(ch, 1, sizeof ch);
	int at = 0;
	for(int i = 0; i < k; i++) {
		int t; cin >>t;
		at = solve(t, n-i, at);
		cout <<at+1 <<' '; 
		ch[at] = false;

		while(!ch[at%n]) at++;
		at = at%n;
	}
	cout <<endl;

    return 0;
}
