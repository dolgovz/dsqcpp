#include "Lots.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	Lots lot;
	Lots *lots;
	Sellers seller;
	Sellers *sellers;

	int size;
	int choose;
	int n;
	char gh[25];
	bool flag = false;

	do {
		system("cls");
		cout<<"MENU:\n1)Add LOT to file\n2)Add SELLER to file\n3)Read from LOTS file\n4)Read from SELLERS file\n5)Delete from file\n6)Exit\n";


		do {
			cout<<"Enter your choose> ";
			cin.getline(gh,25);
			for (int i=0; i<strlen(gh); i++){
				if (isdigit(gh[i])){
					flag = true;
				} else {
					flag = false;
					break;
				}
			}
			if (flag){
				int n = atoi(gh);
				choose = n;
			}
		} while(!flag);	


		switch(choose) {

		case 1: Lots lot;
			inputLot(&lot);
			addToFileLot(lot);
			system("PAUSE");
			break;
		case 2: Sellers seller;
			inputSeller(&seller);
			addToFileSeller(seller);
			system("PAUSE");
			break;
		case 3:
			lots = readFromFileLots(&size);
			for(int i=0; i<size ; i++) {
				printLots(lots[i], i+1);
			}
			system("PAUSE");
			break;

		case 4: 
			sellers = readFromFileSellers(&size);
			for(int i=0; i<size; i++){
				printSellers(sellers[i], i+1);
			}
			system("PAUSE");
			break;

		case 5: 
			lots = readFromFileLots(&size);
			for(int i=0; i<size ; i++) {
				printLots(lots[i], i+1);
			}
			deleteFromFile();
			system("PAUSE");
			break;

		case 6: cout<<"bye bye!\n";
			return 0;
			break;
		default: cout<<"Incorrect number, try again!";
		}

	} 
	while(choose!=5);

	system("PAUSE");
	return 0;
}