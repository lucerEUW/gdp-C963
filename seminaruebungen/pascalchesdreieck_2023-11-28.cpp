#include<iostream>
#include<iomanip>

int pascal(int n, int k){
	if((k == 1) || (k ==n)){
		return 1;
	}
	else
	{
		return pascal(n-1, k-1)+ pascal(n-1,k);
	}
}

void printTriangle(int max){
	
	for(int i = 1; i<=max; i++){
		
		for(int z = 1; z<=max-i; z++){
			std::cout<<"   ";
		}
		for(int j = 1; j<=i; j++){
			std::cout << std::setw(6) << pascal(i,j);
		}
		std::cout<<std::endl;
	}
}

int  main(){
	std::cout << "how many lines? ";
	int lines = 0;
	std::cin >> lines;
	printTriangle(lines);
}
