#include "DrawingObjects.hpp"
#include "Raytraiser.hpp"
#include "Utils.hpp"

namespace WindowParameters {
const size_t kHeight = 600;
const size_t kWidth = 800;
constexpr sf::Vector2u kWindowSize(kWidth, kHeight);

}  // namespace WindowParameters

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    sf::RenderWindow window(sf::VideoMode(WindowParameters::kWindowSize), "SFML");

    sf::Clock fpsClock;
    int frameCount{};

    std::vector<std::unique_ptr<sf::Shape>> shapes;
    std::vector<std::unique_ptr<sf::Shape>> cameras;
    std::vector<std::unique_ptr<sf::VertexArray>> borders;
    std::vector<std::unique_ptr<sf::VertexArray>> traicers;

    DrawingObjects::CreateCircle(shapes);
    DrawingObjects::CreateBorders(borders);
    DrawingObjects::CreateCamera(cameras);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        Fps::FpsCounter(fpsClock, frameCount);

        window.clear();

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        shapes[0]->setPosition({static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)});

        Traicers::CreateTraisers(CameraParams::kCameraPosition, shapes[0].get(), traicers);

        DrawingObjects::DrawAllShapes(shapes, window);
        DrawingObjects::DrawAllShapes(cameras, window);
        DrawingObjects::DrawAllVertexes(borders, window);
        DrawingObjects::DrawAllVertexes(traicers, window);

        window.display();
    }
}
