#include <iostream>
#include <cassert>
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

	Combinatorio::Combinatorio(const unsigned long long int &upper, const unsigned long long int &down)
	{
		this->setUpper(upper);
		this->setDown(down);
		this->update();
	}

	Combinatorio::Combinatorio(const Combinatorio &c)
	{
		this->clone(c);
	}

	unsigned long long int Combinatorio::getUpper() const
	{
		return _upper;
	}

	unsigned long long int Combinatorio::getDown() const
	{
		return _down;
	}

	long double Combinatorio::getResult() const
	{
		assert(!this->checkUpdate());
		return _result;
	}

	bool Combinatorio::checkUpdate() const
	{
		return _needUpdate;
	}
}