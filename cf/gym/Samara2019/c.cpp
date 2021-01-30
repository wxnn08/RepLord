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

const int N = 1e7 + 5;
bool arr[N];

int main() {
	ios_base::sync_with_stdio(false);

	ll p, n;
	cin >>p >>n;

	ll cont = 0;
	arr[0] = 1;
	for(ll i = 1; i <= min(n, (p*2)); i++) {
		cont = (cont+i)%p;
		arr[cont] = 1;
	}

	int ans = 0;
	for(int i = 0; i < p; i++) 
		ans += arr[i];
	cout <<ans <<endl;

	return 0;
}

