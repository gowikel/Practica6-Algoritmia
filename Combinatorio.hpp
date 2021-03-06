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

		/** @brief Devuelve el factorial del numero que le pases **/
		long double factorial(const unsigned long long int &f) const;

		/** @brief Devuelve un factorial truncado su calculo **/
		long double limitedFactorial(const unsigned long long int &f, const unsigned long long int &limite) const;

		/** @brief Devuelve un factorial limitado multiplicado en cada paso por un numero **/
		long double mulLimitedFactorial(const unsigned long long int &f, const unsigned long long int &limite, const long double &mul) const;

		/** @brief Hace la multiplicacion y division del numero para conseguir el factorial, poco a poco **/
		void twoPhasesFactorial(const unsigned long long int &upper,const unsigned long long int &down, const unsigned long long int &limit);

		/** @brief Actualiza el valor del resultado **/
		void update();

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

		/** @brief Devuelve el resultado de la operacion C(m under n) 
			@warning La bandera update debe ser false para que el metodo no falle, si cambio el upper
			o el down del numero, asegurese de realizar antes un Combinatorio::update **/
		long double getResult() const;

		/** @brief Establece el upper y el down de un numero combinatorio, siendo estos C(upper under down) **/
		void set(const unsigned long long int &upper, const unsigned long long &down);

		/** @brief Hace una copia del numero combinatorio c a si mismo **/
		void clone(const Combinatorio &c);

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

		/** @brief Sobrecarga del operador + **/
		long double operator+(const Combinatorio &c) const;

		/** @brief Sobrecarga del operador - **/
		long double operator-(const Combinatorio &c) const;

		/** @brief Sobrecarga del operador * **/
		long double operator*(const Combinatorio &d) const;

		/** @brief Sobrecarga del operador / **/
		long double operator/(const Combinatorio &d) const;

		/** SOBRECARGAS INLINE **/
		template <class T>
		inline long double operator+(const T &n) const
		{
			return this->getResult() + static_cast<long double>(n);
		}

		template <class T>
		inline long double operator-(const T &n) const
		{
			return this->getResult() - static_cast<long double>(n);
		}

		template <class T>
		inline long double operator*(const T &n) const
		{
			return this->getResult() * static_cast<long double>(n);
		}

		template <class T>
		inline long double operator/(const T &n) const
		{
			return this->getResult() / static_cast<long double>(n);
		}

		template <class T>
		inline bool operator==(const T &n) const
		{
			return this->getResult() == n;
		}

		template <class T>
		inline bool operator!=(const T &n) const
		{
			return !(*this == n);
		}

		template <class T>
		inline bool operator<(const T &n) const
		{
			return this->getResult() < static_cast<long double>(n);
		}

		template <class T>
		inline bool operator<=(const T &n) const
		{
			return this->getResult() <= static_cast<long double>(n);
		}

		template <class T>
		inline bool operator>(const T &n) const
		{
			return !(*this <= n);
		}

		template <class T>
		inline bool operator>=(const T &n) const
		{
			return !(*this < n);
		}

		/** @brief Destructor de clase **/
		~Combinatorio();
	};
}

#endif