#ifndef __COMBINATORIO__HPP
#define __COMBINATORIO__HPP

#include <iostream>

using namespace std;

namespace numbers
{
	class Combinatorio
	{
	private:
		unsigned long long int _upper;
		unsigned long long int _down;
		long double _result; //!< Resultado de la operacion, para no tener que calcularlo varias veces
		bool _needUpdate; //Comprueba si se necesita actualizar el numero

		/** @brief Establece una valor a la bandera _needUpdate **/
		void setUpdate(const bool &b);

	public:
		/** @brief Constructor vacio, que identifica el valor del numero combinatorio a 0 **/
		Combinatorio();

		/** @brief Constructor parametrizado
			@param upper Valor m del numero combinatorio C(m sobre n)
			@param down Valor n del numero combinatorio C(m sobre n) **/
		Combinatorio(const unsigned long long int &upper, const unsigned long long int &down);

		/** @brief Constructor de copia
			@param c Numero combinatorio a copiar **/
		Combinatorio(const Combinatorio &c);

		/** @brief Devuelve el valor m, siendo estre el valor del numero combinatorio C(m sobre n)**/
		unsigned long long int getUpper() const;

		/** @brief Devuelve el valor n, siendo este el valor del numero combinatorio C(m sobre n) **/
		unsigned long long int getDown() const;

		/** @brief Devuelve el resultado de la operacion C(m under n) **/
		long double getResult() const;

		/** @brief Checkea si el numero necesita ser recalculado (por un cambio de parametros) **/
		bool checkUpdate() const;

		/** @brief Establece el valor de m, siendo este el numero combinatorio C(m sobre n) **/
		void setUpper(const unsigned long long int &upper);

		/** @brief Establece el valor de n, siendo este el numero combinatorio C(m sobre n) **/
		void setDown(const unsigned long long int &down);

		/** @brief Actualiza el valor del resultado **/
		void update();

		/** @brief Sobrecarga del operador = **/
		void operator=(const Combinatorio &c);

		/** @brief Sobrecarga del operador == **/
		bool operator==(const Combinatorio &c) const;

		/** @brief Sobrecarga del operador != **/
		bool operator!=(const Combinatorio &c) const;

		/** @brief Sobrecarga del operador < **/
		bool operator<(const Combinatorio &c) const;

		/** @brief Sobrecarga del operador <= **/
		bool operator<=(const Combinatorio &c) const;

		/** @brief Sobrecarga del operador > **/
		bool operator>(const Combinatorio &c) const;

		/** @brief Sobrecarga del operador >= **/
		bool operator>=(const Combinatorio &c) const;

		/** @brief Sobrecarga del operador << **/
		friend ostream& operator<<(ostream &output, const Combinatorio &c);

		/** @brief Sobrecarga del operador >> **/
		friend istream& operator>>(istream &input, Combinatorio &c);

		/** @brief Destructor de clase **/
		~Combinatorio();
	};
}

#endif