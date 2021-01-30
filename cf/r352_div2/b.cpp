#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	if(n > 26) {
		cout <<-1 <<endl;
		return 0;
	}

	int l[30];
	memset(l, 0, sizeof l);
	int cont = 0;
	for(int i = 0; i < n; i++) {
		char c; cin >>c;
		int pos = c-'a';
		if(l[pos] == 0) {
			l[pos]++;
			cont++;
		}
	}
	cout <<n-cont <<endl;
    return 0;
}

