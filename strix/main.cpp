#include "Lots.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	Lots lot;
	Lots *lots;
	int size;
	int choice;
	int n;
	do {
		system("cls");
		cout<<"MENU:\n1)Add to file\n2)Read from file\n3)Delete from file\n4)Exit\n";
		cout<<"Enter your choice> ";
		cin>>choice;
		getchar();
		
		switch(choice) {
			case 1: Lots lot;
				inputLot(&lot);
				addTofile(lot);
				system("PAUSE");
				break;
			case 2:
				lots = readFromFile(&size);
				for(int i=0; i<size ; i++) {
					printLots(lots[i], i+1);
				}
				system("PAUSE");
				break;

			case 3: 
				lots = readFromFile(&size);
				for(int i=0; i<size ; i++) {
					printLots(lots[i], i+1);
				}
				deleteFromFile();
				system("PAUSE");
						break;

			case 4: cout<<"bye bye!\n";

			break;


		}
	}
	while(choice!=4);

	system("PAUSE");
	return 0;
}