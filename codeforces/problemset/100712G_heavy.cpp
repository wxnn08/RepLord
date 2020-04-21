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

const int N = 15;
int v[N], n, s;

bool verify(int mask, int sum) {
	for(int i = 0; i < 11; i++) {
		if(mask&(1<<i) and sum-v[i] >= s)
			return false;
	}
	return true;
}

int solve(int pos, int sum, int mask) {
	if(sum >= s) {
		if(verify(mask, sum)) return 0;
		return -INF;
	}
	if(pos >= n) return -INF;

	int L = solve(pos+1, sum, mask);
	int R = solve(pos+1, sum+v[pos], mask|(1<<pos)) + 1;

	return max(L, R);
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;
	while(tc--) {
		cin >>n >>s;
		for(int i = 0; i < n; i++) {
			cin >>v[i];
		}

		cout <<solve(0, 0, 0) <<endl;
	}
    return 0;
}

