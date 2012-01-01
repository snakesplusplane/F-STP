#include "Engine.h"
#include "Camera.h"
#include "Graph.h"
#include <SFML\Graphics.hpp>
#include <iostream>

Engine::Engine(int w, int h, int tileSize)
{
	videoSize = sf::Vector2i(w,h);
	this->tileSize = tileSize;
	imageManager.setTileSize(tileSize);
}
Engine::~Engine(){delete window;}

bool Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(videoSize.x,videoSize.y,32), "Testing");//change first var for window size
	camera = new Camera(videoSize.x, videoSize.y, 0.6);

	LoadImages();
	graph = new Graph(40,40);
	graph->LoadGraph(imageManager);
	if(!window)
		return false;

	return true;
}

void Engine::ProcessInput()
{
	sf::Event evnt;
	bool mouseDown = false, keyDown = false;
	while(window->GetEvent(evnt))
	{
		if(evnt.Type == sf::Event::Closed)
			window->Close();

		if(evnt.Type == sf::Event::KeyPressed && mouseDown == false)
		{
			//int x = camera->GetPosition().x + window->GetInput().GetMouseX();
			//int y = camera->GetPosition().y + window->GetInput().GetMouseY();

			//if (x <= 0)
			//	x = 0;

			//if (y <= 0)
			//	y = 0;
			camera->Move(0,1);
			mouseDown = true;
		}
		//if(evnt.Type == sf::Event::KeyPressed && keyDown == false)
		//{

		//}
		if(evnt.Type == sf::Event::KeyReleased)
			mouseDown = false;
	}
}
void Engine::RenderFrame()
{

	int cameraXOffset = camera->GetPosition().x, cameraYOffset = camera->GetPosition().y;
	Tile* tile;
	window->Clear();	
	
	bound = camera->GetTileBounds(tileSize);

	int tmp = bound.GetHeight();
	

	tmp++;
	tmp--;

	for(int y = 0, tileY = bound.Top; y < bound.GetHeight(); y++, tileY++)
	{
		for(int x = 0, tileX = bound.Left; x < bound.GetWidth(); x++, tileX++)
		{
			tile = graph->getTile(tileX,tileY);
			tile->Draw( (x * tileSize) - cameraXOffset, (y * tileSize) - cameraYOffset, window);
		}
	}

	window->Display();
}

void Engine::LoadImages()
{
	sf::Image sprite;
	sprite.LoadFromFile("test.png");
	imageManager.AddImage(sprite);
	sprite.LoadFromFile("testtwo.png");
	imageManager.AddImage(sprite);

	testTile = new Tile(imageManager.getImage(0));
}
void Engine::Update()
{
	camera->Update();
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



	MainLoop();

}

