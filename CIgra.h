class Igra
{
    public:
        std::string rec;
        std::vector<bool> pogodjeni;
        int pokusaji;
    public:
        Igra(){};
        ~Igra();
        Igra(std:: string &);
};

Igra::~Igra()
{
    std::vector<bool>().swap(pogodjeni);
};

Igra::Igra(std::string &r):rec(r)
{
    for(int i=0;i<rec.size();i++) pogodjeni.at(i)=false;
    pokusaji=0;
};