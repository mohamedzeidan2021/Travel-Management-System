#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string>	

using namespace std;

void menu();

class ManageMenu
{
protected:
	string userName; //hide admin name

public:
	ManageMenu()
	{
		system("color 0A"); //change terminal color 
		cout << "\n\n\n\n\n\n\n\n\n\t   Enter your Name to continue as an admin: ";
		cin >> userName;
		system("CLS");
		menu();
	}
	~ManageMenu() {}
};

class Customers
{
public:
	string name, gender, address;
	int age;
	long long mobileNo;
	static int customerID;
	char all[999];

	void getDetails()
	{

		ofstream out("old-customers.txt", ios::app);
		{
			cout << "Enter Customer ID: ";
			cin >> customerID;
			cout << "Enter Name: ";
			cin >> name;
			cout << "Enter Age: ";
			cin >> age;
			cout << "Enter Mobile Number: ";
			cin >> mobileNo;
			cout << "Enter Address: ";
			cin >> address;
			cout << "Enter Gender: ";
			cin >> gender;
		}

		out << "\nCustomer ID: " << customerID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " 
			<< mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;

		out.close();
		cout << "\nSaved \nNote: We have saved your record for future purchases\n" << endl;
	}

	void showDetails()
	{
		ifstream in("old-customers.txt");
		{
			if (!in)
			{
				cout << "File Error" << endl;
			}
			while (!(in.eof()))
			{
				in.getline(all, 999);
				cout << all << endl;
			}
			in.close();
		}
	}
};

int Customers::customerID;

class Cabs
{
public:
	int cabChoice;
	int kilometers;
	float cabCost;
	static float lastCabCost;

