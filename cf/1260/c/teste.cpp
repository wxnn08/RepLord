#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);


	while(true) {
		int a, b;
		cin >>a >>b;
		for(int i = 0; i <= (a*b)/__gcd(a,b); i++) {
			cout <<"(MOD: " <<(i*a)%b <<")\n";
			bool t = false;
			if(i%a == 0) t = true, cout <<a <<' ';
			if(i%b == 0) t = true, cout <<b <<' ';
			if(t) cout <<endl;
		}
		cout <<"----------------------------" <<endl;
	}
	
	return 0;
}

