/*
LIST OF MEMBERS:

Name(University Roll Number)

01. Unnati Agarwal(201550143) - Leader
02. Kshitij Agarwal(201550072)
03. Kunal Singh(201550073)
04. Akshat Garg(201550015)
05. Neha Roy(201550088)
06. Akarsh Singh()
07. Kartik Mittal(201550069)
08. Aayush Panday(201550002)
09. Aman
10. Amul Singh(201550023)
*/
/**
* Modify section was Created by Kartik and edited by Unnati and Kshitij.
* Kunal and Aman were incharge of menu and the heading.
* Everything was linked by Unnati and Kshitij .
* Akarsh was responsible for the portion which helps in viewing the complete directory.
* Amul made the code for adding new people to the phonebook.
* Neha made the code for removing unwanted members present in Phonebook.
* Aayush and Akshat were the ones who presented the searching feature within the Phone book.
* Kshitij, Unnati was responsible for reviewing each and every code with Making interface alignment as center.
* Unnati was responsible for color coding
* Unnati was responsible for editing each and every code and making sure they work properly.
* Leaders of the project was Unnati
* Members list and their assignment of work at the end of the file.......
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Structure
struct contact
{
    char name[35];
    char address[50];
    char email[50];
    long long int mobile_no;
};

//Pre Decleration of all the Functions
void menu();
void search();
int remove_person(char name1[30]);
void addrecord();
void list_all();
int modify(char name1[30]);
void delete_all();
int search_addrecord(char name1[30]);
int number_of_contacts();

// COLORS

void reset()
{
    printf("\033[0m");
}
void red()
{
    printf("\033[1;31m");
}
void yellow()
{
    printf("\033[1;33m");
}
void green()
{
    printf("\033[0;32m");
}
void blue()
{
    printf("\033[0;34m");
}
void purple()
{
    printf("\033[0;35m");
}
void cyan()
{
    printf("\033[1;36m");
}
void white()
{
    printf("\033[1;37m");
}

//MODULES

void menu()
{
    system("cls");
    int n, a;
    char choice;
    char name1[30];
    blue();
    printf("\n\n");
    printf("\t\t\t\t    ##       ##     #########    ##    ##    ##     ##\n");
    printf("\t\t\t\t    ####   ####     ##           ###   ##    ##     ##\n");
    printf("\t\t\t\t    ## ## ## ##     ##           ####  ##    ##     ##\n");
    printf("\t\t\t\t    ##  ###  ##     ####         ## ## ##    ##     ##\n");
    printf("\t\t\t\t    ##       ##     ##           ##  ####    ##     ##\n");
    printf("\t\t\t\t    ##       ##     ##           ##   ###    ##     ##\n");
    printf("\t\t\t\t    ##       ##     #########    ##    ##    #########\n");
    printf("\n\n\n");
    white();
    printf("\n\t\t\t\t\t    PRESS 1 TO ADD A NEW CONTACT\n\t\t\t\t\t    PRESS 2 TO DELETE ANY EXISTING CONTACT\n\t\t\t\t\t    PRESS 3 TO MODIFY OF A CONTACT\n\t\t\t\t\t    PRESS 4 TO VIEW ALL CONTACTS\n\t\t\t\t\t    PRESS 5 TO SEARCH ANY EXISTING CONTACT\n\t\t\t\t\t    PRESS 6 TO CLOSE THIS PAGE\n\t\t\t\t\t    PRESS 7 TO DELETE ALL CONTACTS\n\n\n\n\n");
	cyan();
    printf("\t\t\t\t\t          ENTER THE CHOICE : ");
    reset();
    scanf("%d", &n);
    fflush(stdin);
    switch (n)
    {
    case 1:
        addrecord();
        fflush(stdin);
        remove_person("");
        break;
    case 2:
        system("cls");
        fflush(stdin);
        yellow();
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t ENTER THE NAME OF A PERSON WHOM YOU WANT TO REMOVE FROM PHONEBOOK : ");
        white();
        gets(name1);
        a = remove_person(name1);
        if (a == 1)
        {
            green();
            printf("\n\n\n\t\t\t\t\t\t   RECORD DELETED.");
        }
        else
        {
            red();
            printf("\n\n\n\t\t\t\t\t\t   DELETION FAILED.");
            printf("\n\n\t\t\t\t\t\t CONTACT DOESN'T EXIST.");
        }
        cyan();
        printf("\n\n\t\t\t\t       !....PRESS ANY KEY TO RETURN TO MENU....!\n");
        getch();
        reset();
        menu();
        break;
    case 3:
        system("cls");
        fflush(stdin);
        yellow();
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t   ENTER THE NAME OF A PERSON WHOM YOU WANT TO MODIFY FROM PHONEBOOK : ");
        fflush(stdin);
        white();
        gets(name1);
        a = modify(name1);
        if (a == 1)
        {
            remove_person(name1);
            remove_person("");
            green();
            printf("\n\n\t\t\t\t\t\t   YOUR DATA IS MODIFIED.");
            cyan();
            printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!");
        }
        else
        {
            red();
            printf("\n\n\t\t\t\t\t\t     DATA IS NOT FOUND.");
            cyan();
            printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!");
        }
        getch();
        menu();
        break;
    case 4:
        list_all();
        menu();
        break;
    case 5:
        search();
        menu();
    case 6:
        red();
        printf("\n\n\n\t\t\t\t\t\tPRESS ANY KEY TO EXIT.....");
        getch();
        reset();
        exit(0);
    case 7:
        delete_all();
        menu();
    default:
        red();
        printf("\n\t\t\t\t\t       ...VALUE ENTERED IS WRONG...\n\n");
        cyan();
        printf("\t\t\t\t\t         ...!PLEASE TRY AGAIN!...\n");
        getch();
        menu();
    }
}

void addrecord()
{
    system("cls");
    FILE *f;
    int a;
    struct contact c;
    f = fopen("record.txt", "ab");
    if (f == NULL)
    {
        red();
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t     !....NO CONTACTS EXIST....!");
        cyan();
        printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!\n");
        reset();
        getch();
        menu();
    }

    fflush(stdin);
    yellow();
    printf("\n\n\n\n\n\n\t\t\t\t\t        ENTER NAME           :  ");
    white();
    gets(c.name);
    a = search_addrecord(c.name);
    if (a == 1)
    {
        blue();
        printf("\n\n\t\t\t\t             !....CONTACT ALREADY EXISTS....!\n");
        cyan();
        printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!\n");
        getch();
        menu();
    }
    yellow();
    printf("\n\t\t\t\t\t        ENTER THE ADDRESS    :  ");
    white();
    gets(c.address);
    yellow();
    printf("\n\t\t\t\t\t        ENTER CONTACT NO.    :  ");
    white();
    scanf("%lld", &c.mobile_no);

    fflush(stdin);
    yellow();
    printf("\n\t\t\t\t\t        ENTER E-MAIL ID      :  ");
    white();
    gets(c.email);

    fwrite(&c, sizeof(c), 1, f);
    green();
    printf("\n\n\n\n\n\t\t\t\t\t\t\tRECORD ADDED.");
    fclose(f);
    cyan();
    printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!\n");
    white();
    getch();
    menu();
}

void list_all()
{
    system("cls");
    int a;
    a = number_of_contacts();
    FILE *f;
    struct contact c[a];
    f = fopen("record.txt", "rb");
    if (f == NULL)
    {
        red();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     !....ERROR IN FILE OPENING, PLEASE TRY AGAIN....!");
        cyan();
        printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!");
        reset();
        getch();
        menu();
    }
    else
    {
        int i;
        blue();
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t               CONTACTS\n");
        for (i = 0; i < a; i++)
        {
            fread(&c, sizeof(c), 1, f);
            green();
            printf("\n\n\t\t\t\t                   *******");
            blue();
            printf(" %d ", i+1);
            green();
            printf("*******\n");
            white();
            printf("\n");
            printf("\n\t\t\t\t\t    NAME           -  ");
            printf("%s", c[i].name);
            printf("\n\t\t\t\t\t    ADDRESS        -  ");
            printf("%s", c[i].address);
            printf("\n\t\t\t\t\t    MOBILE NUMBER  -  ");
            printf("%lld", c[i].mobile_no);
            printf("\n\t\t\t\t\t    EMAIL ADDRESS  -  ");
            printf("%s", c[i].email);
            printf("\n");
        }
        green();
        printf("\n\n\t\t\t\t              <-x-x-x-END OF RECORD-x-x-x->");
        cyan();
        printf("\n\n\t\t\t\t        !....PRESS ANY KEY TO RETURN TO MENU....!");
        getch();
        fclose(f);
        getch();
    }
}

int search_addrecord(char name1[30])
{
    FILE *fp;
    fp = fopen("record.txt", "rb");

    struct contact c;
    int flag = 0, res;
    while (fread(&c, sizeof(c), 1, fp) == 1)
    {
        if (strcmp(c.name, name1) == 0)
        {
            flag = 1;
        }
        else 
        {
            flag = 0;
        }
    }
    fclose(fp);
    return flag;
}

void search()
{
    system("cls");

    FILE *fp;
    fp = fopen("record.txt", "rb");

    if (fp == NULL)
    {
        red();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     !....ERROR IN FILE OPENING, PLEASE TRY AGAIN....!");
        cyan();
        printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!");
        reset();
        getch();
        menu();
    }

    else
    {
        struct contact c;
        int flag = 0, res;
        char name1[30];
        system("cls");
        fflush(stdin);
        yellow();
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t   ENTER THE NAME OF A PERSON WHOM YOU WANT TO SEARCH FROM PHONEBOOK : ");
        fflush(stdin);
        white();
        gets(name1);
        fflush(stdin);
        while (fread(&c, sizeof(c), 1, fp) == 1)
        {
            if (strcmp(c.name, name1) == 0)
            {
                green();
                printf("\n\n\n\n\t\t\t\t\t\t  RECORD IS FOUND.\n\n");
                yellow();
                printf("\n\t\t\t\t\t    NAME             - \t");
                white();
                printf("%s", c.name);
                yellow();;
                printf("\n\t\t\t\t\t    ADDRESS          - \t");
                white();
                printf("%s", c.address);
                yellow();
                printf("\n\t\t\t\t\t    MOBILE NUMBER    - \t");
                white();
                printf("%lld", c.mobile_no);
                yellow();
                printf("\n\t\t\t\t\t    EMAIL ADDRESS    - \t");
                white();
                printf("%s\n\n", c.email);

                flag = 1;
            }

            fflush(stdin);
        }
        if (flag == 0)
        {
            red();
            printf("\n\n\n\n\t\t\t\t\t\tNO RECORD FOUND OF %s NAME.\n", name1);
        }
        fclose(fp);

        fflush(stdin);
        cyan();
        printf("\n\n\t\t\t\t     !....PRESS ANY KEY TO RETURN TO MENU....!");
        reset();
        getch();
        menu();
    }
}

int remove_person(char name1[50])
{

    FILE *fp, *temp;
    fp = fopen("record.txt", "rb");
    temp = fopen("temp.txt", "wb+");
    if (fp == NULL)
    {

        red();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     !....ERROR IN FILE OPENING, PLEASE TRY AGAIN....!");
        cyan();
        printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!");
        reset();
        remove("temp.txt");
        getch();
        menu();
    }
    else
    {
        struct contact c;
        int flag = 0, res;
        while (fread(&c, sizeof(c), 1, fp) == 1)
        {
            if (flag != 1)
            {
                if (strcmp(c.name, name1) == 0)
                {
                    flag = 1;
                }
                else
                    fwrite(&c, sizeof(c), 1, temp);
                fflush(stdin);
            }

            else
                fwrite(&c, sizeof(c), 1, temp);
            fflush(stdin);
        }

        fclose(fp);
        fclose(temp);
        if (flag == 1)
        {
            remove("record.txt");
            rename("temp.txt", "record.txt");
            fflush(stdin);
        }
        else
        {
            remove("temp.txt");
        }
        return flag;
    }
}

int modify(char name1[50])
{
    struct contact c;
    long long int chr;
    FILE *f;

    char e_mail[50];
    char home_address[50];
    int flag = 0;
    int input;
    char val;
    f = fopen("record.txt", "rb+");
    if (f == NULL)
    {
        red();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t     !....ERROR IN FILE OPENING, PLEASE TRY AGAIN....!");
        cyan();
        printf("\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!");
        reset();
        getch();
        menu();
    }
    else
    {
        system("cls");
        // yellow();
        // printf("\n\n\n\n\n\n\n\t\t\t\t\t     ??WHAT DO YOU WANT TO MODIFY??");
        purple();
        printf("\n\n\n\t\t\t\t\t\tPRESS 1 TO MODIFY NAME\n\t\t\t\t\t\tPRESS 2 TO MODIFY CONTACT NUMBER\n\t\t\t\t\t\tPRESS 3 TO MODIFY E-MAIL ADDRESS\n\t\t\t\t\t\tPRESS 4 TO MODIFY ADDRESS");
        green();
        printf("\n\n\n\t\t\t\t\t\tENTER YOUR CHOICE -- ");
        white();
        scanf("%d", &input);
        fflush(stdin);

        while (fread(&c, sizeof(c), 1, f) == 1)
        {
            if (strcmp(name1, c.name) == 0)
            {
                if (input == 1)
                {
                    purple();
                    fflush(stdin);
                    printf("\n\n\n\n\t\t\t\t\t  ENTER THE NEW NAME   :   ");
                    white();
                    gets(c.name);
                    fseek(f, sizeof(c), 1);
                    fwrite(&c, sizeof(c), 1, f);
                    flag = 1;
                    break;
                }

                else if (input == 2)
                {
                    purple();
                    printf("\n\n\n\n\t\t\t\t ENTER THE NEW MOBILE NUMBER   :   ");
                    white();
                    scanf("%lld", &c.mobile_no);
                    fseek(f, sizeof(c), SEEK_CUR);
                    fwrite(&c, sizeof(c), 1, f);
                    flag = 1;
                    break;
                }

                else if (input == 3)
                {
                    purple();
                    printf("\n\n\n\n\t\t\t\t     ENTER THE NEW E-MAIL ID   :   ");
                    white();
                    gets(c.email);
                    fseek(f, sizeof(c), SEEK_CUR);
                    fwrite(&c, sizeof(c), 1, f);
                    flag = 1;
                    break;
                }

                else if (input == 4)
                {
                    purple();
                    printf("\n\n\n\n\t\t\t\t       ENTER THE NEW ADDRESS   :   ");
                    white();
                    gets(c.address);
                    fseek(f, sizeof(c), SEEK_CUR);
                    fwrite(&c, sizeof(c), 1, f);
                    flag = 1;
                    break;
                }

                else
                {
                    red();
                    printf("\n\n\n\n\t\t\t\t\t\tPLEASE ENTER THE VALID INPUT.");
                }
            }
        }
        fflush(stdin);
        fclose(f);
        reset();
        return flag;
    }
}

//Done because it was needed for editing all the above code properly in case of some problem)
void delete_all()
{
    system("cls");
    purple();
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   .....DELETING ALL.....");
    remove("record.txt");
    green();
    printf("\n\n\t\t\t\t   .....ALL THE CONTACTS WERE DELETED SUCCESSFULLY.....");
    cyan();
    printf("\n\n\n\n\n\n\t\t\t\t         !....PRESS ANY KEY TO RETURN TO MENU....!\n");
    getch();
    menu();
}

int number_of_contacts()
{

    FILE *fp;
    fp = fopen("record.txt", "rb");
    struct contact c;
    int flag = 0, res;
    while (fread(&c, sizeof(c), 1, fp) == 1)
    {
		flag ++;
    }
    fclose(fp);
    return flag;
}

int main()
{
    system("cls");
    cyan();
    printf("                 ##       ##   #########   ##           ########      #######     ##       ##   #########\n");
    printf("                 ##       ##   ##          ##         ##            ##       ##   ####   ####   ##\n");
    printf("                 ##       ##   ##          ##         ##            ##       ##   ##  ###  ##   ##\n");
    printf("                 ##   #   ##   ####        ##         ##            ##       ##   ##   #   ##   ####\n");
    printf("                 ##  ###  ##   ##          ##         ##            ##       ##   ##       ##   ##\n");
    printf("                 ####   ####   ##          ##         ##            ##       ##   ##       ##   ##\n");
    printf("                 ##       ##   #########   #########    ########      #######     ##       ##   #########\n");
    printf("\n");
    white();
    printf("\t\t\t\t\t     ##########    #######\n");
    printf("\t\t\t\t\t         ##      ##       ##\n");
    printf("\t\t\t\t\t         ##      ##       ##\n");
    printf("\t\t\t\t\t         ##      ##       ##\n");
    printf("\t\t\t\t\t         ##      ##       ##\n");
    printf("\t\t\t\t\t         ##      ##       ##\n");
    printf("\t\t\t\t\t         ##        #######\n");
    printf("\n");
    cyan();
    printf("   #########     ##      ##     #######     ##     ##   #########    ######      #######       #######     ##     ##\n");
    printf("   ##       ##   ##      ##   ###########   ###    ##   ##          ##     ##  ##       ##   ##       ##   ##   ##\n");
    printf("   ##       ##   ##      ##   ###########   ## #   ##   ##          ##     ##  ##       ##   ##       ##   ## ##\n");
    printf("   #########     ##########   ###########   ##  #  ##   ####        ######     ##       ##   ##       ##   ###\n");
    printf("   ##            ##      ##   ###########   ##   # ##   ##          ##     ##  ##       ##   ##       ##   ## ##\n");
    printf("   ##            ##      ##   ###########   ##    ###   ##          ##     ##  ##       ##   ##       ##   ##   ##\n");
    printf("   ##            ##      ##     #######     ##     ##   #########    ######      #######       #######     ##     ##\n");
    white();
    printf("\n\n\t\t\t\t  ........PRESS ANY KEY TO ENTER THE MENU SCREEN........");
    reset();
    getch();
    menu();
    return 0;
}

