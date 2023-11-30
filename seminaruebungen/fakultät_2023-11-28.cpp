#include<iostream>
using namespace std;

int fakultaet(int x) {
	if(x > 1) {
		return x * fakultaet(x-1);
	}else {
		return 1;
	}
}
/*altenative 
n...ausgabe
fak...ausgabe
kopfgeprüfte:
if(n>0){
    for(int i=1,i<=n,i++){
        fak*=i;
    }
}
if(n>0){
    do{
        fak *= n;
        n--;
    }while(n>0)
}
*/
int main(){
    start:
    cout<<"enter number: ";
    int number;
    cin>>number;
    if(number<0){
        cout<<"not valid"<<endl;
        goto start;
    }
    else if(number>0){
        cout<<fakultaet(number)<<endl;
    }
    else{
        cout<<"1"<<endl;
    }
    goto start;
}

