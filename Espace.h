#ifndef ESPACE_H
#define ESPACE_H

#include <SFML/Graphics.hpp>

/*! \enum Dir
	\brief Les différentes directions possibles
*/
enum Dir {GAUCHE, DROITE, HAUT, BAS};

/*! \namespace Espace
	\brief Namespace contenant des méthodes pour savoir si un point est dans une ligne ou un rectangle
*/
namespace Espace
{
	bool estDans(float point, float min, float max); //point est dans [min, max]
	bool estDans(sf::Vector2f point, sf::Vector2f min, sf::Vector2f max);
	bool estDans(sf::Vector2f point, sf::RectangleShape rect);

	bool estDans(int point, int min, int max); //point est dans [min, max]
	bool estDans(sf::Vector2i point, sf::Vector2i min, sf::Vector2i max);
	bool estDans(sf::Vector2i point, sf::RectangleShape rect);
}


#endif //ESPACE_H
