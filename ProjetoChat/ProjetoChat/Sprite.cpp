#include "Sprite.h"

bool Sprite::carregarSprite(std::string path, int x, int y, int wd, int hg)
{
	posx = x;
	posy = y;
	width = wd;
	height = hg;
	if (texture.loadFromFile(path, sf::IntRect(posx, posy, width, height))) {
		//std::cout << "Erro ao carregar Sprite";
		return false;
	}
	sprite.setTexture(texture);
	return true;
}

void Sprite::setPosition(int x, int y)
{
	posx = x;
	posy = y;
	sprite.setPosition(posx, posy);
}

void Sprite::desenhar(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Sprite::setColor(int r, int g, int b, int a)
{
	sprite.setColor(sf::Color(r, g, b, a));
}

void Sprite::setSmooth(bool set) {
	texture.setSmooth(set);
}

void Sprite::setRotation(float rot) {
	sprite.setRotation(rot);
}

void Sprite::setScale(float scx, float scy) {
	sprite.setScale(sf::Vector2f(scx, scx));
}