#include "Button.h"
#include "Espace.h"
#include "Actions/Nothing.h"

Button::Button(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent) : AbstractButton(texte, pos, parent), action_(new Default_Action::Nothing()), pressed(false)
{}


void Button::setAction(Action* action)
{
	action_ = action;
}

void Button::update()
{
	//Si la souris sort du bouton, sans avoir relâché le clic
	if(pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Espace::estDans(sf::Mouse::getPosition(*parent_), zone_))
	{
		pressed = false;
		zone_.setOutlineColor(sf::Color(250, 150, 100));
	}
	//Si on relâche le clic dans le bouton
	else if(pressed && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) //estDans
	{
		pressed = false;
		zone_.setOutlineColor(sf::Color(250, 150, 100));
		(*action_)();
	}
	//Si on presse le clic dans le bouton
	else if(!pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Espace::estDans(sf::Mouse::getPosition(*parent_), zone_))
	{
		pressed = true;
		zone_.setOutlineColor(sf::Color(250, 100, 100));
	}
	
}
