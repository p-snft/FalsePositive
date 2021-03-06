#ifndef MAPTILE_HPP
#define MAPTILE_HPP

#include <array>
#include <float.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Engine/MapComponent.hpp"
#include "Engine/SFMLext.hpp"
#include "main.hpp"

class MapTile : public MapComponent
{
public:
	MapTile(std::vector<sf::Vector2f> edges, bool switchable=true);

    virtual ~MapTile(){}

    sf::Vector2f getCenter() const;

	/**
	 * @brief getDirectionTo
	 * @param goal
	 * @return direction to goal
	 */
	MapComponent* getDirectionTo(MapComponent* goal) const;

    inline std::vector<sf::Drawable*> getDrawables() const
        { return _drawables; }

	/**
	 * @brief getForce
	 * @param pos
	 * @param comfortzone
	 * @return
	 *
	 * @todo dependence on direction of movement (to stay right) and maybe speed
	 */
	std::pair<bool,sf::Vector2f> getForce(	const sf::Vector2f position,
											const sf::Vector2f direction,
											MapComponent* target,
											const float size) const;

	MapComponent* getNeighbor(unsigned int n) const;

	/**
	 * @brief getNeighbor
	 * @param veto
	 * @return random Neighbor (but not veto)
	 */
	MapComponent* getNeighbor(MapComponent* veto=nullptr) const;

	unsigned int getNNeighbors() const
		{ return _portal.size(); }

	std::vector<std::array<sf::Vector2f,2>> getNormals() const
        { return _normal; }

    inline sf::Vector2f getPoint(size_t i) const
        { return _area.getPoint(i); }

    inline size_t getPointCount() const
        { return _area.getPointCount(); }

	/**
	 * @brief setNeighbor
	 * @param tile: neigboring tile
	 * @return
	 */
	bool setNeighbor(MapTile* tile);

	/**
	 * @brief setNeighbor
	 * @param component
	 * @param n
	 */
	void setNeighbor(MapComponent* component, unsigned int n);

	void setNormals();

	void setSwitchable(bool switchable);

	bool toggleAccessible();

	bool toggleBreaking();

	bool operator==(const sf::Vector2f pos) const;

	inline bool operator!=(const sf::Vector2f pos) const
		{ return !operator==(pos); }

private:
    sf::ConvexShape _area;

	bool _breaking;

    std::vector<sf::Drawable*> _drawables;

	std::vector<MapComponent*> _portal;

	/**
	 * @brief _normal
	 *
	 * _normal[i][0] stores perpendicular vector
	 * _normal[i][1] stores center of side
	 */
	std::vector<std::array<sf::Vector2f,2>> _normal;

	bool _switchable;
};

#endif // MAPTILE_HPP
