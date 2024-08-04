#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<algorithm>

using namespace std;
ifstream fin;
ofstream fout;

void display();
void loading();
string admin_id[2] = { "zadif","ammar" };
string admin_password[2] = { "123","123" };

//Initializing rent of a customer zero and then it is futher used as each rent of a car is added in it you can say that it is final rent 
int sum_of_rent = 0;
int car_serial;
int car_number;//The number of car which user want to rent
int return_car_number;
int index_of_customer;//It stores customer index so that we can store it's data respectively
int rentedstructindex;
int index_of_admin;//It stores admin index so that we can store it's data respectively
int car_store_index1 = 0;//Index which stores rent of car in array assigned in stucture of customer
int car_store_index2 = 0;//Index which stores name of rented car in array assigned in stucture of customer
int car_store_index3 = 0;//Index which stores total hours to rent a car. In array assigned in stucture of customer
int car_store_index4 = 0;//index whixh stores rented hours
int total_rented = 0;//sum of all times a car got rented

struct customer
{
	string customer_name;
	string customer_password;
	string phone_no;
	string id_no;
	string house_no;
	int cus_size = 0;//It control below loops


};
struct customer customerdata[3];
struct customer* dataofcustomer;
struct customer* ptr;
struct customer* ptr2;
struct customer* customers;
static int customer_no = 0;
struct customer* add_costumer(struct customer* dataofcustomer)
{
	if (customer_no == 0)
	{
		dataofcustomer = new struct customer[1];
	}
	if (customer_no > 0)
	{
		ptr = new struct customer[customer_no];
		copy(dataofcustomer, dataofcustomer + customer_no, ptr);
		delete[] dataofcustomer;
		dataofcustomer = new struct customer[customer_no + 1];
		copy(ptr, ptr + customer_no, dataofcustomer);
		delete[] ptr;
	}

	cout << "\n\n\t\t\t\t\tEnter name of customer: ";
	cin.ignore();
	getline(cin, dataofcustomer[customer_no].customer_name);
	cout << "\n\n\t\t\t\t\tEnter password of customer: ";
	getline(cin, dataofcustomer[customer_no].customer_password);
	cout << "\n\n\t\t\t\t\tEnter Phone no of customer: ";
	getline(cin, dataofcustomer[customer_no].phone_no);
	cout << "\n\n\t\t\t\t\tEnter Id no of customer: ";
	getline(cin, dataofcustomer[customer_no].id_no);
	cout << "\n\n\t\t\t\t\tEnter house no of customer: ";

	getline(cin, dataofcustomer[customer_no].house_no);


	loading();
	display();
	cout << "\t\t\t\t\t\tEntered data\n";
	cout << "\n\n\t\t\t\t\tName of customer is " << dataofcustomer[customer_no].customer_name;
	cout << "\n\n\t\t\t\t\tPassword of this customer is " << dataofcustomer[customer_no].customer_password;
	cout << "\n\n\t\t\t\t\tPhone no of this customer is " << dataofcustomer[customer_no].phone_no;
	cout << "\n\n\t\t\t\t\tId no of this customer is " << dataofcustomer[customer_no].id_no;
	cout << "\n\n\t\t\t\t\tHouse no of this customer is " << dataofcustomer[customer_no].house_no;
	Sleep(2000);
	customer_no++;
	return dataofcustomer;
}
struct customer* remove_customer(struct customer* ptr)
{
	cout << "\n\t\t\t\t\tCostumers are: \n\n";
	for (int i = 0; i < customer_no; i++)
	{
		cout << "\t\t\t\t\t";
		cout << i + 1 << ". " << ptr[i].customer_name << endl;
	}

	cout << "\n\n\t\t\t\t\tEnter name of customer you want to remove: ";
	string name;
	cin.ignore();
	getline(cin, name);
	int index = -1;
	for (int i = 0; i < customer_no; i++)
	{
		if (name == ptr[i].customer_name)
		{
			index = i;
			break;
		}

	}
	if (index != -1)
	{

		for (int i = index; i < customer_no - 1; i++)
		{
			ptr[i] = ptr[i + 1];
		}
		--customer_no;
	}
	else
	{
		cout << "\n \n\t\t\t\t\tNot found";
		Sleep(1000);
		return ptr;
	}
	cout << "\n\n\t\t\t\t\tCustomer removed";
	ptr2 = new struct customer[customer_no];
	copy(ptr, ptr + customer_no, ptr2);
	delete[] ptr;
	Sleep(500);
	return ptr2;
}
struct customer* update_customerdata(struct customer* ptr)
{
	cout << "\n\t\t\t\t\tCostumers are: \n";
	for (int i = 0; i < customer_no; i++)
	{
		cout << "\t\t\t\t\t";
		cout << i + 1 << ". " << ptr[i].customer_name << endl;
	}
	cout << "\n\n\t\t\t\t\tIndex of costumer which you data want to update: ";

