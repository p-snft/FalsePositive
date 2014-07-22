#include "Engine/MapTile.hpp"

MapTile::MapTile(std::vector<sf::Vector2f> edges)
{
    setPointCount(edges.size());
	_portal.resize(edges.size(),nullptr);
    for (unsigned int p=0; p<edges.size(); p++)
    {
		setPoint(p,edges[p]);
    }
	setFillColor(sf::Color(127,127,127));
	#ifdef DEBUG
	setOutlineColor(sf::Color::White);
	setOutlineThickness(1);
	#endif //DEBUG
}

bool MapTile::setNeighbor(MapTile *tile)
{
	for (unsigned int t=0; t<getPointCount(); t++)
	{
		for (unsigned int o=0; o<tile->getPointCount(); o++)
		{
			if (getPoint(t) == tile->getPoint(o))
			{
				_portal[t] = tile;
				return true;
			}
		}
	}
	return false;
}

void MapTile::setNeighbor(MapComponent* component, unsigned int n)
{
	_portal[n] = component;
}
