#include "Button.h"
#include "Espace.h"
#include "Actions/Nothing.h"

Button::Button(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent) : marge_(20, 20), parent_(parent), action_(new Default_Action::Nothing()), pressed(false)
{	
	font_.loadFromFile("Font/LiberationSans-Regular.ttf");
	texte_.setString(texte);
	texte_.setFont(font_);
	texte_.setColor(sf::Color::Red);
	
	zone_.setPosition(pos);
	zone_.setOutlineThickness(5);
	zone_.setOutlineColor(sf::Color(250, 150, 100));
	
	autosize();
}

void Button::setAction(Action* action)
{
	action_ = action;
}

void Button::setParent(sf::RenderWindow* parent)
{
	parent_ = parent;
}

void Button::autosize()
{
	sf::FloatRect rect = texte_.getLocalBounds();
	texte_.setPosition(sf::Vector2f(zone_.getPosition().x + marge_.x -rect.left, zone_.getPosition().y + marge_.y -rect.top));
	zone_.setSize(sf::Vector2f(rect.width + 2*marge_.x, rect.height + 2*marge_.y));
	zone_.setFillColor(sf::Color::Blue);
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

void Button::afficher() const
{
	parent_->draw(zone_);
	parent_->draw(texte_);
}
