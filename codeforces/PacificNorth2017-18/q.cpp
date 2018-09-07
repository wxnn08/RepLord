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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	ll v = (n-1)/2;
	v *= n;
	v += n;
	v--;
	v /= 2;
	
	ll i=0, f=1e9, mid;
	while(i<=f){

		mid = ((f-i)/2)+i;

		ll q = (mid-1)/2;
		q *= mid;
		q += mid;
		if(q>v){
			f = mid-1;
		} else {
			i = mid+1;
		}
	}

	cout <<n-i <<endl;
    return 0;
}

