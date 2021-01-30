#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int medidas[100005];

int main(){
    ios_base::sync_with_stdio(false);

    //le n -> numero de medidas
    int n;
    cin >>n;
    
    //ler medidas 0 a n-1
    int aux, max=-999999, min=999999, med;
    for(int i=0; i<n; i++){
	cin >>aux;
	medidas[i]=aux;
	
	if(aux<min) min=aux;
	if(aux>max) max=aux;
    }
    med = (min+max)/2;

    int contMax=0, contMin=0, contMed=0;
    //conta max, med e min
    for(int i=0; i<n; i++){
	if(medidas[i]==min) contMin++;
	else if(medidas[i]==max) contMax++;
	else if(medidas[i]==med) contMed++;
    }

    //se med!=min && med!=max
    if(med>min && med<max){
	//encontrar o menor entre contMax e contMin
	int menor;
	if(contMax<contMin) menor=contMax;
	else menor=contMin;
	
	//remover menor de max e min
	contMin-=menor;
	contMax-=menor;

	//adicionar menor em med
	contMed+=(2*menor);

	//remover 2*menor de n
	n-=(2*menor);
    }
    //imprime n
    cout <<n <<endl;
    //imprime max, med e min
    for(int i=0; i<contMin; i++){
	cout <<min <<" ";
    }
    for(int i=0; i<contMed; i++){
	cout <<med <<" ";
    }
    for(int i=0; i<contMax; i++){
	cout <<max <<" ";
    }
    cout <<endl;
    return 0;
}