	int index;
	cin >> index;
	--index;
	if (index >= 0 && index < customer_no)
	{
		display();
		cout << "\n\t\t\t\t\tWhat you want to update?";
		cout << "\n\t\t\t\t\t1.Name\n\t\t\t\t\t2.Password\n\t\t\t\t\t3.Phone no\n\t\t\t\t\t4.Id no\n\t\t\t\t\t5.House no";
		cout << "\nYour choice: ";
		int choose, num;
		cin >> choose;
		switch (choose)
		{
		case 1:cout << "\n\t\t\t\t\tEnter new name: ";
			cin.ignore();
			getline(cin, ptr[index].customer_name); break;
		case 2:
			cout << "\n\t\t\t\t\tEnter new password: ";
			cin.ignore();
			getline(cin, ptr[index].customer_password); break;

		case 3:
			cout << "\n\t\t\t\t\tEnter Phone number: ";
			cin.ignore();
			getline(cin, dataofcustomer[customer_no].phone_no);
		case 4:
			cout << "\n\t\t\t\t\tEnter Id no number: ";
			cin.ignore();
			getline(cin, dataofcustomer[customer_no].id_no);

		case 5:
			cout << "\n\t\t\t\t\tEnter House no: ";
			cin.ignore();
			getline(cin, ptr[index].house_no); break;

		}

		cout << "\n\n\t\t\t\t\tData is successfully updated";
		Sleep(2000);
	}
	else
	{
		cout << "\n\n\t\t\t\t\tInvalid input";
		cout << "\n\n\t\t\t\t\tAgain enter index";
		Sleep(500);
		display();
		update_customerdata(ptr);
		return ptr;

	}
	return ptr;
}
void writetocustomerfile(struct customer* ptr, const string& filename)
{

	fout.open(filename);
	if (!fout) {
		cout << "\nCustomer file not opened for writng\n"; Sleep(500);
		return;
	}

	//Writing
	for (int i = 0; i < customer_no; i++)
	{
		fout << ptr[i].customer_name << endl;
		fout << ptr[i].customer_password << endl;
		fout << ptr[i].phone_no << endl;
		fout << ptr[i].id_no << endl;
		fout << ptr[i].house_no << endl;

		//ya spaces is lia chori hain ta ka baad main pointers ki mdad sa data daal lon 

	}
	fout.close();
}
void readfromcustomerfile(struct customer* ptr, const string& filename)
{

	fin.open(filename);
	if (!fin) {
		cout << "\nCustomer file not opened for reading\n"; Sleep(500);
		return;
	}
	for (int i = 0; i < customer_no; i++)
	{
		getline(fin, ptr[i].customer_name);
		getline(fin, ptr[i].customer_password);
		getline(fin, ptr[i].phone_no);
		getline(fin, ptr[i].id_no);
		getline(fin, ptr[i].house_no);

		//amendments
	}
	fin.close();
}

struct cars
{
	string serial;
	string car_name;
	string car_color;
	string car_speed;
	int car_rent;
	string no_plate;
	bool status;
	int times_rented; //jitni bar rent hoi
	int times_repaired;
	int distance_covered; //customer na jo fasla cover kia
	int money; //munafa
};
struct cars carsdata[6];
static int car_no = 0;
struct cars* car;
struct cars* dataofcar;
struct cars* car_ptr;
struct cars* car_ptr2;
struct cars* add_car(struct cars* dataofcar)
{
	if (car_no == 0)
	{
		dataofcar = new struct cars[1];
	}

	if (car_no > 0)
	{
		car_ptr = new struct cars[car_no];
		copy(dataofcar, dataofcar + car_no, car_ptr);
		delete[] dataofcar;
		dataofcar = new struct cars[car_no + 1];
		copy(car_ptr, car_ptr + car_no, dataofcar);
		delete[] car_ptr;
	}
	cout << "\n\t\t\t\t\tEnter serial number of car: ";
	cin.ignore();
	getline(cin, dataofcar[car_no].serial);
	cout << "\n\n\t\t\t\t\tEnter name of car: ";

	getline(cin, dataofcar[car_no].car_name);
	cout << "\n\n\t\t\t\t\tEnter colour of car: ";

	getline(cin, dataofcar[car_no].car_color);
	cout << "\n\n\t\t\t\t\tEnter Speed of car: ";
	cin.ignore();
	getline(cin, dataofcar[car_no].car_speed);
	cout << "\n\n\t\t\t\t\tEnter rent of car in dollars: ";

	cin >> dataofcar[car_no].car_rent;
	cout << "\n\n\t\t\t\t\tEnter number plate of car: ";
	cin.ignore();
	getline(cin, dataofcar[car_no].no_plate);
	cout << "\n\n\t\t\t\t\tEnter status of car press '1' for available or'0' for rented: ";
	cin >> dataofcar[car_no].status;
	cout << "\n\n\t\t\t\t\tCar got rented: ";
	dataofcar[car_no].times_rented = 0; //jitni bar rent hoi
	dataofcar[car_no].times_repaired = 0;
	dataofcar[car_no].distance_covered = 0; //customer na jo fasla cover kia
	dataofcar[car_no].money = 0;

	loading();
	display();
	cout << "\tEntered data\n";
	cout << "\n\n\t\t\t\t\tSerial number of car is " << dataofcar[car_no].serial;
	cout << "\n\n\t\t\t\t\tName of car is " << dataofcar[car_no].car_name;
	cout << "\n\n\t\t\t\t\tColor of car is " << dataofcar[car_no].car_color;
	cout << "\n\n\t\t\t\t\tSpeed of car is " << dataofcar[car_no].car_speed;
	cout << "\n\n\t\t\t\t\tRent of car is " << dataofcar[car_no].car_rent;
	cout << "\n\n\t\t\t\t\tNumber plate of car is " << dataofcar[car_no].no_plate;
	cout << "\n\n\t\t\t\t\tStatus of car is " << dataofcar[car_no].status;

