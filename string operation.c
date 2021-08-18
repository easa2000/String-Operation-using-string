/* Menu-Driven program to read the following operation
1 - read string
2 - display the string
3 - merge two string
4 - copy character from given position
5 - find legth of the string
6 - count upper,lower,number and special characters
7 - count the number of words,lines,and characters
8 - replace
9 - exit
*/

#include<stdio.h>
#include<string.h>
#include<conio.h>
void read(char *my_str);
void display(char *my_str);
void merge(char *my_str1, char *my_str2, char *my_str3);
void copy(char my_str1[], int m, int n);
int cal_len(char my_str[]);
void count(char my_str[]);
void count_wlc(char my_str[]);
void replace_str(char *my_str);

int main()
{
    char str1[100], str2[100], merged_str[100];

    int choice, m, n, length = 0;;
    do{
        printf("\n\n\n 1. Enter the string");
        printf("\n 2. Display the string");
        printf("\n 3. Merge two strings");
        printf("\n 4. Copy n characters from M th position");
        printf("\n 5. Calculate length of the string");
        printf("\n 6. Count number of uppercase, lowercase, numbers, and special characters");
        printf("\n 7. Count the number of words, lines, and characters");
        printf("\n 8. Replace , with ; ");
        printf("\n 9. EXIT");

        printf("\n\n Enter your option: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            read(str1);
            break;
        case 2:
            display(str1);
            break;
        case 3:
            read(str2);
            merge(str1,str2,merged_str);
            break;
        case 4:
            printf("\n Enter the position from which to copy the text: ");
            scanf("%d",&m);
            printf("\n Enter the number of characters to be copied: ");
            scanf("%d",&n);
            copy(str1, m, n);
            break;
        case 5 :
            length = cal_len(str1);
            printf("\n the length if the string is %d",length);
            break;
        case 6:
            count(str1);
            break;
        case 7:
            count_wlc(str1);
            break;
        case 8:
            replace_str(str1);
            break;
        
        default:
            break;
        }
    }while(choice != 9);

    return 0;
}

void read(char *my_str)
{
    printf("\n enter a string: ");
    getchar();
    gets(my_str);
}

void display(char *my_str)
{
    printf("\n The string is: ");
    while(*my_str != '\0')
    {
        printf("%c",*my_str);
            my_str++;
    }
}

void merge(char *my_str1, char *my_str2, char *my_str3)
{
    strcpy(my_str3,my_str1);
    strcat(my_str3,my_str2);
    display(my_str3);
}

void copy(char my_str1[], int m, int n)
{
    int i = 0;
    char *pstr;
    printf("\n the copy string is: ");
    while(i < n || my_str1[m] != '\0')
    {
        *pstr = my_str1[m];
        m++;
        i++;
        printf("%c",*pstr);
    }
}

int cal_len(char my_str1[])
{
    char *str = my_str1;
    int len = 0;
    while(*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

void count(char my_str[])
{
    char *pstr = my_str;
    int upper_case = 0, lower_case = 0, numbers = 0, spcl_char = 0;
    while(*pstr != '\0')
    {
        if(*pstr >= 'A' && *pstr <= 'Z')
            upper_case++;
        else if(*pstr >= 'a' && *pstr <= 'z')
            lower_case++;
        else if(*pstr >= '0' && *pstr <='9')
            numbers++;
        else
            spcl_char++;
        pstr++;
    }
    printf("\n Upppercase characters = %d",upper_case);
    printf("\n Lowercase characters = %d",lower_case);
    printf("\n Numbers = %d",numbers);
    printf("\n Special characters = %d",spcl_char);
}

void count_wlc(char my_str[])
{
    char *pstr = my_str;
    int words = 1, lines = 1, characters = 1;
    while(*pstr != '\0')
    {
        if(*pstr == '\n')
            lines++;
        if(*pstr == ' ' && *(my_str+1) != ' ')
            words++;
        characters++;
        pstr++;
    }
    printf("\n Number of words = %d",words);
    printf("\n Number of lines = %d",lines);
    printf("\n Number of characters = %d",characters);
}

void replace_str(char my_str[])
{
    char *pstr = my_str;
    while(*pstr != '\0')
    {
        if(*pstr != '\0')
            *pstr = ';';
        pstr++;
    }
    display(my_str);
}
