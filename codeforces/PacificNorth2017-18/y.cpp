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

double x, k, p;
double func(int n){
	return (double)n*x+((k*p)/n);
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >>k >>p >>x;
	
	double menor = func(1);
	fori(i,2,1e7) menor = min(menor, func(i));
	cout <<fixed <<setprecision(3) <<menor <<endl;
    
    return 0;
}

