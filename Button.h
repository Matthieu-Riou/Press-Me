#ifndef Button_H
#define Button_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Actions/Action.h"

class Button
{
	protected:
		sf::Font font_;
		sf::Text texte_;
		sf::RectangleShape zone_;
		sf::Vector2f marge_;
		
		sf::RenderWindow *parent_;

		Action* action_;
		bool pressed;
		
	public:
		Button(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent = NULL);

		virtual void setAction(Action* action);
		virtual void setParent(sf::RenderWindow *parent);		
		
		virtual void autosize();
		
		virtual void update();
		virtual void afficher() const;

};

#endif //Button_H
