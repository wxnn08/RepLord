#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    ll n, k;
	cin >>n >>k;
	
	ll i=1, j=n;
	while(){
		mid = (i+j)>>1;
		cout <<i <<' '<<j;
		string s;
		cin >>s;
		if(s=="No"){
			i = min(1, j-k);
			j = min(n, j+k);
		} else if(s=="Yes") {
			
		}

	}
    
    return 0;
}

