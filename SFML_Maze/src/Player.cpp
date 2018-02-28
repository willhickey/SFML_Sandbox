#include "Player.h"
Player::Player()
{

}
Player::Player(int startX, int startY)
{
    Initialize(startX, startY);
    /*x = startX;
    y = startY;*/
}
Player::~Player()
{
    //dtor
}
void Player::Initialize(int startX, int startY)
{
    x = startX;
    y = startY;
}

Player::GetX()
{
    return x;
}
Player::GetY()
{
    return y;
}
