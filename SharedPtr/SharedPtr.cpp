// SharedPtr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> iSP1 = shared_ptr<int>(new int(16));
	{
		shared_ptr<int> iSP2 = nullptr;
		iSP2 = iSP1; //不会剥夺iSP1的使用权
		cout << "*iSP1 = " << (iSP1 != nullptr ? *iSP1 : -1) << endl;
		cout << "*iSP2 = " << (iSP2 != nullptr ? *iSP2 : -1) << endl;
		cout << "iSP1.use_count() = " << iSP1.use_count() << endl;//获取指针所指对象被引用的个数
		cout << "iSP2.use_count() = " << iSP2.use_count() << endl;
	}

	cout << "*iSP1 = " << (iSP1 != nullptr ? *iSP1 : -1) << endl; //因为引用数不等于0(2-1>0)，所以不会释放iSP1所指内存
	cout << "iSP1.use_count = " << iSP1.use_count() << endl;

	shared_ptr<int> iSP3 = make_shared<int>(32);//与shared_ptr<int>(new int(32));同效
	shared_ptr<int> iSP4 = nullptr;
	cout << "iSP3.get() = " << iSP3.get() << endl;
	cout << "iSP4.get() = " << iSP4.get() << endl;
	iSP4 = move(iSP3); //使用std::move转让引用所有权，之后iSP3将会被置为null
	cout << "iSP3.get() = " << iSP3.get() << endl;
	cout << "iSP4.get() = " << iSP4.get() << endl;

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
