#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int base1[105], base0[105];
int n;

int main(){
    ios_base::sync_with_stdio(false);

    cin >>n;

    for(int i=0; i<n; i++){
	base1[i]=1-(i%2);
	base0[i]=(i%2);
    }

    int num;
    for(int x=0; x<4; x++){
	int a=0;
	for(int i=0; i<n*n; i++){
	    cin >>num;
	    if(a==1 && num==0) cont;
	    if(a==0 && num==1) 
	}
    }
    
    return 0;
}

