
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
namespace {
inline const float kMaxDegree = 360.f;
}

struct Point {
    float x, y;
};
struct Circle {
    Point center;
    float radius;
};
namespace Traicers {

std::optional<sf::Vector2f> RayCircleIntersection(const sf::Vector2f& cameraPosition, const float angleDeg, sf::CircleShape* obj);

void CreateTraisers(const sf::Vector2f& cameraPosition, sf::Shape* object, std::vector<std::unique_ptr<sf::VertexArray>>& traisers);

}  // namespace Traicers
