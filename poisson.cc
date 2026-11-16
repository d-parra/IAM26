#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

double poisson(double mu, int k){
    return (pow(mu, k)*exp(-mu))/tgamma(k+1);
}


int main(){
    std::ifstream fin("sums.txt");
    std::ofstream fout("histpoi.txt");
    std::vector<int> counts(11);

    double a;
    int n = 0;
    double sum = 0.0;
    while(fin >> a) {
        sum += a ;
        ++ n ;
        counts.at(a) += 1;
    }
    double mean = sum/n;
    std::cout << "mean:" << mean << std::endl;
    for(unsigned int k = 0; k < counts.size(); ++ k ){
        std :: cout << k << ":" << counts [k] << std::endl;
        fout << k << " " << counts[k] << " "  << n*poisson(mean, k) << std::endl;
    }
    fin.close();
    fout.close();
}