	Sleep(2000);
	++car_no;
	return dataofcar;
}
struct cars* remove_car(struct cars* car_ptr)
{
	cout << "\n\t\t\t\t\tCars are: \n";
	for (int i = 0; i < car_no; i++)
	{
		cout << "\n\t\t\t\t\t";
		cout << i + 1 << ". " << car_ptr[i].car_name << endl;
	}
	cout << "\n\n\n\t\t\t\t\tEnter name of car you want to remove: ";
	cin.ignore();
	string name;
	getline(cin, name);
	int index = -1;
	for (int i = 0; i < car_no; i++)
	{
		if (name == car_ptr[i].car_name)
		{
			index = i;
			break;
		}

	}
	if (index != -1)
	{

		for (int i = index; i < car_no - 1; i++)
		{
			car_ptr[i] = car_ptr[i + 1];

		}
		--car_no;
	}
	else
	{
		cout << "\n\n\t\t\t\t\t Not found";
		Sleep(500);
		return car_ptr;
	}
	cout << "\n\n\t\t\t\t\tCar removed";
	car_ptr2 = new struct cars[car_no];
	copy(car_ptr, car_ptr + car_no, car_ptr2);
	delete[] car_ptr;
	Sleep(500);
	return car_ptr2;
}
void writetocarfile(struct cars*& ptr, const string& filename)
{
	fout.open(filename);
	if (!fout) {
		cout << "\nCar file not opened for writng\n"; Sleep(500);
		return;
	}

	//Writing
	for (int i = 0; i < car_no; i++)
	{
		fout << ptr[i].serial << endl;
		fout << ptr[i].car_name << endl;
		fout << ptr[i].car_color << endl;
		fout << ptr[i].car_speed << endl;
		fout << ptr[i].car_rent << endl;
		fout << ptr[i].no_plate << endl;
		fout << ptr[i].status << endl;
		fout << ptr[i].times_rented << endl;
		fout << ptr[i].times_repaired << endl;
		fout << ptr[i].distance_covered << endl;
		fout << ptr[i].money << endl;
	}
	fout.close();


}
void readfromcarfile(struct cars*& ptr, const string& filename)
{
	ptr = new struct cars[car_no];


	fin.open(filename);
	if (!fin) {
		cout << "\nCar file not opened for reading\n"; Sleep(500);
		return;
	}int i = 0;
	while (i < car_no)
	{
		fin >> ptr[i].serial >> ptr[i].car_name >> ptr[i].car_color >> ptr[i].car_speed >> ptr[i].car_rent >> ptr[i].no_plate >> ptr[i].status >> ptr[i].times_rented >> ptr[i].times_repaired >> ptr[i].distance_covered >> ptr[i].money;
		i++;
	}

	fin.close();

}
struct rented
{
	string name;
	string carname;
	int rent;
	int hours;
	int distance;
	bool status;
	void reset() {
		name = "";
		carname = "";
		rent = ' ';
		hours = ' ';
		distance = ' ';
	}
};
struct rented* rentedptr;
struct rented* rentedptr2;
struct rented* rentedptr3;
void writetorentedfile(struct rented*& ptr, const string& filename)
{

	fout.open(filename);
	if (!fout) {
		cout << "\nCar file not opened for writng\n"; Sleep(500);
		return;
	}
	for (int i = 0; i < rentedstructindex; i++)
	{
		if (ptr[i].hours > 0)
		{
			fout << ptr[i].name << endl;

			fout << ptr[i].carname << endl;
			fout << ptr[i].rent << endl;
			fout << ptr[i].hours << endl;
			fout << ptr[i].distance << endl;
			fout << ptr[i].status << endl;
		}
	}
	fout.close();
}
void readfromrentedfile(struct rented* ptr, const string& filename)
{
	fin.open(filename);
	if (!fin) {
		cout << "\nCar file not opened for reading\n"; Sleep(500);
		return;
	}int i = 0;
	while (i < rentedstructindex)
	{
		fin >> ptr[i].name >> ptr[i].carname >> ptr[i].rent >> ptr[i].hours >> ptr[i].distance >> ptr[i].status;
		i++;
	}
	fin.close();
}



//Function to display detail of available car
void functionofouputdetailforrentingcar(struct cars* car_ptr)
{

	for (int i = 0; i < car_no; i++)
	{
		if (car[i].status == 1)
		{
			cout << endl;
			cout << "\t\t\t\t\t\t~(" << i + 1 << ")~";
			cout << "\n\t\t\t\t\tSerial no: " << car[i].serial << endl;
			cout << "\n\t\t\t\t\tName of car: " << car[i].car_name << endl;
			cout << "\n\t\t\t\t\tColour of car: " << car[i].car_color << endl;
			cout << "\n\t\t\t\t\tSpeed of car: " << car[i].car_speed << endl;
			cout << "\n\t\t\t\t\tRent per hour of car: " << car[i].car_rent << endl;
			cout << "\n\t\t\t\t\tNumber plate of car: " << car[i].no_plate << endl;
			cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		}
	}
}



void display();
void rent_cars();
void login(struct customer* customers);
void customer();
void car_rent_time(int index_of_car);
void available_cars();
void rental_reports();

void return_cars();
void admin();
void admin_login();
void change_admin_password();
void exiting();
void loading();
void customer_task();
void car_task();
int countlenghtoffile(const string& filename);

int main()
{
	system("cls");
	system("color 9");
	cout << "\t\t\t|~||~||~||~||~||~||~||~||~||~||~||~||~||~||~|\n" << "\t\t\t|~|";

	cout << "\t\t~~~WELCOME~~~\t\t  |~|" << endl;
	cout << "\t\t\t|~||~||~||~||~||~||~||~||~||~||~||~||~||~||~|\n\n\n";

	cout << "\t\t\t**********************************************\n";
	cout << "\t\t\t*        \"Car Rental Managment System\"       * \n";
	cout << "\t\t\t**********************************************\n\n\n";


	cout << "\t\t\t\tWant to login as an Admin\n";
	cout << "\t\t\t\t\tPress 1\n";
	cout << "\n\t\t\t\tWant to login as a customer\n";
	cout << "\t\t\t\t\tPress 2\n\n";
	cout << "\t\t\t\tYour choice is ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		display();
		cout << "\n\n\t\t\t\t\tYou are in the Admin Portal\n";
		Sleep(500);
		loading();
		admin_login();
		admin();
		break;

	case 2:
		display();
		cout << "\n\n\t\t\t\t\tYou are in the customer Portal\n";
		Sleep(500);
		fout.open("costumer data.txt", ios::app);
		fout.close();
		customer_no = countlenghtoffile("costumer data.txt") / 5;

		customers = new struct customer[customer_no];

		readfromcustomerfile(customers, "costumer data.txt");

		if (customer_no == 0)
		{
			cout << "\nNo customer";
			cout << "\nFirst add customers";
			cout << "\nYou are headed back to main menu";
			Sleep(2000);
			main();
		}
		fout.open("cardata.txt", ios::app);
		fout.close();
		car_no = countlenghtoffile("cardata.txt") / 11;
		car = new struct cars[car_no];

		readfromcarfile(car, "cardata.txt");

		rentedstructindex = car_no;
		rentedptr = new struct rented[car_no];

		fout.open("rented data.txt", ios::app);
		fout.close();
		fout.open("rentedcustomerdata.txt", ios::app);
		fout.close();
		readfromrentedfile(rentedptr, "rented data.txt");

		int reportfile;
		reportfile = countlenghtoffile("rentedcustomerdata.txt") / 6;

		if (reportfile > car_no)
			rentedptr2 = new struct rented[reportfile];
		else
			rentedptr2 = new struct rented[car_no];
		readfromrentedfile(rentedptr2, "rentedcustomerdata.txt");

		loading();
		login(customers);
		customer();

		break;
	default:
		cout << "Invalid Entry\n";
		break;

	}
	return 0;

}


