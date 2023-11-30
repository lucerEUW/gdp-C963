#include <iostream>
using namespace std;

int main() {
    char letter = 'G';
    int asciiValue = static_cast<int>(letter);
    
    cout << "Der ASCII-Wert von 'G' ist: " << asciiValue << endl;
    
    return 0;
}
/*
int main() {
    char letterU = 'U';
    char letterR = 'R';
    int difference = letterU - letterR;
    
    cout << "Die Differenz zwischen 'U' und 'R' ist: " << difference << endl;
    
    return 0;
}
*/
