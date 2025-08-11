#include "Raytraiser.hpp"
#include <cmath>
#include "DrawingObjects.hpp"

namespace Traicers {
using sf::CircleShape;

std::optional<sf::Vector2f> RayBorderIntersection(const sf::Vector2f& cameraPosition, const float angle) {
    float c = std::cos(angle);
    float s = std::sin(angle);
    float x0 = cameraPosition.x;
    float y0 = cameraPosition.y;

    float t{};
    float x{};
    float y{};

    t = (-y0) / s;
    if (t > 0) {
        x = x0 + c * t;
        if ((kMinCoord < x) && (x < kMaxXCoord)) {
            return sf::Vector2f(x, kMinCoord);
        }
    }

    t = (kMaxYCoord - y0) / s;
    if (t > 0) {
        x = x0 + c * t;
        if ((kMinCoord < x) && (x < kMaxXCoord)) {
            return sf::Vector2f(x, kMaxYCoord);
        }
    }

    t = (kMinCoord - x0) / c;
    if (t > 0) {
        y = y0 + s * t;
        if ((kMinCoord < y) && (y < kMaxYCoord)) {
            return sf::Vector2f(kMinCoord, y);
        }
    }

    t = (kMaxXCoord - x0) / c;
    if (t > 0) {
        y = y0 + s * t;
        if ((kMinCoord < y) && (y < kMaxYCoord)) {
            return sf::Vector2f(kMaxXCoord, y);
        }
    }
    return std::nullopt;
}

std::optional<sf::Vector2f> CalculateCollision(const sf::Vector2f& cameraPosition, const float angle, sf::CircleShape* obj) {
    float x0 = cameraPosition.x;
    float y0 = cameraPosition.y;
    float c = std::cos(angle);
    float s = std::sin(angle);

    float r = obj->getRadius();
    float x2 = obj->getPosition().x + r;
    float y2 = obj->getPosition().y + r;

    //         x^2 + bx + c = 0
    float B = 2 * c * (x0 - x2) + 2 * s * (y0 - y2);
    float C = std::pow((x0 - x2), kSquarePower) + std::pow((y0 - y2), kSquarePower) - std::pow(r, kSquarePower);

    float D = std::pow(B, kSquarePower) - 4 * C;
    if (D >= 0) {
        float ft = (-B + std::sqrt(D)) / 2;
        float st = (-B - std::sqrt(D)) / 2;
        if ((ft < 0) || (st < 0)) {
            return RayBorderIntersection(cameraPosition, angle);
        }

        float fx = x0 + c * ft;
        float sx = x0 + c * st;

        float fy = y0 + s * ft;
        float sy = y0 + s * st;

        if ((std::pow(fx - x0, kSquarePower) + std::pow(fy - y0, kSquarePower)) <
            (std::pow(sx - x0, kSquarePower) + std::pow(sy - y0, kSquarePower))) {
            return sf::Vector2f(fx, fy);
        }
        return sf::Vector2f(sx, sy);
    }
    return RayBorderIntersection(cameraPosition, angle);
}

void CreateTraisers(const sf::Vector2f& cameraPosition, sf::Shape* object, std::vector<std::unique_ptr<sf::VertexArray>>& traisers) {
    traisers.clear();

    for (float angle = 0; angle <= kMaxAngle; angle += kDeltaAngle) {
        std::optional<sf::Vector2f> collision = std::nullopt;
        if (auto* circle = dynamic_cast<sf::CircleShape*>(object)) {
            collision = CalculateCollision(cameraPosition, angle, circle);
        }
        if (collision) {
            DrawingObjects::CreateLine(cameraPosition, *collision, sf::Color::White, traisers);
        }
    }
}

}  // namespace Traicers
