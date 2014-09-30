#include "AbstractButton.h"

AbstractButton::AbstractButton(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent) : marge_(20, 20), parent_(parent), colorDefaut_(sf::Color(250, 150, 100))
{	
	font_.loadFromFile("Font/LiberationSans-Regular.ttf");
	texte_.setString(texte);
	texte_.setFont(font_);
	texte_.setColor(sf::Color::Red);
	
	zone_.setPosition(pos);
	zone_.setOutlineThickness(5);
	zone_.setOutlineColor(colorDefaut_);
	
	autosize();
}

void AbstractButton::setParent(sf::RenderWindow* parent)
{
	parent_ = parent;
}

void AbstractButton::autosize()
{
	sf::FloatRect rect = texte_.getLocalBounds();
	texte_.setPosition(sf::Vector2f(zone_.getPosition().x + marge_.x -rect.left, zone_.getPosition().y + marge_.y -rect.top));
	zone_.setSize(sf::Vector2f(rect.width + 2*marge_.x, rect.height + 2*marge_.y));
	zone_.setFillColor(sf::Color::Blue);
}

void AbstractButton::afficher() const
{
	parent_->draw(zone_);
	parent_->draw(texte_);
}

