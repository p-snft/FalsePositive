#ifndef MAP_HPP
#define MAP_HPP

#include <array>
#include <fstream>
#include <random>
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <vector>

#include "Engine/MapPortal.hpp"
#include "Engine/MapTile.hpp"
#include "Engine/Resources.hpp"

class Map
{
public:
	Map(sf::RenderTarget* rendertarget,
		Resources* resources);

	~Map();

	void draw();

	MapPortal* getPortal(MapPortal* veto=nullptr);

	/**
	 * @brief loadFromFile
	 * @param filename
	 * @return Was map succesfully loaded?
	 */
	bool loadFromFile(const std::string& filename);

private:
	std::vector<MapTile*> _tile;

	std::vector<MapPortal*> _portal;

	sf::RenderTarget* _rendertarget;

	Resources* _resources;

	#ifdef DEBUG
	std::vector<sf::Text> _enumerations;
	#endif // DEBUG
};

#endif // MAP_HPP
