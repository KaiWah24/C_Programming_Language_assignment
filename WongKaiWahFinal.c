#include<stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)
#define PACKAGE_A_PRICE 24.50
#define PACKAGE_B_PRICE 26.00
#define PACKAGE_C_PRICE 27.50
#define PACKAGE_D_PRICE 29.00
#define DELIVERY_FEES 5.00
#define DISCOUNT_RATE 0.15

void monday();
void tuesday();
void wednesday();
void thursday();
void friday();
void saturday();
void sunday();


void main()
{

	char surName[31], address1[31], address2[31], address3[31], ask;
	int PhoneNumber, packageAqty, packageBqty, packageCqty, packageDqty, paymentMethod;
	double TotalToPay, packageCharges, deliveryfees, packageAtotal, packageBtotal, packageCtotal, packageDtotal, deliveryCharge, discount, rate;
	int countCust=0;
	int totalA=0, totalB=0, totalC=0, totalD=0, totalABCD;
	double salesamountA=0, salesamountB=0, salesamountC=0, salesamountD=0, salesamountTotal;
	int Deliveryoption;


	do {
	printf("\n\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
	printf("\n\t  +      +                                              +      +");
	printf("\n\t  +      +                                              +      +");
	printf("\n\t  +      +      WELCOME TO GH ORGANIC VEGETABLE FARM    +      +");
	printf("\n\t  +      +       VEGETABLES ORDERING SYSTEM             +      +");
	printf("\n\t  +      +                                              +      +");
	printf("\n\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
	printf("\n\t  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n\n");
	
	printf("%30s   %52s\n", "Package Available", "Price (RM) ");
	printf("%25s   %36.2F\n",  "A  (kangkung, cabbage, ladies finger, banana)", PACKAGE_A_PRICE);
	printf("%25s   %38.2F\n",  "B  (yam leaves, long beans, brinjal, guava)", PACKAGE_B_PRICE);
	printf("%25s   %38.2F\n",  "C  (snake beans, broccoli, spinach, papaya)", PACKAGE_C_PRICE);
	printf("%25s   %34.2F\n",  "D  (bak choy, asparagus, brinjal, dragon fruit)", PACKAGE_D_PRICE);
	printf("\n");

	
	countCust++;
	printf("\n");
	printf("\tCustomer No: %d \n", countCust);
	printf("\tEnter your name:");
	scanf(" %s", &surName);
	rewind(stdin);
	printf("\tEnter Phone Number:");
	scanf("%d", &PhoneNumber);
	rewind(stdin);
	printf("\tEnter Address :");
	printf("\n");
	printf("\t      Address1 :");
	gets(address1);
	printf("\t      Address2 :");
	gets(address2);
	printf("\t      Address3 :");
	gets(address3);

	printf("\n\n");
	do {

		printf("\tPlease select your delivery day options\n");
		printf("\t1. Monday\n");
		printf("\t2. Tuesday\n");
		printf("\t3. Wednesday\n");
		printf("\t4. Thursday\n");
		printf("\t5. Friday\n");
		printf("\t6. Saturday\n");
		printf("\t0. To continue your order\n");

		printf("\tEnter your option : ");
		scanf("%d", &Deliveryoption);
		printf("\n\n");

		switch (Deliveryoption)
		{
		case 1: monday(); break;
		case 2: tuesday(); break;
		case 3: wednesday(); break;
		case 4: thursday(); break;
		case 5: friday(); break;
		case 6: saturday(); break;
		case 0: break;
		default: 
			printf("Invalid option. Please try again.\n\n");
		}
	} while (Deliveryoption != 0);
	
	printf("\n\n");
	printf("\tEnter order quantity of package\n");
	printf("\tPackage A RM24.50 :");
	scanf("%d", &packageAqty);
	rewind(stdin);
	printf("\tPackage B RM26.00 :");
	scanf("%d", &packageBqty);
	rewind(stdin);
	printf("\tPackage C RM27.50 :");
	scanf("%d", &packageCqty);
	rewind(stdin);
	printf("\tPackage D RM29.00 :");
	scanf("%d", &packageDqty);


	packageAtotal = packageAqty * PACKAGE_A_PRICE;
	packageBtotal = packageBqty * PACKAGE_B_PRICE;
	packageCtotal = packageCqty * PACKAGE_C_PRICE;
	packageDtotal = packageDqty * PACKAGE_D_PRICE;
	packageCharges = packageAtotal + packageBtotal + packageCtotal + packageDtotal;

	if (packageCharges >= 100.00)
	{
		rate = DISCOUNT_RATE;
		deliveryCharge = 0.00;
	}
	else if (packageCharges >= 80.00)
	{
		rate = 0.00;
		deliveryCharge = 0.00;
	}
	else
	{
		rate = 0.00;
		deliveryCharge = DELIVERY_FEES;
	}
	discount = packageCharges * rate;
	TotalToPay = packageCharges + deliveryCharge - discount;



	printf("\n\n");
	printf("\t\t\ Invoice\n");
	printf("\tName         : Mr / Mrs %s \n", surName);
	printf("\tPhoneNumber  : %010d\n", PhoneNumber);
	printf("\tAddress      : %s\n\t\t       %s\n\t\t       %s\n\t\t  ", address1, address2, address3);


	printf("\n\n");
	printf("****************************************************************\n");
	printf("%40s\n", "~Customer Orders~");
	printf("****************************************************************\n");

	printf("\n\n");
	printf("%12s   %-10s   %11s   %13s\n", "PACKAGE", "QUANTITY", "UNIT PRICE", "TOTAL PRICE");
	printf("%12s   %-10s   %11s   %13s\n", "-------", "--------", "----------", "-----------");
	printf("%11s   %9d   %13.2f   %13.2f\n", "A", packageAqty, PACKAGE_A_PRICE, packageAtotal);
	printf("%11s   %9d   %13.2f   %13.2f\n", "B", packageBqty, PACKAGE_B_PRICE, packageBtotal);
	printf("%11s   %9d   %13.2f   %13.2f\n", "C", packageCqty, PACKAGE_C_PRICE, packageCtotal);
	printf("%11s   %9d   %13.2f   %13.2f\n", "D", packageDqty, PACKAGE_D_PRICE, packageDtotal);
	printf("%56s\n", "----------- ");
	printf("%20s %-20s %13.2f\n", " ", "Package Charges", packageCharges);
	printf("%20s %-20s %13.2f\n", " ", "Delivery Fees", deliveryCharge);
	printf("%20s %-20s %13.2f\n", " ", "Discount Given", discount);
	printf("%20s %-20s %13.2f\n", " ", "Total to Pay", TotalToPay);


	do {
		printf("Please select payment method (1 for Credit card, 2 for debit card or 3 for COD (cash on delivery) ) :  ");
		scanf("%d", &paymentMethod);


		if (paymentMethod != 1  && paymentMethod != 2 && paymentMethod != 3) {
			printf("Invalid payment method. Please enter again : ");
			scanf("%d", &paymentMethod);
		}

	}while (paymentMethod <1 || paymentMethod >3);
	

	switch (paymentMethod)
	{
	case 1:
		printf("\nYou have selected Credit Card as your payment method\n");
		break;
	case 2:
		printf("\nYou have selected Debit Card as your payment method\n");
		break;
	case 3:
		printf("\nYou have selected COD as your payment method\n");
		break;
	default:
		printf("Others");
	}


	printf("\n\n");
	printf("%43s\n", "Thank you for your order.");
	printf("%36s\n", "Please come again.");
	

	printf("\n\n");
	printf("\tNext Customer? (Y=yes, N=no) :");
	scanf("%s", &ask);
	system("cls");
	rewind(stdin);


	totalA += packageAqty;
	totalB += packageBqty;
	totalC += packageCqty;
	totalD += packageDqty;
	salesamountA += packageAtotal;
	salesamountB += packageBtotal;
	salesamountC += packageCtotal;
	salesamountD += packageDtotal;

	}while(ask == 'Y' || ask == 'y');
	
	totalABCD = totalA + totalB + totalC + totalD;
	salesamountTotal = salesamountA + salesamountB + salesamountC + salesamountD;

	printf("\n\n");
	printf("Total Number of Customer = %d \n", countCust);
	printf("%6s   %13s   %13s\n", "Package", "Quantity Sold", "Sales Amount");
	printf("%7s   %13d   %13.2f\n", "A", totalA, salesamountA);
	printf("%7s   %13d   %13.2f\n", "B", totalB, salesamountB);
	printf("%7s   %13d   %13.2f\n", "C", totalC, salesamountC);
	printf("%7s   %13d   %13.2f\n", "D", totalD, salesamountD);
	printf("%7s\n", "=======================================");
	printf("%5s   %15d   %13.2f\n", "Total", totalABCD, salesamountTotal);
	printf("\n");
	
	system("pause");
}



void monday()
{
	printf("\tYou have selected Monday as your preference delivery day\n");
}

	
void tuesday()
{
	printf("\tYou have selected Tuesday as your preference delivery day\n");
}

void wednesday()
{
	printf("\tYou have selected Wednesday as your preference delivery day\n");
}

void thursday()
{
	printf("\tYou have selected thursday as your preference delivery day\n");
}

void friday()
{
	printf("\tYou have selected friday as your preference delivery day\n");
}

void saturday()
{
	printf("\tYou have selected Saturday as your preference delivery day\n");
}

