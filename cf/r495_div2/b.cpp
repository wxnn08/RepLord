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
	
	int n, m;
	cin >>n >>m;
	
	int v = 0;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >>a >>b;
	}

	for(int i = 0; i < n; i++) {
		cout <<v;
		v = 1-v;
	}
	cout <<endl;

	return 0;
}

