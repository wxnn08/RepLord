#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,i=1;
	cin >>n;

	int acess, total=0, num=0;
	while(i<=n){
		
		cin >>acess;
		total = total+acess;
		
		if(total>=1000000 && num==0) num = i;
			
		i++;
	}
	cout <<num;

return 0;
}
