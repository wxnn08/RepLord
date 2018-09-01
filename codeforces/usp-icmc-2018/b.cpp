#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);
	
	string s;
	int n;
	cin >>n >>s;
	
	bool res = true;
	for(int i=1; i<n && res; i++){
		if(s[i]<s[0]) res = false;
		else if(s[i] == s[0]) {
			int cont = 0;
			for(int j=0; cont<n && res; j++){
				if(s[(i+j)%n]<s[j%n]) res = false;
				cont++;
			}
		}
	}
	
	cout <<(res ? "Yes":"No") <<endl;
    
    return 0;
}

