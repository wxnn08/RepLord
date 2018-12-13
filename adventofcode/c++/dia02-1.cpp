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
	
	string s;
	ll cont2 = 0 , cont3 = 0;
    while(cin >>s) {
		ll qtd[30], aux2 = 0, aux3 = 0;
		memset(qtd, 0, sizeof qtd);
		for(int i = 0; i < s.size(); i++) {
			int pos = s[i] - 'a';
			qtd[pos]++;
			if(qtd[pos] == 2) aux2++;
			if(qtd[pos] == 3) {
				aux2--;
				aux3++;
			}
			if(qtd[pos] == 4) aux3--;
		}
		cont2 += (aux2>0?1:0);
		cont3 += (aux3>0?1:0);
	}
	
	cout <<cont2*cont3 <<endl;
    return 0;
}

