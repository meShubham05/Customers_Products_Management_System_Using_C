#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Product_Details.cpp"
#include "File_Handling_Customeer_Details.cpp"

int choice, allProductCount=0;

int main() {
	
	int addProduct();
	int displayProducts();
	int searchProduct();
	int deleteProduct();
	int addCustomer();
	int displayCustomer();
	int generateBill();
	
    do {
        printf("\n 1: Add \n 2: Display \n 3:SearchProduct\n 4:Delete_Product: \n 5: Add Customer : \n 6: Display Customer \n 7: Generate Bill");
        
        printf("\n Enter Choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
             case 3:
			 searchProduct();
			 break;
			 case 4:
			 	deleteProduct();
			 	break;
			  case 5:
			    addCustomer();
			    break;
			 case 6:
			 	displayCustomer();
			 	break;
			case 7:
				generateBill();
				break;
            default:
                printf("\n Invalid Choice \n");
                break;
        }
    } while(choice != 8);

    return 0;
}


int addProduct() {
    struct Product p;

	
    FILE *fptr;
    fptr = fopen("D:\\GIRI TECH HUB\\FileHandling\\Products.txt", "a"); 
    
    if (fptr == NULL) {
        printf("\n Error opening file\n");
        return 1;
    }

    printf("\n Enter the data for Product (Name, Company Name, ID, Price): ");

    printf("\nProduct Name: ");
    scanf("%s", p.name);

    printf("Company Name: ");
    scanf("%s", p.cmpName);
	_flushall();
    printf("ID: ");
    scanf("%d", &p.id);

    printf("Price: ");
    scanf("%d", &p.price);

    fprintf(fptr, "%-20s %-20s %-10d %-10d\n", p.name, p.cmpName, p.id, p.price);
    
    printf("\n Yes! Product added successfully .........\n");

    fclose(fptr);
    
    return 0;
}


void displayProducts() {
    struct Product p;
	allProductCount=0;
    FILE *fptr;
    fptr = fopen("D:\\GIRI TECH HUB\\FileHandling\\Products.txt", "r");

    if (fptr == NULL) 
	{
    	
        printf("\n Opps ! No Data in File :\n");
        
        return ;
    }
	else
	{
    printf("\n Products:\n");
    printf("-------------------------------------------------------------\n");
    printf(" %-20s %-20s %-10s %-10s\n", "Name", "Company", "ID", "Price");
    printf("-------------------------------------------------------------\n");

    int flag = 0; // Flag to check if any product is found

    while (fscanf(fptr, "%s %s %d %d", p.name, p.cmpName, &p.id, &p.price) !=-1) {
        printf(" %-20s %-20s %-10d %-10d\n", p.name, p.cmpName, p.id, p.price);
        flag = 1;
         allProductCount++;
    }
	}
	int flag;
	
    if (! flag) {
        printf("\n Product Not Found :\n");
    }

    fclose(fptr);
}

int searchProduct() {	
    FILE *fptr; 
    fptr = fopen("D:\\GIRI TECH HUB\\FileHandling\\Products.txt", "r");
    
    if (fptr == NULL) {
        printf("\nNo data in File \n");
        return -1; 
    }

    char sproduct[50]; 
    int sId;
    int flag = 0; 
    printf("\n\nEnter the Product You want to search: ");
    scanf("%s",sproduct);
    printf("\n Enter Product Id :");
    scanf("%d",&sId);

 
    while (fscanf(fptr, "%s %s %d %d", p.name, p.cmpName, &p.id, &p.price) !=-1) {
        if (strcmp(sproduct, p.name) == 0 && sId==p.id) {
            flag = 1;
           break;
        }
    }
	
    if (flag) {
        printf("\nProduct Found:");
    printf("\n-------------------------------------------------------------\n");
    printf(" %-20s %-20s %-10s %-10s\n", "Name", "Company", "ID", "Price");
    printf("-------------------------------------------------------------\n");
    printf(" %-20s %-20s %-10d %-10d\n", p.name, p.cmpName, p.id, p.price);
    
    } 
	else 
	{
        printf("\n Oops! Product Not Found\n");
    }

    fclose(fptr); 
    return 0; 
}


