#pragma once

#include <iostream>

class Complex
{
public:
	Complex();
	Complex(float real, float image);
	Complex(const Complex& c);
	virtual ~Complex();

	inline float GetReal() const { return real; }
	inline float GetImage() const { return image; }

	inline void SetReal(float real) { this->real = real; }
	inline void SetImage(float image) { this->image = image; }

	Complex& operator=(const Complex& c);
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex& operator++();
	Complex operator++(int);
	Complex& operator--();
	Complex operator--(int);


	bool operator==(const Complex& c);
	bool operator!=(const Complex& c);

	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend std::istream& operator>>(std::istream& is, Complex& c);

private:
	float real;
	float image;
};

