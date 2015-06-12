#include "Menu.h"

Menu::Menu(sf::Vector2f pos, sf::RenderWindow *parent) : parent_(parent), buttons_(), colorBorder_(sf::Color(250, 150, 100)), marge_(20, 20), margeIntern_(15)
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
  float posX;
  if(buttons_.empty())
    posX = zone_.getPosition().x + zone_.getSize().x - marge_.x;
  else
    posX = zone_.getPosition().x + zone_.getSize().x - marge_.x + margeIntern_;
    
  buttons_.push_back(button);
  button->setPosition(sf::Vector2f(posX, zone_.getPosition().y + marge_.y));
  button->autosize();
  
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
  
  std::list<AbstractButton*>::const_iterator it;
  
  for(it = buttons_.begin(); it != buttons_.end(); ++it)
  {
    size.x += (*it)->getSize().x;
    size.y = std::max(size.y, (*it)->getSize().y);
  }
  
  float totalMargeIntern;
  if(buttons_.empty())
    totalMargeIntern = 0;
  else
    totalMargeIntern = (buttons_.size()-1)*margeIntern_;
    
	zone_.setSize(sf::Vector2f(size.x + 2*marge_.x + totalMargeIntern, size.y + 2*marge_.y));
	zone_.setFillColor(sf::Color::White);
}
