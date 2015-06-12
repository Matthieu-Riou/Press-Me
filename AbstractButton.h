#ifndef ABSTRACT_BUTTON_H
#define ABSTRACT_BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class AbstractButton
{
	protected:
		sf::Font font_;
		sf::Text texte_;
		sf::RectangleShape zone_;
		sf::Vector2f marge_;
		
		sf::RenderWindow *parent_;

		sf::Color colorDefaut_;
		
	public:
		AbstractButton(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent = NULL);

		virtual void setParent(sf::RenderWindow *parent);		
		
		virtual void autosize();
		
		virtual sf::Vector2f getSize() const;
		
		virtual void update() = 0;
		virtual void afficher() const;

};

#endif //ABSTRACT_BUTTON_H
