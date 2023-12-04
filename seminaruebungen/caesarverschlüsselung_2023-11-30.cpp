#include<iostream>
#include<string>
#include<iomanip>

//checking for upper
bool isUpperCase(char c){

    return(c >= 'A' && c <= 'Z');
}

//checking for lower
bool isLowerCase(char c){

    return(c >= 'a' && c <= 'z');
}

//ciphering char
char cipherChar(char z, int key){

    char cipher = z;

    if( isUpperCase( z ) ){

        cipher = ( z - 'A' + key ) % 26 + 'A';
    }
    if( isLowerCase( z ) ){

        cipher = ( z - 'a' + key ) % 26 + 'a';
    }else{

        cipher = z;
    }
}

//cipherfunc
std::string cipherLine(std::string z, int key){

    for(unsigned int i = 0 ; i < z.size() ; i++){
        z.at(i) = cipherChar( z.at(i) , key );
    }
    return z;
}

int main(){ 

    //get input and open setw
    std::cout << std::setw(15) << "input: ";
    std::string zeile;
    std::getline( std::cin , zeile );

    //output control
    std::cout << std::setw(15) << "control: "<<zeile<<std::endl;

    //output ciphered
    std::cout << std::setw(15) << "ciphered: " << cipherLine( zeile, 3 ) << std::endl;
}
