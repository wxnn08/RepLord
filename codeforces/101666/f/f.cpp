/*29/08/2020*/
#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

	int n; cin >>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >>v[i];
	sort(v.begin(), v.end(), greater<int>());
	int a = 0, b = 0;
	for(int i = 0; i < n; i++) {
		if(i&1) b += v[i];
		else a += v[i];
	}
	cout <<a <<' ' <<b <<endl;
	

    return 0;
}
