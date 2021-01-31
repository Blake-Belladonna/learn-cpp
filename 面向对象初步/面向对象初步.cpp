// 面向对象初步.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Complex.h"

#include <iostream>

using namespace std;

int main()
{
	//自定义构造
	Complex complex(2.0f, 3.0f);

	complex.SetReal(5.0f);
	complex.SetImage(7.0f);
	
	cout << "complex.GetReal() = " << complex.GetReal() << endl;
	cout << "complex.GetImage() = " << complex.GetImage() << endl;

	//自定义构造
	Complex complex2(3.0f, 5.0f);

	//操作符重载(+)中使用的是自定义构造，也就是complex3的构造方式
	Complex complex3 = complex + complex2;

	//拷贝构造
	Complex complex4(complex3);
	Complex complex5 = complex4;

	//默认构造
	Complex complex6;
	complex6 = ++complex6;//对已构造过的对象直接饮用赋值
	Complex complex7 = complex6++;
	Complex complex8 = ++complex6;//对未构造过得对象使用拷贝构造赋值

	cout << "complex6:" << complex6 << endl;
	cout << "wait for input:";
	cin >> complex6;
	cout << "complex6:" << complex6 << endl;

	Complex complex9 = complex6;
	cout << "(complex6 == complex9) = " << (complex6 == complex9) << endl;

	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
