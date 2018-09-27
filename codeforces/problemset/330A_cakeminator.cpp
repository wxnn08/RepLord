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

    int r, c;
	cin >>r >>c;
	char m[15][15];
	fori(i,0,r) {
		fori(j,0,c) {
		cin >>m[i][j];
		}
	}
    
	int cr = 0, cc = 0;
	fori(i,0,r){
		int cont = 0;
		fori(j,0,c) {
			if(m[i][j] == '.') cont++;
		}
		if(cont == c) cr++;
	}

	fori(i,0,c){
		int cont = 0;
		fori(j,0,r) {
			if(m[j][i] == '.') cont++;
		}
		if(cont == r) cc++;
	}

	int ans = (cr*c) + (cc*r) - (cr*cc);
	cout <<ans <<endl;

    return 0;
}

