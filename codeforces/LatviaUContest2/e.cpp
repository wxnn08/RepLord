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

const int N = 5e6 + 5;
const int M = 22;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >>n;

	bool F[N];
	for(int i = 0; i<n; ++i) {
		char c; cin >>c;
		F[i] = (c == '+'? 0 : 1);
	}

	for(int i = 0;i < M; ++i) 
		for(int mask = 0; mask < (1<<M); ++mask) {
			if(mask & (1<<i))
				F[mask] ^= F[mask^(1<<i)];
		}

	for(int i = 0; i < n; i++) cout <<(F[i]?'-':'+');
	cout <<endl;
	return 0;
}

