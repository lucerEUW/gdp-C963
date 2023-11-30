#include<iostream>

int summe(int a, int b) {
    if (a > b) {
        return 0; 
    }
    if (a == b) {
        return a; 
    }
    if (a + 2 > b) {
        return a; 
    }
    return a + summe(a + 2, b);
}

int main(){
	int a, b;
	std::cout<<"a b =";
	std::cin>> a >> b;
	std::cout<<"summe:"<<summe(a,b)<<std::endl;
}
