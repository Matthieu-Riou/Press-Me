#ifndef Button_H
#define Button_H

#include <SFML/Graphics.hpp>
#include <string>
#include "AbstractButton.h"
#include "Actions/Action.h"

class Button : public AbstractButton
{
	protected:
		Action* action_;
		bool pressed;
		
	public:
		Button(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent = NULL);

		virtual void setAction(Action* action);	
		
		virtual void update();

};

#endif //Button_H
