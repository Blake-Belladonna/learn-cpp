// SharedPtr循环引用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>

using namespace std;

struct GoodGirl_Abbey;
struct GoodGirl_Madonna;

struct GoodBoy
{
	shared_ptr<GoodGirl_Abbey> lover = nullptr;

	~GoodBoy()
	{
		cout << "GoodBoy: byebye(T.T)" << endl;
	}
};

struct BadBoy
{
	weak_ptr<GoodGirl_Madonna> lover = {};

	~BadBoy()
	{
		cout << "BadBoy: byebye(^.^)" << endl;
	}
};

struct GoodGirl_Abbey
{
	shared_ptr<GoodBoy> lover = nullptr;

	~GoodGirl_Abbey()
	{
		cout << "GoodGirl_Abbey: byebye(T.T)" << endl;
	}
};

struct GoodGirl_Madonna
{
	shared_ptr<BadBoy> lover = nullptr;

	~GoodGirl_Madonna()
	{
		cout << "GoodGirl_Madonna: byebye(T.T)" << endl;
	}
};

void loveTest(bool inGoodBoy)
{
	if (inGoodBoy)
	{
		shared_ptr<GoodBoy> goodBoy = make_shared<GoodBoy>();
		shared_ptr<GoodGirl_Abbey> goodGirlAbbey = make_shared<GoodGirl_Abbey>();
		cout << "goodBoy.use_count() = " << goodBoy.use_count() << endl;//1
		cout << "goodGirlAbbey.use_count() = " << goodGirlAbbey.use_count() << endl;//1
		goodBoy->lover = goodGirlAbbey;
		goodGirlAbbey->lover = goodBoy;
		cout << "goodBoy.use_count() = " << goodBoy.use_count() << endl;//2
		cout << "goodGirlAbbey.use_count() = " << goodGirlAbbey.use_count() << endl;//2
	}
	else
	{
		shared_ptr<BadBoy> bedBoy = make_shared<BadBoy>();
		shared_ptr<GoodGirl_Madonna> goodGirl_Madonna = make_shared<GoodGirl_Madonna>();
		cout << "bedBoy.use_count() = " << bedBoy.use_count() << endl;//1
		cout << "goodGirl_Madonna.use_count() = " << goodGirl_Madonna.use_count() << endl;//1
		bedBoy->lover = goodGirl_Madonna;
		goodGirl_Madonna->lover = bedBoy;
		cout << "bedBoy.use_count() = " << bedBoy.use_count() << endl;//2
		cout << "bedBoy->lover.use_count() = " << bedBoy->lover.use_count() << endl;//1
		cout << "goodGirl_Madonna.use_count() = " << goodGirl_Madonna.use_count() << endl;//1
	}
}

int main()
{
	loveTest(false);
	cout << endl;
	loveTest(true);

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
