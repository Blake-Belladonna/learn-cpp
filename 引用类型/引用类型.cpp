// 引用类型.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <assert.h>

using namespace std;

void swap(short&, short&);

int main()
{
    int iA = 2;
    const int cIB = 8;
    int& rIA = iA;//rIA不会再开辟新的内存空间，实质上rIA就是iA，内存地址相同
    cout << "iA = " << iA << endl;
    cout << "rIA = " << rIA << endl;
    rIA = cIB;//这里只是将cIB所表示的整形变量赋值给rIA内存空间，故rIA = cIB = iA，而非rIA = cIB != iA
    cout << "iA = " << iA << endl;
    cout << "rIA = " << rIA << endl;

    cout << endl;

    short hA = 16, hB = 32;
    cout << "hA = " << hA << endl;
    cout << "hB = " << hB << endl;
    swap(hA, hB);
    assert(hA == 32 && hB == 16);
    cout << "hA = " << hA << endl;
    cout << "hB = " << hB << endl;

    std::cout << "Hello World!\n";
}

void swap(short& inHA, short& inHB)//也可以使用指针数据类型 来代替引用，但是会开辟额外的内存空间
{
    //short temp = hA;
    //hA = hB;
    //hB = temp;

    inHA += inHB;
    inHB = inHA - inHB;
    inHA -= inHB;
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