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
		cout<<"MENU:\n1)Add LOT to file\n2)Add SELLER to file\n3)Read from LOTS file\n4)search LOTS\n5)Read from SELLERS file\n6)search SELLERs\n7)Delete from LOTS file\n8)Delete from SELLERS file\n9)Exit\n";


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
			char yn[25];
			do {
				cout<<"do you want to add seller(y/n):";
				cin.getline(yn,25);
			}while(yn[0] != 'y' || yn[0] !='n' || strlen(yn)>1);
			

			system("PAUSE");
			break;
		case 4:
			lots = readFromFileLots(&size);
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
		case 5: 
			sellers = readFromFileSellers(&size);
			for(int i=0; i<size; i++){
				printSellers(sellers[i], i+1);
			}
			system("PAUSE");
			break;
		case 6:
			break;
		case 7: 
			lots = readFromFileLots(&size);
			for(int i=0; i<size ; i++) {
				printLots(lots[i], i+1);
			}
			deleteFromFileLots();
			system("PAUSE");
			break;
		case 8: sellers = readFromFileSellers(&size);
			for(int i=0; i<size; i++){
				printSellers(sellers[i], i+1);
			}
			deleteFromFileSellers();
			system("PAUSE");
			break;
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