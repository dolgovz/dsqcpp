/*  описаны тела функций, заголовки которых указаны в файле firm.h */
#include<iostream>
#include<fstream>
#include <ctime>
#include"Lots.h"
using namespace std;
void inputLot(Lots *lot) {
	do{
		cout<<"Enter lot name:";
		cin.getline(lot->lotName,25);	
		}
	while(isdigit(lot->lotName[0])); 
	cout<<"Enter price:";
	cin>>lot->price;
	getchar();
	cout<<"Enter seller name:";
	cin.getline(lot->seller,20);
	//DateTime Now
	time_t now = time(0);
    char* dt = ctime(&now);
	strcpy(lot->date, dt);
}

void printLots(Lots lots, int i) {
	cout<<i<<" Lot name: "<<lots.lotName<<" Price: "<<lots.price<<" Seller: "<<lots.seller<<" Date:"<<lots.date<<endl;
};

void addTofile(Lots lot) {
	ofstream f("lots.dev",ios::binary|ios::app);
	if(!f) {
		f.open("lots.dev",ios::binary);
	}
	f.write((char *)&lot,sizeof(Lots));
	f.close();
}

Lots * readFromFile(int *size) {
	ifstream f ("lots.dev",ios::binary);
	if(!f) {
		cout<<"Error with file\n";
		*size=0;
		return NULL;
	} else {
		f.seekg(0,ios::end);
		*size=f.tellg()/sizeof(Lots);
		f.seekg(0,ios::beg);
		Lots *lots=new Lots[*size];
		f.read((char *)lots,*size*sizeof(Lots));
		f.close();
		return lots;
	}
}

