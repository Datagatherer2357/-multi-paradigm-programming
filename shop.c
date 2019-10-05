#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Begin modelling the entities */
struct Product{
	char* name;
	double price;
	
};

/* This below will provide a link between the stock and the quantity that we have of the stock*/
struct ProductStock{ 
	struct Product product;
	int quantity;
	
};

struct Shop{
	double cashfloat;	/* ProductStock is how many of each product we have*/
	struct ProductStock stock[20];
	int index; 
	
};

struct Customer{
	char* name;
	double budget;
	struct ProductStock shopingList[10]; /*Customer shopping list*/
	int index; 
	
};

/* End of  modelling the entities */
/*------------------------------------------------*/
/* Method to print out the product information e.g. passing the struct in etc*/

void printProduct(struct Product p)
{
	
	printf("PRODUCT: NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
	printf("------------------\n");
}

void printCustomer(struct Customer c)
{
	
	printf("CUSTOMER: NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
	printf("------------------\n");
	// for loop to loop through desired products needed below
	for(int i = 0; i < c.index; i++)
	{
		printProduct(c.shopingList[i].product);
		printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shopingList[i].quantity);
		// cost calculator algorithm below:
		double cost = c.shopingList[i].quantity * c.shopingList[i].product.price;
		printf("The cost to %s will be €%.2f\n", c.name, cost);
	}
}

struct Shop createAndStockShop()
{ 	// struct that represents the shop:
	struct Shop shop = {200};
	// reading in from the file:
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("stock.csv", "r"); // r means read w form write etc
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s IS A LINE", line);
		// Below is the string tokeniser at work:
		char *n = strtok(line, ",");
		char *p = strtok(NULL, ","); // NULL doean't take an input
		char *q = strtok(NULL, ",");
		int quantity = atoi(q);
		double price = atof(p);
		char *name = malloc(sizeof(char) * 50);
		strcpy(name, n);
		struct Product product = {name, price};
		struct ProductStock stockItem = {product, quantity};
		shop.stock[shop.index++] = stockItem;
		
		// printf("NAME of product %s PRICE %.2f QUANTITY %d\n", name, price, quantity);
		//printf("NAME OF PRODUCT %s\n", name);
    }
	// printProduct(shop.stock[0].product);
	return shop;
	
}

// creating a print method for the shop ITSELF:

void printShop(struct Shop s)
{
	printf("Shop has %.2f in cash\n", s.cashfloat);
	// middle part of a for loop is the condition
	for (int i = 0; i < s.index; i++)
	{
		printProduct(s.stock[i].product);
		printf("The shop has %d of the above (QUANTITY)\n", s.stock[i].quantity);
		
	}
}

int main(void)
{
	
	//struct Customer gareth = {"Gareth",100.0};	
		
	//struct Product coke = {"Can Coke", 1.10};
	//struct Product bread = {"Bread", 0.70};
	// printProduct(coke);
	
	//struct ProductStock cokeStock = {coke, 20};
	//struct ProductStock breadStock = {bread, 2};
	
	//gareth.shopingList[gareth.index++]= cokeStock; // [0] in the array/retrieves the index value
	//gareth.shopingList[gareth.index++]= breadStock;
	
	//printCustomer(gareth);
	// printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name); /* Pulling data out of parent data */
	
	struct Shop shop = createAndStockShop();
	printShop(shop);
	
	
	return 0;
}