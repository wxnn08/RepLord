#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
  
vector<string> separaPalavras(string s){
    vector<string> p;
    string palavra="";

    for(int i=0; i<s.length(); i++){
	if(s[i]==' '){
	    p.pb(palavra);
	    palavra="";
	}
	else{
	    palavra+=s[i];
	}
    }
    p.pb(palavra);
    
    return p;
}


int main(){

    //le t
    int t;
    cin >>t;

    //repete 1-t
    for(int i=0; i<t; i++){

	//le m- dicionario / le n- quantidade de frases
	int m, n;
	cin >>m >>n;

	//é necessario dar um get char devido ao \n do cin>>n
	getchar();

	//cria e mapeia dicionario
	map<string, string> dic;
	string jap, port;

	for(int j=0; j<m; j++){
	    getline(cin,jap);
	    getline(cin,port);
	    dic.insert(mk(jap, port));
	}

	//traduz
	map<string, string>::iterator it;
	
	for(int k=0; k<n; k++){
	    getline(cin,jap);
	    vector<string> palavra = separaPalavras(jap);
	    
	    for(int l=0; l<palavra.size(); l++){
		it = dic.find(palavra[l]);
		if(it!=dic.end()){
		    cout <<it->sec <<' ';
		}
		else cout <<palavra[l] <<' ';
	    }
	    cout <<endl;
	}
	cout <<endl;
    }
    return 0;
}
