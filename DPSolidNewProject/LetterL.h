#pragma once
class Rectangle
{
protected:
	int width, height;
public:
	virtual int GetWidth() { return width; }
	virtual void SetWidth(int value) { width = value; }
	
	virtual int GetHeight() { return height; }
	virtual void SetHeight(int value) { height = value; }

	int Area() { return width * height; }
};

class Square : public Rectangle
{
public:
	int GetWidth() override { return Rectangle::GetWidth(); }
	void SetWidth(int value) override
	{
		width = value;
		height = value;
	}

	int GetHeight() override { return Rectangle::GetHeight(); }
	void SetHeight(int value) override
	{
		width = value;
		height = value;
	}

};

