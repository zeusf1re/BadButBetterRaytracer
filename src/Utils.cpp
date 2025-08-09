#include "Utils.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <ostream>
namespace Fps {

void FpsCounter(sf::Clock& fpsClock, int& frameCount) {
    frameCount++;
    if (fpsClock.getElapsedTime().asSeconds() >= 1.0f) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "FPS: " << frameCount << std::endl;
        frameCount = 0;
        fpsClock.restart();
    }
}

}  // namespace Fps
