#include "Level.h"


Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;
	sf::View view1(sf::FloatRect(200.f, 200.f, 300.f, 200.f));
	// initialise game objects
	rect.setSize(sf::Vector2f(50, 5));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	circle.setRadius(50);
	circle.setOrigin(50, 50);
	circle.setPosition(600, 337.5);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineThickness(2);
	circle.setOutlineColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(50, 50));  
	rect2.setPosition(200, 200);
	rect2.setFillColor(sf::Color::Red);

	rect3.setSize(sf::Vector2f(25, 25));
	rect3.setPosition(212.5, 212.5);
	rect3.setFillColor(sf::Color::Green);

	rect4.setSize(sf::Vector2f(12.5, 12.5));
	rect4.setPosition(218.30, 218.30);
	rect4.setFillColor(sf::Color::Blue);

	font.loadFromFile("font/arial.ttf");

	text.setFont(font);
	text.setString("hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setOrigin(text.getGlobalBounds().width/2.0f, 5);
	text.setPosition(600, 10);


	sf::Vector2u vec = window->getSize();
	sf::Vector2f pos = sf::Vector2f(vec);

	leftRect.setSize(sf::Vector2f(50, 50));

	sf::Vector2f recPos = sf::Vector2f(50,50);

	leftRect.setPosition(pos-recPos);
	leftRect.setFillColor(sf::Color::Green);
	

} 

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	sf::Vector2f recPos = sf::Vector2f(50, 50);
	sf::Vector2f vec = sf::Vector2f(pos);

	leftRect.setPosition(vec-recPos);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);

	window->draw(circle);

	window->draw(rect2);
	window->draw(rect3);
	window->draw(rect4);

	window->draw(text);

	window->draw(leftRect);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}