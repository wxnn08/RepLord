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

int v[4];
int sum = 0;
bool solve(int at, int cont) {
	if(at == 4) {
		return sum-cont == cont;
	}
	bool L = solve(at+1, cont+v[at]);
	bool R = solve(at+1, cont);
	return max(L,R);
}

int main() {
	ios_base::sync_with_stdio(false);
	
	for(int i = 0; i < 4; i++) cin >>v[i], sum += v[i];
	cout <<(solve(0, 0)?"YES":"NO") <<endl;

	return 0;
}

