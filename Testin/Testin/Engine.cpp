#include "Engine.h"
#include "Camera.h"
#include "Graph.h"
#include <SFML\Graphics.hpp>

Engine::Engine(){}
Engine::~Engine(){delete window;}

bool Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(800,600,32), "Testing");//change first var for window size
	camera = new Camera(800, 600, 1.0f);
	graph = new Graph(20,20);
	if(!window)
		return false;

	return true;
}

void Engine::ProcessInput()
{
	sf::Event evnt;

	while(window->GetEvent(evnt))
	{
		if(evnt.Type == sf::Event::Closed)
			window->Close();
	}
}
void Engine::RenderFrame()
{

	int cameraXOffset = camera->GetPosition().x, cameraYOffset = camera->GetPosition().y;
	Tile* tile;
	window->Clear();	
	
	sf::IntRect bound = camera->GetTileBounds(20);

	for(int y = 0, tileY = bound.Top; y < bound.GetHeight(); y++, tileY++)
	{
		for(int x = 0, tileX = bound.Left; x < bound.GetWidth(); x++, tileX++)
		{
			tile = graph->getTile(x,y);
			tile->Draw( (x * 20) - cameraXOffset, (y * 20) - cameraYOffset, window);
		}
	}

	window->Display();
}

void Engine::LoadImages()
{
	sf::Image sprite;
	sprite.LoadFromFile("test.png");
	imageManager.AddImage(sprite);

	testTile = new Tile(imageManager.getImage(0));
}
void Engine::Update()
{

}

void Engine::MainLoop()
{
	while(window->IsOpened())
	{
		ProcessInput();
		Update();
		RenderFrame();
	}
}

void Engine::Start()
{
	if(!Init())
		throw "Could not init";

	LoadImages();

	MainLoop();

}