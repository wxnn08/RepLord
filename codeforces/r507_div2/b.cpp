#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, k;
	cin >>n >>k;
	vector<int> aux, res;
	for(int i=0; i<=k; i++){
		int j=i;
		while(j<n){
			aux.pb(j+1);
			j+=2*k+1;
		}
		j-=2*k+1;
		if(j+k>=n-1) {
			if(res.size()==0) res = aux;
			else if(res.size()>aux.size()) res = aux;
		}
		aux.clear();
	}
	cout <<res.size() <<endl;
	for(int i:res) cout <<i <<' ';
	cout <<endl;

    return 0;
}

