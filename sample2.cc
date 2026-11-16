#include <fstream>
#include <iostream>
#include <cmath>

int main(){
std::ifstream fin("sums.txt");
std::ofstream fout("means.txt");
double a;
int n = 0;
double sum = 0.0;
while (fin >> a) {
sum += a;
++n;
if(n==9){
    fout << sum/n <<std::endl;
    sum=0;
    n=0;
}
}
fout.close();
fin.close();

sum = 0.0;
fin.open("sums.txt");
std::ifstream fin2("means.txt");
std::ofstream fout2("variances.txt");
double mean = 0.0;
n = 0;
fin2 >> mean;
while(fin >> a) {
sum += (a-mean) * (a-mean);
++n;
if(n==9){
    fout2 << sum/n <<std::endl;
    fin2 >> mean;
    sum=0;
    n=0;
}
}
fin.close();
fin2.close();
fout2.close();
}