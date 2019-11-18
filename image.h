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
		_data = new bool*[m];   // ������� 
		for (int i = 0; i < m; ++i) {          // ���������
			_data[i] = new bool[n]; // ������ 
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

	// ����������
	~Image();
	
	// ����������� �����������
	Image(const Image& obj);

	//�������� ������������ ������������. 
	Image& operator =(const Image &obj);
	
	//����������� �����������.
	Image(Image& obj);

	//�������� ������������ ������������.
	Image& operator =(Image&& obj);

	//������ � ��������� �� �����������, ���� ������ �� ������ ���������
	const bool& operator () (int x, int y) const;
	
	//������ � �������� �� �����������, ���� ����� �� ��������� � ������ ��� ��������
	bool& operator () (int x, int y);
	
	//�������� ��������� 2 ��������
	Image operator*(const Image& obj);

	//�������� �������� 2 ��������
	Image operator+(const Image& obj);

	//����������� ��������� true � ������ ����������
	const double& attitude() const;
};

//������������ ������� �� �����
Image operator*(bool a, const Image& obj);

//������������ ����� �� ������
Image operator*(const Image& obj, bool a);

//�������� ������� �� ������
Image operator+(bool a, const Image& obj);

//�������� ����� � ��������
Image operator+(const Image& obj, bool a);

// ��������� ��������
Image operator!(const Image& obj) noexcept;
