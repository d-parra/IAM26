#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

double poisson(double mu, int k){
    return (pow(mu, k)*exp(-mu))/tgamma(k+1);
}

double prob(const std::vector<int>& data, double mu){
    double like = 1;
    for(int k:data){
        like *= poisson(mu, k);
    }
    return like;
}

int main(){
    std::ifstream fin("sums.txt");
    std::ofstream fout("likelihood.txt");
    std::ofstream fout2("nll.txt");
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

    for(double i=0.0; i <= 6; i+=0.1)
    {
        fout << i << " " << prob(data, i) << std::endl;
        fout2 << i << " " << -2*std::log(prob(data, i)) << std::endl;
    }
    fin.close();
    fout.close();
    fout2.close();
}