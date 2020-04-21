#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >> n;

	set<int> s;
	int a[105];
	memset(a, 0, sizeof a);
	for(int i = 0; i < n; i++) {
		int t; cin >>t;
		s.insert(t);
		a[t]++;
	}
    
	bool ans = true;
	set<int>::iterator it;
	it = s.begin();
	int qt = *it;

	if(s.size() > 2 or s.size() == 1) ans = false;
	if(ans) {
		it++;
		if(a[qt] != a[*it]) ans = false;
	}

	if(ans) {
		cout <<"YES" <<endl;
		cout <<qt <<' ' <<*it <<endl;
	}
	else cout <<"NO" <<endl;
    return 0;
}

