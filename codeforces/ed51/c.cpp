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
 
const int N = 1e2+5;
int v[N], a[N];

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;

	fori(i,0,n) cin >>a[i];

	vector<int> nice, unice;
	fori(i,0,n) {
		v[a[i]]++;
	}

	fori(i,0,n) {
		if(v[a[i]] == 1) nice.pb(a[i]);
		if(v[a[i]] > 1) unice.pb(a[i]);
	}

	map<int, char> m;

	fori(i,0,nice.size()) {
		if(i%2 == 0) m[nice[i]] = 'A';
		else m[nice[i]] = 'B';
	}
	fori(i,0,unice.size()) m[unice[i]] = 'A';

	if(nice.size()%2 == 0) {
		
		cout <<"YES" <<endl;
		fori(i,0,n){
			cout <<m[a[i]];
		}
		cout <<endl;
	} else {
		
		int special = -1;
		for(int i=0; i<N; i++) {
			if(v[i] > 2) {
				special = i;
				break;
			}
		}
		if(unice.size() == 0 or special == -1) {
			cout <<"NO" <<endl;
			return 0;
		}
		bool put = false;
		cout <<"YES" <<endl;

		fori(i,0,n) {
			if(a[i] == special and !put) {
				put = true;
				cout <<'B';
			}
			else cout <<m[a[i]];
		}
		cout <<endl;
	}
    return 0;
}

