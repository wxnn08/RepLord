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
	
	const int N = 1e4+5;
	pair<int, string> p[N];

    int n, t;
	cin >>n >>t;
	for(int i = 0; i < n; i++) {
		cin >>p[i].sec >>p[i].fi;
	}
	sort(p, p+n, greater<pair<int, string>>());
	
	vector<string> team[N];
	for(int i = 0; i < t; i++) {
		for(int j = i; j < n; j+=t) {
			team[i].pb(p[j].sec);
		}
		sort(team[i].begin(), team[i].end());
	}

	for(int i = 0; i < t; i++) {
		cout <<"Time " <<i+1 <<endl;
		for(string j:team[i]) {
			cout <<j <<endl;
		}
		cout <<endl;
	}
    
    return 0;
}

