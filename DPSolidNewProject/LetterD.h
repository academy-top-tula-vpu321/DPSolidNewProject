#pragma once
#include <iostream>
#include <vector>

class ISort
{
public:
	virtual void Sort(std::vector<int>&) = 0;
};

class SortBubble : public ISort
{
public:
	void Sort(std::vector<int>& v) override
	{
		for (int i{}; i < v.size(); i++)
		{
			for (int j = v.size() - 1; j > i; j--)
				if (v[j] < v[j - 1])
					std::swap(v[j], v[j - 1]);
		}
	}
};

class SortSelect : public ISort
{
public:
	void Sort(std::vector<int>& v) override
	{
		for (int i{}; i < v.size(); i++)
		{
			int min{ i };
			for (int j{}; j < v.size(); j++)
				if (v[min] > v[j])
					std::swap(v[min], v[j]);
		}
	}
};

class Vector : public std::vector<int>
{
	ISort* sort;
public:
	void SetSort(ISort* sort)
	{
		this->sort = sort;
	}

	void Sort()
	{
		sort->Sort(*this);
	}

	friend std::ostream& operator<<(std::ostream& out, Vector v)
	{
		for (int i{}; i < v.size(); i++)
			out << v[i] << " ";
		out << "\n";
		return out;
	}
};

