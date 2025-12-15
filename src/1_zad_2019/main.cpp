


//      g++ -std=c++20 main.cpp -o main



#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>    
#include <stdexcept> 
#include <exception>
#include <algorithm>      //    transform



int oblicz_pelne_paliwo(int masa) 
{
    int paliwo_modulu = (masa / 3) - 2;         //  zaokrąglanie w dół robi sie samo bo to inty
    int total = 0;
    int aktualne = paliwo_modulu;
    
    while (aktualne > 0) {
        total += aktualne;
        aktualne = (aktualne / 3) - 2;
    }
    return total;
}


int main() 
{
    try
    {
        int x = 0;
        
        std::vector<int> masa_czlonu ;
        std::vector<int> paliwo ;

        std::ifstream inFile;
        
        inFile.open("input.txt");
        if (!inFile) {
            throw std::runtime_error("problemy z plikiem ");
        }
        
        while (inFile >> x) {
            masa_czlonu.push_back(x);        //  wektor masy członów
        }
        inFile.close();

        paliwo.resize(masa_czlonu.size());      // żeby paliwo był takiego samego rozmiaru jak masa_czlonu

        std::ranges::transform(masa_czlonu, paliwo.begin(), oblicz_pelne_paliwo);   //    paliwo = oblicz_paliwo(masa_czlonu)

        double sum = std::accumulate(paliwo.begin(), paliwo.end(), 0);

        std::cout << "Sum = " << sum << "\n"; 
    }
    catch(const std::exception& e)
    {
        std::cerr << "BLAD: " << e.what() << "\n";
        return 1;    }
    return 0;
}