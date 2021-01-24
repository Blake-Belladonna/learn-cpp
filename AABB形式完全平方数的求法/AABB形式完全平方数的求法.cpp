// AABB形式完全平方数的求法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>

using namespace std;

void function_01();// 正向求解
void function_02();// 逆向求解

int main()
{
	function_01();
	function_02();

	std::cout << "Hello World!\n";
}

void function_01()
{
	unsigned int n = 0;
	for (unsigned int i = 1; i < 10; i++)
	{
		for (unsigned int j = 0; j < 10; j++)
		{
			n = i * 1100 + j * 11;
			double sqrtRet = sqrt(n);
			sqrtRet -= int(sqrtRet);
			if (sqrtRet < 0.00000001) //判断平方根结果是否为整数（不推荐）
			{
				cout << "找到AABB类型完全平方数：" << n << endl;
			}
		}
	}
}

void function_02()
{
	unsigned int n = 0, high = 0, low = 0;
	for (unsigned int i = 31; i < 100; i++)
	{
		n = i * i;
		high = n / 100;
		low = n % 100;
		if ((high / 10 == high % 10) && (low / 10 == low % 10))
		{
			cout << "找到AABB类型完全平方数：" << n << endl;
		}
	}
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
