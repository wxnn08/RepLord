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
	
	char c;
	int cont = -1;
	bool ans = true;
	while(cin >>c and ans) {
		if(c == '1') cont = 0;
		else if(c == '4'){
			if(cont == -1) ans = false;
			cont++;
		}
		else ans = false;
		if(cont > 2) ans = false;
	}

	cout <<(ans?"YES":"NO") <<endl;
    
    return 0;
}

