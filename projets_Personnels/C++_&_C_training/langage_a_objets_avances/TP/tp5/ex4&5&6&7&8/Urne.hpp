#ifndef URNE_HPP
#define URNE_HPP

friend class  Scrutin;


class Urne {
    Scrutin *monScrutin;
    static int numBureauVote;
    int *votes;
    Urne();
    ~Urne();
    public :
    bool voter(int choix);
};

#endif
