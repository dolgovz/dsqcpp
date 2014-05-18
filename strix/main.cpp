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

		cout<<"--- LOTS MENU ---\n1)Add LOT to file\n2)Read LOTS from file\n3)Search LOT\n4)Delete LOT from file\n--- SELLERS MENU ---\n5)Add SELLER to file\n6)Read SELLERS from file\n7)Search SELLER\n8)Delete SELLER from file\n9)Exit\n";


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
			//1)Add LOT to file
		case 1: Lots lot;
			inputLot(&lot);
			addToFileLot(lot);
			system("PAUSE");
			break;

			//2)Read from LOTS file
		case 2:
			lots = readFromFileLots(&size);
			lotsTablePrint();
			for(int i=0; i<size ; i++) {
				printLots(lots[i], i+1);
			}
			char yn[25];
			do {
				cout<<"do you want to add seller(y/n):";
				cin.getline(yn,25);
			}while((yn[0] != 'y' && yn[0] !='n') || strlen(yn)>1);

			if (yn[0] == 'y') {
				lots = readFromFileLots(&size);
				int lotsSize = size;
				char d[25];
				int sellerNumber;
				int lotNumber;
				char text[25] = "\nChoose Lot number: ";
				lotNumber = chooseNumberValidation(d,flag,lotsSize);

				sellers = readFromFileSellers(&size);
				int sellerSize = size;
				sellersTablePrint();
				if (sellerSize < 1){
					do {
						cout<<"Firstly you have to add seller.\nDo you want to do it now? y/n";
						cin.getline(yn,25);
					}
					while((yn[0] != 'y' && yn[0] !='n') || strlen(yn)>1);
					if (yn[0] == 'y') {
						Sellers seller;
						inputSeller(&seller);
						addToFileSeller(seller);
						sellers = readFromFileSellers(&size);
						int sellerSize = size;
						sellersTablePrint();
						for(int i=0; i<size; i++){
							printSellers(sellers[i], i+1);
						}
						sellerNumber = chooseNumberValidation(d,flag,sellerSize);
					strcpy(lots[lotNumber-1].seller,sellers[sellerNumber-1].date);
					ofstream f("lots.dev",ios::binary);
					if(!f) {
						f.open("lots.dev",ios::binary);
					}
					for(int i = 0; i<lotsSize ; i++){
						f.write((char *)&lots[i],sizeof(Lots));
					}

					f.close();
						system("PAUSE");
						break;
					}

				} else {
					for(int i=0; i<sellerSize ; i++) {
						printSellers(sellers[i], i+1);
					}
					sellerNumber = chooseNumberValidation(d,flag,sellerSize);
					strcpy(lots[lotNumber-1].seller,sellers[sellerNumber-1].date);
					ofstream f("lots.dev",ios::binary);
					if(!f) {
						f.open("lots.dev",ios::binary);
					}
					for(int i = 0; i<lotsSize ; i++){
						f.write((char *)&lots[i],sizeof(Lots));
					}

					f.close();
				}
			} 

			system("PAUSE");
			break;
			//3)Search LOTS
		case 3:
			lots = readFromFileLots(&size);
			lotsTablePrint();
			for(int i=0; i<size ; i++) {
				printLots(lots[i], i+1);
			}
			cout<<"Choose your category:\n 1)lot name 2)price 3)seller 4)date"<<endl;
			int chooseSearch;
			char searchText[25];
			cin>>chooseSearch;
			getchar();
			switch(chooseSearch) {
			case 1:
				cout<<"Enter search lot name: ";
				cin.getline(searchText,25);
				lotsTablePrint();
				for(int i=0; i<size ; i++) {
					bool g = strstr(lots[i].lotName,searchText);
					if(g) {
						printLots(lots[i], i+1);
					}
				}	
				system("PAUSE");
				break;
			case 2:
				cout<<"Enter search price: ";
				cin.getline(searchText,25);
				lotsTablePrint();
				for(int i=0; i<size ; i++) {
					char str[25];
					bool g = strstr(itoa(lots[i].price, str, 10),searchText);
					if(g) {
						printLots(lots[i], i+1);
					}
				}	
				system("PAUSE");
				break;
			case 3:
				cout<<"Enter seller name: ";
				cin.getline(searchText,25);
				lotsTablePrint();
				for(int i=0; i<size ; i++) {
					char str[25];
					bool g = strstr(lots[i].seller,searchText);
					if(g) {
						printLots(lots[i], i+1);
					}
				}	
				system("PAUSE");
				break;
			case 4:
				cout<<"Enter date: ";
				cin.getline(searchText,25);
				lotsTablePrint();
				for(int i=0; i<size ; i++) {
					char str[25];
					bool g = strstr(lots[i].date,searchText);
					if(g) {
						printLots(lots[i], i+1);
					}
				}
				system("PAUSE");
				break;

			}
			break;

			//4)Delete from LOTS file
		case 4: 
			lots = readFromFileLots(&size);
			lotsTablePrint();
			for(int i=0; i<size ; i++) {
				printLots(lots[i], i+1);
			}
			deleteFromFileLots();
			system("PAUSE");
			break;


			//5)Add SELLER to file
		case 5: Sellers seller;
			inputSeller(&seller);
			addToFileSeller(seller);
			system("PAUSE");
			break;

			//6)Read from SELLERS file
		case 6: 
			sellers = readFromFileSellers(&size);
			sellersTablePrint();
			for(int i=0; i<size; i++){
				printSellers(sellers[i], i+1);
			}
			system("PAUSE");
			break;
			//7)Search SELLERS
		case 7:
			break;

			//8)Delete from SELLERS file
		case 8: sellers = readFromFileSellers(&size);
			for(int i=0; i<size; i++){
				printSellers(sellers[i], i+1);
			}
			deleteFromFileSellers();
			system("PAUSE");
			break;
			//9)Exit
		case 9: cout<<"bye bye!\n";
			return 0;
			break;
		default: cout<<"Incorrect number, try again!";
		}

	} 
	while(choose!=9);

	system("PAUSE");
	return 0;
}