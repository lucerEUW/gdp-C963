#include<iostream>
#include<cmath>

int main(){
	double inc=0.0;
	std::cout<<"C= ";
	std::cin>>inc;
	double x_n=1.0;
	std::cout<<"start x_n= "<<x_n<<std::endl;
	
	double e=0.000001;
	for (int i=0;e<fabs(x_n*x_n-inc);i++){
		x_n=x_n/2.0+inc/(2.0*x_n);
		std::cout<<"iteration "<<i<<" : "<<x_n<<std::endl<<"fehler: "<<fabs(x_n*x_n-						 													inc)<<std::endl;
	}
	std::cout<<"wurzel aus "<<inc<<" ist "<<x_n<<std::endl;
}
