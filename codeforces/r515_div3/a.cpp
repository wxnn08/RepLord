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

    int tc;
	cin >>tc;
	while(tc--) {
		ll L, v, l, r;
		cin >>L >>v >>l >>r;
		ll ans = L/v;
		ll sub = r/v - (l-1)/v;
		cout <<max(0LL, ans-sub) <<endl;
	}
    
    return 0;
}

