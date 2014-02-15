#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
int main() {
	sf::RenderWindow win(sf::VideoMode(800, 600), "Malloc");
	sf::View view(sf::FloatRect(0, 0, 800, 600));
	sf::Event evt;
	while(win.isOpen()) {
		while(win.pollEvent(evt)) {
			switch(evt.type) {
			case sf::Event::Closed:
				win.close();
				break;
			default:
				break;
			}
		}
		win.clear(sf::Color::Black);
		win.display();
	}
	return 0;
}