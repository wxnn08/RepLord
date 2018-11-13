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
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
ull gcd(ull a, ull b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);

	unsigned long long t, w, b;
	cin >>t >>w >>b;

	ull ans = 0;
	ans += min(min(w-1,b-1), t);
	
	ull mdc = gcd(w, b);
	ull mmc = (b/mdc);
	mmc *= w;


	return 0;
}
