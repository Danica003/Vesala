class Igra
{
    public:
        std::string rec;
        std::vector<bool> pogodjeni;
        int pokusaji;
        bool pobeda;
        bool poraz;
    public:
        Igra(){};
        ~Igra();
        Igra(std:: string &);

        void Print();
        void Runda(char);
};

Igra::~Igra()
{
    std::vector<bool>().swap(pogodjeni);
};

Igra::Igra(std::string &r):rec(r)
{
    for(int i=0;i<rec.size();i++) pogodjeni.push_back(false);
    pokusaji=0;
    pobeda=false;
    poraz=false;
};

void Igra::Print()
{
    std::cout << "\033[3J\033[2J\033[H" << std::flush;
    std::cout<<std::endl;
    for(int i=0;i<rec.size();i++)
    {   
        if(pogodjeni.at(i)==true) std::cout<<"_"<<rec.at(i)<<"_ ";
        else  std::cout<<"___ ";
    };
    std::cout<<std::endl<<std::endl<<"TRIES LEFT: ";
    for(int i=0;i<pokusaji;i++) std::cout<<"[ X ] ";
    for(int i=0;i<6-pokusaji;i++) std::cout<<"[  ] ";
    std::cout<<std::endl<<std::endl;

};

void Igra::Runda(char slovo)
{
    int z=0;
    bool uspeh=false;
    for (int i=0;i<rec.size();i++)
    {
        if(tolower(rec.at(i))==tolower(slovo)){
            pogodjeni.at(i)=true;
            uspeh=true;
        }; 
        if (pogodjeni.at(i)==true) z++;
    };
    if (!uspeh) pokusaji++;
    if(z==rec.size()) pobeda=true;
    else if (pokusaji==6) poraz=true;
};
