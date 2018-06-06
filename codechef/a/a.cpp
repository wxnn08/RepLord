#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;

string ganhador(){
    int n;
    cin >>n;
   
    int aux;

    //le tempos alice
    int somaA=0, maiorA=0;
    for(int i=0; i<n; i++){
	cin >>aux;
	somaA+=aux;
	if(aux>maiorA) maiorA=aux;
    }
    somaA-=maiorA;

    //le tempos bob 
    int somaB=0, maiorB=0;
    for(int i=0; i<n; i++){
	cin >>aux;
	somaB+=aux;
	if(aux>maiorB) maiorB=aux;
    }
    somaB-=maiorB;

    if(somaA>somaB) return "Bob";
    if(somaA<somaB) return "Alice";
    return "Draw";
}


int main(){

    //le T
    int t;
    cin >>t;

    //para cada T
    for(int i=0; i<t; i++){
	cout <<ganhador() <<endl;
    }

    return 0;
}

