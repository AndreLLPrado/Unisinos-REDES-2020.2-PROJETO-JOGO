#pragma once
#include <iostream>
#include <string>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Game
{
public:
	Game(){}
	~Game(){}

	void inicializar();
	void atualizar();
	void finalizar();

	void gameRun();
private:
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket;
	char connectionType, mode;
	char buffer[2000];
	std::size_t received;
	std::string text = "Connected to: ";
	bool done;

	std::string textAcao;
};

