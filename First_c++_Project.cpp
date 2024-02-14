//  HOTEL MANGEMENT  PROJECCT .....
// CREATE TWO CLASSES 
// 1 : ONE FOR BOOKING
// 2 : SECOND FOR FOOD 

//								--------------	ERRORS --------------
//  2: MAKE THIS PROJECT IN SMALLER MODULES AND LINK IT IN MAIN ONE..
//								------------- CHECK IT -------------

#include<iostream>
#include<string>
using namespace std;

//  ----------------  CLASS FOR BOOKING -------------------
class Booking {
private:
	string Guest_name;
	string Phone_no;
	string Hotel_name;
	int Stay;
	int Confirmation;
	int Budget;
	int Rooms;
	int Bill;
	int Filter;

protected:
	int Guest_count = 0;

public:
	int Return_value;
	string ALL_Hotels[15] = { "1 : Hotel Burg" ,"2 : Hotel Rose","3 : Hotel Tulip","4 : Hotel Mughals","5 : Hotel Golden","6 : Hotel International","7 : Hotel vivanta","8 : Hotel mumtaz"
		,"9 : Hotel SAnta","10 :  Hotel Tradition","11 : Hotel culture ","12 : Hotel westcoat ","13 : Hotel las vagas","14 :  Hotel water","15 : Hotel Hell" };


	//    ------------------------  Booking Function to get store details -----------------------------
	void Get_guest(Booking& ob, istream& inp, int Budget);

   //       ------------------ Function to check correct Hotel name -------------------------
	int check(Booking& in);
	
	//   ............... STORE THE INFORMATION OF GUEST ......... 
	friend istream& operator >>(istream& inp, Booking& in);

	//  ...............  PRINT THE INFORMATION OF GUEST .......... 
	friend ostream& operator <<(ostream& out, const Booking& otp);

	//   ..............	CONSTRUCTOR FOR BOOKING ( default as well as parameterized ) ........
	Booking(string Guest_name, string Phone_no, string Hotel_name, int Stay, int Confirmation, int Budget, int Rooms, int Bill);
};



//       ------------------ Function to check correct Hotel name -------------------------
int Booking::check(Booking& in)
{
	if (in.Hotel_name == "1" || in.Hotel_name == " Hotel Burg" || in.Hotel_name == "2" || in.Hotel_name == "Hotel Rose") {
		in.Budget = 2000;
		//	     ------------------------------  Function call ------------------------------
		in.Get_guest(in, cin, in.Budget);
		return 1;
	}
	else if (in.Hotel_name == "Hotel Tulip" || in.Hotel_name == "Hotel Mughals" || in.Hotel_name == "3" || in.Hotel_name == "4" || in.Hotel_name == "Hotel Golden" || in.Hotel_name == "5" || in.Hotel_name == "Hotel International" || in.Hotel_name == "6")
	{
		in.Budget = 5000;
		//	     ------------------------------  Function call ------------------------------
		in.Get_guest(in, cin, in.Budget);
		return 2;
	}
	else if (in.Hotel_name == " Hotel vivanta" || in.Hotel_name == "Hotel goop" || in.Hotel_name == "Hotel Tradition"
		|| in.Hotel_name == "Hotel culture4" || in.Hotel_name == "Hotel westcoat" || in.Hotel_name == " Hotel las vagas" || in.Hotel_name == "Hotel International" || in.Hotel_name == "Hotel water" || in.Hotel_name == " Hotel Hell" || in.Hotel_name == "7" || in.Hotel_name == "8" || in.Hotel_name == "9" || in.Hotel_name == "10" || in.Hotel_name == "11" || in.Hotel_name == "12" || in.Hotel_name == "13" || in.Hotel_name == "14" || in.Hotel_name == "15")
	{
		in.Budget = 10000;
		//	     ------------------------------  Function call ------------------------------
		in.Get_guest(in, cin, in.Budget);
		return 3;
	}

	return 0;
}


//					 ................  OUTER BODY FUNCTIONS OF BOOKING CLASS ............... 

