#ifndef __NREINAS_HPP_ALGORITMIA
#define __NREINAS_HPP_ALGORITMIA

#include <iostream>
#include <list>
#include "TableroAjedrez.hpp"
#include "FichaAjedrez.hpp"

using namespace std;

namespace algoritmia
{
	class NReinas
	{
	private:
		unsigned int _dim; //!< Dimension de los tableros de la solucion NReinas

	public:
		/** @brief Constructor por defecto del tablero de las N-Reinas, este tablero
			se dimensiona a un tablero de ajedrez por defecto (8 columnas x 8 filas) **/
		NReinas();

		/** @brief Constructor del tablero de las N-Reinas parametrizado. Este tablero
			establece el tamaño de las reinas al tamaño deseado
			@param dim Dimension del tablero **/
		NReinas(const unsigned int &dim);

		/** @brief Constructor de copia del tablero de las N-Reinas
			@param nr Tablero a copiar **/
		NReinas(const NReinas &nr);

		/** @brief Rellena el tablero con una solucion del problema, y lo deja almacenado
			@return Un tablero de ajedrez con la solucion deseada **/
		TableroAjedrez singleSolution() const;

		/** @brief Devuelve una lista con todos las soluciones posibles al problema de
			las ocho reinas
			@return Una lista con todas las soluciones encontradas **/
		list<TableroAjedrez> allSolutions() const;

		/** @brief Establece la nueva dimension que deberan de seguir los tableros **/
		void setDimension(const unsigned int &dim);

		/** @brief Devuelve la dimension en la cual se establecio la clase **/
		unsigned int getDimension() const;

		/** @brief Destructor de la clase NReinas **/
		~NReinas();
	};
}

#endif