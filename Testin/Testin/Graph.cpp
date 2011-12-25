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

void Graph::LoadGraph()
{
	//EL OH EL NOTHING YET
}