#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
#define MAX 10005
#define MOD 1000000007
ll nFib[MAX];

ll fib(int n){
    if(nFib[n]!=-1) return nFib[n];
    return nFib[n] = (fib(n-1)+fib(n-2))%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    
    nFib[0]=0;
    nFib[1]=1;
    for(int i=2; i<MAX; i++)
	nFib[i]=-1;
    
    int n;
    cin >>n;

    int t;
    for(int i=0; i<n; i++){
	cin >>t;
	cout <<fib(t) <<endl;
    }
    
    return 0;
}

