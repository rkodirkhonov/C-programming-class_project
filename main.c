#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    char *number;
    char *birthdate;
}Contact;
void renew(Contact** list, int* cnt);

int main()
{
    Contact **people = NULL;
    Contact *people2 = NULL; // let's create another struct for copying "people" struct to and use to show sorted version of the list

    // declaring the necessary variables
    int i = 0, menuNum;
    // declaring counter in order to be aware of the contact numbers saved in the array
    int cnt = 0;
    // I am using do while loop for the menu over other loops
    char name[21];
    char name2[21];
    // create a side variable to know whether there is already registered duplicate of the contact name
    int thereIsDuplicate = 0;
    int max_size;
    printf("Max_num:");
    scanf("%d", &max_size);
    people = (Contact*)malloc(max_size*sizeof(Contact));
    people2 = (Contact*)malloc(max_size*sizeof(Contact));
    do
    {
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");
        // get the menu number from the user
        scanf("%d", &menuNum);
        switch (menuNum)
        {
        case 1:
        {
            // let's put a condition to check whether we reach the array limit or not, if so print out "OVERFLOW" massage to the screen and return to the main menu
            if (cnt == max_size)
            {
                printf("OVERFLOW\n");
                break;
            }
            printf("Name:");
            scanf("%s", name);
            for (int j = 0; j < cnt; j++)
            {
                if (strcmp(people[j]->name, name) == 0)
                {
                    printf("This name has already been registered!\n");
                    thereIsDuplicate++;
                    break;
                }
            }

            if (thereIsDuplicate == 0) // if there is a duplicate of the entered name ignore the rest of code and go back to the main menu
            {
                people[i]->name = (char*)malloc(21*sizeof(char));
                strcpy(people[i]->name, name);
                printf("Phone_number:");
                people[i]->number = (char*)malloc(21*sizeof(char));
                scanf("%s", people[i]->number);
                printf("Birth:");
                people[i]->birthdate = (char*)malloc(21*sizeof(char));
                scanf("%s", people[i]->birthdate);
                cnt++;
                printf("<<%d>>\n", cnt);
                i++;
            }
            thereIsDuplicate = 0;
            break;
        };
        case 2:
        {
            for (int i = 0; i < cnt; i++)
            {
                people2[i].name = (char*)malloc(21*sizeof(char));
                people2[i].number = (char*)malloc(21*sizeof(char));
                people2[i].birthdate = (char*)malloc(21*sizeof(char));
                strcpy(people2[i].name, people[i]->name);
                strcpy(people2[i].number, people[i]->number);
                strcpy(people2[i].birthdate, people[i]->birthdate);
            }

            char temp[21]; // extra storage variable to use when sorting the list
            for (int i = 0; i < cnt; i++)
            {
                for (int j = 0; j < cnt - 1 - i; j++)
                {
                    if (strcmp(people2[j]->name, people2[j + 1]->name) > 0)
                    {
                        // swap people2[j]->name and people2[j+1]->name
                        strcpy(temp, people2[j]->name);
                        strcpy(people2[j]->name, people2[j + 1]->name);
                        strcpy(people2[j + 1]->name, temp);
                    }
                }
            }
            for (int i = 0; i < cnt; i++)
            {
                printf("%s %s %s\n", people2[i]->name, people2[i]->number, people2[i]->birthdate);
            }
            break;
        };
        case 3: // Delete a contact by finding contact's name
        {
            if (cnt == 0)
            {
                printf("NO MEMBER\n");
                break;
            }
            printf("Name:"); // get the contact name to be deleted
            scanf("%s", name2);
            int searchItem = 0;
            for (int i = 0; i < cnt; i++)
            {
                if (strcmp(name2, people[i]->name) == 0) //if true. the name is in the list. Find and remove it
                {
                    for (int j = i; j < cnt; j++)
                    {
                        people[j] = people[j + 1];
                    }
                    cnt--;
                    searchItem++;
                }
            }
            if (searchItem == 0)
            {
                printf("NO MEMBER\n");
            }
            break;
        };
        case 4: // find by birth month
        {
            char birthMonth[2];
            scanf("%s", birthMonth);
            for (int i = 0; i < cnt; i++)
            {
                if (strcmp(birthMonth, "10") == 0 || strcmp(birthMonth, "11") == 0 || strcmp(birthMonth, "12") == 0)
                {
                    if (people[i]->birthdate[4] == birthMonth[0] && people[i]->birthdate[5] == birthMonth[1])
                    {
                        printf("%s %s %s\n", people[i]->name, people[i]->number, people[i]->birthdate);
                    }
                }
                else
                {
                    if (people[i]->birthdate[5] == birthMonth[0])
                    {
                        printf("%s %s %s\n", people[i]->name, people[i]->number, people[i]->birthdate);
                    }
                }
            }
            break;
        }
        case 5:
        {
            FILE *p_file;
            int i, j, counter = 0;
            Contact sort_temp = {0};
            //buffer for names data
            Contact temp_name[100] = {0};

            p_file = fopen("PHONE_BOOK.txt", "r");
            i=cnt;
            while(1)
            {
                if(i>max_size){
                    printf("Overflow\n");
                    break;
                }
                fscanf(p_file, "%s", temp_name);
                if(i>0 && strcmp(temp, people[i-1]->birthdate) == 0)
                    break;

                people[i]->name = (char*)malloc((strlen(temp)+1) * sizeof(char));
                strcpy(people[i]->name, temp_name);
                fscanf(fname, "%s", temp);


                people[i]->number = (char*)malloc((strlen(temp) + 1) * sizeof(char));
                strcpy(people[i]->number, temp);

                fscanf(fname, "%s", temp);
                people[i]->birthdate = (char*)malloc((strlen(temp) + 1) * sizeof(char));
                strcpy(people[i]->birthdate, temp);

                i++;
                cnt2++;
            }
            fclose(p_file);
            // sort after registering from the file
            for (i = 0; i < cnt; i++) {
                for (j = 0; j < cnt - 1; j++) {
                    //If str2 is less then str1 swap
                    if (strcmp(people[j]->name, people[j + 1]->name) > 0) {
                        temp_name = *people[j];
                        *people[j] = *people[j + 1];
                        *people[j + 1] = temp_name;
                    }
                }
            }

            break;
        }
        case 6:
        {
            renew(people, &cnt);
            break;
        };
    }

    }while(1);


    return 0;
}

void renew(Contact** list, int* cnt) {
    FILE* fname;
    fname = fopen("PHONE_BOOK.txt", "w");

    for (int i = 0; i < *cnt; i++) {
        fprintf(fname, "%s %s %s", list[i]->name, list[i]->number, list[i]->birthdate);
    }
    fclose(fname);
}
