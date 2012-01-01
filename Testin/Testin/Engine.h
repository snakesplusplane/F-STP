#pragma once

#include <SFML\Graphics.hpp>
#include "ImageManager.h"
#include "Tile.h"
#include "Camera.h"
#include "Graph.h"

class Engine
{
private:
	sf::RenderWindow* window;
	ImageManager imageManager;

	sf::Vector2i videoSize;

	sf::IntRect bound;

	Camera* camera;
	Graph* graph;
	int tileSize;

	void LoadImages();
	Tile* testTile;
	bool Init();
	void MainLoop();
	void RenderFrame();
	void ProcessInput();
	void Update();
	void loadGraph();

public:
	Engine(int w, int h, int tileSize);
	~Engine();
	void Start();
};