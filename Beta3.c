#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

char* AlphabetValidation(char InformationType[]);
char* StuFullNameConcat(char LastName[], char FirstName[], char Middle[]);
char* DigitValidation(char Number[]);



int main()
{
    printf("Automated Grade Management System\n\n");

    char UserEmailInput[100], UserPasswordInput[100];
    char LastNameText[20] = "Last Name: ", FirstNameText[20] = "First Name: ", MiddleNameText[20] = "Middle Name: ";
    char ITC_SubText[50] = "Introduction to Computing: ", ComProg_SubText[50] = "Computer Programmer: ", PurCom_SubText[50] = "Purposive Communication: ", RPH_SubText[50] = "Reading in Philippine History: ", TWC_SubText[50] = "The Cotemporary World: ";
    char StudentLastName[100], StudentFirstName[100], StudentMiddleName[100], StudentFullName[100];
    char ITC_Sub[5], ComProg_Sub[5], PurCom_Sub[5], RPH_Sub[5], TWC_Sub[5];
    float FinalGrade;
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

        if(strcmp(UserEmailInput, "1") == 0 && strcmp(UserPasswordInput, "1") == 0)
        {   
            printf("No Student Record Yet!\n");
            while (true)
            {
                printf("\n+--------------------------+");
                printf("\n| ADD STUDENT RECORD -   A |");
                printf("\n| BACK               -   B |");
                printf("\n+--------------------------+");

                printf("\nChoose: ");
                fgets(Choose, sizeof(Choose), stdin);
                Choose[strlen(Choose) - 1] = '\0';

                if(strcmp(Choose, "A") == 0 || strcmp(Choose, "a") == 0)
                {
                    strcpy(StudentLastName, AlphabetValidation(LastNameText));
                    strcpy(StudentFirstName, AlphabetValidation(FirstNameText));
                    strcpy(StudentMiddleName, AlphabetValidation(MiddleNameText));
                    strcpy(StudentFullName, StuFullNameConcat(StudentLastName, StudentFirstName, StudentMiddleName));
                    strcpy(ITC_Sub, DigitValidation(ITC_SubText));
                    strcpy(ComProg_Sub, DigitValidation(ComProg_SubText));
                    strcpy(PurCom_Sub, DigitValidation(PurCom_SubText));
                    strcpy(RPH_Sub, DigitValidation(RPH_SubText));
                    strcpy(TWC_Sub, DigitValidation(TWC_SubText));
                    printf("ITC Grade: %s\nComProg Grade: %s\nPurCom Grade: %s\nRPH Grade: %s\nTCW Grade: %s", 
                            ITC_Sub, 
                            ComProg_Sub, 
                            PurCom_Sub, 
                            RPH_Sub, 
                            TWC_Sub
                        );
                    FinalGrade = (atof(ITC_Sub) + atof(ComProg_Sub) + atof(PurCom_Sub) + atof(RPH_Sub) + atof(TWC_Sub)) / 5;
                    printf("Final Grade: %.2f", FinalGrade);
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

char* DigitValidation(char Number[])
{
    char* ReturnInput = malloc(100);
    char InputUserNumber[100];
    int StrToInt;

    bool IsNumber;
    do
    {
        IsNumber = false;
        printf("%s", Number);
        fgets(InputUserNumber, sizeof(InputUserNumber), stdin);
        InputUserNumber[strlen(InputUserNumber) - 1] = '\0';

        for(int CheckNumber = 0; CheckNumber < strlen(InputUserNumber); CheckNumber++)
        {
            if(!isdigit(InputUserNumber[CheckNumber]))
            {
                printf("Please enter only digit(s).\n");
                IsNumber = true;
                break;
            }
        }
    } while (IsNumber);

    StrToInt = atoi(InputUserNumber);
    if(StrToInt >= 50 && StrToInt <= 100)
    {
        printf("\nCorrect grade range.\n");
        ReturnInput = InputUserNumber;
        return ReturnInput;
    }
    else
    {
        printf("\nIncorrect grade input, Correct range (50 - 100)\n");
        DigitValidation(Number);
    }
}
