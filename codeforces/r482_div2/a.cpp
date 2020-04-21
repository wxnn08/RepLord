#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

    ll n;
	cin >>n;
	if(n == 0) {
		cout <<0 <<endl;
		return 0;
	}
	if((n+1)&1) {
		cout <<n+1 <<endl;
	} else {
		cout <<(n+1)/2 <<endl;
	}
    
    return 0;
}

