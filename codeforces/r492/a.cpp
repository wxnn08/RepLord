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

	int n;
	cin >>n;
	int val[5] = {100,20,10,5,1};
	ll cont = 0;
	for(int i=0; i<5 && n!=0; i++){
		for(int j=0; n-val[i]>=0; j++){
			n-=val[i];
			cont ++;
		}
	}
	cout <<cont <<endl;

    
    return 0;
}

