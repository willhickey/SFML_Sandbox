 #include <queue>
 #include <set>
 #include <future>

class KeyboardListener
{
    public:
        static void listen(std::queue<sf::Keyboard::Key>& ,std::set<sf::Keyboard::Key> ,std::future<void> quitSignal
                        ,int initialDelay ,int repeatDelay);
//        void operator()(std::queue<sf::Keyboard::Key> ,std::set<sf::Keyboard::Key> ,std::future<void> quitSignal);
    private:
 //       const int defaultInitialDelay = 200;
 //       const int defaultRepeatDelay = 50;
};
