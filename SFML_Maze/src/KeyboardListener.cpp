#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include <SFML/Graphics.hpp>
#include "KeyboardListener.h"


void KeyboardListener::listen(std::queue<sf::Keyboard::Key>& q, std::set<sf::Keyboard::Key> keys
                                ,std::future<void> quitSignal, int initialDelay ,int repeatDelay)
{

    sf::Clock clock;
    std::unordered_map<sf::Keyboard::Key, sf::Time> lastEventTime;
    std::unordered_set<sf::Keyboard::Key> keysDown;

    while (quitSignal.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout)
    {
        //TODO implement delay logic
        for(sf::Keyboard::Key key : keys){
            bool keyPressed = sf::Keyboard::isKeyPressed(key);
            if(keyPressed){

                if(!keysDown.count(key)){
                //Key was pressed but isn't in keysDown
                //TODO add/update lastEventTime
                    keysDown.insert(key);
                    q.push(key);
                    std::cout<<"newly pressed: "<<key<<std::endl;
                    lastEventTime[key] = clock.getElapsedTime();
                }
                //TODO special case for initial delay
                else{
                    sf::Time timeSinceLastEvent = clock.getElapsedTime() - lastEventTime[key];
                    if(timeSinceLastEvent.asMilliseconds() >= repeatDelay){
                        q.push(key);
                        std::cout<<"repeat pressed: "<<key<<std::endl;
                        lastEventTime[key] = clock.getElapsedTime();
                    }
                }
            }
            else {
                if(keysDown.count(key)){
                    keysDown.erase(key);
                }
            }
        }
//        q.push(sf::Keyboard::Down);
        sf::sleep(sf::milliseconds(10));
        //std::cout<<"running thread"<<std::endl;
    }
    std::cout<<"Thread exiting"<<std::endl;

}
