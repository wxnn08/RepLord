#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int medidas[100005];

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;
    
    set<int> range;
    int aux;

    for(int i=0; i<n; i++){
	cin >>aux;
	medidas[i]=aux;
	range.insert(aux);
    }
    
    int min, med, max, contMin=0, contMed=0, contMax=0;
    set<int>::iterator it = range.begin();
    
    med=min=max=999999;

    min = *it;
    if(range.size()>2) med = *(++it);
    if(range.size()>1) max = *(++it);

    for(int i=0; i<n; i++){
	if(medidas[i]==min) contMin++;
	if(medidas[i]==med) contMed++;
	if(medidas[i]==max) contMax++;
    }

    if(range.size()>1){
	if(max-min==2){
	    int menor;
	    if(contMin<contMax) menor=contMin;
	    else menor=contMax;	

	    int n1 = n-(2*menor);
	    int n2=999999;
	    if(range.size()==3) n2 = n-(contMed-contMed%2);
	    
	    if(n1<=n2){
		contMin-=menor;
		contMax-=menor;
		contMed+=(2*menor);
		med=(min+max)/2;
		n=n1;
	    }
	    else{
		menor=contMed/2;
		contMin+=menor;
		contMax+=menor;
		contMed-=(2*menor);
		n=n2;
	    }
	}
    }

    cout <<n <<endl;

    for(int i=0; i<contMax; i++){
	cout <<max <<' ';
    }
    for(int i=0; i<contMed; i++){
	cout <<med <<' ';
    }
    for(int i=0; i<contMin; i++){
	cout <<min <<' ';
    }

    cout <<endl;

    return 0;
}

