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
	
	int n;
	cin >>n;
	string s;
	cin >>s;
	
	int c8 = 0;
	for(int i = 0; i < n-10; i++) {
		if(s[i] == '8') c8++;
	}
	
	if(c8 <= (n-11)/2) cout <<"NO" <<endl;
	else cout <<"YES" <<endl;

	return 0;
}
