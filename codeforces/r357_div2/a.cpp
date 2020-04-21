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

    int n;
	cin >>n;
	bool ans = false;
	fori(i,0,n) {
		string s;
		int v, u;
		cin >>s >>v >>u;
		if(v >= 2400 and u > v) ans = true;
	}

	cout <<(ans?"YES":"NO") <<endl;
    
    return 0;
}

