#include"Lots.h"
bool flag = false;
void inputLot(Lots *lot) {
	char d[25];
	do{
		cout<<"Enter lot name:"<<endl;
		cin.getline(lot->lotName,50);
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

	strcpy(lot->seller, "#");

	//DateTime Now
	time_t now = time(0);
	char* dt = ctime(&now);
	strftime(dt, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
	strcpy(lot->date, dt);
}


void inputSeller(Sellers * seller){

	do{
		cout<<"Enter seller name:"<<endl;
		cin.getline(seller->name,25);
		for (int i=0; i<strlen(seller->name); i++){
			if (!isdigit(seller->name[i])){
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}

	} while(!flag);

	do{
		cout<<"Enter seller lastname:";
		cin.getline(seller->lastName,25);
		for (int i=0; i<strlen(seller->lastName); i++){
			if (!isdigit(seller->lastName[i])){
				flag = true;
			}
			else {
				flag = false;
				break;
			}
		}

	} while(!flag);

	do{
		char d[25];
		cout<<"Enter seller phone number:";
		cin.getline(d,25);
		if(strlen(d)==8 && d[0]=='2') {
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
				seller->phone = n;
			}
		} else {
			flag = false;
		}

	} while(!flag);

	cout<<"Enter seller mail:";
	cin.getline(seller->mail, 30);

	//DateTime Now
	time_t now = time(0);
	char* dt = ctime(&now);
	strftime(dt, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
	strcpy(seller->date, dt);
}
void lotsTablePrint() {
			cout <<setw(4);
			cout<<"Id|";
			cout <<setw(9);
			cout<<"Lot name|";
			cout <<setw(10);
			cout<<"Price|";
			cout <<setw(10);
			cout<<"Seller|";
			cout <<setw(30);
			cout<<"Date\n";
			cout<<"---------------------------------------------------------------\n";
}
void sellersTablePrint() {
			cout <<setw(4);
			cout<<"Id|";
			cout <<setw(10);
			cout<<"Name|";
			cout <<setw(10);
			cout<<"Surname|";
			cout <<setw(10);
			cout<<"Phone|";
			cout <<setw(18);
			cout<<"Email|";
			cout <<setw(12);
			cout<<"Lot Name|\n";
			cout<<"---------------------------------------------------------------\n";
}
void printLots(Lots lots, int i) {
	int size;
	char sellerName[25] = "";
	Sellers *sellers = readFromFileSellers(&size);
	for (int i = 0; i<size; i++) {
		char *g = strstr(sellers[i].date,lots.seller);
		if (g) {
			strcpy(sellerName,sellers[i].name);
		}
	}
		    cout <<setw(3);
			cout<<i<<"|";
			cout <<setw(9);
			cout<<lots.lotName<<"|";
			cout <<setw(9);
			cout<<lots.price<<"|";
			cout <<setw(9);
			cout<<sellerName<<"|";
			cout <<setw(30);
			cout<<lots.date<<endl;
};

void printSellers(Sellers sellers, int i) {

		int size;
	   char lotName[25] = "";
	Lots *lots = readFromFileLots(&size);
	for (int i = 0; i<size; i++) {
		char *g = strstr(lots[i].seller,sellers.date);
		if (g) {
			strcpy(lotName,lots[i].lotName);
		}
	}

			cout <<setw(3);
			cout<<i<<"|";
			cout <<setw(9);
			cout<<sellers.name<<"|";
			cout <<setw(9);
			cout<<sellers.lastName<<"|";
			cout <<setw(9);
			cout<<sellers.phone<<"|";
			cout <<setw(17);
			cout<<sellers.mail<<"|";
			cout <<setw(11);
			cout<<lotName<<endl;


};
int chooseNumberValidation(char *d,bool flag,int size) {
	int number;
	do{
		cout<<"\nChoose number: ";
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
			if (n<=size&&n>0) {
				flag = true;
				number = n;
			} else {
				flag = false;
			}
		}
	} while(!flag);
	return number;
}


void addToFileLot(Lots lot) {
	ofstream f("lots.dev",ios::binary|ios::app);
	if(!f) {
		f.open("lots.dev",ios::binary);
	}
	f.write((char *)&lot,sizeof(Lots));
	f.close();
}
void rewriteLot(Lots lot) {
	ofstream f("lots.dev",ios::binary);
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


void deleteFromFileLots(){
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

void deleteFromFileSellers(){
	int size;
	ifstream f ("sellers.dev",ios::binary);
	if(!f) {
		cout<<"Error with file\n";
		size=0;
	} else {
		f.seekg(0,ios::end);
		size=f.tellg()/sizeof(Sellers);
	}
	f.close();
	int n;
	Sellers *sellers=new Sellers[size];

	do {
		cout<<"Enter seller number:";
		cin>>n;
	} while(n-1>=size || n-1<0);


	sellers = readFromFileSellers(&size);
	ofstream g("sellers.dev",ios::binary);
	for (int i = 0; i < size; i++) {
		if(i != n-1) {
			g.write((char *)&sellers[i],sizeof(Sellers));
		}
	}
	g.close();
}

void sortCompareLots(int size, Lots *lots, int choose,int sortWay) {
	char **lotsCat = new char*[size];
	int *lotsCatInt = new int[size];
	Sellers *sellers;
	int superSize;
	bool condition;
	switch(choose) {
	case 1:
		for (int i = 0; i<size ; i++) {
			lotsCat[i] = new char[25];
			strcpy(lotsCat[i],lots[i].lotName);	
			 for(int j = 0; j<25; j++) {
				 lotsCat[i][j] = tolower(lotsCat[i][j]);
			 }
		}
		break;
	case 2:
		for (int i = 0; i<size ; i++) {
			lotsCat[i] = new char[25];
			lotsCatInt[i] = lots[i].price;	
			strcpy(lotsCat[i],"");	
		}
		break;
	case 3:
		sellers = readFromFileSellers(&superSize);

		for (int i = 0; i<size ; i++) {
			lotsCat[i] = new char[25];	
			for(int j = 0;j<superSize;j++){
				char *g = strstr(lots[i].seller,sellers[j].date);
				if (g) {
					strcpy(lotsCat[i],sellers[j].name);
					break;
				} else {
					strcpy(lotsCat[i],"~");
				}
			}
			for(int j = 0; j<25; j++) {
				lotsCat[i][j] = tolower(lotsCat[i][j]);
			}
		}
		
		break;
	case 4:
		for (int i = 0; i<size ; i++) {
			lotsCat[i] = new char[25];
			strcpy(lotsCat[i],lots[i].date);	
			 for(int j = 0; j<25; j++) {
				 lotsCat[i][j] = tolower(lotsCat[i][j]);
			 }
		}
		break;	
	}

	for(int i = 0; i < size - 1; i++){
		for(int j = i + 1; j < size; j++){
			if (choose == 2) {
				if (sortWay == 1) {
					condition = lotsCatInt[i] > lotsCatInt[j];
				} else {
					condition = lotsCatInt[i] < lotsCatInt[j];
				}
			} else {
				if (sortWay == 1) {
					condition = strcmp(lotsCat[i], lotsCat[j]) > 0;
				} else {
					condition = strcmp(lotsCat[i], lotsCat[j]) < 0;
				}
			}
			if(condition){
				Lots temp;
				int tempInt;
				char tempChar[25];

				strcpy(temp.lotName,lots[i].lotName);
				temp.price=lots[i].price;
				strcpy(temp.seller,lots[i].seller);
				strcpy(temp.date,lots[i].date);
				tempInt = lotsCatInt[i];
				strcpy(tempChar,lotsCat[i]);

				strcpy(lots[i].lotName,lots[j].lotName);
				lots[i].price=lots[j].price;
				strcpy(lots[i].seller,lots[j].seller);
				strcpy(lots[i].date,lots[j].date);
				lotsCatInt[i] = lotsCatInt[j];
				strcpy(lotsCat[i],lotsCat[j]);

				strcpy(lots[j].lotName,temp.lotName); 
				lots[j].price=temp.price;
				strcpy(lots[j].seller,temp.seller); 
				strcpy(lots[j].date,temp.date); 
				lotsCatInt[j] = tempInt;
				strcpy(lotsCat[j],tempChar);
			}
		}
	}

	lotsTablePrint();
	for(int i=0; i<size ; i++) {
		printLots(lots[i], i+1);
	}
}
void sortCompareSellers(int size, Sellers *sellers, int choose,int sortWay) {
	char **sellersCat = new char*[size];
	int *sellersCatInt = new int[size];
	bool condition;
	switch(choose) {
	case 1:
		for (int i = 0; i<size ; i++) {
			sellersCat[i] = new char[25];
			strcpy(sellersCat[i],sellers[i].name);	
			 for(int j = 0; j<25; j++) {
				 sellersCat[i][j] = tolower(sellersCat[i][j]);
			 }
		}
		break;
	case 2:
		for (int i = 0; i<size ; i++) {
			sellersCat[i] = new char[25];
			strcpy(sellersCat[i],sellers[i].lastName);	
			 for(int j = 0; j<25; j++) {
				 sellersCat[i][j] = tolower(sellersCat[i][j]);
			 }
		}
		break;
	case 3:
		for (int i = 0; i<size ; i++) {
			sellersCat[i] = new char[25];
			sellersCatInt[i] = sellers[i].phone;	
			strcpy(sellersCat[i],"");	
		}
		break;	
	case 4:
		for (int i = 0; i<size ; i++) {
			sellersCat[i] = new char[25];
			strcpy(sellersCat[i],sellers[i].mail);	
			 for(int j = 0; j<25; j++) {
				 sellersCat[i][j] = tolower(sellersCat[i][j]);
			 }
		}
		break;	
	
	}
	for(int i=0; i<size ; i++) {
		cout<<sellersCat[i]<<endl;
	}
	for(int i = 0; i < size - 1; i++){
		for(int j = i + 1; j < size; j++){
			if (choose == 3) {
				if (sortWay == 1) {
					condition = sellersCatInt[i] > sellersCatInt[j];
				} else {
					condition = sellersCatInt[i] < sellersCatInt[j];
				}
			} else {
				if (sortWay == 1) {
					condition = strcmp(sellersCat[i], sellersCat[j]) > 0;
				} else {
					condition = strcmp(sellersCat[i], sellersCat[j]) < 0;
				}
			}
			if(condition){
				Sellers temp;
				int tempInt;
				char tempChar[25];

				strcpy(temp.name,sellers[i].name);
				strcpy(temp.lastName,sellers[i].lastName);
				temp.phone = sellers[i].phone;
				strcpy(temp.mail,sellers[i].mail);
				strcpy(temp.date,sellers[i].date);
				tempInt = sellersCatInt[i];
				strcpy(tempChar,sellersCat[i]);

				strcpy(sellers[i].name,sellers[j].name);
				strcpy(sellers[i].lastName,sellers[j].lastName);
				sellers[i].phone = sellers[j].phone;
				strcpy(sellers[i].mail,sellers[j].mail);
				strcpy(sellers[i].date,sellers[j].date);
				sellersCatInt[i] = sellersCatInt[j];
				strcpy(sellersCat[i],sellersCat[j]);

				strcpy(sellers[j].name,temp.name);
				strcpy(sellers[j].lastName,temp.lastName);
				sellers[j].phone = temp.phone;
				strcpy(sellers[j].mail,temp.mail);
				strcpy(sellers[j].date,temp.date);
				sellersCatInt[j] = tempInt;
				strcpy(sellersCat[j],tempChar);
			}
		}
	}

	sellersTablePrint();
	for(int i=0; i<size ; i++) {
		printSellers(sellers[i], i+1);
	}
}

