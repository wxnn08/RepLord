#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;

    map <int, int> m;
    int num;
    for(int i=0; i<n; i++){
	cin >>num;
	m[num]++;
    }
    map <int, int>::iterator it;
    pair <int, int> maior;
    maior = mk(-1,-1);
    for(it=m.begin(); it!=m.end(); it++){
	if(it->sec > maior.sec)
	    maior = mk(it->fi, it->sec);
	
    }

    cout <<maior.fi <<endl;
    
    return 0;
}

