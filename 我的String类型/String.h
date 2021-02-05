#pragma once

#include <iostream>

class String
{
public:
	String(const char* cStr = NULL);
	String(const String& iStr);
	String(String&& iStr) noexcept;
	virtual ~String();

	inline size_t Size() const
	{
		return mSize;
	}

	inline String& operator=(const String& iStr)
	{
		if (this != &iStr)
		{
			delete[] mData;//删除自身数据
			size_t len = iStr.mSize;
			mData = new char[len + 1]; //预留字符串结束符存储空间
			strcpy_s(mData, len + 1, iStr.mData); //深度拷贝目标字符串内容
			mSize = iStr.mSize;//更新字符串长度
		}

		return *this;
	}

	String& operator=(String&& iStr) noexcept
	{
		if (this != &iStr)
		{
			delete[] mData;
			mData = iStr.mData; //这里浅拷贝目标字符串
			mSize = iStr.mSize;
			iStr.mData = NULL; //切断原有字符串引用，但保留内存数据
			iStr.mSize = 0;
		}

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& iOstream, const String& iStr);
	friend std::istream& operator>>(std::istream& iIstream, String& iStr);

private:
	char* mData = NULL;
	size_t mSize = 0;
};

