#include "Engine.h"
#include <SFML\Graphics.hpp>

Engine::Engine(){}
Engine::~Engine(){delete window;}

bool Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(800,600,32), "Testing");//change first var for window size

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
	window->Clear();
	testTile->Draw(0,0,window);
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