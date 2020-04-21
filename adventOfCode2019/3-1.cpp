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

	vector<ii> w1, w2;
	w1.eb(0,0);
	w2.eb(0,0);
	char op;

	int walk[4][2] = { {};
	map<char, int> coord;
	coord['U'] = 0;
	coord['R'] = 1;
	coord['D'] = 2;
	coord['L'] = 3;
	while(cin >>op) {
		int n; cin >>n;
		char comma; cin >>comma;
		if(comma != ',') break;
	}
	
	return 0;
}

