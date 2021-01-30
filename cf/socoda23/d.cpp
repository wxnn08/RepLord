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
#define all(x) 	x.begin(), x.end()

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<int> mbw;
void transformToBase(int x, int w) {
	if(x == 0) {
		mbw.pb(x);
		return;
	}
	mbw.pb(x%w);
	transformToBase(x/w, w);
}
 
int main() {
    ios_base::sync_with_stdio(false);

	int w, m; cin >>w >>m;

	transformToBase(m, w);
	// [LSB, ... , MSB]
	
	for(int i = 0; i < mbw.size(); i++) {
		int &r = mbw[i];
		if(r == w) r = 0, mbw[i+1]++;
		if(r == 0 or r == 1) continue;
		if(r + 1 == w) {
			r = 0;
			mbw[i+1] += 1;
			continue;
		}
		cout <<"NO" <<endl;
		return 0;
	}
	cout <<"YES" <<endl;
	
    return 0;
}

