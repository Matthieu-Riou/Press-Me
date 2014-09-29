#ifndef Button_H
#define Button_H

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
	protected:
		sf::Font font_;
		sf::Text texte_;
		sf::RectangleShape zone_;
		sf::Vector2f marge_;
		
		sf::RenderWindow *parent_;
		
	public:
		Button(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent = NULL);

		virtual void setParent(sf::RenderWindow *parent);		
		
		virtual void autosize();
		
		virtual void afficher() const;

};

#endif //Button_H
