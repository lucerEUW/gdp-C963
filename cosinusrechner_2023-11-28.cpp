#include<iostream>
#include<cmath>

int fak(int n)
{
	if(n == 0){
		return 1;
	}else{
		return fak(n - 1) * n;
	}
}

int main (){
	std::cout << "X-Werteingeben: ";
	double x;
	std::cin >> x;
	double cos = 0.0;
	x=M_PI /180.0*x; //umrechnung grad.bogen
	for (int i = 0; i <= 6; i++){
		cos += (pow(-1,i) * pow(x,2.0*i)) / (fak(2*i));
	}
	std::cout << "cos("<< x << ") = " << cos;
}
