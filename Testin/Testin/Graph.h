#pragma once
#include <vector>
#include "Tile.h"

class Graph
{
private:
	std::vector<std::vector<Tile*>>map;
	int w;
	int h;

	void SetDimensions(int w, int h);

public:
	Graph(int w, int h);
	~Graph();
	void AddTile(int x, int y, Tile* tile);
	Tile* getTile(int x, int y);

	void LoadGraph();
	int getWidth() {return w;}
	int getHeight() {return h;}
};