#ifndef MENU_H
#define MENU_H

#include <list>
#include <SFML/Graphics.hpp>
#include "AbstractButton.h"
#include "Actions/Action.h"

class Menu
{
  protected:
    sf::RenderWindow* parent_;
    
    std::list<AbstractButton*> buttons_;
    sf::Color colorBorder_;
    
    sf::RectangleShape zone_;
		sf::Vector2f marge_;
		float margeIntern_;

  public:
    Menu(sf::Vector2f pos, sf::RenderWindow *parent = NULL);

    void setParent(sf::RenderWindow* parent);
    void addButton(AbstractButton* button);	

    void autosize();
    
    void update();
    void afficher() const;
  };

#endif //MENU_H

