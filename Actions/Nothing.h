#ifndef NOTHING_H
#define NOTHING_H

#include "Action.h"

namespace Default_Action
{
	class Nothing : public Action
	{
		public:
			virtual void  operator() () const;
	};
}

#endif //NOTHING_H
