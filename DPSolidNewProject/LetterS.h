//// S - Single Responsibility Principle
//// ѕринцип единственной отвественности
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <exception>
//#include <fstream>
//
//class IPhoneReader
//{
//	std::vector<std::string> data;
//
//public:
//	virtual std::vector<std::string>& GetData() = 0;
//};
//
//class ConsolePhoneReader : public IPhoneReader
//{
//public:
//	std::vector<std::string>& GetData() override
//	{
//		std::vector<std::string> data;
//		std::string model;
//		std::string price;
//
//		std::cout << "Input model name: ";
//		std::cin >> model;
//		std::cout << "Input price: ";
//		std::cin >> price;
//		data.push_back(model);
//		data.push_back(price);
//	}
//};
//
//class IPhoneBinder
//{
//public:
//	virtual Phone* CreatePhone(std::vector<std::string> data) = 0;
//};
//
//class GeneralPhoneBinder : public IPhoneBinder
//{
//public:
//	Phone* CreatePhone(std::vector<std::string> data) override
//	{
//		if (data.size() == 2)
//		{
//			try
//			{
//				int price = std::stoi(data[1]);
//				Phone* phone = new Phone(data[0], price);
//				return phone;
//			}
//			catch (std::exception e)
//			{
//				std::cout << e.what() << "\n";
//			}
//		}
//		return nullptr;
//	}
//};
//
//class IPhoneSaver
//{
//public:
//	virtual void Save(Phone* phone, std::string fileName) = 0;
//};
//
//class TxtFilePhoneSaver : public IPhoneSaver
//{
//public:
//	void Save(Phone* phone, std::string fileName) override
//	{
//		std::ofstream file(fileName, std::ios::binary | std::ios::app);
//		file << phone;
//		file.close();
//	}
//};
//
//
//
//
//	// class bad
///*
//class Report
//{
//	std::string text;
//public:
//	std::string& Text() { return text; }
//
//	void GoToFirstPage()
//	{
//		std::cout << "Go to first page of report\n";
//	}
//
//	void GoToLastPage()
//	{
//		std::cout << "Go to last page of report\n";
//	}
//
//	void GoToPage(int number)
//	{
//		std::cout << "Go to " << number << " page of report\n";
//	}
//
//	void Print()
//	{
//		std::cout << "Report:\n";
//		std::cout << text << "\n";
//	}
//};
//*/
//
//// class good
//class Report
//{
//	std::string text;
//public:
//	std::string& Text() { return text; }
//
//	void GoToFirstPage()
//	{
//		std::cout << "Go to first page of report\n";
//	}
//
//	void GoToLastPage()
//	{
//		std::cout << "Go to last page of report\n";
//	}
//
//	void GoToPage(int number)
//	{
//		std::cout << "Go to " << number << " page of report\n";
//	}
//};
//
//class OutReport
//{
//public:
//	void OutConsole(Report* report)
//	{
//		std::cout << "Report:\n";
//		std::cout << report->Text() << "\n";
//	}
//	void OutEmail(Report* report, std::string email)
//	{
//		std::cout << "Send email to " << email << "\n";
//		std::cout << "Report:\n";
//		std::cout << report->Text() << "\n";
//	}
//};
//
//
//
//
///// <summary>
/////
///// </summary>
//class Phone
//{
//	std::string model;
//	int price;
//public:
//	std::string& Model() { return model; }
//	int& Price() { return price; }
//	Phone(std::string model, int price)
//		: model{ model }, price{ price } {}
//};
//
//// bad mega (monstr) class
//class PhoneStore
//{
//	std::vector<Phone*> phones;
//
//	IPhoneReader* reader;
//	IPhoneBinder* binder;
//	IPhoneSaver* saver;
//
//public:
//	IPhoneReader*& Reader() { return reader; }
//	IPhoneBinder*& Binder() { return binder; }
//	IPhoneSaver*& Saver() { return saver; }
//
//	PhoneStore(IPhoneReader* reader, IPhoneBinder* binder, IPhoneSaver* saver)
//		: reader{ reader }, binder{ binder }, saver{ saver } {};
//
//	void Process()
//	{
//		std::vector<std::string> data{ reader->GetData() };
//		Phone* phone = binder->CreatePhone(data);
//		phones.push_back(phone);
//		saver->Save(phone, "phones.dat");
//	}
//
//	// bad method
////public:
//	//void Process()
//	//{
//	//	// input data
//	//	std::string model;
//	//	std::string price;
//	//	std::cout << "Input model name: ";
//	//	std::cin >> model;
//	//	std::cout << "Input price: ";
//	//	std::cin >> price;
//	//	// validate data
//	//	int p;
//	//	try
//	//	{
//	//		p = std::stoi(price);
//	//		Phone* phone = new Phone(model, p);
//	//		// save data
//	//		std::ofstream file("phones.dat", std::ios::binary);
//	//		file << phone;
//	//		file.close();
//	//	}
//	//	catch (std::exception e)
//	//	{
//	//		std::cout << e.what();
//	//	}
//	//}
//
//};
//
//
