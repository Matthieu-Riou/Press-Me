#ifndef Button_H
#define Button_H

#include <SFML/Graphics.hpp>
#include "AbstractButton.h"
#include "Actions/Action.h"

class Button : public AbstractButton
{
	protected:
		Action* action_;
		bool pressed_;

		sf::Color colorPressed_;
		
	public:
		Button(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent = NULL);

		virtual void setAction(Action* action);	
		
		virtual void update();

};

#endif //Button_H
