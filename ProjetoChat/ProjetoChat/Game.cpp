#include "Game.h"

void Game::inicializar()
{
	std::cout << "Digite (s) pra Servidor e (c) pra Cliente" << std::endl;
	std::cin >> connectionType;
	if (connectionType == 's') {
		sf::TcpListener listener;
		listener.listen(2000);
		listener.accept(socket);
		text += "Server";
		mode = 's';
	}
	else if (connectionType == 'c') {
		socket.connect(ip, 2000);
		text += "Client";
		mode = 'r';
	}
	socket.send(text.c_str(), text.length() + 1);
	socket.receive(buffer, sizeof(buffer), received);
	std::cout << buffer << std::endl;
	done = false;
}

void Game::atualizar()
{
	
	while (!done)
	{
		if (mode == 's') {
			std::getline(std::cin, textAcao);
			socket.send(textAcao.c_str(), text.length() + 1);

			mode = 'r';
		}
		else if (mode == 'r') {
			socket.receive(buffer, sizeof(buffer), received);
			if (received > 0) {
				gameRun();

				mode = 's';
			}
		}
	}
	system("pause");
}

void Game::finalizar()
{
}

void Game::gameRun() {
	int vidaJ1 = 2500, vidaJ2 = 3000;
	if (connectionType == 's') {
		std::cout << "Vida: " << vidaJ1 << std::endl;
		// std::cin >> textAcao;
		if (textAcao == "a") {
			vidaJ2 -= 100;
		}
		else if (textAcao == "A") {
			vidaJ2 -= 250;
		}
	}
	else if (connectionType == 'c') {
		std::cout << "Vida: " << vidaJ2 << std::endl;
		//std::cin >> textAcao;
		if (textAcao == "a") {
			vidaJ1 -= 100;
		}
		else if (textAcao == "A") {
			vidaJ1 -= 250;
		}
	}
}
