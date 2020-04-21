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
	while(tc--) {
		int n; cin >>n;
		bool firstP = false, ans = true;
		int dist = -1;
		for(int i = 0; i < n; i++) {
			int v; cin >>v;

			dist++;
			if(v and firstP and dist < 6) ans = false;
			if(v) firstP = true, dist = 0;
		}
		cout <<(ans?"YES":"NO") <<endl;
	}

    return 0;
}

