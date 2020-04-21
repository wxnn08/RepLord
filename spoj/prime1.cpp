#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool isPrime(int n) {
	if(n == 1) return false;
	if(n == 2) return true;
	if(n%2 == 0) return false;
	for(int i = 3; i <= sqrt(n); i++) {
		if(n%i == 0) return false;
	}
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;
	
	while(tc--) {
		int n, m; 
		cin >>n >>m;
		
		for(int i = n; i <= m; i++) {
			if(isPrime(i))  cout <<i <<endl;
		}
		if(tc > 0) cout <<endl;
	}

    return 0;
}

