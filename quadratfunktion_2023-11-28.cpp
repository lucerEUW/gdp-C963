#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cout<<"lsg einer quadratischen gleichung"<<endl;
    double a,b,c;
    cout<<"eingabe[a b c]: ";
    cin>>a, b, c;
    
    if(a!=0){
        double discriminante=b*b-4.0*a*c;
        if(discriminante==0){
                cout<<"1 lineare lsg"<<endl;
        }else{
            if(discriminante>0){
                double x1,x2;
                x1=(-b+sqrt(discriminante))/(2*a);
                x2=(-b-sqrt(discriminante))/(2*a);
                cout<<x1<<x2;
            }else{
                double real, imag;
                real= -b/(2*a);
                imag= (sqrt(-discriminante))/(2*a);
                cout<<"x1 ="<<real<<"+j"<<imag<<"x2 ="<<real<<"-j"<<imag<<endl;
            }
        }
    }else{
        if(b!=0){
                double x=-c/b;
                cout<<x;
        }else{
            if(c==0){
                cout<<"unendlich viele lsg"<<endl;
            }else{
                cout<<"oo lsg"<<endl;
            }
        }
    }
}
