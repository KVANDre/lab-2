#include <cstdio>
#include <iostream>
#include <libutils/io.h>
#include <cmath>
#include "image.h"
using namespace std;

void mainMenu();
void fillOutRand(Image& obj);
void getElement(const Image& obj, int x, int y);
void getElementChange(const Image& obj, int x, int y, int a);
void multiImages(const Image& obg, const Image& obj);
void addImages(const Image& obg, const Image& obj);
std::ostream& operator<<(std::ostream& out, const Image& obj); //Вывод красивого изображения


void mainMenu() {
	std::cout << "Choose function:" << std::endl;
	std::cout << "1. Get the element by coordinates;" << std::endl;
	std::cout << "2. Get the element by coordinates and change its value;" << std::endl;
	std::cout << "3. Multiplication of two images;" << std::endl;
	std::cout << "4. Addition of two images;" << std::endl;
	std::cout << "5. Adding bool and image (commutative);" << std::endl;
	std::cout << "6. Multiplication bool and image (commutative);" << std::endl;
	std::cout << "7. Calculation of the fill factor of the image (the number of true values per total number of values);" << std::endl;
	std::cout << "8. Do invert;" << std::endl;
	std::cout << "0. Exit program;" << std::endl;
}

void fillOutRand(Image& obj) {
	for (int i = 0; i < obj.getM(); ++i) {
		for (int j = 0; j < obj.getN(); ++j) {
			obj(i,j)=(bool)rand()%2;
		}
	}
}

void getElement(const Image& obj, int x, int y) {
	if (((x < obj.getM()) || (x >= 1)) && ((y < obj.getN()) || (y >= 1))) std::cout << obj(x, y) << std::endl;
	else std::cout << "This element does not exist, since the entered coordinates are not included in the range" << std::endl;
}

void getElementChange(Image& obj, int x, int y, int a) {
	if (((x < obj.getM()) || (x >= 1)) && ((x < obj.getN()) || (x >= 1))) {
		if (a = 1) obj(x, y) = true;
		else obj(x, y) = false;
		std::cout << obj(x, y) << std::endl;
	}
	else std::cout << "This element does not exist, since the entered coordinates are not included in the range" << std::endl;
}

void multiImages(const Image& obg, const Image& obj) {
	Image res(obj.getM(),obj.getN());
	for (int i = 0; i < obj.getM(); ++i) {
		for (int j = 0; j < obj.getN(); ++j) {
			res(i, j) = obg(i, j) * obj(i, j);
		}
	}
	std::cout << res << std::endl;
}

void addImages(const Image& obg, const Image& obj) {
	Image res(obj.getM(), obj.getN());
	for (int i = 0; i < obj.getM(); ++i) {
		for (int j = 0; j < obj.getN(); ++j) {
			res(i, j) = obg(i, j) + obj(i, j);
		}
	}
	std::cout << res << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Image& obj) {
	for (int i = 0; i < obj.getM(); ++i) {
		for (int j = 0; j < obj.getN(); ++j) {
			if (obj(i, j)) std::cout << '1' << ' ';
			else std::cout << '.' << ' ';
		}
		std::cout << std::endl;
	}
	return (out);
}

int main() {
	
	std::cout << "Enter image dimension" << std::endl;
	int x = utils::read_int("Input M(1, 1000): ", 1, 1000);
	int y = utils::read_int("Input N(1, 1000): ", 1, 1000);
	
	Image paint(x,y);
	fillOutRand(paint);

	std::cout << "Image first" << std::endl;
	std::cout << paint << std::endl;
	int k = -1;
	
	while (k != 0){
		mainMenu();
		k = utils::read_int("Your choise: ", 0, 10);
		system("cls");
		
		switch (k)
		{

		case 1: {
			std::cout << "Get the element by coordinates" << std::endl;
			int x = 0, y = 0;
			x = utils::read_int("Input coordinate X (1, 1000): ", 1, 1000);
			y = utils::read_int("Input coordinate Y (1, 1000): ", 1, 1000);
			getElement(paint, x, y);
		} break;

		case 2: {
			std::cout << "Get the element by coordinates and change its value" << std::endl;
			int x = 0, y = 0, b = 0;
			b = utils::read_int("Input new meaning 1 - TRUE or 0 - FALSE: ", 0, 1);
			x = utils::read_int("Input coordinate X (1, 1000): ", 1, 1000);
			y = utils::read_int("Input coordinate Y (1, 1000): ", 1, 1000);
			getElementChange(paint, x, y, b);
		} break;

		case 3: { 
			std::cout << "Multiplication of two images" << std::endl;
			std::cout << "Input second images" << std::endl;
			int x = utils::read_int("Input M(1, 1000): ", 1, 1000);
			int y = utils::read_int("Input N(1, 1000): ", 1, 1000);
			Image paint2(x,y);
			fillOutRand(paint2);
			std::cout << "Image second" << std::endl;
			std::cout << paint2 << std::endl << std::endl;
			multiImages(paint2, paint);
			
		} break;

		case 4: {
			std::cout << "Addition of two images" << std::endl;
			int x = utils::read_int("Input M(1, 1000): ", 1, 1000);
			int y = utils::read_int("Input N(1, 1000): ", 1, 1000);
			Image paint2(x, y);
			fillOutRand(paint2);
			std::cout << "Image first" << std::endl;
			std::cout << paint2 << std::endl << std::endl;;
			addImages(paint2, paint);
		} break;

		case 5: { 
			std::cout << "Adding bool and image (commutative)" << std::endl;
			int a = 0;
			bool c;
			x = paint.getM();
			y = paint.getN();
			Image res(x,y);
			a = utils::read_int("Input new meaning 1 - TRUE or 0 - FALSE: ", 0, 1);
			if (a == 1) c = true;
			else c = false;
			for (int i = 0; i < paint.getM(); ++i) {
				for (int j = 0; j < paint.getN(); ++j) {
					res(i,j)= paint(i,j) * c;
				}
			}
			std::cout << res << std::endl;
		} break;

		case 6: {
			std::cout << "Multiplication bool and image (commutative)" << std::endl;
			int a = 0;
			bool c;
			x = paint.getM();
			y = paint.getN();
			Image res(x, y);
			a = utils::read_int("Input new meaning 1 - TRUE or 0 - FALSE: ", 0, 1);
			if (a == 1) c = true;
			else c = false;
			for (int i = 0; i < paint.getM(); ++i) {
				for (int j = 0; j < paint.getN(); ++j) {
					res(i, j) = paint(i, j) + c;
				}
			}
			std::cout << res << std::endl;
		} break;

		case 7: {
			std::cout << "Calculation of the fill factor of the image (the number of true values per total number of values)" << std::endl;
			std::cout << paint.attitude() << std::endl;
		} break;

		case 8: {
			std::cout << "Do invert" << std::endl;
			x = paint.getM();
			y = paint.getN();
			Image res(x, y);
			for (int i = 0; i < paint.getM(); ++i) {
				for (int j = 0; j < paint.getN(); ++j) {
					res(i, j) = !paint(i,j);
				}
			}
			std::cout << res << std::endl;
		} break;

		case 0: { exit(0); } break;
		}
	}

}