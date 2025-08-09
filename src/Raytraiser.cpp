#include "Raytraiser.hpp"
#include <cmath>
#include <iostream>
#include <optional>
#include "DrawingObjects.hpp"

// Проверяет пересечение луча (заданного углом) с окружностью
namespace Traicers {
using sf::CircleShape;

std::optional<sf::Vector2f> RayCircleIntersection(const sf::Vector2f& cameraPosition, const float angleDeg, sf::CircleShape* obj) {
    const sf::Vector2f circleCenter = obj->getGeometricCenter();
    const float maxRayLength = 1000.f;
    const float circleRadius = obj->getRadius();
    const float halfDegrees = 180.f;
    float angleRad = angleDeg * static_cast<float>(M_PI) / halfDegrees;
    float dx = std::cos(angleRad);
    float dy = std::sin(angleRad);

    // Коэффициенты квадратного уравнения
    float a = dx * dx + dy * dy;  // Всегда == 1 (т.к. нормализовано)
    float b = 2 * (dx * (cameraPosition.x - circleCenter.x) + dy * (cameraPosition.y - circleCenter.y));
    float c = (cameraPosition.x - circleCenter.x) * (cameraPosition.x - circleCenter.x) +
              (cameraPosition.y - circleCenter.y) * (cameraPosition.y - circleCenter.y) - circleRadius * circleRadius;

    float D = b * b - 4 * a * c;
    if (D < 0) {
        return sf::Vector2f(cameraPosition.x + dx, cameraPosition.y + dy);
        return std::nullopt;  // Нет пересечений
                              //
    }

    float t1 = (-b + std::sqrt(D)) / (2 * a);
    float t2 = (-b - std::sqrt(D)) / (2 * a);

    // Ищем минимальное t в диапазоне [0, maxRayLength]
    float t = std::min(t1, t2);
    if (t < 0 || t > maxRayLength) {
        t = std::max(t1, t2);
        if (t < 0 || t > maxRayLength) {
            return std::nullopt;
        }
    }

    return sf::Vector2f(cameraPosition.x + t * dx, cameraPosition.y + t * dy);
}

std::optional<sf::Vector2f> CalculateCollision(const sf::Vector2f& cameraPosition, const float angle, sf::CircleShape* obj) {
    float x1 = cameraPosition.x;
    float y1 = cameraPosition.y;

    float r = obj->getRadius();
    float x2 = obj->getPosition().x + r;
    float y2 = obj->getPosition().y + r;

    float k = std::tan(angle);
    float b = cameraPosition.y - k * cameraPosition.x;

    // float D = (2 * k * b - 2 * k * y2 - 2 * x2) * (2 * k * b - 2 * k * y2 - 2 * x2) - (4 * (k * k + 1) * (x2 * x2 + (b - y2) * (b - y2) - r * r));
    float D = std::pow((2 * k * b) - (2 * k * y2) - (2 * x2), 2.f) - (4 * (k * k + 1) * (b * b - (2 * b * y2) + y2 * y2 + x2 * x2 - r * r));
    if (D > 0) {
        // float fx = (-(2 * k * b - 2 * k * y2 - 2 * x2) - (4 * std::sqrt(D))) / (2 * (k * k + 1));
        // float sx = (-(2 * k * b - 2 * k * y2 - 2 * x2) + (4 * std::sqrt(D))) / (2 * (k * k + 1));
        float fx = ((2 * k * y2) - (2 * k * b) + (2 * x2) + std::sqrt(D)) / (2 * k * k + 2);
        float sx = ((2 * k * y2) - (2 * k * b) + (2 * x2) - std::sqrt(D)) / (2 * k * k + 2);
        float fy = k * fx + b;
        float sy = k * sx + b;
        if (((fx - x1) * (fx - x1) + (fy - y2) * (fy - y2)) <= ((sx - x1) * (sx - x1) + (sy - y2) * (sy - y2))) {
            return sf::Vector2f(fx, fy);
        } else {
            return sf::Vector2f(sx, sy);
        }
    }

    //    return std::nullopt;
    return sf::Vector2f(1000, k * 1000 + b);
}

void CreateTraisers(const sf::Vector2f& cameraPosition, sf::Shape* object, std::vector<std::unique_ptr<sf::VertexArray>>& traisers) {
    const float maxAngle = 360.f;
    traisers.clear();

    for (float angle = 0; angle <= maxAngle; angle += 1.f) {
        std::optional<sf::Vector2f> collision = std::nullopt;
        if (auto* circle = dynamic_cast<sf::CircleShape*>(object)) {
            collision = CalculateCollision(cameraPosition, angle, circle);
        }
        if (collision) {
            // std::cout << collision->x << ' ' << collision->y << '\n';
            DrawingObjects::CreateLine(cameraPosition, *collision, sf::Color::White, traisers);
        }
    }
}

}  // namespace Traicers
