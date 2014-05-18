//---//
#include<iostream>
#include<fstream>
#include <ctime>
#include <iomanip>
using namespace std;
struct Lots {
	char lotName[50];
	int price;
	char seller[20];
	char date[20];
};

struct Sellers {
	char name[25];
	char lastName[25];
	int phone;
	char mail[30];
	char date[20];
};
void rewriteLot(Lots lot);
void lotsTablePrint();
void sellersTablePrint();
int chooseNumberValidation(char *d,bool flag,int size);
void inputLot(Lots * lot);
void inputSeller(Sellers * seller);
void printLots(Lots lot,int i);
void printSellers(Sellers sellers, int i);
void addToFileLot(Lots lot);
void addToFileSeller(Sellers seller);
void deleteFromFileLots();
void deleteFromFileSellers();
Lots * readFromFileLots(int *size);
Sellers * readFromFileSellers(int *size);

