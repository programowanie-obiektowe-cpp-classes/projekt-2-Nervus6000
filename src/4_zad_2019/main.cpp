
//  g++ -std=c++20 main.cpp -o main


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  
#include <ranges>     // iota
#include <iterator>     // distance
#include <exception>



bool wymog_pierwszy(const std::string& s)  
{
    return std::ranges::is_sorted(s);
}

bool wymog_drugi(const std::string& s)    
{
    return std::ranges::adjacent_find(s) != s.end();
}

bool wymog_trzeci(const std::string& s)
{
    auto it = s.begin();
    while (it != s.end())   //  przejście po kolei przez stringa
    {
        char literka = *it;

        auto koniec_grupy = std::find_if(it, s.end(), [literka](char c){        //      find if przyjmuje tylko jeden argument, więc literke trzeba z zewnątrz jako "prerekwizyt"
                                                        return c != literka;    
                                                        });

        auto dlugosc = std::distance(it, koniec_grupy);

        if (dlugosc == 2) {
            return true; 
        }

        it = koniec_grupy;
    }
    return false;
}


int main() 
{
    try 
    {
        const int input_beg = 138307;
        const int input_end = 654504;
        
        std::vector<int> rozwiazania;

        auto zakres_liczb = std::views::iota(input_beg, input_end + 1);     // +1 bo jakby zakres prawostronnie matematyczne ) a nie >

        for (int i : zakres_liczb)
        {
            std::string s = std::to_string(i);

            if(wymog_pierwszy(s) && wymog_trzeci(s))      //      wsm to trzeci od razu spełnia drugi
            {
                rozwiazania.push_back(i);
            }
        }
        std::cout << "rozwiazanie: " << rozwiazania.size() << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cerr << "blad: " << e.what() << "\n";
        return 1;
    }

    return 0;
}