#include<iostream>

int ggT(int a, int b){
	
	if(a<b){
		return ggT(b,a);
	}else if((a % b) == 0){
		return b;
	}else{
		return ggT(b, a % b);
	}
	
}

int main(){
	int a,b;
	std::cout<<"a b =";
	std::cout<<"ggt: "<<ggT(a,b)<<std::endl;
	std::cin>>a>>b;
}
