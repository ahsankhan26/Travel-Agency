#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>                                
#include<math.h>
#include<time.h>
using namespace std;
/////////////////////////////////////////////////////////////////////
COORD coord = { 0, 0 };
//////////////////////////////////////////////

// ********************************STRUCTURES*********************************
struct city_domestic
{
	int seats[5][10];
	city_domestic()
	{
		for (int i = 0; i<5; i++)
		{
			for (int j = 0; j<10; j++)
			{
				seats[i][j] = 0;
			}
		}
	}
};
/////////////////////////////////////////////////////////////////////////////////////

struct city_international
{
	int seats[5][10];

	city_international()
	{
		for (int i = 0; i<5; i++)
		{
			for (int j = 0; j<10; j++)
			{
				seats[i][j] = 0;
			}
		}
	}
};

//////////////////////////////////////////////////////////////////////////
struct Person
{
	char name[20];
	int id;
	int age;
	int ticket_no;
	int seat_no;
	char *choice;
	char home_city[15];
	char destination[15];
	city_domestic *p;
	city_international *ptr;
	int index;
};

// ********************************STRUCTURES*********************************//
//++++++++++++++++++++++++++++++FUNCTION DECLARATIONS+++++++++++++++++++++++++++++++++//

void gotoxy(int x, int y);
void mainmenu();
void title(void);
void travel_destination(Person *temp);
void get_data(Person *);
void ticket_booking(Person *, int);
int ticket_generator();
void print_data(Person *);
int search_id(Person *[], int);
void exit_func();
//++++++++++++++++++++++++++++++FUNCTION DECLARATIONS+++++++++++++++++++++++++++++++++//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

char *possible_dom_cities[5] = { "Karachi", "Lahore", "Faisalabad", "Islamabad", "Multan" };
char *possible_int_cities[5] = { "London", "Washington DC", "Beiijng", "Tokyo", "Dubai" };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

city_domestic karachi, lahore, faisalabad, islamabad, multan, peshawar;//home city
city_international london, washington_dc, beijing, tokyo, dubai;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------MAIN---------------------------------------//

int main()
{

	int i = 0,res = 0;
	char choice;
	char ch = 'y';
	title();
	while (ch != 'n' && i<80)
	{
		Person *arr[80];
		mainmenu();
		gotoxy(20, 17); cout << "Enter your choice :";
		gotoxy(40, 17); cin >> choice;
		arr[i] = new Person;
		switch (choice)
		{
		case '1': // get data
			system("cls");
			arr[i] = new Person;
			get_data(arr[i]);
			travel_destination(arr[i]);
			fflush(stdout);
			i++;
			break;

		case  '2'://edit information
			system("cls");
			if (i == 0)
			{
				cout << "we dont have any information right now\nso u cant edit.\n";
				system("pause");
				break;
			}
			res = search_id(arr, i);
			if (res == -1)
			{
				cout << "sorry no data found\n";
				system("pause");
			}
			else
			{
				int opt;
				gotoxy(20, 3); cout << "\t\tyour id has been matched\n";
				gotoxy(20, 4); cout << "\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB";
				gotoxy(20, 5); cout << "\xB2"; gotoxy(66, 5); cout << "\xB2";
				gotoxy(20, 6); cout << "\xB2"; gotoxy(66, 6); cout << "\xB2";
				gotoxy(20, 7); cout << "\xB2"; gotoxy(66, 7); cout << "\xB2";
				gotoxy(20, 8); cout << "\xB2"; gotoxy(66, 8); cout << "\xB2";
				gotoxy(20, 9); cout << "\xB2"; gotoxy(66, 9); cout << "\xB2";
				gotoxy(20, 10);cout << "\xB2"; gotoxy(66, 10); cout << "\xB2";
				gotoxy(20, 11);cout << "\xB2"; gotoxy(66, 11); cout << "\xB2";
				gotoxy(20, 12);cout << "\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB";
				gotoxy(21, 6);cout << " select the option :-";
				gotoxy(21, 7);cout << " 1. edit personal details";
				gotoxy(21, 8);cout << " 2. edit destination";
				gotoxy(21, 9);cout << " 3. edit everything";
				gotoxy(22, 10); cin >> opt;
				switch (opt)
				{
				case 1:
					get_data(arr[res]);break;
				case 2:
					if (arr[res]->choice == "Domestic")
					{
						arr[res]->p->seats[arr[res]->index][(arr[res]->seat_no) - 1] = 0;
					}
					else
					{
						arr[res]->ptr->seats[arr[res]->index][(arr[res]->seat_no) - 1] = 0;
					}
					travel_destination(arr[res]);break;
				case 3:
					get_data(arr[res]);
					travel_destination(arr[i]);break;
				}
			}
			break;

		case '3': //print
			if (i == 0)
			{
				cout << "we dont have any information right now\nso u cant edit.\n";
				system("pause");break;
			}
			res = search_id(arr, i);
			if (res == -1)
			{
				cout << "sorry no data found\n";
			}
			else
			{
				cout << "your id has been matched\n";
				system("pause");														
				print_data(arr[res]);
			}
			break;

		case '4'://search 
			char temp_choice;
			int l;
			l = search_id(arr, i);
			if (l == -1)
			{
				cout << "sorry no data found\n";
			}
			else
			{
				cout << "\t\tyour id has been matched\n";
				cout << "\t\tdo u want to print the information(y/n)\n";
				cin >> temp_choice;
				if (temp_choice == 'y')
				{
					print_data(arr[l]);
				}
			}
			break;

		case '5': //exit
			exit_func();break;

		default:
			gotoxy(10, 23);
			cout << "\aWrong Entry!!Please re-entered correct option\n";
			system("pause");
		}
	}
	return 0;
}
//-----------------------------MAIN---------------------------------------//
//__________________________________FUNCTION DECLARATIONS____________________________________________________//