void display()
{
	system("cls");
	cout << "\t\t\t\t**********************************************\n";
	cout << "\t\t\t\t*        \"Car Rental Managment System\"       * \n";
	cout << "\t\t\t\t**********************************************\n\n\n";
}
string email;
string password;
void login	(struct customer* customers)
{
	display();
	cout << "\n\t\t\t\t\tEnter ID ";
	cin.ignore();
	getline(cin, email);

	cout << "\n\t\t\t\t\tEnter Password ";
	getline(cin, password);

	for (int i = 0; i <= customer_no; i++)
	{
		if (customers[i].customer_name == email && customers[i].customer_password == password)
		{ //Comapring login id and password provided by user with IDs and passwords stored
			cout << i;

			display();
			cout << "\n\t\t\t\t\tSuccesfully login!!!!!!\n\n";
			Sleep(500);
			return;
		}

	}
	{
		// In case of invalid password


		display();

		cout << "\n\t\t\t\t\tInvalid entry\n";
		cout << "\n\t\t\t\t\tWant to try again\n";
		cout << "\n\t\t\t\t\tPress Y to re-enter\n";
		cout << "\n\t\t\t\t\tPress E to exit\n";
		cout << "\n\t\t\t\t\tEnter your choice ";
		char choose;
		cin >> choose;
		switch (choose)
		{
		case 'Y':
		case 'y':

			display();
			login(customers);
			return;
			break;

		case 'E':
		case 'e':
			exiting();

		default:
			cout << "\nInvalid input\n";
			cout << "Again directed to login page";
			Sleep(1000);
			display();
			login(customers);
			return;
			break;

		}

	}

}
void customer()
{

	display();

	cout << "\n\t\t\t\t\tCustomer menu\n";
	cout << "\n\t\t\t\t\t1.Rent a car\n";
	cout << "\n\t\t\t\t\t2.Return a car\n";
	cout << "\n\t\t\t\t\t3.View available car\n";
	cout << "\n\t\t\t\t\t4.Generate rental reports\n";
	cout << "\n\t\t\t\t\t5.Logout\n";
	cout << "\n\t\t\t\t\t6.Go To main menu";
	cout << "\n\n\n\t\t\t\t\tEnter your choice ";
	int choice;
	cin >> choice;
	writetorentedfile(rentedptr, "rented data.txt");
	writetocarfile(car, "cardata.txt");
	writetorentedfile(rentedptr2, "rentedcustomerdata.txt");
	if (total_rented > car_no)
	{
		rentedptr2 = new struct rented[total_rented];
		readfromrentedfile(rentedptr2, "rentedcustomerdata.txt");
	}
	switch (choice)
	{
	case 1:

		rent_cars();

		break;

	case 2:
		return_cars();


		break;
	case 3:
		available_cars();

		{
			cout << "\nPress \"E\" to exit the portal or press \"M\" to go to customer menu ";
			cout << "\nEnter your choice ";
			char chose;
			cin >> chose;
			switch (chose)
			{
			case 'E':
			case 'e':
				exiting();
			case 'M':
			case 'm':
				customer(); break;
			default:

				//If customer inputs invalid key

				display();
				cout << "Invalid entry\n";
				cout << "Want to rent again?\n";
				cout << "Press\"M\", on clicking anything else you will be exited\n";
				char choice;
				cin >> choice;
				if (choice == 'M' || choice == 'm')
					customer();
				else
				{
					exiting();
				}
				break;
			}
		}
		break;

	case 4:
		rental_reports();
		break;
	case 5:
		exiting();
		break;
	case 6:
		main();
		break;
	default:
		display();

		cout << "\nInvalid entry\n";
		cout << "Want to try again\n";
		cout << "Press Y to re-enter or on pressing anything else you will be exited\n";
		cout << "\nEnter your choice ";
		char choose;
		cin >> choose;
		switch (choose)
		{
		case 'Y':
		case 'y':

			display();
			customer();
			break;

		default:
			exiting();
		}
	}
}


void available_cars()
{ //This function show available cars 

	display();

	if (car_no == 0)
	{
		cout << "\n\n\t\t\t\t\tNo car available for rent at the moment";
		cout << "\n\n\t\t\t\t\tYou are directed to menu";
		Sleep(1000);
		customer();
		return;
	}
	cout << "\n\n\t\t\t\t\t~Following cars are available~\n\n";
	functionofouputdetailforrentingcar(car);
}



