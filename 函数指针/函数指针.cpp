// 函数指针.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int max(int, int);
int min(int, int);
int add(int, int);
int process(int, int, int(*)(int, int));

int main()
{
	int(*functionPointer)(int, int);
	functionPointer = add;
	//(*function) 和 function 的地址值一致，所以以下两种调用方式都可以
	cout << "function() = " << functionPointer(2, 8) << endl;
	cout << "function() = " << (*functionPointer)(2, 8) << endl;

	int a = 3, b = 5;
	cout << "process(a, b, max) = " << process(a, b, max) << endl;
	cout << "process(a, b, min) = " << process(a, b, min) << endl;
	cout << "process(a, b, add) = " << process(a, b, add) << endl;

	std::cout << "Hello World!\n";
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int add(int a, int b)
{
	return a + b;
}

int process(int a, int b, int(*p)(int, int))
{
	return p(a, b);
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
