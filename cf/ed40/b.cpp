#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int cont=0;
string a;

void trata(int t){
    if(t==0 || t==1 || t==2){
	cont+=t;
	return;
    }
    
    cont+=t%2;
    t-=(t%2);

    int ini = t/2;
    string str1 = a.substr(0,t/2);
    string str2 = a.substr(t/2,t/2);

    if(str1==str2){
	cont+=(str1.length()+1);
    }
    else{
	t-=2;
	cont+=2;
	trata(t);
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    // le string
    int n;
    cin>>n;
    cin >>a;

    //tamanho
    int t = n;
    trata(t); 
    cout <<cont <<endl;    
    return 0;
}

