#include <cassert>
#include <random>
#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"
#include "Punto.hpp"
#include "NReinas.hpp"

using namespace std;

namespace algoritmia
{
	NReinas::NReinas()
	{
		const unsigned int defaultDimension = 8;
		this->setDimension(defaultDimension);
	}

	NReinas::NReinas(const unsigned int &dim)
	{
		this->setDimension(dim);
	}

	NReinas::NReinas(const NReinas &nr)
	{
		*this = nr;
	}

	TableroAjedrez NReinas::singleSolution() const
	{
		TableroAjedrez tablero;
		Punto posicion(0, 0);

		tablero.setTablero(this->getDimension());

		while(posicion.getX() < tablero.getDimension())
		{
			if(!tablero.amenaza(posicion))
			{
				tablero.setFicha(posicion, REINA);
				posicion.setPunto(posicion.getX() + 1, 0);
			}
			else
			{
				posicion.setPunto(posicion.getX(), posicion.getY() + 1);

				if(posicion.getY() >= tablero.getDimension()) //Hay que retroceder
				{
					posicion.setPunto(posicion.getX() - 1, 0);

					if(this->buscarReina(tablero, posicion))
					{
						tablero.borrarFicha(posicion);
						posicion.setPunto(posicion.getX(), posicion.getY() + 1);

						if(posicion.getY() >= tablero.getDimension()) //No creo que deba de pasar nunca
						{
							if(posicion.getX() != 0)
							{
								posicion.setPunto(posicion.getX() - 1 , 0);
								this->buscarReina(tablero, posicion);
								tablero.borrarFicha(posicion);
								posicion.setPunto(posicion.getX(), posicion.getY() + 1);
							}
						}
					}
					else //No creo que deba de pasar nunca
					{
						posicion.setPunto(posicion.getX() + 2, 0);
					}
				}
			}
		}

		return tablero;
	}

	list<TableroAjedrez> NReinas::allSolutions() const
	{
		list<TableroAjedrez> lista;
		TableroAjedrez tablero = this->singleSolution();
		Punto posicion;
		Punto busqueda;
		Punto limite(0, tablero.getDimension());

		lista.push_back(tablero);

		this->buscarReina(tablero, posicion);

		busqueda = posicion;

		while(busqueda.getY() < tablero.getDimension() - 1)
		{
			unsigned int reinas = 0;
			posicion.setPunto(busqueda.getX(), busqueda.getY() + 1);
			busqueda = posicion;
			tablero.clear();


			while(posicion.getX() < tablero.getDimension())
			{
				if(posicion == limite)
				{
					break;
				}
				else if(!tablero.amenaza(posicion))
				{
					tablero.setFicha(posicion, REINA);
					posicion.setPunto(posicion.getX() + 1, 0);
					reinas++;
				}
				else
				{
					posicion.setPunto(posicion.getX(), posicion.getY() + 1);

					if(posicion.getY() >= tablero.getDimension()) //Hay que retroceder
					{
						posicion.setPunto(posicion.getX() - 1, 0);

						if(this->buscarReina(tablero, posicion))
						{
							tablero.borrarFicha(posicion);
							posicion.setPunto(posicion.getX(), posicion.getY() + 1);
							reinas--;

							if(posicion.getY() >= tablero.getDimension()) //No creo que deba de pasar nunca
							{
								if(posicion.getX() != 0)
								{
									posicion.setPunto(posicion.getX() - 1 , 0);
									this->buscarReina(tablero, posicion);
									tablero.borrarFicha(posicion);
									posicion.setPunto(posicion.getX(), posicion.getY() + 1);
									reinas--;
								}
							}
						}
						else //No creo que deba de pasar nunca
						{
							posicion.setPunto(posicion.getX() + 2, 0);
						}
					}
				}
			}

			if(reinas == this->getDimension())
			{
				list<TableroAjedrez> per = this->getPermutaciones(tablero);
				lista.push_back(tablero);

				for(list<TableroAjedrez>::const_iterator it = per.begin(); it != per.end(); it++)
				{
					lista.push_back(*it);
				}

				//lista.unique();
			}
		}

		return lista;
	}

	list<TableroAjedrez> NReinas::getPermutaciones(const TableroAjedrez &t) const
	{
		list<TableroAjedrez> lista;
		TableroAjedrez tabla;
		list<Punto> posicionesReinas = this->searchQueens(t);

		for(list<Punto>::const_iterator it = posicionesReinas.begin(); it != posicionesReinas.end(); it++)
		{
			for(list<Punto>::const_iterator sig = next(it, 1); sig != it; sig++)
			{
				if(sig == posicionesReinas.end())
				{
					sig = posicionesReinas.begin();
				}

				if(distance(it, sig) == 0)
				{
					break;
				}

				tabla = t;

				Punto start;
				Punto end;

				start.setPunto(sig->getX(), it->getY());
				end.setPunto(it->getX(), sig->getY());


				tabla.borrarFicha(*it);
				tabla.borrarFicha(*sig);

				if(!tabla.amenaza(start))
				{
					tabla.setFicha(start, REINA);
				}
				else
				{
					break;
				}

				if(!tabla.amenaza(end))
				{
					tabla.setFicha(end, REINA);
				}
				else
				{
					break;
				}

				lista.push_back(tabla);
			}

		}

		return lista;
	}

	void NReinas::setIntentosVegas(const unsigned int &intentos)
	{
		_intentosVegas = intentos;
	}

	unsigned int NReinas::getIntentosVegas() const
	{
		return _intentosVegas;
	}

	bool NReinas::vegas(TableroAjedrez &table, const unsigned int &nIntentos)
	{
		random_device rd;
		unsigned int reinas = 0;
		table.clear();
		unsigned int intentos = 0;

		for(unsigned int i = 0; i < table.getDimension(); i++)
		{
			while(intentos < nIntentos)
			{
				unsigned int j = rd() % table.getDimension();
				Punto p(i, j);

				if(table.amenaza(p))
				{
					intentos++;
				}
				else
				{
					table.setFicha(p, REINA);
					reinas++;
					break;
				}

				if(intentos >= nIntentos)
				{
					break;
				}
			}
		}

		this->setIntentosVegas(intentos);

		if(reinas == table.getDimension())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool NReinas::buscarReina(const TableroAjedrez &t, Punto &p) const
	{
		assert(p.getX() < t.getDimension());
		
		bool resultado = false;

		for(unsigned int j = 0; j < t.getDimension(); j++)
		{
			if(t.getEnumFicha(Punto(p.getX(), j)) == REINA)
			{
				p.setPunto(p.getX(), j);
				resultado = true;
				break;
			}
		}

		return resultado;
	}

	list<Punto> NReinas::searchQueens(const TableroAjedrez &t) const
	{
		list<Punto> l;

		for(unsigned int i = 0; i < t.getDimension(); i++)
		{
			for(unsigned int j = 0; j < t.getDimension(); j++)
			{
				Punto p(i, j);

				if((t.hayFicha(p)) && (t.getEnumFicha(p) == REINA))
				{
					l.push_back(p);
				}
			}
		}

		return l;
	}

	void NReinas::setDimension(const unsigned int &dim)
	{
		assert(dim > 3);
		_dim = dim;
	}

	unsigned int NReinas::getDimension() const
	{
		return _dim;
	}

	void NReinas::operator=(const NReinas &nr)
	{
		unsigned int dimension = nr.getDimension();
		this->setDimension(dimension);
	}

	NReinas::~NReinas()
	{
		//Empty
	}
}