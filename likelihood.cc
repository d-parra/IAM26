#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

double poisson(double mu, int k){
    return (pow(mu, k)*exp(-mu))/tgamma(k+1);
}

double prob(const std::vector<int>& data, double mu){
    double like = 1.0;
    for(int k:data){
        like *= poisson(mu, k);
    }
    return like;
}

double nll(const std::vector<int>& data, double mu){
    double like = 0.0;
    for(int k:data){
        like += std::log(poisson(mu, k));
    }
    return like;
}

double sat(const std::vector<int>& data, double mu){
    double numerator = prob(data, mu);
    double denominator = 1.0;
    for(int k:data){
        denominator *= poisson(k, k);
    }
    return numerator/denominator;
}

int main(){
    std::ifstream fin("sums.txt");
    std::ofstream fout("likelihood.txt");
    std::ofstream fout2("nll.txt");
    std::ofstream fout3("deltanll.txt");
    std::vector<int> data;

    double a;
    int n = 0;
    double sum = 0.0;
    while(fin >> a) {
        sum += a ;
        ++ n ;
    }
    double mean = sum/n;
    std::cout << "mean:" << mean << std::endl;
    fin.close();
    fin.open("sums.txt");
    double number;
    while(fin >> number) {
        data.push_back(number);
    }
    double likelihood = prob(data, mean);
    std::cout << "likelihood:" << likelihood << std::endl;
    std::cout << "sigma/sqrt(N):" << sqrt(2.73455)/sqrt(n) << std::endl;
    std::cout << "sqrt(mu/N):" << sqrt(mean/n) << std::endl;

    double saturated = sat(data, mean);

    std::cout << "saturated model:" << -2*log(saturated) << std::endl;
    std::cout << "deviation:" << (-2*log(saturated)-233)/sqrt(2*233) << std::endl;

    for(double i=0.0; i <= 6; i+=0.1)
    {
        fout << i << " " << prob(data, i) << std::endl;
        fout2 << i << " " << -2*nll(data, i) << std::endl;
        fout3 << i << " " << -2*nll(data, i) + 2*nll(data, mean) << std::endl;
    }
    fin.close();
    fout.close();
    fout2.close();
    fout3.close();
}