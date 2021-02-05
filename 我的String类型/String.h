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
			delete[] mData;//ɾ����������
			size_t len = iStr.mSize;
			mData = new char[len + 1]; //Ԥ���ַ����������洢�ռ�
			strcpy_s(mData, len + 1, iStr.mData); //��ȿ���Ŀ���ַ�������
			mSize = iStr.mSize;//�����ַ�������
		}

		return *this;
	}

	String& operator=(String&& iStr) noexcept
	{
		if (this != &iStr)
		{
			delete[] mData;
			mData = iStr.mData; //����ǳ����Ŀ���ַ���
			mSize = iStr.mSize;
			iStr.mData = NULL; //�ж�ԭ���ַ������ã��������ڴ�����
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