//                ''''''' Body of constructor '''''''''
Booking::Booking(string Guest_name = "nil", string Phone_no = "nil", string Hotel_name = "nil", int Stay = 0, int Confirmation = 0, int Budget = 0, int Rooms = 0, int Bill = 0)
{
	this->Guest_name = Guest_name;
	this->Phone_no = Phone_no;
	this->Hotel_name = Hotel_name;
	this->Stay = Stay;
	this->Confirmation = Confirmation;
	this->Budget = Budget;
	this->Rooms = Rooms;
	this->Bill = Bill;
}



//    ------------------------  Booking Function body -----------------------------
void Booking::Get_guest(Booking& ob, istream& inp, int Budget)
{
	system("cls");
	cout << "Excelent choice" << endl;
	cout << "how many rooms u want" << endl;
	inp >> ob.Rooms;

	while (ob.Rooms == 0) {
		cout << " Invalid input " << endl;
		cout << "RE-enter rooms" << endl;
		inp >> ob.Rooms;
	}

	cout << "how many days u want to stay (don't put 0)" << endl;
	inp >> ob.Stay;

	while (ob.Stay == 0) {
		cout << "Invalid input" << endl;
		cout << "RE-enter stay" << endl;
		inp >> ob.Stay;
	}


	ob.Bill = (ob.Budget + 50) * ob.Stay * ob.Rooms;
	cout << "Your total Bill : " << ob.Bill << endl;
	cout << "Type 1 to pay or 10 to not" << endl;
	inp >> ob.Confirmation;

	while (ob.Confirmation != 1)
	{
		cout << "Invalid input " << endl;
		cout << "RE-enter your input" << endl;
		inp >> ob.Confirmation;
	}

	cout << "enter your name" << endl;
	std::cin.ignore(); // Ignore the newline character left in the input buffer
	std::getline(std::cin, ob.Guest_name);

	cout << "enter your phone number" << endl;
	getline(cin, ob.Phone_no);

	while (ob.Phone_no.length() != 10) {
			std::cout << "your entered phone number is not ten digit .It's only " << ob.Phone_no.length()
				<< " digits " << std::endl;
			std::cout << "Re-enter your phone number" << std::endl;
			getline(std::cin, ob.Phone_no);
	}

	cout << "Enjoy!" << endl;
	ob.Return_value = 1;
	ob.Guest_count++;

}


//			'''' Output function '''''
ostream& operator <<(ostream& out, const Booking& otp)
{
	out << " \t-------- Visit Again -----------" << endl;
	out << "\n  \n ------------------ customer detail ---------------" << endl;
	out << "Guest name : " << otp.Guest_name << endl;
	out << "Hotel name : " << otp.Hotel_name << endl;
	out << "phone no. " << otp.Phone_no << endl;
	out << "stays : " << otp.Stay << endl;
	out << "Rooms : " << otp.Rooms << endl;
	out << " Total bill paid : " << otp.Bill << endl;

	return out;
}




//         '''''' Input function '''''''

