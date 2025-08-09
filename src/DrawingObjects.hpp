#ifndef DRAWINGOBJECTS_HPP
#define DRAWINGOBJECTS_HPP

#include <SFML/Graphics.hpp>
namespace CircleParams {

inline constexpr float kRadius = 50.f;

inline const sf::Vector2f kCirclePosition(300.f, 300.f);

inline const sf::Color kSirclePurple(69, 13, 112);

}  // namespace CircleParams

namespace CameraParams {

inline constexpr float kRadius = 5.f;

inline const sf::Vector2f kCameraPosition(5.f, 300.f);

inline const sf::Color kCameraColor(56, 242, 127);

}  // namespace CameraParams

namespace DrawingObjects {

void CreateCircle(std::vector<std::unique_ptr<sf::Shape>>& shapes);

void CreateKrug(std::vector<std::unique_ptr<sf::VertexArray>>& vertexes);

void CreateBorders(std::vector<std::unique_ptr<sf::Shape>>& shapes);

void DrawAllShapes(std::vector<std::unique_ptr<sf::Shape>>& shapes, sf::RenderWindow& window);

void DrawAllVertexes(std::vector<std::unique_ptr<sf::VertexArray>>& vertexes, sf::RenderWindow& window);

void CreateBorders(std::vector<std::unique_ptr<sf::VertexArray>>& borders);

void CreateLine(const sf::Vector2f& startPoint, const sf::Vector2f& endPoint, const sf::Color& color,
                std::vector<std::unique_ptr<sf::VertexArray>>& vertexs);

void CreateCamera(std::vector<std::unique_ptr<sf::Shape>>& shapes);
}  // namespace DrawingObjects

namespace BordersParams {
inline constexpr sf::Vector2f kTopLeft(5.f, 5.f);
inline constexpr sf::Vector2f kTopRight(795.f, 5.f);
inline constexpr sf::Vector2f kBottomRight(795.f, 595.f);
inline constexpr sf::Vector2f kBottomLeft(5.f, 595.f);

inline const sf::Vector2f kCornersCoords[5] = {kTopLeft, kTopRight, kBottomRight, kBottomLeft, kTopLeft};

inline const sf::Color kBorderColor(sf::Color::Blue);
}  // namespace BordersParams

#endif  // DRAWINGOBJECTS_HPP
