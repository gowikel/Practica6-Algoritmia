#include <iostream>
#include "Combinatorio.hpp"

using namespace std;

namespace numbers
{
	void Combinatorio::setUpdate(const bool &b)
	{
		_needUpdate = b;
	}

	Combinatorio::Combinatorio()
	{
		this->setUpper(0);
		this->setDown(0);
		this->update();
	}
}