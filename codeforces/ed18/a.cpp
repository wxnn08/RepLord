#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int a;
		cin >>a;
		v.pb(a);
	}

	sort(v.begin(), v.end());
	
	int menor = v[1]-v[0];
	for(int i = 1; i < n; i++) {
		menor = min(abs(v[i]-v[i-1]), menor);
	}
	
	int qtd = 0;
	for(int i = 1; i < n; i++) {
		if(abs(v[i]-v[i-1]) == menor) qtd++;
	}

	cout <<menor <<' ' <<qtd <<endl;

    return 0;
}

