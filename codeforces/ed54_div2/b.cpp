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

const int N = 1e5 + 5;
bool crivo[N];

ll menorPrimo(ll n) {
	for(ll i = 2; i < N; i++) {
		if(!crivo[i]) {
			for(ll j = i+i; j < N; j+=i) {
				crivo[j] = 1;
			}
		if(n%i == 0) return i;
		}
	}
	return n;
}

int main(){
    ios_base::sync_with_stdio(false);

    ll n; cin >>n;
	ll menor = menorPrimo(n);
	if(menor == 2) cout <<n/2 <<endl;
	else if(menor == n) {
		cout <<1 <<endl;
	}
	else {
		n -= menor;
		cout <<(n/2)+1 <<endl;
	}
    
    return 0;
}

