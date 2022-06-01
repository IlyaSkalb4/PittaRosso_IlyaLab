#include <iostream>
#include <string>

#define clear() system("cls")

using namespace std;

struct shoes
{
	string name;
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
	string name;
	string address;
	seller* salesman;
	shoes* pair;
};

void removeShops(shop* shops)
{
	delete[] shops->pair;
	delete[] shops->salesman;
	delete[] shops;
}
shop* creatShops(int amountshops,int amountshoes,int amountseller)
{
	shop* shops = new shop[amountshops];
	shops->pair = new shoes[amountshoes];
	shops->salesman = new seller[amountseller];
	clear();
	return shops;
}

string colorShoe(char color)
{
	string colorstr;
	switch (color)
	{
	case '0':
	{
		colorstr = "black";
	}break;
	case '1':
	{
		colorstr = "blue";
	}break;
	case '2':
	{
		colorstr = "green";
	}break;
	case '3':
	{
		colorstr = "cyan";
	}break;
	case '4':
	{
		colorstr = "red";
	}break;
	case '5':
	{
		colorstr = "purple";
	}break;
	case '6':
	{
		colorstr = "yellow";
	}break;
	case '7':
	{
		colorstr = "white";
	}break;
	case '8':
	{
		colorstr = "grey";
	}break;
	case '9':
	{
		colorstr = "light blue";
	}break;
	case 'a':
	{
		colorstr = "light green";
	}break;
	case 'b':
	{
		colorstr = "light cyan";
	}break;
	case 'c':
	{
		colorstr = "light red";
	}break;
	case 'd':
	{
		colorstr = "light purple";
	}break;
	case 'e':
	{
		colorstr = "light yellow";
	}break;
	case 'f':
	{
		colorstr = "pure white";
	}break;

	default:
	{
		colorstr = "#Not color";
	}
	}
	return colorstr;
}

void fillingShoe(shoes& shoe)
{
	cout << "Enter shoes name: ";
	cin >> shoe.name;
	cout << "Enter shoes size: ";
	cin >> shoe.size;
	clear();
	cout << "0 = black,\n1 = blue,\n2 = green,\n3 = cyan,\n4 = red,\n5 = purple,\n6 = yellow,\n7 - white,\n";
	cout << "8 = grey,\n9 = light blue,\na = light green,\nb = light cyan,\nc = light red,\n";
	cout << "d = light purple,\ne = light yellow,\nf = pure white\n";
	cout << "Enter shoes clolor: ";
	cin >> shoe.color;
}
shoes* fillingShoes(shoes* shoes, int size)
{
	for (int i = 0; i < size; i++)
	{
		fillingShoe(shoes[i]);
	}
	return shoes;
}
void fillingSeller(seller& salesman)
{
	cout << "Enter seller name: ";
	cin >> salesman.name;
	cout << "Enter seller's age: ";
	cin >> salesman.age;
}
seller* fillingSellers(seller* salesmans, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin.ignore();
		fillingSeller(salesmans[i]);
	}
	return salesmans;
}
void fillingShop(shop& shop, int sizeseller, int sizeshoes)
{
	cout << "Enter name shop: ";
	cin >> shop.name;
	cout << "Enter address shop: ";
	cin >> shop.address;
	shop.salesman = fillingSellers(shop.salesman, sizeseller);
	shop.pair = fillingShoes(shop.pair, sizeshoes);
}
shop* fillingShops(shop* shops, int size, int sizeseller,int sizeshoes)
{
	for (int i = 0; i < size; i++)
	{
		fillingShop(shops[i], sizeseller, sizeshoes);
	}
	return shops;
}

void outputShoe(shoes shoe)
{
	string color;
	cout << "Name shou: " << shoe.name;
	cout << "\tSize shou: " << shoe.size << "\t";
	color = colorShoe(shoe.color);
	cout << "Color: " << color;
	cout << endl;
}
void outputShoes(shoes* shoes, int size)
{
	for (int i = 0; i < size; i++)
	{
		outputShoe(shoes[i]);
	}
}
void outputSeller(seller salesman)
{
	cout << "Name salesman: " << salesman.name;
	cout << "\tAge salesman: " << salesman.age << endl;
}
void outputSellers(seller* salesman, int size)
{
	for (int i = 0; i < size; i++)
	{
		outputSeller(salesman[i]);
	}
}
void outputShop(shop shop, int sizeseller, int sizeshoes)
{
	cout << "Name shop: " << shop.name;
	cout << "\nAddress shop: " << shop.address << endl;
	outputSellers(shop.salesman, sizeseller);
	outputShoes(shop.pair, sizeshoes);
	cout << endl;
}
void outputShops(shop* shops, int size, int sizeseller, int sizeshoes)
{
	clear();
	for (int i = 0; i < size; i++)
	{
		outputShop(shops[i], sizeseller, sizeshoes);
	}
	cout << endl;
}

int main()
{
	//system("color 7c");
	//cout << "\t\t\tWelcome to the PittaRosso chain of stores\n\n";
	int amountshops, amountshoes, amountseller;
	cout << "Enter number of shops: ";
	cin >> amountshops;
	cout << "Enter number of shoes: ";
	cin >> amountshoes;
	cout << "Enter number of salesman: ";
	cin >> amountseller;
	shop* shops = creatShops(amountshops, amountshoes, amountseller);
	shops = fillingShops(shops, amountshops, amountseller, amountshoes);
	outputShops(shops, amountshops, amountseller, amountshoes);
	removeShops(shops);
	return 0;
}