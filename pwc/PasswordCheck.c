#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {
    srand(time(NULL));
    unsigned int PrivateKeyLength,PublicKeyLength,CheckYourPassword,NumberOfSpecialCharachers,NumberOfDigits,NumberOfUperCaseLetters,NumberOfLowerCaseLetters,LookingForNumbers,LookingForSpecialCharacters,LookingForLowerCaseLetters,LookingForUpperCaseLetters; //ValidateYourPassword, not used
    char ListOfUpperCaseLetters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
    char ListOfLowerCaseLetters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y'};
    char SpecialCharachers[] = {' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','@','[','\\',']','^','_','`','{','|','}'};
    char ListOfNumbers[] = {'0','1','2','3','4','5','6','7','8','9'};
    PrivateKeyLength = 8192; PublicKeyLength = 262144; CheckYourPassword = 0; NumberOfDigits = 0; NumberOfLowerCaseLetters = 0; NumberOfSpecialCharachers = 0; NumberOfUperCaseLetters = 0; LookingForLowerCaseLetters = 0; LookingForNumbers = 0; LookingForSpecialCharacters = 0; LookingForUpperCaseLetters = 0;
    char * PrivateKey = malloc(PrivateKeyLength);
    char * PublicKey = malloc(PublicKeyLength);
    //char Comment[32];
    printf("Enter Your Password "); fgets(PrivateKey,PrivateKeyLength,stdin); PrivateKey[strlen(PrivateKey)-1] = 0;
    while (strlen(PrivateKey) < 16)
    {
        printf("Your Password Is Too Short.\nRetype Your Password "); fgets(PrivateKey,PrivateKeyLength,stdin); PrivateKey[strlen(PrivateKey)-1] = 0;
    }
    do
    {
        LookingForLowerCaseLetters = 0; LookingForNumbers = 0; LookingForSpecialCharacters = 0; LookingForUpperCaseLetters = 0;
        while (LookingForUpperCaseLetters != 26)
        {
            if (PrivateKey[CheckYourPassword] == ListOfUpperCaseLetters[LookingForUpperCaseLetters])
            {
                NumberOfUperCaseLetters++;
            }
            LookingForUpperCaseLetters++;
        }
        while (LookingForLowerCaseLetters != 26)
        {
            if (PrivateKey[CheckYourPassword] == ListOfLowerCaseLetters[LookingForLowerCaseLetters])
            {
                NumberOfLowerCaseLetters++;
            }
            LookingForLowerCaseLetters++;
        }
        while (LookingForSpecialCharacters != 32)
        {
            if (PrivateKey[CheckYourPassword] == SpecialCharachers[LookingForSpecialCharacters])
            {
                NumberOfSpecialCharachers++;
            }
            LookingForSpecialCharacters++;
        }
        while (LookingForNumbers != 11)
        {
            if (PrivateKey[CheckYourPassword] == ListOfNumbers[LookingForNumbers])
            {
                NumberOfDigits++;
            }
            LookingForNumbers++;
        }
        CheckYourPassword++;
    } while (CheckYourPassword != (unsigned int)(strlen(PrivateKey)-1));

    printf("Your Password Length is   |%04d|\n",(int)(strlen(PrivateKey)));
    printf("Your Password Stregth is  |%04d|\n",(NumberOfDigits*2)+(NumberOfLowerCaseLetters*2)+(NumberOfUperCaseLetters*2)+(NumberOfSpecialCharachers*2));
    printf("Number Upper Case Letters |%04d|\n",NumberOfUperCaseLetters);
    printf("Number Lower Case Letters |%04d|\n",NumberOfLowerCaseLetters);
    printf("Number Special Charcters  |%04d|\n",NumberOfSpecialCharachers);
    printf("Number Of Digits are      |%04d|\n",NumberOfDigits);
    free(PrivateKey);free(PublicKey);
    return 0;
}