#include<iostream>
//packages for reading files in
#include<streambuf>
#include<fstream>
//count is included in following package
#include <algorithm>

//file in string
std::string GanzeDatei(const std::string& dateiname) {

    //open file for reading
     std::ifstream ifs(dateiname);

    //reading everything
     return std::string((std::istreambuf_iterator<char>(ifs)),
    //giving it out in string
                        (std::istreambuf_iterator<char>()));
}


int main(){

    //file selection
    std::string filename="rot.txt";

    //input into string
    std::string inhalt=GanzeDatei(filename);

    //going through the differnt chars
    for (int i = 32; i <=127; i++) {
        char currentChar = i;

            //counting every char
            int count = std::count(inhalt.begin(), inhalt.end(), i);
            std::cout << currentChar << " : ";

            // printing # every 10 char
            for (int j = 0; j <= count; j++) {
                if (j % 100 == 0) {
                    std::cout << "#";
                }
            }
            std::cout << " (" << count << ")" << std::endl;
    }
}
