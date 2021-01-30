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
	const int N = 9;

	int tc; cin >>tc;
	while(tc--) {
		for(int i = 0; i < N; i++) {
			string s; cin >>s;
			for(auto c : s) {
				int a = (c-'0');
				cout <<(a == 1? 2 : a);
			}
			cout <<endl;
		}
	}

    return 0;
}

