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