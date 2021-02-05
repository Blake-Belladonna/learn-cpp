#include "String.h"

String::String(const char* iCstr)
{
	if (iCstr == NULL)
	{
		mData = new char[1];
		*mData = '\0';
		mSize = 0;
	}
	else
	{
		size_t len = strlen(iCstr);
		mData = new char[len + 1];
		strcpy_s(mData, len + 1, iCstr);
		mSize = len;
	}
}

String::String(const String& iStr)
{
	size_t len = iStr.mSize;
	mData = new char[len + 1];
	strcpy_s(mData, len + 1, iStr.mData);
	mSize = len;
}

String::String(String&& iStr) noexcept
{
	size_t len = iStr.mSize;
	mData = new char[len + 1];
	strcpy_s(mData, len + 1, iStr.mData);
	mSize = len;
	iStr.mData = NULL;
	iStr.mSize = 0;
}

String::~String() 
{
	if (mData != NULL)
	{
		delete[] mData;
		mData = NULL;
	}

	mSize = 0;
}

std::ostream& operator<<(std::ostream& oStream, const String& iStr) 
{
	oStream << iStr.mData;
	return oStream;
}

std::istream& operator>>(std::istream& iIstream, String& iStr) 
{
	iIstream >> iStr.mData;
	return iIstream;
}

