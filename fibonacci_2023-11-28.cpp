#include<iostream>
using std::cout;
using std::cin;
int main(){
    cout<<"zahl: ";
    int n;
    cin>>n;
    if(n<3){
        cout<<"fibonaccizahl: 1"<<std::endl;
    }else{
        int fibn =0;
        int fibn1=1;
        int fibn2=1;
        for(int i=3;i<=n;i++){
            fibn=fibn2+fibn1;
            fibn2=fibn1;
            fibn1=fibn;
        }
        cout<<"zahl"<<n<<" -> "<<"fib zahl: "<<fibn<<std::endl;
    }
}
