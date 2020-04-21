#include<bits/stdc++.h>
using namespace std;

int main(){
	    
    int n, m;
    cin>>n >>m;

    int total=0, aux=0, tam;
    for(int i=0; i<n; i++){
	    cin >>tam;
	    tam+=aux;
	    aux = m-tam;
	    total+=abs(aux);
    }

    cout <<total;
    return 0;
}
