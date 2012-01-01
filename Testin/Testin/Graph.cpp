#include <vector>
#include "Graph.h"
#include "Tile.h"

Graph::Graph(int w, int h)
{
	SetDimensions(w,h);
	this->w = w;
	this->h = h;
}

Graph::~Graph(){}

void Graph::SetDimensions(int w, int h)
{
	map.resize(w);
	for(int index = 0; index < w; index++)
		map.at(index).resize(h, 0);
}

void Graph::AddTile(int x, int y, Tile* tile)
{
	map[x][y] = tile;
}

Tile* Graph::getTile(int x, int y)
{
	return map[x][y];
}

void Graph::LoadGraph(ImageManager& imageManager)
{
		
	

	Tile* tile;

	for(int y = 0; y < this->h; y++)
	{
		for(int x = 0; x < this->w; x++)
		{
			if(y%3 == 0)
				tile = new Tile(imageManager.getImage(1));
			else
				tile = new Tile(imageManager.getImage(0));

			AddTile(x,y,tile);
		}
	}
}