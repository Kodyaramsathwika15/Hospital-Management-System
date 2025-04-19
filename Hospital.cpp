#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ad {
    char name[30];
    char disease[30];
    int cabin, age;
    long long int phone;
};

struct ad* x;  // Dynamic array of structures
int n, i, j = 0, a = 0, sum = 0, g, flag, num;
void read();
void add();
void view();
void search();
void edit();
void del();
void show();
void write();

int main() {
    int c, i, q;
    printf("Simple Hospital Management System\n");
    printf("You Heal Hospital\n");
    int m, n;

    while (c != 6) {
        printf("**Enter your choice**\n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Exit\n\nOption=");
        scanf("%d", &c);  // choice for option
        fflush(stdin);  // making it clear
        if (c == 1)  // add
        {
            system("cls");
            add();
        } else if (c == 2)  // view
        {
            system("cls");
            view();
        } else if (c == 3)  // search
        {
            system("cls");
            search();
        } else if (c == 4)  // edit
        {
            system("cls");
            edit();
        } else if (c == 5)  // delete
        {
            system("cls");
            del();
        } else if (c == 6) {
            system("cls");
            write();
            return 0;
        } else {
            system("cls");
            printf("\n\nInvalid input, try again using valid inputs");
        }
        printf("\n\n");
    }
}

void add() {
    printf("\n\n");
    printf("Already data inputted on the database = %d\n\n", num);  // how many inputs
    printf("How many entries do you want to add? ");
    scanf("%d", &n);
    sum = n + num;

    x = (struct ad*)realloc(x, sum * sizeof(struct ad));  // Reallocate memory for new entries

    for (i = num, j = 0; i < sum; i++) {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name: ");
        scanf("%s", x[i].name);
        fflush(stdin);
        printf("Enter disease: ");
        scanf("%s", x[i].disease);
        fflush(stdin);
        printf("Enter the age: ");
        scanf("%d", &x[i].age);
        fflush(stdin);
        printf("Enter cabin no: ");
        scanf("%d", &x[i].cabin);
        fflush(stdin);
        printf("Enter phone number: ");
        scanf("%lld", &x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void view() {
    if (num == 0) {
        printf("No data available in the database.\n");
        return;
    }

    for (i = 0; i < num; i++) {
        printf("\n");
        printf("Serial Number = %d\n", i);
        printf("Name: %s\n", x[i].name);
        printf("Disease: %s\n", x[i].disease);
        printf("Cabin no: %d\nPhone number: %lld\nAge: %d\n", x[i].cabin, x[i].phone, x[i].age);
    }
}

void search() {
    char target[30];
    printf("Enter the name of the patient you want to search: ");
    scanf("%s", target);

    flag = 0;
    for (i = 0; i < num; i++) {
        if (strcmp(x[i].name, target) == 0) {
            printf("Data Found!\n");
            printf("Serial Number = %d\n", i);
            printf("Name: %s\n", x[i].name);
            printf("Disease: %s\n", x[i].disease);
            printf("Cabin no: %d\nPhone number: %lld\nAge: %d\n", x[i].cabin, x[i].phone, x[i].age);
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("Data Not Found!\n");
    }
}

void edit() {
    char target[30];
    printf("Enter the name of the patient you want to edit: ");
    scanf("%s", target);

    flag = 0;
    for (i = 0; i < num; i++) {
        if (strcmp(x[i].name, target) == 0) {
            printf("Data Found! Enter the new information.\n");
            printf("Enter patient's Name: ");
            scanf("%s", x[i].name);
            printf("Enter disease: ");
            scanf("%s", x[i].disease);
            printf("Enter the age: ");
            scanf("%d", &x[i].age);
            printf("Enter cabin no: ");
            scanf("%d", &x[i].cabin);
            printf("Enter phone number: ");
            scanf("%lld", &x[i].phone);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Data Not Found!\n");
    }
}

void del() {
    char target[30];
    printf("Enter the name of the patient you want to delete: ");
    scanf("%s", target);

    flag = 0;
    for (i = 0; i < num; i++) {
        if (strcmp(x[i].name, target) == 0) {
            printf("Data Deleted Successfully!\n");
            for (j = i; j < num - 1; j++) {
                strcpy(x[j].name, x[j + 1].name);
                strcpy(x[j].disease, x[j + 1].disease);
                x[j].age = x[j + 1].age;
                x[j].cabin = x[j + 1].cabin;
                x[j].phone = x[j + 1].phone;
            }
            num--;
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Data Not Found!\n");
    }
}
void read()  
{  
    FILE *fp = fopen("patient.txt","r");  
    if(fp == NULL)  
    {  
        fp = fopen("patient.txt","w");  
        fclose(fp);  
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");  
          
    }  
  
    num = fread(x, sizeof(struct ad),100, fp);  
    fclose(fp);  
}  
void write()  
{  
    FILE *fp = fopen("patient.txt","w");  
    if(fp == NULL)  
    {  
        printf("Error");  
        exit(1);  
    }  
    fwrite(x, sizeof(struct ad),num, fp);  
  
    fclose(fp);  
}  




        
