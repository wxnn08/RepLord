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

	int cont8 = 0, contN = 0;
	for(int i = 0; i < n; i++) {
		char c; int v;
		cin >>c;
		v = c - '0';
		if(v == 8) cont8++;
		else contN++;
	}
    int ans = min(cont8, contN/10);
	cont8 -= ans;
	contN  = contN - ans*10;
	while(cont8 > 0) {
		contN++;
		cont8--;
		if(cont8 > 0 and contN >= 10) {
			cont8--;
			contN-=10;
			ans++;
		}
	}

	cout <<ans <<endl;
    return 0;
}

