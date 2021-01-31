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
	//�������ڵ�һ�ι��죨����Ĭ�Ϲ��캯����
	//Complex temp; 
	//temp.real = real + c.real;
	//temp.image = image + c.image;
	//�������ڵڶ��ι��죨���ÿ������죩
	//return temp;//ͨ���������������µĶ������洢�������� (ջ���ݡ�temp�����ں�������ʱ�ͷ�)
	return Complex(real + c.real, image + c.image);//ͨ���Զ��幹�캯�� �洢���ص�����
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
	//�������ڵ�һ�ι��죨����Ĭ�Ϲ��캯����
	//Complex temp;
	//temp.real = real;
	//temp.image = image;
	//�������ڵڶ��ι��죨���ÿ������죩
	//return temp;//ͨ���������������µĶ������洢�������� (ջ���ݡ�temp�����ں�������ʱ�ͷ�)
	return Complex(real++, image++); //ͨ���Զ��幹�캯�� �洢���ص�����
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