void car_rent_time(int index_of_car)
{
	// This function calculates the rent of car rented

	display();
	cout << "\n\t\t\t\t\tEach hour will cost you $" << car[index_of_car].car_rent;
	cout << "\n\n\t\t\t\t\tYou can rent a car for maximum of 10 hours\n";
	cout << "\n\t\t\t\t\tFor how many hours do you want to rent the car\n";
	cout << "\n\t\t\t\t\tEnter your choice ";
	int time_of_rent;
	cin >> time_of_rent;
	rentedptr[car_number].hours = time_of_rent;
	rentedptr2[car_number].hours = time_of_rent;

	if (time_of_rent > 0 && time_of_rent < 11)
	{
		//checking that the hours to rent the car are valid
		display();
		cout << "\n\n\t\t\t\t\tCalculating your rent";
		Sleep(500);
		int sum;
		sum = car[index_of_car].car_rent * time_of_rent;
		sum_of_rent += sum;

		//We are storing the rent of car  to customer stucutre so we can make  individual reports
		rentedptr[car_number].rent = sum;
		rentedptr2[car_number].rent = sum;
		car[index_of_car].money += sum;


		cout << "\n\n\t\t\t\t\tThis car will cost you " << sum << "$\n";
		Sleep(1900);
	}
	else
	{

		display();
		cout << "\t\t\t\t\tInvalid\n\n";
		cout << "\t\t\t\t\tWant to enter time again ?\n\n";
		cout << "\t\t\t\t\tPress \"Y\" to  again and \"N\" to go back to menu\n";
		char choise;
		cin >> choise;
		switch (choise)
		{
		case 'Y':
		case 'y':
			car_rent_time(car_number - 1);
			return;
			break;
		case 'N':
		case 'n':
			customer();
			return;
			break;
		}

	}
}
void rent_cars()
{

	int count = 0;
	display();
	for (int i = 0; i < car_no; i++)
	{
		if (car[i].status == 1)
		{
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\n\n\t\t\t\t\tNo car available for rent at the moment";
		cout << "\n\t\t\t\t\tYou are directed to menu";
		Sleep(1000);
		customer();
		return;
	}

	available_cars();//Available cars


	cout << "\n\t\t\t\t\tWhich car do you want to rent?\n";
	cout << "\n\t\t\t\t\tEnter index of car: ";

	cin >> car_number;
	car_number = car_number - 1;
	if (car_number >= 0 && car_number < car_no && car[car_number].status == 1)
	{
		car[car_number].status = 0; //making car rented
		rentedptr[car_number].status = 0;
		rentedptr2[car_number].status = 0;

		rentedptr[car_number].distance = -1;
		rentedptr2[car_number].distance = -1;

		car_rent_time(car_number);
		car[car_number].times_rented += 1;//Increasing times car rented of car stucture
		total_rented += 1;
		display();
		cout << "\n\t\t\t\t\tGenerating recipt"; Sleep(300);
		display();
		cout << "\n\t\t\t\t\tCar name: " << car[car_number].car_name;
		cout << "\n\t\t\t\t\tCostumer name: " << email;
		cout << "\n\t\t\t\t\tRent of car per hour: $" << car[car_number].car_rent;
		cout << "\n\t\t\t\t\tRented for " << rentedptr[car_number].hours << " hours";
		cout << "\n\t\t\t\t\tTotal sum is $" << car[car_number].money;
		cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		Sleep(2000);
		rentedptr[car_number].carname = car[car_number].car_name;
		rentedptr2[car_number].carname = car[car_number].car_name;
		rentedptr[car_number].name = email;
		rentedptr2[car_number].name = email;
		//If customer want to rent another car	
		display();
		cout << "\n\t\t\t\t\tWant to rent another car?\n";
		cout << "\n\t\t\t\t\tPress \"R\" to rent again and \"M\" to go back to menu\n";
		cout << "\n\t\t\t\t\tEnter your choice ";
		char chose;
		cin >> chose;
		switch (chose)
		{
		case 'R':
		case 'r':
			rent_cars();
			break;
		case 'M':
		case 'm':
			customer(); break;
		default:

			//If customer inputs invalid key
			//other than "y" or "n"
			display();
			cout << "\t\t\t\t\tInvalid entry\n\n";
			cout << "\t\t\t\t\tWant to rent again?\n\n";
			cout << "\t\t\t\t\tPress\"R\", to rent or press 'M' to go to menu on clicking anything else you will be exited\n";
			char choice;
			cin >> choice;
			switch (choice)
			{
			case 'R':
			case 'r':
				rent_cars();
				return;
				break;
			case 'M':
			case 'm':
				customer();
				return;
				break;
			default:
				exiting();
				break;
			}

		}


	}
	else
	{
		display();
		cout << "\n\n\t\t\t\t\tInvalid entry\n\n";
		cout << "\t\t\t\t\tWant to try again\n\n";
		cout << "\t\t\t\t\tPress Y to re-enter or Press 'M' to go to menu on pressing anything else you will be exited\n";
		cout << "\t\t\t\t\tEnter your choice ";
		char choose;
		cin >> choose;
		switch (choose)
		{
		case 'Y':
		case 'y':
			rent_cars();
			return;
			break;
		case 'M':
		case 'm':
			customer();
			return;
			break;
		default:
			exiting();
		}

	}

}

void rental_reports()
{
	display();

	cout << "\n\t\t\t\tIf you want to see individual report(s) click 'Y' else click 'N'";
	char choice;
	int count = 0;
	cout << "\n\n\t\t\t\tEnter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 'y':
	case'Y':
		display();

		for (int i = 0; i < car_no; i++)
		{
			if (rentedptr2[i].name == email)
			{
				cout << "\n\t\t\t\t\t" << "Customer name: " << rentedptr2[i].name;
				cout << "\n\n\t\t\t\t\tCar name is " << rentedptr2[i].carname;
				cout << "\n\n\t\t\t\t\tYou rented car for " << rentedptr2[i].hours;
				cout << "\n\n\t\t\t\t\tCar costed you " << rentedptr2[i].rent;
				if (rentedptr2[i].distance > 0)
					cout << "\n\n\t\t\t\t\tYou travelled " << rentedptr2[i].distance << " kms  ";
				else
					cout << "\n\t\t\t\t\tCar still rented";
				cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~\n\n";
				count++;
			}
		}
		if (count == 0)
			cout << "\n\n\t\t\t\t\tNo report available yet\n";

		break;
	case 'N':
	case 'n':
		break;

	}
	{
		cout << "\n\n\t\t\t\tPress \"E\" to exit the portal or press \"M\" to go to customer menu ";
		cout << "\n\n\t\t\t\tEnter your choice ";
		char chose;
		cin >> chose;
		switch (chose)
		{
		case 'E':
		case 'e':
			exiting();
			break;
		case 'M':
		case 'm':
			customer(); break;
		default:

			//If customer inputs invalid key

			display();
			cout << "\t\t\t\t\tInvalid entry\n\n";
			cout << "\t\t\t\t\tWant to rent again?\n\n";
			cout << "\t\t\t\t\tPress\"M\", on clicking anything else you will be exited\n";
			char choice;
			cin >> choice;
			if (choice == 'M' || choice == 'm')
				customer();
			else
				exiting();
			break;
		}
	}
}


