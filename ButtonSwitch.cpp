#include "ButtonSwitch.h"
#include "Espace.h"
#include "Actions/Nothing.h"

ButtonSwitch::ButtonSwitch(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent) : 
		AbstractButton(texte, pos, parent), 
		on_(new Default_Action::Nothing()), 
		off_(new Default_Action::Nothing()), 
		pressed_(false), 
		active_(false),
		colorDefaut(sf::Color(250, 150, 100)),
		colorActive(sf::Color(250, 50, 100)),
		colorPressed(sf::Color(250, 100, 100)),
		colorPressedActive(sf::Color(250, 0, 100))
{}

void ButtonSwitch::setActionOn(Action* on)
{
	on_ = on;
}

void ButtonSwitch::setActionOff(Action* off)
{
	off_ = off;
}

void ButtonSwitch::update()
{
	//Si la souris sort du bouton, sans avoir relâché le clic
	if(pressed_ && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Espace::estDans(sf::Mouse::getPosition(*parent_), zone_))
	{
		pressed_ = false;

		if(active_)
			zone_.setOutlineColor(colorActive);
		else
			zone_.setOutlineColor(colorDefaut);
	}
	//Si on relâche le clic dans le bouton
	else if(pressed_ && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) //estDans
	{
		pressed_ = false;

		if(active_)
		{
			active_ = false;
			(*off_)();
			zone_.setOutlineColor(colorDefaut);
		}
		else
		{
			active_ = true;
			(*on_)();
			zone_.setOutlineColor(colorActive);
		}
	}
	//Si on presse le clic dans le bouton
	else if(!pressed_ && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Espace::estDans(sf::Mouse::getPosition(*parent_), zone_))
	{
		pressed_ = true;

		if(active_)
			zone_.setOutlineColor(colorPressedActive);
		else
			zone_.setOutlineColor(colorPressed);
	}
	
}
