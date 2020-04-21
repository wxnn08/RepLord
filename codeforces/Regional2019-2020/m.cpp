#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, x;
	cin >>n >>x;
	int ans = 1, last, cont = 1; 
	cin >>last;
	for(int i = 1; i < n; i++) {
		int v; cin >>v;
		if(v-last <= x) cont++;
		else cont = 1;
		ans = max(ans, cont);
		last = v;
	}

	cout <<ans <<endl;

	return 0;
}

