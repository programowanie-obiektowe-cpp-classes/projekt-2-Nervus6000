#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <exception>

int main() 
{
    try
    {
        std::string input_data;
        
        std::ifstream inFile("input.txt");

        if (!inFile) {
            throw std::runtime_error("problemy z plikiem");
        }

        inFile >> input_data;

        inFile.close();

        int N = input_data.length();
        

        int polowa = N / 2;
        double sum = 0;

        for (int i = 0; i < polowa; ++i) {
            
            if (input_data.at(i) == input_data.at(i + polowa)) {
                sum += input_data.at(i) - '0';
            }
        }
        
        sum = sum * 2;
        
        std::cout << sum << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cerr << "źle policzone "<< e.what() << "\n"; 
        return 1;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "zbyt długi czas " << e.what() << "\n";
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "blad: " << e.what() << "\n";
        return 1;
    }

    return 0;
}