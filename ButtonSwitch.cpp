#include "ButtonSwitch.h"
#include "Espace.h"
#include "Actions/Nothing.h"

ButtonSwitch::ButtonSwitch(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent) : 
    AbstractButton(texte, pos, parent), 
    on_(new Default_Action::Nothing()), 
    off_(new Default_Action::Nothing()), 
    pressed_(false), 
    active_(false),
    colorActive_(sf::Color(250, 50, 100)),
    colorPressed_(sf::Color(250, 100, 100)),
    colorPressedActive_(sf::Color(250, 0, 100))
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
      zone_.setOutlineColor(colorActive_);
    else
      zone_.setOutlineColor(colorDefaut_);
  }
  //Si on relâche le clic dans le bouton
  else if(pressed_ && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) //estDans
  {
    pressed_ = false;

    if(active_)
    {
      active_ = false;
      (*off_)();
      zone_.setOutlineColor(colorDefaut_);
    }
    else
    {
      active_ = true;
      (*on_)();
      zone_.setOutlineColor(colorActive_);
    }
  }
  //Si on presse le clic dans le bouton
  else if(!pressed_ && sf::Mouse::isButtonPressed(sf::Mouse::Left) && Espace::estDans(sf::Mouse::getPosition(*parent_), zone_))
  {
    pressed_ = true;

    if(active_)
      zone_.setOutlineColor(colorPressedActive_);
    else
      zone_.setOutlineColor(colorPressed_);
  }

}
