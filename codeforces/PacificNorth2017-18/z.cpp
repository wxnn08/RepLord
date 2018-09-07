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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

	int n; cin >> n;    
	int cont = n;
	while(true) {
		cont++;
		string tmp = to_string(cont);
		bool flag = true;
		for(int i = 0; i < tmp.length(); i++) {
			if(tmp[i] == '0')
				flag = false;
		}
		if(flag) break;
	}
	cout << cont << endl;
    return 0;
}

