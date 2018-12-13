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

bool ehPrimo(int n) {
	if(n == 2) return true;
	if(n%2 == 0) return false;
	for(int i = 3; i <= sqrt(n); i += 2) {
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;

	for(int i = 2; i <= n; i++) {
		if(ehPrimo(i)) cout <<i <<' ';
	}
	cout <<endl;
    
    return 0;
}

