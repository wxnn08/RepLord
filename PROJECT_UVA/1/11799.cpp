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
	for(int cs = 1; cs <= tc; cs++) {
		int speed = 0;
		int n; cin >>n;
		for(int i = 0; i < n; i++) {
			int c; cin >>c;
			speed = max(c, speed);
		}
		cout <<"Case " <<cs <<": " <<speed <<endl;
	}

    return 0;
}

