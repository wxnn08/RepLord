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

    int n;
	cin >>n;
	
	int sum1 = 0, sum2 = 0;
	bool ans = true;
	for(int i = 0; i < n; i++) {
		char v; cin >>v;
		if(v != '4' and v != '7') ans = false;
		if(i < n/2) sum1 += (v-'0');
		else sum2 += (v-'0');
	}
	if(sum1 != sum2) ans = false;
	cout <<(ans?"YES":"NO") <<endl;
    
    return 0;
}

