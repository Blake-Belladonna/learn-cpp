#include "Complex.h"

Complex::Complex()
{
	real = image = 0.0f;
	std::cout << ":::::Complex::Complex()" << std::endl;
}

Complex::Complex(float real, float image)
{
	this->real = real;
	this->image = image;
	std::cout << ":::::Complex::Complex(float real, float image)" << std::endl;
}

Complex::Complex(const Complex& c)
{
	real = c.real;
	image = c.image;
	std::cout << ":::::Complex::Complex(const Complex& c)" << std::endl;
}

Complex::~Complex()
{
	std::cout << ":::::Complex::~Complex()" << std::endl;
}

Complex& Complex::operator=(const Complex& c)
{
	if (this != &c)
	{
		real = c.real;
		image = c.image;
	}
	return *this;
}

Complex Complex::operator+(const Complex& c)
{
	//函数体内第一次构造（调用默认构造函数）
	//Complex temp; 
	//temp.real = real + c.real;
	//temp.image = image + c.image;
	//函数体内第二次构造（调用拷贝构造）
	//return temp;//通过拷贝构造生成新的对象来存储返回数据 (栈数据‘temp’会在函数结束时释放)
	return Complex(real + c.real, image + c.image);//通过自定义构造函数 存储返回的数据
}

Complex Complex::operator-(const Complex& c)
{
	return Complex(real - c.real, image - c.image);
}

Complex& Complex::operator++()
{
	++real;
	++image;
	return *this;
}

Complex Complex::operator++(int)
{
	//函数体内第一次构造（调用默认构造函数）
	//Complex temp;
	//temp.real = real;
	//temp.image = image;
	//函数体内第二次构造（调用拷贝构造）
	//return temp;//通过拷贝构造生成新的对象来存储返回数据 (栈数据‘temp’会在函数结束时释放)
	return Complex(real++, image++); //通过自定义构造函数 存储返回的数据
}

Complex& Complex::operator--()
{
	--real;
	--image;
	return *this;
}

Complex Complex::operator--(int)
{
	return Complex(--real, --image);
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << "real = " << c.real << "; image = " << c.image;
	return os;
}

std::istream& operator>>(std::istream& io, Complex& c)
{
	io >> c.real >> c.image;
	return io;
}

bool Complex::operator==(const Complex& c)
{
	return (real == c.real && image == c.image);
}

bool Complex::operator!=(const Complex& c)
{
	return (real != c.real && image != c.image);
}