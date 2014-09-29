#ifndef ACTION_H
#define ACTION_H

/*Classe abstraite définissant une action*/
class Action
{
	public:
		virtual void  operator() () const = 0;
};


#endif //ACTION_H
