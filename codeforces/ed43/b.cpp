#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, m, k, lin, col;
    cin >>n >>m >>k;

    if(k<n) {
	cout <<1+k <<' ' <<"1" <<endl;
	return 0;
    }

    int res = (k-n+1)/(m-1);
    lin = n-res;

    if((k-n+1)%(m-1)==0) lin--;

    k-=(lin*(m-1));
    
    if(res%2==0) col = 1+k;
    else col = m-k+1;

    cout <<lin <<' ' <<col <<endl;
    
    return 0;
}

