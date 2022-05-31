#include <iostream>
#include <string>

#define clear() system("cls")

using namespace std;

struct shoes
{
	char color;
	int size;
};
struct seller
{
	string name;
	int age;
};
struct shop
{
	string nameshop;
	string addressshop;
	seller salesman;
	shoes pair;
};

shop* createShops(int size)
{
	shop* shops = new shop[size];
	return shops;
}
void fillingShoe(shoes shoe)
{
	cout << "Enter seller name: ";
	cin>>shoe.color;
	cout << "Enter seller's age: ";
	cin >> shoe.size;
}
void fillingSeller(seller salesman)
{
	cout << "Enter seller name: ";
	getline(cin,salesman.name);
	cout << "Enter seller's age: ";
	cin >> salesman.age;
}
void fillingShops(int size, shop shop)
{
	cout << "Enter name shop: ";
	getline(cin, shop.nameshop);
	cout << "Enter address shop: ";
	getline(cin, shop.addressshop);
	fillingSeller(shop.salesman);
	fillingShoe(shop.pair);
}

int main()
{
	int size = 0;
	cout << "Enter number of shops: ";
	cin >> size;
	clear();
	shop* shops = createShops(size);

	delete[] shops;
	return 0;
}