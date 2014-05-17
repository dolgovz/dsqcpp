/*  описаны тела функций, заголовки которых указаны в файле firm.h */
#include<iostream>
#include<fstream>
#include <ctime>
#include"Lots.h"
using namespace std;
void inputLot(Lots *lot) {
char d[25];
bool flag = false;
	do{
		cout<<"Enter lot name:"<<endl;
		cin.getline(lot->lotName,25);
		if (isdigit(lot->lotName[0])){
			cout<<"First symbol must be a letter\n";
		}
	}
	while(isdigit(lot->lotName[0])); 

	do{
		cout<<"Enter price:";
		cin.getline(d,25);
		for (int i=0; i<strlen(d); i++){
			if (isdigit(d[i])){
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag){
			int n = atoi(d);
			lot->price = n;
		}
	} while(!flag);

	do{
		cout<<"Enter seller name:";
		cin.getline(lot->seller,20);
		if(isdigit(lot->seller[0])){
			cout<<"First symbol must be a letter\n";
		}
	}
	while(isdigit(lot->seller[0]));
	
	//DateTime Now
	time_t now = time(0);
    char* dt = ctime(&now);
	strcpy(lot->date, dt);
}

void inputSeller(Sellers * seller){
	cout<<"Enter seller name:"<<endl;
	cin.getline(seller->name, 25);
	
	cout<<"Enter seller lastname:";
	cin.getline(seller->lastName, 25);

	cout<<"Enter seller phone number:";
	cin>>seller->phone;
		getchar();
	cout<<"Enter seller mail:";
	cin.getline(seller->mail, 30);
}

void printLots(Lots lots, int i) {
	cout<<i<<" Lot name: "<<lots.lotName<<" Price: "<<lots.price<<" Seller: "<<lots.seller<<" Date:"<<lots.date<<endl;
};

void printSellers(Sellers sellers, int i) {
	cout<<i<<" Name: "<<sellers.name<<" Lastname: "<<sellers.lastName<<" Phone: "<<sellers.phone<<" Mail: "<<sellers.mail<<endl;
};

void addToFileLot(Lots lot) {
	ofstream f("lots.dev",ios::binary|ios::app);
	if(!f) {
		f.open("lots.dev",ios::binary);
	}
	f.write((char *)&lot,sizeof(Lots));
	f.close();
}

void addToFileSeller(Sellers seller){
	ofstream f("sellers.dev",ios::binary|ios::app);
	if(!f){
	f.open("sellers.dev",ios::binary);	
	}
	f.write((char *)&seller,sizeof(Sellers));
	f.close();
}

Lots * readFromFileLots(int *size) {
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

Sellers * readFromFileSellers(int *size){
	ifstream f ("sellers.dev", ios::binary);
	if (!f){
		cout<<"Error with file\n";
		*size=0;
		return NULL;
	}
	else {
	f.seekg(0,ios::end);
	*size=f.tellg()/sizeof(Sellers);
	f.seekg(0,ios::beg);
	Sellers *sellers=new Sellers[*size];
	f.read((char *)sellers,*size*sizeof(Sellers));
	f.close();
	return sellers;
	
	}
		

}


void deleteFromFile(){
	int size;
	ifstream f ("lots.dev",ios::binary);
	if(!f) {
		cout<<"Error with file\n";
		size=0;
	} else {
		f.seekg(0,ios::end);
		size=f.tellg()/sizeof(Lots);
	}
	f.close();
	
	int n;
	Lots *lots=new Lots[size];
	
	do {
		cout<<"Enter lot number:";
	    cin>>n;
	} while(n-1>=size || n-1<0);

	
	lots = readFromFileLots(&size);
	ofstream g("lots.dev",ios::binary);
	for (int i = 0; i < size; i++) {
		if(i != n-1) {
			g.write((char *)&lots[i],sizeof(Lots));
		}
	}
	g.close();
}


