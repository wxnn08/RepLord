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

    ll a, b, c, d;
	cin >>a >>b >>c >>d;
	
	for(ll n = 1; n <= sqrt(c); n++) {
		if(n%a == 0 and n%b != 0 and c%n == 0 and d%n != 0) {
			cout <<n <<endl;
			return 0;
		}
	}
	if(c%a == 0 and c%b != 0 and c%c == 0 and d%c != 0) {
		cout <<c <<endl;
		return 0;
	}
    cout <<-1 <<endl;
    return 0;
}

