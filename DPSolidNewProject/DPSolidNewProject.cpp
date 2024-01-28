#include <iostream>
#include "LetterS.h"
#include "LetterO.h"
#include "LetterL.h"
#include "LetterD.h"

void SPrincipleExample(); 
void PPrincipleExample();
void LPrincilpleExample();



int main()
{
	srand(time(nullptr));

	int size = 10;
	Vector v;
	for (int i{}; i < size; i++)
		v.push_back(rand() % 100);
	std::cout << v;

	v.SetSort(new SortSelect());
	v.Sort();

	std::cout << v;
}

void SPrincipleExample()
{
	/*Report* report = new Report();
	report->Text() = "Hello world";

	OutReport outer;
	outer.OutConsole(report);
	std::cout << "\n";
	outer.OutEmail(report, "user@mail.ru");

	PhoneStore store(new ConsolePhoneReader(), new GeneralPhoneBinder(), new TxtFilePhoneSaver());
	store.Process();*/
}

void PPrincipleExample()
{
	MyString str("Hello");
	std::cout << str.length() << " " << str.CharCount('l');
}


void TestRectangle(Rectangle* rect)
{
	rect->SetWidth(5);
	rect->SetHeight(10);
	if (rect->Area() != 50)
		std::cout << "Error!\n";
	else
		std::cout << "All right!\n";
}
void LPrincilpleExample()
{
	TestRectangle(new Square());
}