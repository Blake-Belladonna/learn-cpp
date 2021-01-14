// 结构体和联合体.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

union GPA
{
	double score;//存放地址是8的整数倍
	unsigned char level;//存放地址无强制要求
};

struct StudentA
{
	//存在最大尺寸变量类型double，以8字节内存对齐
	unsigned int id;//内存对齐 4 + 4
	char name[6]; // 内存对齐 6
	//存放地址是偶数倍
	unsigned short age;//内存对齐 2
	GPA gpa; //内存对齐 8
};

struct StudentB
{
	//存在最大尺寸变量类型double，以8字节内存对齐
	unsigned int id;//内存对齐 4 + 4
	char name[6];//内存对齐 6 + 2
	GPA gpa;//内存对齐 8
	unsigned short age;//内存对齐 2 + 6
};

int main()
{
	StudentA studentA = {};
	studentA.id = 001;
	strcpy_s(studentA.name, "Cowen");
	studentA.age = 18;
	studentA.gpa.score = 100;
	studentA.gpa.level = 'A';

	StudentB studentB = {};
	studentB.id = 013;
	strcpy_s(studentB.name, "Alex");
	studentB.gpa.score = 85;
	studentB.gpa.level = 'B';
	studentB.age = 16;

	//内存占用大小（字节）
	cout << "(4 + 4) + (6 + 2) + 8 = " << sizeof(StudentA) << endl;
	cout << "(4 + 4) + (6 + 2) + 8 + (2 + 6)= " << sizeof(StudentB) << endl;

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
