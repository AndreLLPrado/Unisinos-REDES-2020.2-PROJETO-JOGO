#include "Janela.h"

void Janela::criarJanela(int x, int y, std::string titulo)
{
	janela.create(sf::VideoMode(x, y), "Provisorio");
	//janela.create(sf::VideoMode(800, 600), "Titulo");
}

void Janela::setFPS(int fps)
{
	janela.setFramerateLimit(fps);
}

void Janela::fecharJanela()
{
	janela.close();
}

bool Janela::aJanelaEstaAberta()
{
	return janela.isOpen();
}

unsigned int Janela::getAltura()
{
	size = janela.getSize();
	return height = size.y;
}

unsigned int Janela::getLargura()
{
	size = janela.getSize();
	return width = size.x;
}

void Janela::AtualizarJanela()
{
	/*while (janela.isOpen()) {
		if (event.type == sf::Event::Closed)
			janela.close();
	}*/

	janela.clear(sf::Color::Black);

	sprite.setPosition(400, 300);
	sprite.desenhar(janela);

	janela.display();
}
