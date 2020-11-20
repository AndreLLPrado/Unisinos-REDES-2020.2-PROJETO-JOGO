#pragma once
#include <SFML/Graphics.hpp>
class Sprite
{
public:
	Sprite(){}
	~Sprite(){}
	bool carregarSprite(std::string path, int x, int y, int wd, int hg);
	void setPosition(int x, int y);
	void desenhar(sf::RenderWindow &window);
	void setColor(int r, int g, int b, int a = 255);
	void setSmooth(bool set);
	void setRotation(float rot);
	void setScale(float scx, float scy);

private:
	sf::Texture texture;
	sf::Sprite sprite;
	int posx;
	int posy;
	int height;
	int width;
};

