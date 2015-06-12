#ifndef BUTTON_SWITCH_H
#define BUTTON_SWITCH_H

#include <SFML/Graphics.hpp>
#include "AbstractButton.h"
#include "Actions/Action.h"

class ButtonSwitch : public AbstractButton
{
  protected:
    Action* on_;
    Action* off_;
    bool pressed_;
    bool active_;

    sf::Color colorActive_;
    sf::Color colorPressed_;
    sf::Color colorPressedActive_;

  public:
    ButtonSwitch(std::string texte, sf::Vector2f pos, sf::RenderWindow *parent = NULL);

    virtual void setActionOn(Action* on);
    virtual void setActionOff(Action* off);

    virtual void update();		
};

#endif //BUTTON_SWITCH_H