void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
////////////////////////////////////////

void mainmenu()
{
	system("cls");
	gotoxy(20, 3);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";

	gotoxy(20, 5);
	cout << "\xDB\xDB\xDB\xDB\xB2 1. Book a trip";
	gotoxy(20, 7);
	cout << "\xDB\xDB\xDB\xDB\xB2 2. Edit";
	gotoxy(20, 9);
	cout << "\xDB\xDB\xDB\xDB\xB2 3. Print Ticket ";
	gotoxy(20, 11);
	cout << "\xDB\xDB\xDB\xDB\xB2 4. Search";
	gotoxy(20, 13);
	cout << "\xDB\xDB\xDB\xDB\xB2 5. Close Application";
	gotoxy(20, 15);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
}
/////////////////////////////////////////////////////////////////////////////
void title(void)
{

	system("cls");
	char d[25] = "  ASA TRAVEL AGENCY";
	int i = 0, j;

	gotoxy(10, 4);
	for (j = 0; j<20; j++)
	{
		Sleep(50);
		cout << "*";
	}
	for (j = 0; j<20; j++)
	{
		Sleep(50);
		cout << d[j];
	}
	cout << " ";
	for (j = 0; j<20; j++)
	{
		Sleep(50);
		cout << "*";
	}
	cout << "\n\n\n\t\t\tGroup Name : Diabetes"
		<< "\n\n\t\t\t    Group Members\n\n"
		<< "\n\t\t\t1. Ammar Gadit  (CS-045)\n"
		<< "\n\t\t\t2. M.Ahsan Khan (CS-125)\n"
		<< "\n\t\t\t3. Shaheer Amin (CS-117)\n"
		<< "\n\t\t\t4. Vijay Kumar  (CS-137)\n\n\n\n";
	system("pause");
}

