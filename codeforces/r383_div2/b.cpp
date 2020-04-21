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
 
const int N = 1e5;
int v[N];

int main(){
    ios_base::sync_with_stdio(false);

    int n, k; cin >>n >>k;
	for(int i = 0; i < n; i++) 
		cin >>v[i];
    
	sort(v, v+n);
	
	ll ans = 0;
	for(int i = 0; i < n; i++) 
		ans += (upper_bound(v+i+1, v+n, v[i]^k) 
			- lower_bound(v+i+1, v+n, v[i]^k));

	cout <<ans <<endl;
    return 0;
}

