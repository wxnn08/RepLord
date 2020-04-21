#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int escolheValor(int ant, int m, int a){
    int res = 0;
    if(a>=ant) res+=1;
    if((m-a)>=ant) res+=2;
    
    if(res==0) return -1;
    if(res==1) return a;
    if(res==2) return (m-a);
    if(res==3){
	if((m-a)<a) return (m-a);
	else return a;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >>n >>m;
    
    int med[10005];
    for(int i=0; i<n; i++){
	cin >>med[i];
    }

    if(m-med[0]<med[0]) med[0]=m-med[0];

    ll res=0, total=med[0];
    for(int i=1; i<n && res!=-1; i++){
	res = escolheValor(med[i-1], m, med[i]);
	med[i]=res;
	total+=res;
    }

    if(res==-1) cout <<-1;
    else cout <<total;
    return 0;
}

