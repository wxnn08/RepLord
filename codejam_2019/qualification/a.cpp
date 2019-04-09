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

    int tc;
	cin >>tc;
	
	for(int i = 1; i <= tc; i++){
		bool f = false;
		string s;
		cin >>s;
		string n1 = "", n2 = "";
		for(char at:s) {
			if(at == '4') {
				n1 += '3';
				n2 += '1';
				f = true;
			} else {
				n1 += at;
				if(f) n2 += '0';
			}
		}
		cout <<"Case #" <<i <<": " <<n1 <<' ' <<(f?n2:"0") <<endl;
	}
    
    return 0;
}

