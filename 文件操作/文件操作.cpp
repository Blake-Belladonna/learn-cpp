// 文件操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

#define READ_BUFFER_SIZE 1024 * 4

int textToFile(const std::string path, const std::string content);
int fileToText(const std::string path, std::string& content);
int copyFile(const std::string src, const std::string dest, const bool isBinary);

int main()
{
	std::cout << "请键入内容（按下回车键后将会写入文件）：" << std::endl;
	char contentIn[128] = {};
	std::cin.getline(contentIn, sizeof(contentIn));
	textToFile("data.txt", contentIn);

	std::string contentOut = "";

	fileToText("data.txt", contentOut);

	std::cout << "contentOut:" << contentOut << std::endl;

	copyFile("C:/Users/13782/Desktop/d.mp4", "C:/Users/13782/Desktop/d2.mp4", true);

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

int textToFile(const std::string path, const std::string content)
{
	if (path.size() == 0)
	{
		std::cout << "path is empty in 'dataToFile' function." << std::endl;
		return 1;
	}

	std::ofstream ofs;
	ofs.open(path, std::ios::out | std::ios::trunc);
	if (!ofs)
	{
		std::cout << "failed to open the '" << path << "' file." << std::endl;
		return 3;
	}


	ofs.write(content.c_str(), content.size());

	//ofs << content;

	ofs.close();

	return 0;
}

int fileToText(const std::string path, std::string& content)
{
	if (path.size() == 0)
	{
		std::cout << "path is empty in 'dataToFile' function." << std::endl;
		return 1;
	}

	std::ifstream ifs;
	ifs.open(path, std::ios::in);

	if (!ifs)
	{
		std::cout << "failed to open the '" << path << "' file." << std::endl;
		return 2;
	}

	char readBuffer[1024] = {};

	ifs.seekg(0, std::ios::end);
	long long contentLength = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	ifs.read(readBuffer, contentLength);

	//ifs >> std::noskipws >> content;
	content = std::string(readBuffer);

	ifs.close();

	return 0;
}

int copyFile(const std::string source, const std::string destination, const bool isBinary)
{
	if (source.size() == 0 || destination.size() == 0)
	{
		std::cout << "in-parameter 'source' or 'destination' is empty in 'copyFile' function." << std::endl;
		return 1;
	}

	std::ifstream ifs;
	std::ofstream ofs;

	ifs.open(source, isBinary ? std::ios::in | std::ios::binary : std::ios::in);
	ofs.open(destination, isBinary ? std::ios::out | std::ios::binary | std::ios::trunc : std::ios::out | std::ios::trunc);

	if (!ifs || !ofs)
	{
		std::cout << "failed to open file!" << std::endl << "[source:" << source << ";destination:" << destination << "]" << std::endl;
		return 2;
	}

	char readBuffer[READ_BUFFER_SIZE] = {};

	ifs.seekg(0, std::ios::end);
	long long fileSize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	long long cruuectReadCount = 0;

	while (!ifs.eof())
	{
		ifs.read(readBuffer, READ_BUFFER_SIZE);

		long long realCount = ifs.gcount(); //获取实际的读取长度

		ofs.write(readBuffer, realCount);

		cruuectReadCount += realCount;

		std::cout << "copying: " << (double)cruuectReadCount / (double)fileSize * 100.0 << "%" << std::endl;
	}

	ifs.close();
	ofs.close();

	return 0;
}