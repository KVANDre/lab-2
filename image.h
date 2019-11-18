#pragma once

#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>

class Image {
private:
	int _m, _n;
	bool** _data;
	mutable double _s;
public:
	//Image() :_m(0), _n(0), _data(nullptr), _s(-1) {}

	Image(int m, int n): _m(m), _n(n), _s(-1){
		_data = new bool*[m];   // создаем 
		for (int i = 0; i < m; ++i) {          // двумерный
			_data[i] = new bool[n]; // массив 
		}
	}

	int getM() const
	{
		return _m;
	}
	
	int getN() const
	{
		return _n;
	}
	
	bool getData(int m, int n) const
	{
		return _data[m][n];
	}
	
	void setM(int set)
	{
		_m = set;
	}
	
	void setN(int set)
	{
		_n = set;
	}

	void setData(bool set, int m, int n) {
		_data[m][n] = set;
	}

	// Деструктор
	~Image();
	
	// Конструктор копирования
	Image(const Image& obj);

	//Оператор присваивания копированием. 
	Image& operator =(const Image &obj);
	
	//Конструктор перемещения.
	Image(Image& obj);

	//Оператор присваивания перемещением.
	Image& operator =(Image&& obj);

	//Доступ к значениям по координатам, если справа то просто выводится
	const bool& operator () (int x, int y) const;
	
	//Доступ к значения по координатам, если слева то выводится и меняет своё значение
	bool& operator () (int x, int y);
	
	//Оператор умножения 2 объектов
	Image operator*(const Image& obj);

	//Оператор сложения 2 объектов
	Image operator+(const Image& obj);

	//Конструктор отношения true к общему количеству
	const double& attitude() const;
};

//Произведение объекта на число
Image operator*(bool a, const Image& obj);

//Произведение числа на объект
Image operator*(const Image& obj, bool a);

//Сложение объекта на числом
Image operator+(bool a, const Image& obj);

//Сложение числа с объектом
Image operator+(const Image& obj, bool a);

// Переворот значений
Image operator!(const Image& obj) noexcept;
