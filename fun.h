void UcitajReci(std::ifstream &datoteka, std::vector<std::string> &reci)
{
    std::string rec;
    bool ind=datoteka.good() && !datoteka.eof();
    while(ind)
    {
        datoteka>>rec;
        reci.push_back(rec);
        ind=datoteka.good() && !datoteka.eof();
    };
};

void Inicijalizacija(){
    std::cout<<"!!!   Welcome to Hangman   !!!"<<std::endl<<std::endl;
    std::cout<<"!!!   Type any letter and press Enter to begin   !!!";
    char x;
    std::cin>>x;
};