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

    int a[20];
    fori(i, 0, 14) cin >>a[i];

    ll maior = 0, soma;

    int k;
    for(int i=0; i<14; i++){
	k=a[i];
	a[i]=0;
	ll vAll = k/14;
	ll vNex = k%14;

	soma=0;
	for(int j=1; j<=14; j++){
	    if(i+j<14){
		if(j<=vNex){
		    if((a[i+j]+vAll+1)%2==0)
			soma+=a[i+j]+vAll+1;
		} else {
		    if((a[i+j]+vAll)%2==0)
			soma+=a[i+j]+vAll;
		}

	    } else {
		if(j<=vNex){
		    if((a[i+j-14]+vAll+1)%2==0)
			soma+=a[i+j-14]+vAll+1;
		} else {
		    if((a[i+j-14]+vAll)%2==0)
			soma+=a[i+j-14]+vAll;
		}
	    }
	}
	a[i]=k;
	maior = max(soma, maior);
    }

    cout <<maior <<endl;
    
    return 0;
}

