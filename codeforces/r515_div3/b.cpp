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

    int n, r;
	cin >>n >>r;
	int cont = 0;
	const int N = 1e3 + 5;
	int v[N];
	fori(i, 0, n) {
		cin >>v[i];
		if(v[i] == 1) cont++;
	}
    
	double reg = ((r-1)*2)+1;
	double total = ceil(n/reg);
	if(cont < total) {
		cout <<-1 <<endl;
		return 0;
	}
	int ans = 0;
	int l1 = -1;
	for(int i = r-1; i >= 0 and i < n;) {
		if(i == l1) {
			cout <<-1 <<endl;
			return 0;
		}
		if(v[i] == 1) {
			l1 = i;
			i += (2*(r-1)+1);
			ans++;
		}
		else i--;
	}
	
	if(l1+(r-1) < n-1) {
		for(int i = (n-1)-(r-1); i < n; i++) {
			if(v[i] == 1){
				cout <<ans+1 <<endl;
				return 0;
			}
		}
		cout <<-1 <<endl;
		return 0;
	}

	cout <<ans <<endl;

    return 0;
}