	void cabDetails()
	{
		cout << "We collaborated with fastest, safest, and smartest cab service around the country" << endl;
		cout << "-------------------------------ABC Cabs------------------------------------------\n" << endl;
		cout << "1. Rent a Standard Cab - $0.49 per mile\n";
		cout << "2. Rent a Luxury Cab - $0.69 per mile\n";

		cout << "\nTo calculate the cost for the journey: " << endl;
		cout << "Enter which kind of cab you need: ";
		cin >> cabChoice;
		cout << "Enter the kilometers you have to travel: ";
		cin >> kilometers;

		int hireCab;

		if (cabChoice == 1)
		{
			cabCost = kilometers * .49;
			cout << "\nYour total tour cost $" << cabCost << " for a Standard Cab\n";
			cout << "Press 1 to hire this cab: \n";
			cout << "Press 2 to select another cab: ";
			cin >> hireCab;

			system("CLS");

			if (hireCab == 1)
			{
				lastCabCost = cabCost;
				cout << "\nYou have successfully hired a Standard Cab\n";
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (hireCab == 2)
			{
				cabDetails();
			}
			else 
			{
				cout << "Invalid Input! Redirecting to previous menu \nPlease Wait..." << endl;
				Sleep(1100);
				system("CLS");
				cabDetails();
			}
		}
		
		else if (cabChoice == 2)
		{
			cabCost = kilometers * .69;
			cout << "\nYour total tour cost $" << cabChoice << "for a Luxury Cab\n";
			cout << "Press 1 to hire this cab: \n";
			cout << "Press 2 to select another cab: ";
			cin >> hireCab;

			system("CLS");

			if (hireCab == 1)
			{
				lastCabCost = cabChoice;
				cout << "\nYou have successfully hired a Luxury Cab\n";
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (hireCab == 2)
			{
				cabDetails();
			}
			else
			{
				cout << "Invalid Input! Redirecting to main menu \nPlease Wait..." << endl;
				Sleep(1100);
				system("CLS");
				menu();
			}

			cout << "\nPress 1 to Redirect main menu: ";
			cin >> hireCab;
			system("CLS");
			if (hireCab == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}
	}
};

float Cabs::lastCabCost;

class Bookings
{
public:
	int choiceHotel;
	int packChoice;
	static float hotelCost;

	void hotels()
	{
		string hotelNo[] = { "Avendra", "ChoiceYou", "ElephantBay" };
		for (int a = 0; a < 3; a++)
			cout << (a + 1) << ". Hotel" << hotelNo[a] << endl;

		cout << "\nCurrently we collaborated with above hotels!" << endl;

		cout << "Press any key to back or\n Enter the hotel number you want to book: ";
		cin >> choiceHotel;

		system("CLS");

		if (choiceHotel == 1) {
			cout << "-----------------Welcome to Hotel Avendra-----------------" << endl;

			cout << "The Garden, food and beverage. Enjoy all you can drink, stay cool, and relax under the summer sun." << endl;

			cout << "Packages offered by Avendra:\n" << endl;

			cout << "1. Standard Pack" << endl;
			cout << "\tAll basic facilities you need just for: $1000.00" << endl;
			cout << "2. Premium Pack" << endl;
			cout << "\tEnjoy Premium: $5000.00" << endl;
			cout << "3. Luxury Pack" << endl;
			cout << "\tLive like a king at Avendra: $20000.00" << endl;

			cout << "\nPress another key to go back or\nEnter the package number you want to book: ";
			cin >> packChoice;



			if (packChoice == 1)
			{
				hotelCost = 1000.00;
				cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (packChoice == 2)
			{
				hotelCost == 5000.00;
				cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
			}
			else if (packChoice == 3)
			{
				hotelCost = 20000.00;
				cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
			}
			else
			{
				cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;

				Sleep(1100);
				system("CLS");
				hotels();
			}
			int gotoMenu;
			cout << "\nPress 1 to redirect main menu: ";
			cin >> gotoMenu;
			if (gotoMenu == 1)
			{
				menu();
			}
			else {
				menu();
			}
		}

		else if (choiceHotel == 2) {
			cout << "-----------------Welcome to Hotel ChoiceYou-----------------" << endl;

			cout << "The pools, spa, and local beaches are all things you must experience in Hotel ChoiceYou." << endl;

			cout << "Packages offered by ChoiceYou:\n" << endl;

			cout << "1. Bronze Pack" << endl;
			cout << "\tAccess to the public pool and one spa visit for: $1499.99" << endl;
			cout << "2. Silve Pack" << endl;
			cout << "\tEnjoy unlimited spa visits and access to all pools: $7999.99" << endl;
			cout << "3. Gold Pack" << endl;
			cout << "\tUnlimited spa and pool visits, a king's suite, and access to the private pool: $26999.99" << endl;

			cout << "\nPress another key to go back or\nEnter the package number you want to book: ";
			cin >> packChoice;



			if (packChoice == 1)
			{
				hotelCost = 1499.99;
				cout << "\nYou have successfully booked the Bronze Pack at ChoiceYou" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else if (packChoice == 2)
			{
				hotelCost == 7999.99;
				cout << "\nYou have successfully booked Silver Pack at ChoiceYou" << endl;
			}
			else if (packChoice == 3)
			{
				hotelCost = 26999.99;
				cout << "\nYou have successfully booked Gold Pack at ChoiceYou" << endl;
			}
			else
			{
				cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;

				Sleep(1100);
				system("CLS");
				hotels();
			}

			int gotoMenu;
			cout << "\nPress 1 to Redirect Main Menu: ";
			cin >> gotoMenu;
		}
		
		else if (choiceHotel == 3)
		{
			cout << "-----------------Welcome to Hotel ElephantBay-----------------" << endl;

			cout << "Set in tropical gardens onthe banks of the Maya Oya river while seeing elephants" << endl;

			cout << "Incredible offer this summer: $3000.00 for one day!\n" << endl;

			cout << "\nPress another key to back or\nPress 1 to book this special package: ";
			cin >> packChoice;

			if (packChoice == 1)
			{
				hotelCost = 3000.00;
				cout << "\nYou have successfully booked the a room at ElephantBay" << endl;
				cout << "Goto Menu and take the receipt" << endl;
			}
			else
			{
				cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;

				Sleep(1100);
				system("CLS");
				hotels();
			}

			int gotoMenu;
			cout << "\nPress 1 to Redirect Main Menu: ";
			cin >> gotoMenu;
			system("CLS");
			if (gotoMenu == 1)
			{
				menu();
			}
			else {
				menu();
			}
		}
		else {
		cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
		Sleep(1100);
		system("CLS");
		menu();
		}
	}
};

float Bookings::hotelCost;

class Charges : public Bookings, Cabs, Customers
{

public:
	void printBill()
	{

		ofstream outf("reciept.txt");
		{
			outf << "----ABC Travel Agency----" << endl;
			outf << "---------Receipt---------" << endl;
			outf << "__________________________" << endl;

			outf << "Customer ID: " << Customers::customerID << endl << endl;
			outf << "Description\t\t Total" << endl;
			outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Bookings::hotelCost << endl;
			outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

			outf << "__________________________" << endl;
			outf << "Total Charge:\t\t " << fixed << setprecision(2) << Bookings::hotelCost + Cabs::lastCabCost << endl;
			outf << "__________________________" << endl;
			outf << "--------Thank you---------" << endl;

		}
		outf.close();
	}

	void showBill()
	{
		ifstream inf("receipt.txt");
		{
			if (!inf)
			{
				cout << "File Error!" << endl;
			}

			while (!(inf.eof()))
			{
				inf.getline(all, 999);
				cout << all << endl;
			}
		}
		inf.close();
	}
};

void menu()
{
	int mainChoice;
	int inChoice;
	int gotoMenu;


	cout << "\t\t     * ABC Travels *\n" << endl;
	cout << "------------------------Main Menu------------------------" << endl;
	cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
	cout << "\t|\t\t\t\t\t|" << endl;
	cout << "\t|\tCustomer Management      -> 1\t|" << endl;
	cout << "\t|\tCabs Management          -> 2\t|" << endl;
	cout << "\t|\tBookings Management      -> 3\t|" << endl;
	cout << "\t|\tCharges & Bill           -> 4\t|" << endl;
	cout << "\t|\tExit                     -> 5\t|" << endl;
	cout << "\t|\t\t\t\t\t|" << endl;
	cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

	cout << "\nEnter your choice: ";
	cin >> mainChoice;

	system("CLS");

	Customers a2;
	Cabs a3;
	Bookings a4;
	Charges a5;

	if (mainChoice == 1)
	{
		cout << "------Customers------\n" << endl;
		cout << "1. Enter New Customer" << endl;
		cout << "2. See Old Customers" << endl;

		cout << "\nEnter Choice: ";
		cin >> inChoice;
		system("CLS");
		if (inChoice == 1) {
			a2.getDetails();
		}
		else if (inChoice == 2)
		{
			a2.showDetails();
		}
		else
		{
			cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
			Sleep(1100);
			system("CLS");
			menu();
		}

		cout << "\nPress 1 to Redirect main menu: ";
		cin >> gotoMenu;
		system("CLS");
		if (gotoMenu == 1)
		{
			menu();
		}
		else
		{
			menu();
		}
	}

	else if (mainChoice == 2) {
		a3.cabDetails();
	}

	else if (mainChoice == 3) {
		cout << "--> Book a luxury hotel using the system <--" << endl;
		a4.hotels();
	}
	else if (mainChoice == 4) {
		cout << "-->Get your receipt <--" << endl;
		a5.printBill();

		cout << "Your receipt has already printed, you can get it from file path,\n" << endl;
		cout << "To display your receipt on the screen, enter 1, or enter another key to go back to main menu: ";

		cin >> gotoMenu;

		if (gotoMenu == 1) {
			system("CLS");
			a5.showBill();
			cout << "\nPress 1 to redirect main menu: ";
			cin >> gotoMenu;
			system("CLS");
			if (gotoMenu == 1)
			{
				menu();
			}
			else {
				menu();
			}
		}
		else {
			system("CLS");
			menu();
		}
	}

	else if (mainChoice == 5)
	{
		cout << "--GOOD-BYE--" << endl;
		Sleep(999);
		system("CLS");
		menu();
	}
	else {
		cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
		Sleep(1100);
		system("CLS");
		menu();
	}
}

int main()
{
	ManageMenu startObj;


	return 0;
}