istream& operator >>(istream& inp, Booking& in)
{
	cout << " want to see all avalaible hotels or filter " << endl;
	cout << " type 1 to all and 2 to filter" << endl;
	inp >> in.Filter;

	while (in.Filter != 1 && in.Filter != 2) {
		cout << "Invalid input Either enter 1 or 2" << endl;
		inp >> in.Filter;
	}

	if (in.Filter == 2) {
		cout << "how much budget u have" << endl;
		inp >> in.Budget;

		while (in.Budget < 1000) {
			cout << "Sorry! no rooms avalaible" << endl;
			cout << "Budget shoul'd at least be 1000 or to cancel Enter 0" << endl;
			inp >> in.Budget;
			if (in.Budget == 0)
				exit(0);
		}
		if (in.Budget <= 2000) {
			cout << "These are avalaible" << endl;
			cout << "1 : Hotel Burg" << endl;
			cout << "2 : Hotel Rose" << endl;
			inp >> in.Hotel_name;
			while (in.Hotel_name != "1" && in.Hotel_name != " Hotel Burg" && in.Hotel_name != "2" && in.Hotel_name != "Hotel Rose") {
				cout << "Invalid input enter hotel number" << endl;
				inp >> in.Hotel_name;
			}
			//  ------------------------------  Function call ------------------------------
			in.Budget = 2000;
			in.Get_guest(in, inp, in.Budget);
		}


		else if (in.Budget <= 6000) {
			cout << "These are avalaible" << endl;
			cout << "3 : Hotel Tulip" << endl;
			cout << "4 : Hotel Mughals" << endl;
			cout << "5 : Hotel Golden" << endl;
			cout << "6 : Hotel International" << endl;
			inp >> in.Hotel_name;



			while (in.Hotel_name != "Hotel Tulip" && in.Hotel_name != "Hotel Mughals" && in.Hotel_name != "3" &&
				in.Hotel_name != "4" && in.Hotel_name != "Hotel Golden" && in.Hotel_name != "5" &&
				in.Hotel_name != "Hotel International" && in.Hotel_name != "6")
			{
				cout << "Invalid input enter hotel number" << endl;
				inp >> in.Hotel_name;
			}
			//	     ------------------------------  Function call ------------------------------
			in.Get_guest(in, inp, in.Budget);
		}
		else if (in.Budget > 6000) {
			cout << "These are avalaible" << endl;
			cout << "7 : Hotel vivanta" << endl;
			cout << "8 : Hotel mumtaz" << endl;
			cout << "9 : Hotel goop" << endl;
			cout << "10 : Hotel Tradition" << endl;
			cout << "11 : Hotel culture" << endl;
			cout << "12 : Hotel westcoat" << endl;
			cout << "13 : Hotel las vagas" << endl;
			cout << "14 : Hotel water" << endl;
			cout << "15 : Hotel Hell" << endl;

			inp >> in.Hotel_name;

			while (in.Hotel_name != " Hotel vivanta" && in.Hotel_name != "Hotel goop" && in.Hotel_name != "Hotel Tradition"
				&& in.Hotel_name != "Hotel culture4" && in.Hotel_name != "Hotel westcoat" && in.Hotel_name != " Hotel las vagas"
				&& in.Hotel_name != "Hotel International" && in.Hotel_name != "Hotel water" && in.Hotel_name != " Hotel Hell" &&
				in.Hotel_name != "7" && in.Hotel_name != "8" && in.Hotel_name != "9" && in.Hotel_name != "10" && in.Hotel_name != "11"
			&& in.Hotel_name != "12" && in.Hotel_name != "13" && in.Hotel_name != "14" && in.Hotel_name != "15")
			{
				cout << "Invalid input enter hotel number" << endl;
				inp >> in.Hotel_name;
			}

			//	     ------------------------------  Function call ------------------------------
			in.Get_guest(in, inp, in.Budget);
		}
	}
	else if (in.Filter == 1) {

		for (int i = 0; i < 15; i++) {
			int j = 1;
			cout << in.ALL_Hotels[i] << endl;
			j++;
		}

		cout << "choose one" << endl;
		inp >> in.Hotel_name;

		int a = 1, b = 1;
		while (b) {
			a = in.check(in);
			if (a == false) {
				cout << "invalid input" << endl;
				cout << "Re-enter your input" << endl;
				inp >> in.Hotel_name;
			}
			else
				b = 0;
		}

	}


	return inp;

}






























//   ---------------------  CLASS FOR FOOD -----------------------------
class Food {
private:
	int Chicken_briyani;
	int Mutton_briyani;
	int chickenblast_pizza;
	int veg_pizza;
	int Fish;
	int DalRoti;
	int Sabzi;
	int zahar_exclusively_avlaible;
	int water;
	int cold_drink;
	int REd_wine;
	int White_wine;
	int Champane;
	int icecream;

	string ALL_ITEMS[14] = { "Chicken_briyani","Mutton_briyani", "chickenblast_pizza","veg_pizza","Fish","DalRoti","Sabzi","zahar_exclusively_avlaible","water","cold_drink","White_wine","REd_wine","icecream","Champane" };

public:
	//			--------------------  CONSTRUCTIR FOR FOOD CLASS ---------------------
	Food(int Chicken_briyani, int Mutton_briyani, int chickenblast_pizza, int veg_pizza, int Fish, int DalRoti, int Sabzi, int zahar_exclusively_avlaible, int water, int cold_drink, int REd_wine, int White_wine, int Champane, int icecream);
	friend istream& operator >> (istream& inp, Food& in);
	void Food_call(Food& in);
};

