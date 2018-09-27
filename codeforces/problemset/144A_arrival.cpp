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

    vector<int> v;
	int n;
	cin >>n;
	
	fori(i,0,n) {
		int p;
		cin >>p;
		v.pb(p);
	}
    
	int idmax = 0, idmin = 0;
	fori(i,0,n) {
		if(v[idmax] < v[i]) 
			idmax = i;
		if(v[idmin] >= v[i]) idmin = i;
	}
	
	int ans = idmax + (v.size() - idmin - 1);
	cout <<(idmax>idmin?ans-1:ans) <<endl;

    return 0;
}

