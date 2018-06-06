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

    int n;
    cin >>n;

    string s, newS;
    set <string> a;
    int cont=0;

    while(n--){
	cin >>s;
	sort(s.begin(), s.end());
	
	newS = "";
	for(int i=0; i<s.length(); i++){
	    if(newS.length()==0) newS+=s[i];
	    else if(newS[newS.length()-1] != s[i]) newS+=s[i];
	}
	
	if(!a.count(newS)) cont++;
	a.insert(newS);
    }

    cout <<cont <<endl;
    

    return 0;
}

