#pragma once
#include <iostream>

class MyString : public std::string
{
	// str;
public:
	MyString(std::string str) : std::string(str){}
	
	int CharCount(char symbol)
	{
		int count{};
		for (char c : *this)
			if (c == symbol)
				count++;
		return count;
	}
};

