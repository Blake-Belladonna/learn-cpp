// 指针基本操作(一).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int main()
{
	int iArray[][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int(*iP)[4][4] = &iArray;
	int(*iP2)[4] = &iArray[0];
	int* iP3 = iArray[0];

	size_t row = sizeof(iArray) / sizeof(iArray[0]);
	size_t col = sizeof(iArray[0]) / sizeof(iArray[0][0]);
	for (size_t i = 0; i < col; i++)
	{
		cout << "*(iP3+" << i << "):" << *(iP3 + i) << endl;
	}

	cout << endl;
	iP2 += 1;

	for (size_t i = 0; i < col; i++)
	{
		cout << "*(iP4+" << i << "):" << *((*iP2) + i) << endl;
	}

	cout << endl;

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << "*(iP2+" << i << "," << j << "):" << (*iP)[i][j] << endl;
		}
	}

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
