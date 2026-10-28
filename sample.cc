#include <fstream>
#include <iostream>
#include <cmath>

int main(){
std::ifstream fin("sums.txt");
double a;
int n = 0;
double sum = 0.0;
while ( fin >> a ) {
sum += a ;
++ n ;
}
double mean = sum/n;
std::cout << sum/n << std::endl;
fin.close();

sum = 0.0;
fin.open("sums.txt");
while ( fin >> a ) {
sum += (a-mean) * (a-mean);
}
double variance = sum/n;
std::cout << variance << std::endl;
fin.close();
double std = sqrt(variance);
std::cout << std << std::endl;
}