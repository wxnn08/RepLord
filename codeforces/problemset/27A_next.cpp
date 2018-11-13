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
 
const int N = 3e3+5;
bool v[N];

int main(){
    ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	fori(i, 0, n) {
		int t; cin >>t;
		v[t] = 1;
	}
    fori(i, 1, n+2) {
		if(v[i] == 0) {
			cout <<i <<endl;
			return 0;
		}
	}
    return 0;
}