void return_cars()
{
	int count = 0;
	display();
	for (int i = 0; i < car_no; i++)
	{
		if (car[i].status == 0)
		{
			count++;
		}
	}
	if (count == 0)
	{
		cout << "\n\n\t\t\t\t\tNo car available for return at the moment";
		cout << "\n\n\t\t\t\t\tYou are directed to menu";
		Sleep(1000);
		customer();
		return;
	}

	int counter = 0;
	cout << "\n\n\t\t\t\t\tCar for returning are: ";
	for (int i = 0; i < rentedstructindex; i++)
	{
		if (email == rentedptr[i].name)
		{
			cout << "\n\n\t\t\t\t\t";
			cout << i + 1 << ")  ";
			cout << rentedptr[i].carname;
			cout << endl;
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "\n\n\t\t\t\t\tNo car available for return at the moment";
		cout << "\n\n\t\t\t\t\tYou are directed to menu";
		Sleep(1000);
		customer();
		return;
	}
	cout << "\n\n\t\t\t\t\tWhich car do you want to return?\n\n";
	cout << "\t\t\t\t\tEnter name of car: ";
	string return_car;
	cin.ignore();
	getline(cin, return_car);
	for (int i = 0; i < car_no; i++)
	{
		if (return_car == rentedptr2[i].carname && rentedptr2[i].name == email && rentedptr2[i].status == 0)
		{
			car[i].status = 1;//making again available
			rentedptr[i].status = 1;
			rentedptr2[i].status = 1;
			display();
			cout << "\n\t\t\t\t\tCar returned!!!!\n\n";
			cout << "\t\t\t\t\tHow much distance you covered(in kms) with this car: ";
			int distance;
			cin >> distance;
			car[i].distance_covered += distance;
			rentedptr[i].distance = distance;
			rentedptr2[i].distance = distance;

			rentedptr[i].reset();


			//If customer want to rent another car	
			display();
			cout << "\t\t\t\t\tWant to return another car?\n\n";
			cout << "\t\t\t\t\tPress \"R\" to return again and \"M\" to go back to menu\n\n";
			cout << "\t\t\t\t\tEnter your choice ";
			char chose;
			cin >> chose;
			switch (chose)
			{
			case 'R':
			case 'r':
				return_cars();
				break;
			case 'M':
			case 'm':
				customer(); break;
			default:

				//If customer inputs invalid key
				//other than "y" or "n"
				display();
				cout << "\t\t\t\t\tInvalid entry\n\n";
				cout << "\t\t\t\t\tWant to return again?\n\n";
				cout << "\t\t\t\t\tPress\"R\", on clicking anything else you will be exited\n\n";
				char choice;
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
					return_cars();
				else
					exiting();
				break;
			}
		}
	}


	{
		display();
		cout << "\n\t\t\t\t\tInvalid entry\n\n";
		cout << "\t\t\t\t\tWant to try again\n\n";
		cout << "\t\t\t\t\tPress Y to re-enter or press 'M' to go to menu on pressing anything else you will be exited\n\n";
		cout << "\t\t\t\t\tEnter your choice ";
		char choose;
		cin >> choose;
		switch (choose)
		{
		case 'Y':
		case 'y':

			display();

			return_cars();
			return;
			break;

		case 'M':
		case 'm':
			customer();
			return;

		default:
			exiting();
		}

	}
}
void admin_login()
{
	display();
	string id;
	string password;
	cout << "\n\n\t\t\t\t\tEnter login id: ";
	cin >> id;
	cout << "\n\t\t\t\t\tEnter password: ";
	cin >> password;
	for (int i = 0; i < 2; i++)
	{
		if (id == admin_id[i] && password == admin_password[i])
		{
			//Comapring login id and password provided by user with IDs and passwords stored
			display();
			cout << "\t\t\t\t\tSuccessfully login\n";
			index_of_admin = i;
			Sleep(500);
			return;
		}
	}
	{
		display();

		cout << "\n\t\t\t\t\tInvalid entry\n";
		cout << "\n\t\t\t\t\tWant to try again\n";
		cout << "\n\t\t\t\t\tPress Y to re-enter\n";
		cout << "\n\t\t\t\t\tPress N to exit\n";
		cout << "\n\t\t\t\t\tEnter your choice ";
		char choose;
		cin >> choose;
		switch (choose)
		{
		case 'Y':
		case 'y':

			display();
			admin_login();
			return;
			break;

		case 'N':
		case 'n':
			exiting();

		default:
			cout << "Invalid input\n";
			Sleep(500);
			display();
			admin_login();
		}
	}
}
void admin()
{
	display();
	cout << "\n\t\t\t\t\t   Admin Menu\n";
	cout << "\n\t\t\t\t\t1.Can change password\n";
	cout << "\n\t\t\t\t\t2.Do work related to customers\n";
	cout << "\n\t\t\t\t\t3.Do work related to cars\n";
	cout << "\n\t\t\t\t\t4.Go back to main menu\n";
	cout << "\n\t\t\t\t\t5.Go to main menu";
	cout << "\n\n\t\t\t\t\t6.Logout\n";
	cout << "\n\n\n\t\t\t\t\tYour choice is: ";
	int choice, lenght = 0, car_lenght = 0;
	cin >> choice;

	switch (choice)
	{
	case 1:
		display();
		change_admin_password();
		break;
	case 2:
		lenght = countlenghtoffile("costumer data.txt") / 5;

		customer_no = lenght;
		customers = new struct customer[lenght];
		if (lenght > 0)
		{
			readfromcustomerfile(customers, "costumer data.txt");

		}
		customer_task();

		break;
	case 3:
		car_lenght = countlenghtoffile("cardata.txt") / 11;
		car_no = car_lenght;

		car = new struct cars[car_lenght];
		if (car_lenght > 0)
		{
			readfromcarfile(car, "cardata.txt");

		}

		car_task();
		break;
	case 4:
		admin();
		break;
	case 5:
		main();
		return;
	case 6:
		exiting();
	default:
		admin();
	}

}
void change_admin_password()
{
	display();
	cout << "\n\t\t\t\t\tEnter current password: ";
	string currentpassword;
	cin >> currentpassword;

	cout << "\n\n\t\t\t\t\tEnter the new password: ";
	string newpassword1;
	cin >> newpassword1;

	//password koi alphabet nhi ho rha 
	cout << "\n\t\t\t\t\tRe-enter new password: ";
	string newpassword2;
	cin >> newpassword2;
	if (currentpassword != admin_password[0] && currentpassword != admin_password[1])
	{
		display();
		cout << "\n\t\t\t\t\tYou current password doesnot match to the existing password ";
		cout << "\n\t\t\t\t\tRe-enter credentials ";
		Sleep(2000);
		change_admin_password();
		return;
	}
	if (newpassword1 != newpassword2)
	{
		display();
		cout << "\n\t\t\t\t\tNew passwords are not same";
		cout << "\n\n\t\t\t\t\tRe-enter credentials ";
		Sleep(2000);
		change_admin_password();
		return;
	}
	admin_password[index_of_admin] = newpassword1;//Changing password
	display();
	cout << "\n\t\t\t\t\tPassword successfuly changed";
	cout << "\n\n\t\t\t\t\tPress 'R'to re-login or press 'M' to go to admin menu";
	cout << "\n\n\t\t\t\t\tYour choice is: ";
	char choice;
	cin >> choice;
	switch (choice)
	{
	case 'R':
	case 'r':
		system("cls");
		main();
		return;
		break;

	case 'M':
	case 'm':
		admin();
		return;
	default:
		display();

		cout << "\n\t\t\t\t\tInvalid entry\n\n";
		cout << "\t\t\t\t\tWant to try again\n\n";
		cout << "\t\t\t\t\tPress M to go to admin menu or you will be exited: ";
		char choose;
		cin >> choose;
		if (choose == 'M' || choose == 'm')
		{
			admin();
			return;
		}
		else
			exiting();
	}
}
void exiting()
{
	display();
	cout << "\n\t\t\t\t\tThanks for coming to our portal";
	cout << "\n\n\t\t\t\t\tNow you are exiting\n\n";
	exit(0);
}
void loading()
{
	system("cls");
	system("color 2");
	for (int i = 0; i < 5; i++) {
		Sleep(400);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t   Loading";
		for (int i = 0; i < 2; i++) {
			cout << ".";
			Sleep(5);
			cout << "..";
			Sleep(5);
			cout << ".";
		}
		cout << endl;
		cout << "\n\t\t\t\t";
		if (i < 1) {
			cout << "|||||||"; continue;
		}
		if (i < 2) {
			cout << "|||||||||"; continue;
		}
		if (i < 3) {
			cout << "||||||||||||"; continue;
		}
		if (i < 4) {
			cout << "||||||||||||||||||"; continue;
		}
		if (i < 5) {
			cout << "|||||||||||||||||||||||||||||||||||"; continue;
		}
		if (i < 6) {
			cout << "|||||||||||||||||||||||||||||||||||||||||||||||||"; continue;
		}
	}
	system("color 9");
	cout << "\n\n\n";
}

void customer_task()
{

	display();
	cout << "\n\n\t\t\t\t\tCustomer related works";
	cout << "\n\n\t\t\t\t\t1.Add a customer";
	cout << "\n\n\t\t\t\t\t2.Remove a customer";
	cout << "\n\n\t\t\t\t\t3.Update customer data";
	cout << "\n\n\t\t\t\t\t4.Show Customer report";
	cout << "\n\n\t\t\t\t\t5.View all customers";
	cout << "\n\n\t\t\t\t\t6.Goback";
	cout << "\n\n\t\t\t\t\tYour choice is: ";
	int choice, index = -1;
	string ism;
	char key;
	cin >> choice;
	switch (choice)
	{
	case 1:
		display();

		customers = add_costumer(customers);

		break;
	case 2:
		display();
		customers = remove_customer(customers);

		break;
	case 3:
		display();

		customers = update_customerdata(customers);
		break;
	case 4:
		display();
		cout << "\n\t\t\t\t\t Detail of which customer you want?";
		for (int i = 0; i < customer_no; i++)
		{
			cout << endl;
			cout << "\t\t\t\t\t\t";
			cout << customers[i].customer_name << endl;
			cout << "\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~";
		}
		cout << "\n\n\t\t\t\t\tEnter name: ";
		cin.ignore();
		getline(cin, ism);
		fout.open("rentedcustomerdata.txt", ios::app);
		fout.close();
		rentedptr2 = new struct rented[car_no];
		readfromrentedfile(rentedptr2, "rentedcustomerdata.txt");

		for (int i = 0; i < customer_no; i++)
		{
			if (rentedptr2[i].name == ism)
			{
				index = i;
			}

		}
		if (index != -1)
		{
			cout << "\n\t\t\t\t\t" << "Customer name: " << rentedptr2[index].name;
			cout << "\n\n\t\t\t\t\tCar name is " << rentedptr2[index].carname;
			cout << "\n\n\t\t\t\t\tRented car for " << rentedptr2[index].hours;
			cout << "\n\n\t\t\t\t\tCar costed $" << rentedptr2[index].rent;
			if (rentedptr2[index].distance > 0)
				cout << "\n\t\t\t\t\tTravelled " << rentedptr2[index].distance << " kms ";
			else
				cout << "\n\t\t\t\t\tCar still rented";

			cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		}
		else
		{
			display();
			cout << "\n\t\t\t\t\tCostumer didn't rent any car yet";
		}
		cout << "\n\n\t\t\t\t\tEnter any alphabet to continue: ";
		cin >> key;

		break;
	case 5:
		for (int i = 0; i < customer_no; i++)
		{
			cout << "\t\t\t\t\t\tEntered data\n";
			cout << "\n\n\t\t\t\t\tName of customer is " << customers[i].customer_name;
			cout << "\n\n\t\t\t\t\tPassword of this customer is " << customers[i].customer_password;
			cout << "\n\n\t\t\t\t\tPhone no of this customer is " << customers[i].phone_no;
			cout << "\n\n\t\t\t\t\tId no of this customer is " << customers[i].id_no;
			cout << "\n\n\t\t\t\t\tHouse no of this customer is " << customers[i].house_no;
			cout << "\n\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		}
		cout << "\t\t\t\t\tEnter any alphabet to continue: ";
		cin >> key;
		break;
	case 6:
		admin();
		return;
	default:
		customer_task();
		break;
	}
	writetocustomerfile(customers, "costumer data.txt");
	display();

	cout << "\n\t\t\tIf you want to go back press 'B' or press 'M' to go to admin menu  else you will be exited";
	cout << "\n\n\t\t\t\t\t Your choice: ";
	char ch;
	cin >> ch;
	switch (ch)
	{
	case 'M':
	case 'm':
		admin();
		break;
	case 'B':
	case'b':
		customer_task();
		break;

	default:
		exiting();
	}
}
void car_task()
{
	display();
	cout << "\n\t\t\t\t\tCar related works";
	cout << "\n\n\t\t\t\t\t1.Add a car";
	cout << "\n\n\t\t\t\t\t2.Remove a car";
	cout << "\n\n\t\t\t\t\t3.Inventory report";
	cout << "\n\n\t\t\t\t\t4.Maintainence report";
	cout << "\n\n\t\t\t\t\t5.Utilization report";
	cout << "\n\n\t\t\t\t\t6.Display all cars";
	cout << "\n\n\t\t\t\t\t7.Go back";
	cout << "\n\n\t\t\t\t\tYour choice: ";
	int chose;
	cin >> chose;
	char key;
	switch (chose)
	{
	case 1:
		display();

		car = add_car(car);

		break;
	case 2:
		display();

		car = remove_car(car);
		break;

	case 3:
		display();
		for (int i = 0; i < car_no; i++)
		{
			cout << "\t\t\t\t\t\t~(" << i + 1 << ")~ ";
			cout << "\n\t\t\t\t\tSerial no: " << car[i].serial;
			cout << "\n\t\t\t\t\tName of car: " << car[i].car_name;
			cout << "\n\t\t\t\t\tStatus of car: ";
			if (car[i].status == 1)
				cout << "Available";
			else
				cout << "Rented";
			cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		}
		cout << "\t\t\t\t\tEnter any alphabet to continue: ";
		cin >> key;
		break;
	case 4:
		display();
		cout << "\n\n\t\t\t\tIf a car has covered more than 500kms than it goes for Maintenance";
		for (int i = 0; i < car_no; i++)
		{
			cout << "\n\t\t\t\t\t            ~(" << i + 1 << ")~ ";
			cout << "\n\n\t\t\t\t\tSerial no: " << car[i].serial;
			cout << "\n\n\t\t\t\t\tName of car: " << car[i].car_name;

			cout << "\n\n\t\t\t\t\tDistance covered: " << car[i].distance_covered;
			if (car[i].distance_covered < 500)
			{

				if (car[i].distance_covered > 400)
				{
					cout << "\n\n\t\t\t\t\tUpcoming maintainence"; break;
				}
				cout << "\n\n\t\t\t\t\t--Maintence not required at moment--";
			}
			else
			{
				cout << "\n\n\t\t\t\t\t--Maintence required--";
				cout << "\n\n\t\t\t\t\tTo do maintence of " << car[i].car_name << " enter any alphabet: ";
				cin >> key;
				car[i].distance_covered -= 500;
			}

			cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		}
		cout << "\t\t\t\t\tEnter any alphabet to continue: ";
		cin >> key;
		break;

	case 5:
		display();
		for (int i = 0; i < car_no; i++)
		{
			cout << "\n\t\t\t\t\t               ~(" << i + 1 << ")~ ";
			cout << "\n\n\t\t\t\t\tSerial no: " << car[i].serial;
			cout << "\n\n\t\t\t\t\tName of car: " << car[i].car_name;
			cout << "\n\n\t\t\t\t\tTimes rented: " << car[i].times_rented;
			cout << "\n\n\t\t\t\t\tDistance covered: " << car[i].distance_covered;
			cout << "\n\n\t\t\t\t\tProfit gained: " << car[i].money;
			cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		}
		cout << "\t\t\t\t\tEnter any alphabet to continue: ";
		cin >> key;
		break;
	case 6:
		display();
		for (int i = 0; i < car_no; i++)
		{
			cout << "\n\t\t\t\t\t             ~(" << i + 1 << ")~ ";
			cout << "\n\n\t\t\t\t\tSerial number of car is " << car[i].serial;
			cout << "\n\n\t\t\t\t\tName of car is " << car[i].car_name;
			cout << "\n\n\t\t\t\t\tColor of car is " << car[i].car_color;
			cout << "\n\n\t\t\t\t\tSpeed of car is " << car[i].car_speed;
			cout << "\n\n\t\t\t\t\tRent of car is " << car[i].car_rent;
			cout << "\n\n\t\t\t\t\tNumber plate of car is " << car[i].no_plate;
			cout << "\n\n\t\t\t\t\tStatus of car is ";
			if (car[i].status == 1)
				cout << "available";
			else
				cout << "rented";
			cout << "\n\n\t\t\t\t\tCar got rented " << car[i].times_rented;
			cout << "\n\n\t\t\t\t\tCar got repaired " << car[i].times_repaired;
			cout << "\n\n\t\t\t\t\tDistance covered " << car[i].distance_covered;
			cout << "\n\n\t\t\t\t\tProfit " << car[i].money;
			cout << "\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		}

		cout << "\t\t\t\t\tEnter any alphabet to continue: ";
		cin >> key;
		break;
	case 7:
		admin();
		return;
	default:
		car_task();
		return;
	}
	writetocarfile(car, "cardata.txt");

	display();
	cout << "\n\t\t\tIf you want to go back press 'B' or press 'M' to go to admin menu  else you will be exited";
	cout << "\n\n \t\t\t\t\tYour choice: ";
	char ch;
	cin >> ch;
	switch (ch)
	{
	case 'M':
	case 'm':
		admin();
		break;
	case 'B':
	case'b':
		car_task();
		break;

	default:
		exiting();
	}
}
int countlenghtoffile(const string& filename)
{
	int counter = 0;
	fin.open(filename);
	if (!fin.is_open())
	{
		return -1;
	}
	string a;
	while (getline(fin, a))
	{
		counter++;
	}
	fin.close();
	return counter;
}
