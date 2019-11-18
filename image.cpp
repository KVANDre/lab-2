#include <cstdio>
#include <cmath>
#include "image.h"

Image::~Image() {
	for (int i = 0; i < _n; ++i) {
		delete[] _data[i];  // удаляем массив
	}
	delete[] _data;
}

Image::Image(const Image& obj) {
	_data = new bool*[obj._m];
	for (int i = 0; i < obj._m; ++i)
		_data[i] = new bool[obj._n];
	_s = obj._s;
	for (int i = 0; i < obj._m; ++i) {
		for (int j = 0; j < obj._n; ++j) {
			_data[i][j] = obj._data[i][j];
		}
	}
}

Image& Image::operator =(const Image &obj)
{
	// Проверка на самоприсваивание
	if (this == &obj)
		return *this;

	for (int i = 0; i < _n; ++i) {
		delete[] _data[i];  // удаляем массив
	}
	delete[] _data;
	_data = new bool*[_m];   // создаем 
	for (int i = 0; i < _m; ++i) {          // двумерный
		_data[_n] = new bool[_n]; // массив 
	}

	// Выполняем копирование значений
	_m = obj._m;
	_n = obj._n;
	_s = obj._s;

	for (int i = 0; i < obj._m; ++i) {
		for (int j = 0; j < obj._n; ++j) {
			_data[i][j] = obj._data[i][j];
		}
	}

	// Возвращаем текущий объект
	return *this;
}

Image::Image(Image& obj) {
	_data = new bool*[obj._m];
	for (int i = 0; i < obj._m; ++i)
		_data[i] = new bool[obj._n];
	_s = obj._s;
	for (int i = 0; i < obj._m; ++i) {
		for (int j = 0; j < obj._n; ++j) {
			obj._data = nullptr;
		}
	}
}

Image& Image :: operator= (Image&& obj){
	for (int i = 0; i < _n; ++i) {
		delete[] _data[i];
	}
	delete[] _data;
	_data = obj._data;
	obj._data = nullptr;
	_s = obj._s;
	return *this;
}

const bool& Image:: operator () (int x, int y) const {
	return _data[x][y];
}

bool& Image::operator () (int x, int y) {
	_s=-1.0;
	return _data[x][y];
}

Image Image::operator*(const Image& obj) {
	Image res(obj.getM(), obj.getN());
	for (int i = 0; i < _m; ++i) {
		for (int j = 0; j < _n; ++j) {
			if (obj._data[i][j] && _data[i][j]) res._data[i][j] = true;
			else res._data[i][j] = false;
		}
	}
	return res;
}

Image Image::operator+(const Image& obj) {
	Image res(obj.getM(), obj.getN());
	for (int i = 0; i < _m; ++i) {
		for (int j = 0; j < _n; ++j) {
			if (obj._data[i][j] || _data[i][j]) res._data[i][j] = true;
			else res._data[i][j] = false;
		}
	}
	return res;
}

Image operator*(bool a, const Image& obj) {
	if (a) return Image(obj);
	else return !Image(obj);
}

Image operator*(const Image& obj, bool a) {
	return  a * obj;
}

Image operator+(bool a, const Image& obj) {
	Image res(obj.getM(), obj.getN());
	for (int i = 0; i < obj.getM(); ++i)
		for (int j = 0; j < obj.getN(); ++j)
		{
			if ((obj(i, j) == 0) && (a == 0)) res(i, j) = false;
		}
	return res;
}

Image operator+(const Image& obj, bool a) {
	return a + obj;
}

Image operator!(const Image& obj) noexcept{
	Image res(obj.getM(), obj.getN());
	for (int i = 0; i < obj.getM(); ++i)
		for (int j = 0; j < obj.getN(); ++j)
		{
			if (obj(i, j)) res(i, j) = false;
			else res(i, j) = true;
		}
	return res;
}

const double& Image::attitude() const {
	int a = 0;
	for (int i = 0; i < _m; ++i) {
		for (int j = 0; j < _n; ++j) {
			if (_data[i][j]) a = a + 1;;
		}
	}
	_s = a / (_n*_m);
	return _s;
}
