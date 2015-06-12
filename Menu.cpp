#include "Menu.h"
#include <iostream>

Menu::Menu(sf::Vector2f pos, sf::RenderWindow *parent) : parent_(parent), buttons_(), colorBorder_(sf::Color(250, 150, 100)), marge_(20, 20)
{	
	zone_.setPosition(pos);
	zone_.setOutlineThickness(5);
	zone_.setOutlineColor(colorBorder_);
	
	autosize();
}

void Menu::setParent(sf::RenderWindow* parent)
{
  parent_ = parent;
}

void Menu::addButton(AbstractButton* button)
{
  buttons_.push_back(button);
  autosize();
}

void Menu::update()
{
  std::list<AbstractButton*>::const_iterator it;
  
  for(it = buttons_.begin(); it != buttons_.end(); ++it)
  {
    (*it)->update();
  }
}

void Menu::afficher() const
{
  parent_->draw(zone_);
  
  std::list<AbstractButton*>::const_iterator it;
  
  for(it = buttons_.begin(); it != buttons_.end(); ++it)
  {
    (*it)->afficher();
  }
}

void Menu::autosize()
{
  sf::Vector2f size;
  
  std::cout << "1" << size.x << " - " << size.y << std::endl;
  
  std::list<AbstractButton*>::const_iterator it;
  
  for(it = buttons_.begin(); it != buttons_.end(); ++it)
  {
    std::cout << "a" << std::endl;
    size+=(*it)->getSize();
  }
  
  std::cout << size.x << " - " << size.y << std::endl;
  
	zone_.setSize(sf::Vector2f(size.x + 2*marge_.x, size.y + 2*marge_.y));
	zone_.setFillColor(sf::Color::White);
}
