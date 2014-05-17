//---//
struct Lots {
	char lotName[25];
	float price;
	char seller[20];
	char date[20];
};

struct Sellers {
	char name[25];
	char lastName[25];
	int phone;
	char mail[30];
};

void inputLot(Lots * lot);
void inputSeller(Sellers * seller);
void printLots(Lots lot,int i);
void printSellers(Sellers sellers, int i);
void addToFileLot(Lots lot);
void addToFileSeller(Sellers seller);
void deleteFromFile();
Lots * readFromFileLots(int *size);
Sellers * readFromFileSellers(int *size);

