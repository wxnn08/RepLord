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

    int r,g,b;
	cin >>hex >>r >>g >>b;
	
	ll qtdG = r/g;
	qtdG = pow(qtdG, 2);
    
	ll qtdB = g/b;
	qtdB = pow(qtdB,2);
	
	cout <<hex <<(qtdB*qtdG)+(qtdG)+1 <<endl;

    return 0;
}

