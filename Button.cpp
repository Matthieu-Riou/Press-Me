#include "Button.h"
#include "Espace.h"
#include "Actions/Nothing.h"

Button::Button(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent) : 
		AbstractButton(texte, pos, parent), 
		action_(new Default_Action::Nothing()), 
		pressed_(false),
		colorPressed_(sf::Color(250,100,100))
{}


void Button::setAction(Action* action)
{
	action_ = action;
}

void Button::update()
{
	//Si la souris sort du bouton, sans avoir relâché le clic
	if(pressed_ && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Espace::estDans(sf::Mouse::getPosition(*parent_), zone_))
	{
		pressed_ = false;
		zone_.setOutlineColor(colorDefaut_);
	}
	//Si on relâche le clic dans le bouton
	else if(pressed_ && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) //estDans
	{
		pressed_ = false;
		zone_.setOutlineColor(colorDefaut_);
		(*action_)();
	}
	//Si on presse le clic dans le bouton
	else if(!pressed_ && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Espace::estDans(sf::Mouse::getPosition(*parent_), zone_))
	{
		pressed_ = true;
		zone_.setOutlineColor(colorPressed_);
	}
	
}
