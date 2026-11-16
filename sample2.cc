#include <fstream>
#include <iostream>
#include <cmath>

int main(){
std::ifstream fin("sums.txt");
std::ofstream fout("means.txt");
double a;
int n = 0;
int m = 0;
double sum = 0.0;
double means_sum = 0.0;
while (fin >> a) {
sum += a;
++n;
if(n==9){
    fout << sum/n <<std::endl;
    means_sum += sum/n;
    sum=0;
    n=0;
    ++m;
}
}
double mean_of_means = means_sum/m;
std::cout << mean_of_means << std::endl;
fout.close();
fin.close();

sum = 0.0;
means_sum = 0.0;
fin.open("sums.txt");
std::ifstream fin2("means.txt");
std::ofstream fout2("variances.txt");
double mean = 0.0;
n = 0;
m = 0;
fin2 >> mean;
while(fin >> a) {
sum += (a-mean) * (a-mean);
means_sum += (mean-mean_of_means) * (mean-mean_of_means);
++n;
++m;
if(n==9){
    fout2 << sum/n <<std::endl;
    fin2 >> mean;
    sum=0;
    n=0;
}
}
std::cout << sqrt(means_sum/m) << std::endl;
fin.close();
fin2.close();
fout2.close();
}