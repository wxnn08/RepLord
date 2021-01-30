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
 
pair<int, int> qta, qtb; //qtd: 4, 7

int main(){
    ios_base::sync_with_stdio(false);

    string a, b;
	cin >>a >>b;
	int dif = 0;
	
	for(int i = 0; i < a.size(); i++) {
		if(a[i] == '4') qta.fi++;
		if(a[i] == '7') qta.sec++;
		if(b[i] == '4') qtb.fi++;
		if(b[i] == '7') qtb.sec++;

		if(a[i] != b[i]) dif++;
	}
	
	int ans = 0;
	if(dif > 0) {
		if(qta.fi != qtb.fi) {
			int v;
			if(qta.fi > qtb.fi) {
				v = qta.fi-qtb.fi;
				qtb.fi += v;
				qtb.sec -= v;
			}
			if(qta.fi < qtb.fi) {
				v = qtb.fi-qta.fi;
				qta.fi += v;
				qta.sec -= v;
			}
			ans += v;
		}
		if(qta.sec != qtb.sec) {
			int v;
			if(qta.sec > qtb.sec) {
				v = qta.sec-qtb.sec;
				qtb.sec += v;
				qtb.fi -= v;
			}
			if(qta.sec < qtb.sec) {
				v = qtb.sec-qta.sec;
				qta.sec += v;
				qta.fi -= v;
			}
			ans += v;
		}
		dif -= ans;
		if(dif > 0) {
			ans += dif/2;
		}
	}
	
	cout <<ans <<endl;
    return 0;
}