void  get_data(Person *temp)
{
	char ans;
	system("cls");
	gotoxy(20, 3); cout << "\t\tEnter the Information Below";
	gotoxy(20, 4); cout << "\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB";
	gotoxy(20, 5);
	cout << "\xB2"; gotoxy(66, 5); cout << "\xB2";
	gotoxy(20, 6);
	cout << "\xB2"; gotoxy(66, 6); cout << "\xB2";
	gotoxy(20, 7);
	cout << "\xB2"; gotoxy(66, 7); cout << "\xB2";
	gotoxy(20, 8);
	cout << "\xB2"; gotoxy(66, 8); cout << "\xB2";
	gotoxy(20, 9);
	cout << "\xB2"; gotoxy(66, 9); cout << "\xB2";
	gotoxy(20, 10);
	cout << "\xB2"; gotoxy(66, 10); cout << "\xB2";
	gotoxy(20, 11);
	cout << "\xB2"; gotoxy(66, 11); cout << "\xB2";
	gotoxy(20, 12);
	cout << "\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB";
	gotoxy(21, 6);
	cout << " Name :";
	gotoxy(30, 6);
	cin >> temp->name;//
	gotoxy(21, 7);
	cout << " Age  : ";
	gotoxy(29, 7); //
	cin >> temp->age; //
	gotoxy(21, 8);
	cout << " Domestic or International (d or i)  : ";
	gotoxy(60, 8);
	cin >> ans;
	if (ans == 'd')
	{
		temp->choice = "Domestic";
	}
	else
	{
		temp->choice = "International";
	}
	gotoxy(21, 9);
	cout << " Enter Home City :";
	gotoxy(40, 9);
	cin >> temp->home_city;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void  travel_destination(Person *temp)
{
	if (temp->choice == "Domestic")
	{
		gotoxy(20, 17); cout << "\t\tDOMESTIC CITIES";
		gotoxy(20, 18); cout << "Choose the destination from the following places\n";
		gotoxy(20, 20); cout << "\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB";
		gotoxy(20, 21);
		cout << "\xB2"; gotoxy(66, 21); cout << "\xB2";
		gotoxy(20, 22);
		cout << "\xB2"; gotoxy(66, 22); cout << "\xB2";
		gotoxy(20, 23);
		cout << "\xB2"; gotoxy(66, 23); cout << "\xB2";
		gotoxy(20, 24);
		cout << "\xB2"; gotoxy(66, 24); cout << "\xB2";
		gotoxy(20, 25);
		cout << "\xB2"; gotoxy(66, 25); cout << "\xB2";
		gotoxy(20, 26);
		cout << "\xB2"; gotoxy(66, 26); cout << "\xB2";
		gotoxy(20, 27);
		cout << "\xB2"; gotoxy(66, 27); cout << "\xB2";
		gotoxy(20, 28);
		cout << "\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB";

		int y = 22;
		for (int i = 0; i<5; i++)
		{
			if (strcmp(temp->home_city, possible_dom_cities[i]))
			{
				gotoxy(22, y++); cout << possible_dom_cities[i] << endl;
			}
		}
		gotoxy(22, y++); cin >> temp->destination;

		if (!strcmp(temp->destination, "Karachi"))
		{
			int i = 0;
			temp->p = &karachi;
			ticket_booking(temp, i);
		}
		if (!strcmp(temp->destination, "Lahore"))
		{
			int i = 1;
			temp->p = &lahore;
			ticket_booking(temp, i);
		}
		if (!strcmp(temp->destination, "Faisalabad"))
		{
			int i = 2;
			temp->p = &faisalabad;
			ticket_booking(temp, i);
		}
		if (!strcmp(temp->destination, "Islamabad"))
		{
			int i = 3;
			temp->p = &islamabad;
			ticket_booking(temp, i);
		}
		if (!strcmp(temp->destination, "Multan"))
		{
			int i = 4;
			temp->p = &multan;
			ticket_booking(temp, i);
		}
	}
	else //if (temp->destination == "International")
	{
		cout << "\tInternational CITIES\nChoose from the following places\n";
		for (int i = 0; i<5; i++)
		{
			if (strcmp(temp->home_city, possible_int_cities[i]))
			{
				cout << possible_int_cities[i] << endl;
			}
		}
		cin >> temp->destination;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (!strcmp(temp->destination, "London"))
		{
			int i = 0;
			temp->ptr = &london;
			ticket_booking(temp, i);
		}
		else if (!strcmp(temp->destination, "Washington DC"))
		{
			int i = 1;
			temp->ptr = &washington_dc;
			ticket_booking(temp, i);
		}
		else
			if (!strcmp(temp->destination, "Beijing"))
			{
				int i = 2;
				temp->ptr = &beijing;
				ticket_booking(temp, i);
			}
			else
				if (!strcmp(temp->destination, "Tokyo"))
				{
					int i = 3;
					temp->ptr = &tokyo;
					ticket_booking(temp, i);
				}
				else
					if (!strcmp(temp->destination, "Dubai"))
					{
						int i = 4;
						temp->ptr = &dubai;
						ticket_booking(temp, i);
					}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////
void ticket_booking(Person *nigga, int target)
{
	int count = 0, j, n, k = 0;
	int arr[10] = { 0 };
	char choice;
	system("cls");
	cout << "\t\tDestination : " << nigga->destination << endl;
	if (nigga->choice == "International")
	{
		choice = 'i';
		for (j = 0; j < 10; j++)
		{
			if (nigga->ptr->seats[target][j] == 0)
			{
				count++;
				arr[k++] = j + 1;
			}
		}
	}
	else
		if (nigga->choice == "Domestic")
		{
			choice = 'd';
			for (j = 0; j < 10; j++)
			{
				if (nigga->p->seats[target][j] == 0)
				{
					count++;
					arr[k++] = j + 1;
				}
			}
		}
	if (count == 0)
	{
		cout << "no seats are available\n";
	}
	else
	{
		cout << "\t\tFollowing seats are available\n\t\tkindly select one of the following\n\n\n";
		for (int i = 0; i<count; i++)
		{
			cout << "--------";
			cout << "\t";
		}
		cout << "\n";
		for (int i = 0; i<count; i++)
		{
			cout << "|  " << arr[i] << "   |";
			cout << "\t";
		}
		cout << "\n";
		for (int i = 0; i<count; i++)
		{
			cout << "--------";
			cout << "\t";
		}
		cout << "\n";
		cout << "\nenter the seat no u want : ";
		cin >> n;
		cout << endl;
		int z = 0;
		if (choice == 'd')
		{
			if (nigga->p->seats[target][n - 1] == 1)
			{
				cout << "seat alredy occupied.enter again\n";
				cin >> n;
			}
			while (1)
			{
				if (nigga->p->seats[target][n - 1] == 0)
				{
					break;
				}
				else
				{
					cout << "seat alredy occupied.enter again\n";
					cin >> n;
				}
			}
			nigga->p->seats[target][n - 1] = 1;
		}
		else
		{
			if (nigga->ptr->seats[target][n - 1] == 1)
			{
				cout << "seat alredy occupied.enter again\n";
				cin >> n;
			}
			while (1)
			{
				if (nigga->ptr->seats[target][n - 1] == 0)
				{
					break;
				}
				else
				{
					cout << "seat alredy occupied.enter again\n";
					cin >> n;
				}
			}
			nigga->ptr->seats[target][n - 1] = 1;
		}
		nigga->seat_no = n;
		nigga->id = ticket_generator();
		cout << "\t\tyour ID number is : " << nigga->id <<" (Kindly note it down) "<< endl;
		cout << "\t\tThank you !\n\t\tyour booking has been confirmed\n\n";
		system("pause");
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
int ticket_generator()
{
	srand(time(NULL));
	int temp;
	temp = (rand() % 8999) + 1000;
	return temp;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int search_id(Person *arr[], int k)
{
	int i, id, index, l = 0;
	cout << "enter your id\n";
	cin >> id;
	for (i = 0; i <= k; i++)
	{
		if (arr[i]->id == id)
		{
			index = i;
			l = 1;
			break;
		}
	}
	if (l == 0)
	{
		return -1;
	}
	return index;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_data(Person *test)
{
	system("cls");
	long long int x = 750000;
	for (int i = 1; i <40; i++)
	{
		gotoxy(74, i);
		cout << "*|" << endl;
	}
	for (int i = 1; i <= 73; i++)
	{
		gotoxy(i, 01);
		cout << "*";
	}
	for (int i = 1; i <= 73; i++)
	{
		gotoxy(i, 2);
		cout << "-";
	}
	gotoxy(12, 5);
	char pas_no[10] = "ALK12467";//passport number, hardcoded
	gotoxy(6, 6); cout << "\t\t\t     ASA TRAVEL AGENCY" << endl;
	gotoxy(6, 7); cout << "\t\t\t     *****************" << endl;
	gotoxy(6, 9); cout << "\t\t\t       TOUR DETAILS " << endl;
	gotoxy(6, 10); cout << "\t\t\t       ************" << endl;
	gotoxy(8, 12); cout << "\n\n  \t\t* Name : " << test->name << endl << endl;
	gotoxy(8, 14); cout << "\n\n  \t\t* Passport Number : " << pas_no << endl;
	gotoxy(8, 16); cout << "\n\n  \t\t* Travelling from : " << test->home_city << endl;
	gotoxy(8, 18); cout << "\n\n  \t\t* Travelling to : " << test->destination << endl;
	gotoxy(8, 20); cout << "\n\n  \t\t* e-Ticket Number : " << (rand() % 800000) + 600000 << endl;
	gotoxy(8, 22); cout << "\n\n  \t\t* Age : " << test->age << endl;
	gotoxy(8, 24); cout << "\n\n  \t\t* Flight Num : " << "EK-" << rand() % 800 + 600;
	gotoxy(27, 30); cout << "Total Cost = " << x;
	gotoxy(22, 33); cout << "Have a safe and joyful trip :)";
	gotoxy(1, 38); cout << " ------------------------------------------------------------------------";
	gotoxy(1, 39); cout << " ************************************************************************";

	for (int i = 1; i < 40; i++)
	{
		gotoxy(1, i);
		cout << "|*" << endl;
	}
	system("pause");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void exit_func()
{
	system("cls");
	gotoxy(16, 3);
	cout << "\t\tTravel Agency";
	gotoxy(16, 4);
	cout << "\tComputer Programming Project";
	gotoxy(16, 5);
	cout << "\t\tMade by";
	gotoxy(16, 7);
	cout << "\n\t\t\t1. Ammar Gadit  (CS-045)\n"
		<< "\n\t\t\t2. M.Ahsan Khan (CS-125)\n"
		<< "\n\t\t\t3. Shaheer Amin (CS-117)\n"
		<< "\n\t\t\t4. Vijay Kumar  (CS-137)\n\n\n\n";

	gotoxy(10, 17);
	cout << "Exiting in 3 second...........>";
	Sleep(3000);
	cout << endl;
	exit(0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//__________________________________FUNCTION DECLARATIONS____________________________________________________//
