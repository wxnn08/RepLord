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
 
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	const int N = 2e3 + 5;
	int v[N];

	cin >>v[0];
	int ac = v[0], cont1 = 0;
	if(v[0] == 1) cont1++;

	fori(i, 1, n) {
		cin >>v[i];
		if(v[i] == 1) cont1++;
		ac = gcd(ac, v[i]);
	}

	if(ac != 1) {
		cout <<-1 <<endl;
		return 0;
	}

	if(cont1 > 0) {
		cout <<n-cont1 <<endl;
		return 0;
	}

	int menor = INF;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(gcd(v[i], v[j]) == 1) menor = min(menor,j-i-1);
		}
	}
	int ans = 0;
	if(menor != INF) {
		ans = menor;
	}
	else ans = 1;

	cout <<ans+(n-cont1) <<endl;

	return 0;
}
