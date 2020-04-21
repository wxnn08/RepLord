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
 
int main() {
	ios_base::sync_with_stdio(false);

	int b, k;
	cin >>b >>k;
	
	if(b%2 == 0) {
		int v;
		for(int i = 0; i < k; i++) cin >>v;
		if(v%2 == 0) cout <<"even" <<endl;
		else cout <<"odd" <<endl;
	}
	else {
		int ans = 0;
		for(int i = 0; i < k; i++) {
			int v; cin >>v;
			ans += (v%2);
		}
		if(ans%2 == 1) cout <<"odd" <<endl;
		else cout <<"even" <<endl;
	}

	return 0;
}
