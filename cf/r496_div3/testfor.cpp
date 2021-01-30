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

    int a[10];
	a[0]=0;
	a[1]=1;

	vector<int> v;
	v.pb(0);
	v.pb(1);

	for(int i:a){
		cout <<i <<' ';
	}
	cout <<endl;
    
	for(int i:v){
		cout <<i <<' ';
	}
	cout <<endl;
    return 0;
}

