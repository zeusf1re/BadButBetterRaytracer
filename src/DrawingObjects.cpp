#include "DrawingObjects.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

namespace DrawingObjects {

void CreateCircle(std::vector<std::unique_ptr<sf::Shape>>& shapes) {
    std::unique_ptr<sf::Shape> circlePtr = std::make_unique<sf::CircleShape>(CircleParams::kRadius);
    circlePtr->setFillColor(CircleParams::kSirclePurple);
    circlePtr->move(CircleParams::kCirclePosition);

    shapes.push_back(std::move(circlePtr));
}

void DrawAllShapes(std::vector<std::unique_ptr<sf::Shape>>& shapes, sf::RenderWindow& window) {
    for (const auto& shape : shapes) {
        window.draw(*shape);
    }
}

void DrawAllVertexes(std::vector<std::unique_ptr<sf::VertexArray>>& vertexes, sf::RenderWindow& window) {
    for (const auto& vertex : vertexes) {
        window.draw(*vertex);
    }
}

void CreateLine(const sf::Vector2f& startPoint, const sf::Vector2f& endPoint, const sf::Color& color,
                std::vector<std::unique_ptr<sf::VertexArray>>& vertexes) {
    //    std::unique_ptr<sf::Shape> line = std::make_unique<sf::VertexArray>(sf::Lines, 2);
    std::unique_ptr<sf::VertexArray> line = std::make_unique<sf::VertexArray>(sf::PrimitiveType::Lines, 2);
    (*line)[0].position = startPoint;
    (*line)[1].position = endPoint;

    vertexes.push_back(std::move(line));
}

void CreateBorders(std::vector<std::unique_ptr<sf::VertexArray>>& borders) {
    for (size_t i = 0; i < 4; ++i) {
        CreateLine(BordersParams::kCornersCoords[i], BordersParams::kCornersCoords[i + 1], BordersParams::kBorderColor, borders);
    }
}

void CreateCamera(std::vector<std::unique_ptr<sf::Shape>>& shapes) {
    std::unique_ptr<sf::Shape> camera = std::make_unique<sf::CircleShape>(CameraParams::kRadius);
    camera->setFillColor(CameraParams::kCameraColor);
    camera->move(CameraParams::kCameraPosition);

    shapes.push_back(std::move(camera));
}

// void CreateKrug(std::vector<std::unique_ptr<sf::VertexArray>>& vertexes) {
//     float x1 = 300.f;
//     float y1 = 300.f;
//     float r = 50.f;
//
//     sf::Vector2f a(x1, y1);
//     sf::VertexArray vertices(sf::PrimitiveType::Points);
//     for (float i = 0; i < 360; ++i) {
//         vertices.append({
//             {x1 + r * std::cos(i), y1 + r * std::sin(i)},
//             sf::Color::Green
//         });
//     }
//     window.draw(vertices);
// }
//
}  // namespace DrawingObjects
