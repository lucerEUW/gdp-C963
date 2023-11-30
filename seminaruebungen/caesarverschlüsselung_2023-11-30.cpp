#include<iostream>
#include<string>

char caesar(char in) {
    //offset
    int verschiebung = 3;
    char out = in;

    //deselecting any non-letter
    if (!isalpha(in)) {
        return in;
    }

    //selecting every letter
    //uppercase chars
    if (isupper(in)) {

        out = 'A' + (in - 'A' + verschiebung) % 26;
                    //in - & --gives position in our range
                                //+our offshift
                                            //mod(26) so it loops in just the alphabet
            //+ A -- converting back to uppecase letter

    //selectin lower case letters
    } else if (islower(in)) {

        out = 'a' + (in - 'a' + verschiebung) % 26;
    }

    return out;
}
int main(){

    //getting input
	std::cout<<"enter string: ";
	std::string inputString;
	std::cin >> inputString;
	std::cout<<"output string: ";
	
    //for chars of string
	char out;
	for(int i=0;i<inputString.size();i++){
        //out chars
		char out = caesar(inputString.at(i));
		std::cout << out;
	}
    std::cout<<std::endl;
}