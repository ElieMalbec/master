#ifndef DEF_DUREE
#define DEF_DUREE

class Duree
{
    public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    bool operator==(Duree const& a, Duree const& b);
    private:

    int m_heures;
    int m_minutes;
    int m_secondes;
};

#endif