//		......................  FOOD Call .....................
void Food::Food_call(Food& in)
{
	system("cls");
	int j = 1;
	for (int i = 0; i < 14; i++) {
		cout << j << " : " << in.ALL_ITEMS[i] << endl;
		j++;
	}

	while (true)
	{
		cout << "enter food number of foods u want to order.To finish order enter 0 " << endl;
		int choice, quantity;
		cin >> choice;

		if (choice > 0 && choice < 15) {
			cout << " enter quantiy of food " << endl;
			cin >> quantity;
			while (quantity == 0)
			{
				cout << "Quantity can't be negative" << endl;
				cout << "RE-enter your quantity or cancel enter order enter 0" << endl;
				cin >> quantity;
				if (quantity == 0)
					break;
			}

			switch (choice)
			{
			case 0:
				break;
			case 1:
				in.Chicken_briyani = quantity;
				break;
			case 2:
				in.Mutton_briyani = quantity;
				break;
			case 3:
				in.chickenblast_pizza = quantity;
				break;
			case 4:
				in.veg_pizza = quantity;
				break;
			case 5:
				in.Fish = quantity;
				break;
			case 6:
				in.DalRoti = quantity;
				break;
			case 7:
				in.Sabzi = quantity;
				break;
			case 8:
				in.zahar_exclusively_avlaible = quantity;
				break;
			case 9:
				in.water = quantity;
				break;
			case 10:
				in.cold_drink = quantity;
				break;
			case 11:
				in.White_wine = quantity;
				break;
			case 12:
				in.REd_wine = quantity;
				break;
			case 13:
				in.icecream = quantity;
				break;
			case 14:
				in.Champane = quantity;
				break;
				// default case.......
			default:
				cout << "invalid item number.Enter 0 to exit order" << endl;
				cout << "Or enter correct item number and quantity" << endl;
				break;
			}

		}
		else if (choice == 0)
			break;

		else {
			cout << "invalid input" << endl;
			cout << "RE-enter your input" << endl;
		}
	}
	cout << "order on its way" << endl;
}


//		...................... CONSTRUCTOR FOR FOOD CLASS  .....................

Food::Food(int Chicken_briyani = 0, int Mutton_briyani = 0, int chickenblast_pizza = 0, int veg_pizza = 0, int Fish = 0, int DalRoti = 0, int Sabzi = 0,
	int zahar_exclusively_avlaible = 0, int water = 0, int cold_drink = 0, int REd_wine = 0, int White_wine = 0, int Champane = 0, int icecream = 0)
{
	this->Chicken_briyani = Chicken_briyani;
	this->Mutton_briyani = Mutton_briyani;
	this->chickenblast_pizza = chickenblast_pizza;
	this->veg_pizza = veg_pizza;
	this->Fish = Fish;
	this->DalRoti = DalRoti;
	this->Sabzi = Sabzi;
	this->zahar_exclusively_avlaible = zahar_exclusively_avlaible;
	this->water = water;
	this->cold_drink = cold_drink;
	this->REd_wine = REd_wine;
	this->White_wine = White_wine;
	this->Champane = Champane;
	this->icecream = icecream;
}

//			..................  INPUT FUCTION FOR FOOD CLASS   ..........................
istream& operator >> (istream& inp, Food& in)
{
	int i;
	cout << "enter 1 if u want to order food.Otherwise 2" << endl;
	cin >> i;
	int j = 1;
	while (i != 1 && i != 2) {
		cout << "Invalid input " << endl;
		cout << "Re-enter your input" << endl;
		cin >> i;
	}
	if (i == 1)
		in.Food_call(in);
	 
	return inp;
}

//         ------------------------  MAIN FUNCTION --------------------------
int main()
{
	cout << "			---------------- WELCOME TO HOTEL FINDER  --------------" << endl;
	Booking Guest;
	cin >> Guest;
	int check = Guest.Return_value;

	if (check == 1) {
		Food Guest_1;
		cin >> Guest_1;
	}
	//system("cls");
	cout << Guest;

	Booking Guest2;
	cin >> Guest2;
	int check0 = Guest2.Return_value;

	if (check0 == 1) {
		Food Guest_2;
		cin >> Guest_2;
	}
	system("cls");
	cout << Guest2;


	return 0;
}
