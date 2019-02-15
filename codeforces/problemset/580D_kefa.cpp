#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 20;
int v[N];
int n, m, k;
vector<ii> rul[N];

int bonus(int at, int mask) {
	int ans = 0;
	for(int i = 0; i < rul[at].size(); i++) {
		if(mask&(1<<rul[at][i].fi)) 
			ans += rul[at][i].sec;
	}
	return ans;
}

int solve(int at, int mask) {
	if(at >= n) return 0;

	int L = solve(at+1, mask);
	int R = 0;
	if(!(mask & (1<<at))) {
		R = solve(at+1, mask|(1<<at)) + v[at] + bonus(at, mask);
	}

	return max(L, R);
}

int main() {
    ios_base::sync_with_stdio(false);

	cin >>n >>m >>k;
    
	for(int i = 0; i < n; i++) 
		cin >>v[i];

	for(int i = 0; i < k; i++) {
		int a, b, c;
		cin >>a >>b >>c;
		rul[b-1].eb(a-1, c);
	}

	cout <<solve(0, 0) <<endl;

    return 0;
}