int deleteProduct() {
    FILE *fptr;
    int flag = 0;
    fptr = fopen("D:\\GIRI TECH HUB\\FileHandling\\Products.txt", "r");
    int count = -1;

    char delProduct[50]; // Increased the size to accommodate longer product names
    struct Product *temp = (struct Product *)malloc(sizeof(struct Product) * allProductCount); // Use struct Product instead of Product

    printf("\n Enter the Product You want to delete: ");
    scanf("%s", delProduct);
    _flushall();

    while (fscanf(fptr, "%s%s%d%d", &p.name, &p.cmpName, &p.id, &p.price) != EOF) { // Use EOF instead of -1 for file reading
        if (strcmp(delProduct, p.name) == 0) {
            flag = 1;
        } else {
            count++;
            temp[count] = p;
        }
    }
    
    printf("all Product count is %d and temp size is : %d", allProductCount, count);

    if (flag) 
	{
        fclose(fptr);

        fptr = fopen("D:\\GIRI TECH HUB\\FileHandling\\Products.txt", "w");

        for (int i = 0; i <= count; i++) 
		{
            fprintf(fptr, "%s\t%s\t%d\t%d\n", temp[i].name, temp[i].cmpName, temp[i].id, temp[i].price);
        }

        fclose(fptr);
    }

    free(temp); 

    return 0; 
}

int addCustomer()
{
	FILE *fptr;
	
	fptr= fopen("D:\\GIRI TECH HUB\\FileHandling\\Customers.txt", "a");
	
	printf("\n Enter customer id :");
	scanf("%d",&c.custId);
	
	printf("\n Enter Customer Name : ");
	scanf("%s",c.custName);
	
	printf("\n Enter Customer mail ");
	scanf("%s",c.custEmail);
	
	printf("\n Enter Customer Mobile Number :");
	scanf("%s",c.mobile);
	
	fprintf(fptr,"%-10d%-20s%-20s%-10s\n",c.custId,c.custName,c.custEmail,c.mobile);
	
	printf("\n Customer Added Successfully ! ");
	
	fclose(fptr);
}

int displayCustomer()
{
	FILE *fptr;
	fptr=fopen("D:\\GIRI TECH HUB\\FileHandling\\Customers.txt", "r");
	
	 if (fptr == NULL) 
	{
    	
        printf("\n Opps ! No Data in File :\n");
             
    }
	else
	{
    
    printf("-------------------------------------------------------------\n");
    printf(" %-20d %-20s %-10s %-10s\n", "Id", "Customer Name", "Customer Email", "Mobile No");
    printf("-------------------------------------------------------------\n");

  

    while (fscanf(fptr, "%d %s %s %s", &c.custId,c.custName,c.custEmail,c.mobile) !=-1)
	{
    printf(" %-20d %-20s %-10s %-10s\n",c.custId, c.custName, c.custEmail, c.mobile);
           
    }
	}

    fclose(fptr);
		
}


int generateBill()
{

    FILE *fptrProducts, *fptrCustomers;

    
    fptrProducts = fopen("D:\\GIRI TECH HUB\\FileHandling\\Products.txt", "r");
    fptrCustomers = fopen("D:\\GIRI TECH HUB\\FileHandling\\Customers.txt", "r");

    if (fptrProducts == NULL || fptrCustomers == NULL) {
        printf("\n No Data in File : \n");
  
    }
	else
	{
    char productName[50];
    int productId, quantity;
    int totalAmount = 0;

    printf("\nEnter Product Name: ");
    scanf("%s", productName);

    printf("Enter Product Id: ");
    scanf("%d", &productId);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    // Here the main logic of Searching for the product 
    
    
    struct Product p;
        
    int flag = 0;
    while (fscanf(fptrProducts, "%s %s %d %d", p.name, p.cmpName,&p.id, &p.price) != -1) {
        if (strcmp(productName, p.name) == 0 && productId == p.id) {
            flag = 1;
            totalAmount = p.price * quantity;
            break;
        }
    }

    if (flag) {
        printf("\nProduct Found:");
        printf("\n-------------------------------------------------------------\n");
        printf(" %-20s %-20s %-10s %-10s\n", "Name", "Company", "ID", "Price");
        printf("-------------------------------------------------------------\n");
        printf(" %-20s %-20s %-10d %-10d\n", p.name, p.cmpName, p.id, p.price);

        printf("\nTotal Amount: %d\n", totalAmount);
    } 
	else
    {
        printf("\nOops! Product Not Found\n");
    }
}
    fclose(fptrProducts);
    fclose(fptrCustomers);
}
