#ifndef PERSON_HPP
#define PERSON_HPP

#include <cmath>
#include <queue>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "Engine/Map.hpp"
#include "Engine/MapPortal.hpp"
#include "Engine/MapTile.hpp"

class Person : public sf::CircleShape
{
public:
	Person(Map* map, MapComponent* spawn, MapComponent* goal=nullptr);

	/**
	 * @brief move
	 * @param elapsed
	 * @return last waypoint reached?
	 */
	bool move(sf::Time elapsed);

private:
	std::queue<MapComponent*> _checkpoint;

	MapComponent* _goal;

	Map* _map;

	MapComponent* _pos;

	float _speed;
};

#endif // PERSON_HPP
