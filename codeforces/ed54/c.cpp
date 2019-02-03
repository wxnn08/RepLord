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

bool vale(double a, double b, double d) {
	if(a < 0 or b < 0) return 0;
	if(abs((a+b) - a*b) <= 1e-6 and abs((a+b) - d) <= 1e-6) 
		return true;
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int tc; cin >>tc;
	while(tc--) {
		double d; cin >>d;
		double delta = d*(d-4);
		double b2 = (d + sqrt(delta))/2;
		double b1 = (d - sqrt(delta))/2;
		if(vale(d-b1, b1, d)) {
			cout <<'Y' <<' ';
			cout <<fixed <<setprecision(9) <<d-b1 <<' ' <<b1 <<endl;
		}
		else if(vale(d-b2, b2, d)) {
			cout <<'Y' <<' ';
			cout <<fixed <<setprecision(9) <<d-b2 <<' ' <<b2 <<endl;
		}
		else cout <<'N' <<endl;
	}

    return 0;
}

