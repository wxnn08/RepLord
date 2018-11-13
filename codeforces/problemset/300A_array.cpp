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

    int n; cin >>n;
	vector<int> pos, neg, z;

	fori(i, 0, n) {
		int t; cin >>t;
		if(t > 0) pos.pb(t);
		if(t < 0) neg.pb(t);
		if(t == 0) z.pb(t);
	}

	if(pos.size() == 0) {
		fori(i,0,2) {
			pos.pb(neg[neg.size()-1]);
			neg.pop_back();
		}
	}
    
	if(neg.size()%2 == 0) {
		z.pb(neg[neg.size()-1]);
		neg.pop_back();
	}
	cout <<neg.size() <<' ';
	for(int i:neg) cout <<i <<' ';
	cout <<endl <<pos.size() <<' ';
	for(int i:pos) cout <<i <<' ';
	cout <<endl <<z.size() <<' ';
	for(int i:z) cout <<i <<' ';
	cout <<endl;

    return 0;
}
