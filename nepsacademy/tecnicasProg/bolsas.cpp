#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;
    

    int max=0, total=0, t, d;
    for(int i=0; i<n; i++){
	cin >>t >>d;
	total+=t;
	if(d>max) max=d;
    }

    if(total>max) cout<<(total-max) <<endl;
    else cout <<0;

    return 0;
}

