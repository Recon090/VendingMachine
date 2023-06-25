#include <iostream>

/* Header file for struct of vending machine item
*/

struct products {
	std::string drinkName;
	float price;
	int itemNumber;
	int quantity;
};
class vendingMachine {
	int managerId;
	//input money function
	float inputMoney(int c) {//takes in user choice
		float inputtedMoney;
		std::cout << "\nYou selected: " << drinks[c - 1].drinkName;
		do {
			cout << "\nPlease input $" << drinks[c - 1].price << ": "; //verifies the user inputs at mininum the amount of money needed for the drink
			cin >> inputtedMoney;
		} while (inputtedMoney < drinks[c - 1].price);
		return inputtedMoney;//returns the money the user inputted
	}
	void dailyReport() {//daily report function
		float totalAmountMade = 0;
		for (int i = 0; i < 5; i++) {//for loop goes through the report of each drink and how many were sold
			cout << left << setw(20) << "\nDrink: " + drinks[i].drinkName << setw(10) << "\nNumber of drinks sold: " << 20 - drinks[i].numAvailable;
			totalAmountMade += ((20.0 - drinks[i].numAvailable) * drinks[i].price);
		}
		cout << "\nTotal money collected: $" << totalAmountMade;//ends off by stating how much money made that day
	}


public:
	products items[9];//initalize the array with drinks

	void displayChoices() {//displays the vending machine screen
		cout << left << setw(10) << "\nDrink Name" << right << setw(14) << "Cost" << setw(23) << "Number in Machine"

			<< endl << left << setw(20) << "1 " + drinks[0].drinkName << setw(10) << drinks[0].price << setw(10) << drinks[0].numAvailable
			<< endl << left << setw(20) << "2 " + drinks[1].drinkName << setw(10) << drinks[1].price << setw(10) << drinks[1].numAvailable
			<< endl << left << setw(20) << "3 " + drinks[2].drinkName << setw(10) << drinks[2].price << setw(10) << drinks[2].numAvailable
			<< endl << left << setw(20) << "4 " + drinks[3].drinkName << setw(10) << drinks[3].price << setw(10) << drinks[3].numAvailable
			<< endl << left << setw(20) << "5 " + drinks[4].drinkName << setw(10) << drinks[4].price << setw(10) << drinks[4].numAvailable;
	}

	void buyDrink(int c) {//the function that processes the verifying, buying, and updating of the machine, parameter represents user choice
		char confirm;//variable used to confirm 
		float moneyTaken = inputMoney(c);//calls function to take users money
		cout << "\nEnter c to confirm purchase, enter anything else to cancel: ";//allows user to back out at the last second
		cin >> confirm;
		if (confirm == 'c' || confirm == 'C') {
			if (drinks[c - 1].numAvailable == 0) {//checks if the drink is available and outputs if its not
				cout << "\nSOLD OUT, here is $" << moneyTaken << " back have a good day";
			}
			else {
				drinks[c - 1].numAvailable--;//deducts number of drinks available for what the user selected
				moneyTaken -= drinks[c - 1].price;//takes users money
				moneyTaken == 0 ? cout << "Here is 1 " << drinks[c - 1].drinkName << " have a good day!" :
					cout << "Here is 1 " << drinks[c - 1].drinkName << " and $" << moneyTaken << " back and have a good day!"; //ternary operator which will see if the user has any change
				//if the user has no change, message is outputted just saying drink, 
				//if user has change, message outputts along wtih change message
			}
		}
		else {
			cout << "\nPurchase canceled, here is $" << moneyTaken << " back have a good day"; //if user cancels message of cancellation and money given back is said
		}
	}
	~DrinkingMachine() {//destructor that is called when class is destroyed, calls daily report
		cout << fixed << showpoint << setprecision(2);//sets standard output to what we want
		dailyReport();
	}

};