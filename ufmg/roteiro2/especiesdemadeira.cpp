#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){

    int n;
    cin >>n;
    string s;
    getchar();
    getline(cin, s);
    for(int j=0; j<n; j++){
	map <string, int> m;
	int cont=0;
	while(getline(cin, s), s!=""){
	    m[s]++;
	    cont++;
	}
	
	map<string, int>::iterator it;
	double pop;
	for(it=m.begin(); it!=m.end(); it++){
	    pop = ((double)(it->sec)/cont)*100;
	    cout <<it->fi <<' ' <<setprecision(4) <<fixed <<pop <<endl;
	}
	if(j!=n-1) cout <<endl;
    }
    return 0;
}

