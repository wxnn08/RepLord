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
 
int main(){
    ios_base::sync_with_stdio(false);
	
	const int N = 1e5 + 5;
    int n, v[N];
	cin >>n;
	
	cin >>v[0];
	int j = 0, u = v[0], n1 = v[0], n2 = v[0], ans = 0, cont = 1;

	for(int i = 1; i < n; i++) {
		cin >>v[i];
		if(v[i] != n1 and v[i] != n2) {
			ans = max(ans, cont);
			cont = i-j;
			n1 = v[i];
			n2 = v[j];
		}

		if(v[i] != u) j = i;
		cont++;
		u = v[i];
	}

    ans = max(ans, cont);
	cout <<ans <<endl;

    return 0;
}

