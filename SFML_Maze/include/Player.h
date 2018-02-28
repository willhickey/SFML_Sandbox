#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        Player(int, int);
        virtual ~Player();
        void Initialize(int, int);
        int GetX();
        int GetY();
        int x, y;
    protected:

    private:

};

#endif // PLAYER_H
