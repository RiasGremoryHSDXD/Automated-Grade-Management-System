#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

bool CheckUserEmailPassInput(char InputEmail[100], char InputPassword[100]);
char* AlphabetValidation(char InformationType[]);
char* StuFullNameConcat(char LastName[], char FirstName[], char Middle[]);
bool DigitValidation(char Number[]);



int main()
{
    printf("Automated Grade Management System\n\n");

    char UserEmailInput[100];
    char UserPasswordInput[100];
    char LastNameText[20] = "Last Name: ";
    char FirstNameText[20] = "First Name: ";
    char MiddleNameText[20] = "Middle Name: ";
    char StudentLastName[100];
    char StudentFirstName[100];
    char StudentMiddleName[100];
    char StudentFullName[100];
    char Choose[100];

    printf("Enter the details: \n");

    

    while (true)
    {
        printf("\nEmail: ");
        fgets(UserEmailInput, sizeof(UserEmailInput), stdin);
        UserEmailInput[strlen(UserEmailInput) - 1] = '\0';

        printf("Password: ");
        fgets(UserPasswordInput, sizeof(UserPasswordInput), stdin);
        UserPasswordInput[strlen(UserPasswordInput) - 1] = '\0';

        if(CheckUserEmailPassInput(UserEmailInput, UserPasswordInput))
        {   
            printf("No Student Record Yet!\n");

            while (true)
            {
                printf("\n+--------------------+");
                printf("\n| ADD STUDENT -   Y  |");
                printf("\n| BACK        -   B  |");
                printf("\n+--------------------+");

                printf("\nChoose: ");
                fgets(Choose, sizeof(Choose), stdin);
                Choose[strlen(Choose) - 1] = '\0';

                if(strcmp(Choose, "Y") == 0 || strcmp(Choose, "y") == 0)
                {
                    strcpy(StudentLastName, AlphabetValidation(LastNameText));
                    strcpy(StudentFirstName, AlphabetValidation(FirstNameText));
                    strcpy(StudentMiddleName, AlphabetValidation(MiddleNameText));
                    strcpy(StudentFullName, StuFullNameConcat(StudentLastName, StudentFirstName, StudentMiddleName));
                    printf("Student Full Name: %s", StudentFullName);
                }
                else if (strcmp(Choose, "B") == 0 || strcmp(Choose, "b") == 0)
                {   
                    break;
                }
                else
                {
                    printf("Invalid Input! Try Again!\n");
                }
            }
            
        }
        else
        {
            printf("\nInvalid Credentials.\n");
        }
    }

    return 0;
}

bool CheckUserEmailPassInput(char InputEmail[100], char InputPassword[100])
{
    char TeacherEmailArray[][50] = {"1", "TeacherEmailTwo", "TeacherEmailThree"};
    char TeacherPasswordArray[][50] = {"1", "TeacherPasswordTwo", "TeacherPasswordThree"};

    for(int CheckArr = 0; CheckArr < sizeof(TeacherEmailArray) / sizeof(TeacherEmailArray[0]); CheckArr++)
    {
        if(strcmp(TeacherEmailArray[CheckArr], InputEmail) == 0 && strcmp(TeacherPasswordArray[CheckArr], InputPassword) == 0)
        {
            return true;
        }
    }
    return false;
}

char* AlphabetValidation(char InformationType[])
{   
    char* ReturnInput = malloc(100);
    char InputUserLetter[100];

    bool IsAlphabetic;
    do
    {
        IsAlphabetic = false;

        printf("%s", InformationType);
        fgets(InputUserLetter, sizeof(InputUserLetter), stdin);
        InputUserLetter[strlen(InputUserLetter) - 1] = '\0';
        
        for(int CheckLetter = 0; CheckLetter < strlen(InputUserLetter); CheckLetter++)
        {
            if(!isalpha(InputUserLetter[CheckLetter]) && !isspace(InputUserLetter[CheckLetter]))
            {
                printf("Please enter only alphabetical characters and spaces. \n");
                IsAlphabetic = true;
                break;
            }
        }
    } while (IsAlphabetic);

    ReturnInput = InputUserLetter;
    return ReturnInput;
}

char* StuFullNameConcat(char LastName[], char FirstName[], char Middle[])
{
    char* ReturnConcat = malloc(100);
    char FullName[100]; 
    strcpy(FullName, LastName);
    strcat(FullName, ", ");
    strcat(FullName, FirstName);
    strcat(FullName, " ");
    strcat(FullName, Middle);
    
    ReturnConcat = FullName;
    return ReturnConcat;
}
