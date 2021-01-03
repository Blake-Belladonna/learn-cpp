// String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    string str2 = "Hello world!";
    string str3("Hello");
    string str4 = string("world");

    cout << "length:" << str2.length() << endl;
    cout << "size:" << str2.size() << endl;
    cout << "capacity:" << str2.capacity() << endl;

    cout << (str3 == str4) << endl;
    cout << (str3 != str4) << endl;

    const char* cStr = str2.c_str();
    cout << cStr << endl;

    for (int i = 0; i < strlen(cStr); i++)
    {
        cout << cStr[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < str2.size(); i++)
    {
        cout << str2[i] << " ";
    }

    cout << endl;

    str2 = str3 + str4;

    str4 = str3 = str2;

    cout << "str2:" << str2 << endl;
    cout << "str3:" << str3 << endl;
    cout << "str4:" << str4 << endl;

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
