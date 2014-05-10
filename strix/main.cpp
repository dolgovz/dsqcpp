#include "Lots.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	Lots lot;
	Lots *lots;
	int size;
	int choice;
	do {
		system("cls");
		cout<<"ENU:\n1)Add to file\n2)Read from file\n3)Delete from file\n4)Exit\n";
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

			case 3: cout<<"Enter lot number:";

						break;



			case 4: cout<<"bye bye!\n";
			

		}
	}
	while(choice!=3);

	system("PAUSE");
	return 0;
}