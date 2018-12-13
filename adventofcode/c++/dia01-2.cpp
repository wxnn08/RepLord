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
 
int main(){
    ios_base::sync_with_stdio(false);
	
	set<ll> s;
	vector<ll> v;
	ll sum = 0;
	s.insert(sum);
	ll p;
	while(cin >>p) {
		v.pb(p);
		sum += p;
		if(s.count(sum)) {
			cout <<sum <<endl;
			return 0;
		}
		s.insert(sum);
	}
	
	ll i = 0;
	while(true) {
		sum += v[i++];
		if(s.count(sum)) break;
		if(i >= v.size()) i = 0;
		s.insert(sum);
	}
    
	cout <<sum <<endl;
    return 0;
}

