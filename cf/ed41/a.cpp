#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

const int INF = 0x3f3f3f3f;

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    map<int, int> ma;
    int n, m;
    cin >>n >>m;
    
    int x;
    for(int i=0; i<n; i++){
	ma[i+1]=0;
    }
    for(int i=0; i<m; i++){
	cin >>x;
	ma[x]++;
    }
    
    map<int,int>::iterator it;
    int mi = INF;
    for(it=ma.begin(); it!=ma.end(); it++){
	mi = min(mi ,it->sec);
    }
    
    cout <<mi <<endl;
    return 0;
}

