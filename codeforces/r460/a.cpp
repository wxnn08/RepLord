#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

	double n, m;
	cin >>n >>m;
	double menor = 99999999;
	fori(i,0,n){
		double a, b;
		cin >>a >>b;
		double res = (a*m)/b;
		menor = min(menor, res);
	}
	
	cout <<setprecision(8) <<fixed <<menor <<endl;
    
    return 0;
}

