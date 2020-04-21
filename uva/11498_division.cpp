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

	int n; cin >>n;
	while(n) {
		int x, y; 
		cin >>x >>y;
		
		for(int i = 0; i < n; i++) {
			int a, b; cin >>a >>b;
			if(a == x or b == y) cout <<"divisa" <<endl;
			else {
				if(b > y) cout <<'N';
				else cout <<'S';
				if(a > x) cout <<'E';
				else cout <<'O';
				cout <<endl;
			}
		}
		cin >>n;
	}
    
    return 0;
}

