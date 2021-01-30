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

	// 3 4 3 2 4
	int n; cin >>n;
	int last = 0;;
	int ans = 0;
	int save = 0;

	for(int i = 0; i < n; i++) {
		int curr; cin >>curr;
		int cost = curr-last;
		if(save - cost >= 0) {
			save -= cost;
		} else {
			ans += (cost-save);
			save = 0;
		}
		last = curr;
	}
	cout <<ans <<endl;
    return 0;
}

