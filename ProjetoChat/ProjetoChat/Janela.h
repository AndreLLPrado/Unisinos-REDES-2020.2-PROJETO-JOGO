#pragma once
#include<SFML/Window.hpp>
#include "Sprite.h"
class Janela
{
public:
	Janela(){/*janela.setVerticalSyncEnabled(true);*/ }
	~Janela(){ sprite.carregarSprite("/Sprites/teste.png", 10, 10, 32, 32); }

	void criarJanela(int x, int y, std::string titulo);
	void setFPS(int fps = 30);//setar o limite maximo de FPS da janela
	void fecharJanela();
	bool aJanelaEstaAberta();
	unsigned int getAltura();
	unsigned int getLargura();
	//sf::RenderWindow getJanela() { return janela; }

	void AtualizarJanela();

private:
	sf::RenderWindow janela;
	sf::Vector2u size;
	unsigned int width;
	unsigned int height;

	sf::Event event;

	Sprite sprite;
};

