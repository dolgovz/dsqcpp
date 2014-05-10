/* заголовочный файл
описание типов
и заголовки функций*/

struct Lots {
	char lotName[25];
	float price;
	char seller[20];
	char date[20];
};

void inputLot(Lots * lot);
void printLots(Lots lot,int i);
void addTofile(Lots lot);
//void deleteFromFile(Lots lot, int i,int *size);
Lots * readFromFile(int *size);

