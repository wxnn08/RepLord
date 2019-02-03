#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, d;
	cin >>n >>d;
	
	const int N = 1e2+5;
	int v[N];
	int a;
	cin >>a;
	if(a < 0) {
		a = abs(a);
		v[0] = 0;
	}
	else {
		v[0] = a;
		a = 0;
	}
	for(int i = 1; i < n; i++) {
		cin >>v[i];
		v[i] += a;
	}

	int ans = 2;
	for(int i = 0; i < n-1; i++) {
		if(v[i+1] - (v[i]+d) > d) ans+=2;
		else if(v[i+1] - (v[i]+d) == d) ans++;
	}

	cout <<ans <<endl;
    return 0;
}

