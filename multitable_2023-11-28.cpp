#include<iostream>
#include<iomanip>
using std::cout;

int main(){
    int tiefe = 10;
    for (int  i= 1; i <=tiefe; i++)
    {
        for(int j=1; j <= tiefe; j++)
        {
            cout<<std::setw(4)<<i*j;
        }
        cout<<std::endl;
    }
}
