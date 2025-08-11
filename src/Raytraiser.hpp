#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <optional>

namespace {
inline const float kMaxAngle = 360.f;
inline const float kDeltaAngle = 0.25f;

inline const float kSquarePower = 2.f;

inline const float kMaxXCoord = 795.f;
inline const float kMaxYCoord = 595.f;
inline const float kMinCoord = 5.f;
}  // namespace

namespace Traicers {

std::optional<sf::Vector2f> RayBorderIntersection(const sf::Vector2f& cameraPosition, const float angle);

std::optional<sf::Vector2f> CalculateCollision(const sf::Vector2f& cameraPosition, const float angle, sf::CircleShape* obj);

void CreateTraisers(const sf::Vector2f& cameraPosition, sf::Shape* object, std::vector<std::unique_ptr<sf::VertexArray>>& traisers);

}  // namespace Traicers
