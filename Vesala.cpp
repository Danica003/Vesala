#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <random>

#include "fun.h"
#include "CIgra.h"

int main(int argc, char** argv)
{   
    //inicijalizacija reci
    std::ifstream datoteka("recnik.txt");
    std::vector<std::string> reci;
    UcitajReci(datoteka,reci);

    //biranje nasumicne reci
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, reci.size() - 1);
    size_t index = dist(gen);

    // Inicijalizacija
    Inicijalizacija();
    std::string rec=reci.at(index);
    Igra ig(rec);
    char slovo;
    while(true)
    {
        ig.Print();
        std::cout<<"Please type in your next letter:";
        std::cin>>slovo;
        ig.Runda(slovo);
        if(ig.pobeda)
        {
            ig.Print();
            std::cout<<"Congratulations! You won! Heres a gold star ☆"<<std::endl;
            break;
        };
        if(ig.poraz)
        {
            ig.Print();
            std::cout<<"Oh no! You lost! Better luck next time!"<<std::endl;
            break;
        }

    };  
    


    std::vector<std::string>().swap(reci);
    datoteka.close();
    return 0;
}
