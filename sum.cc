#include <fstream>
#include <iostream>

int main(){
    std::ifstream fin("data.txt");
    std::ofstream fout("sums.txt");
    int number1;
    int number2;
    for(int i =0; i<234; i++){
        fin >> number1 >> number2;   
        std::cout << number1+number2 << std::endl;
        fout << number1+number2 << std::endl;
    }
    fout.close();
    fin.close();
}