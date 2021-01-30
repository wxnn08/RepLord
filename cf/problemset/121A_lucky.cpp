#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<ll> v;
void genLucky() {
	v.pb(4);
	v.pb(7);
	ll pot = 10;
	int back = 2;
	while(true) {
		int tam = v.size();
		for(int i = tam-back; i < tam and v[v.size()-1] <= 1e9; i++)
			v.pb(4*pot + v[i]);
		for(int i = tam-back; i < tam and v[v.size()-1] <= 1e9; i++)
			v.pb(7*pot + v[i]);

		if(v[v.size()-1] > 1e9) break;
		
		pot *= 10;
		back *= 2;
	}
	return;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	genLucky();
	ll n, m;
	cin >>n >>m;
	vector<ll>::iterator it = lower_bound(v.begin(), v.end(), n);
	ll at = n-1, ans = 0;
	while(true) {
		if(m < *it) {
			ans += (m-at)*(*it);
			break;
		}
		ans += (*it-at) * (*it);
		at = *it;
		it++;
	}

	cout <<ans <<endl;
    return 0;
}

