#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    int myints[]={75,23,65,42,42,13};
    set<int> myset(myints, myints+6);

    for(set<int>::iterator it=myset.begin(); it!=myset.end(); ++it){
	cout << ' ' <<*it;
    }
    
    cout <<endl;
    return 0;
}

