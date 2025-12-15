


    //  g++ -std=c++20 main.cpp -o main     
    //  przez unordered_set^

#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>          // do accumulate
#include <unordered_set> 
#include <stdexcept>
#include <exception>

int main() 
{
    try
    {
        int x = 0;
        std::vector<int> input;

        std::ifstream inFile;

        
        inFile.open("input.txt");
        if (!inFile) {
            throw std::runtime_error("problemy z plikiem ");
        }
        
        while (inFile >> x) {
            input.push_back(x);
        }
        inFile.close();

        double suma = std::accumulate(input.begin(), input.end(), 0);

        std::cout << "czesc pierwsza, suma: " << suma << "\n";

        std::unordered_set<double> historia;                //      hash map / hash function
        
        double czestotlwosc = 0;
        
        historia.insert(0);

        while(true)
        {
            for(int zmiana : input)
            {
                czestotlwosc += zmiana;

                if(historia.contains(czestotlwosc))
                {
                    std::cout << "czesc druga, pierwsza powtórzona częstotliwość: " << czestotlwosc << "\n";
                    return 0; 
                }

                historia.insert(czestotlwosc);      // tworzymy historie
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "blad: " << e.what() << "\n";
        return 1;   
    }
    return 0;
}