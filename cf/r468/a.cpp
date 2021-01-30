#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    //le a e b
    int a, b;
    cin >>a >>b;

    //calcula o valor absoluto da diferença
    int dif = abs(a-b);
    
    //soma +1 até dif/2
    int soma=0, i;
    for(i=0; i<=dif/2; i++){
	soma += i;
    }

    //multiplica soma por 2 representando a somaancia de a e b até dif/2
    soma *= 2;

    //se a dif for impar, some i ao resultado. Esse valor representa a ultima casa necessária para ser andada
    if(dif%2) soma+=i; 
    
    //imprime somaancia
    cout <<soma <<endl;

    return 0;
}

