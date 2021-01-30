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

    int n1=0, n0=0;
    char c;

    int n;
    cin >>n;

    for(int i=0; i<n; i++){
	cin >>c;
	if(c-'0'==0) n0++;
	else n1++;
    }
    
    if(n1!=0)cout <<'1';
    for(int i=0; i<n0; i++) cout <<'0';
    cout <<endl;

    return 0;
}

