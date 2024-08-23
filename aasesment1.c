#include <stdio.h>
#include <string.h>

void reverseS(char str[]);
void concatenateS(char str1[], char str2[], char result[]);
int Palindrome(char str[]);
void copyS(char dest[], const char src[]);
int stringL(const char str[]);
int charF(const char str[], char ch);
int countVowels(const char str[]);
int countConsonants(const char str[]);
int countBlankSpaces(const char str[]);
int countDigits(const char str[]);

void main() {
    char str[100], str2[100], concatenated[200],ch;
    int choice,length, frequency;

    do {
        
        printf("\nChoose a number :\n");
        printf("\n 1. Reverse string");
        printf("\n 2. Concatenate string");
        printf("\n 3. Check palindrome");
        printf("\n 4. Copy string");
        printf("\n 5. length of string");
        printf("\n 6. frequency of character");
        printf("\n 7. Count vowels and consonants");
        printf("\n 8. Count blank spaces and digits");
        printf("\n 9. Exit\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch(choice) {
            case 1:
                printf("Enter string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; 
                
                char reversed[100];
                strcpy(reversed, str);
                reverseS(reversed);
                printf("Reversed string: %s\n", reversed);
                break;

            case 2: 
                printf("Enter the first string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';  

                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; 
                
                concatenateS(str, str2, concatenated);
                printf("Concatenated string: %s\n", concatenated);
                break;

            case 3: 
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';  
                
                if (Palindrome(str)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;

            case 4: 
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; 
                
                char copied[100];
                copyS(copied, str);
                printf("Copied string: %s\n", copied);
                break;

            case 5: 
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';  
                
                length = stringL(str);
                printf("Length of the string: %d\n", length);
                break;

            case 6: 
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; 

                printf("Enter a character to find its frequency: ");
                scanf(" %c", &ch);  
                
                frequency = charF(str, ch);
                printf("Frequency of '%c': %d\n", ch, frequency);
                break;

            case 7: 
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0'; 
                
                printf("Number of vowels: %d\n", countVowels(str));
                printf("Number of consonants: %d\n", countConsonants(str));
                break;

            case 8: 
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';  

                printf("Number of blank spaces: %d\n", countBlankSpaces(str));
                printf("Number of digits: %d\n", countDigits(str));
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);


}

void reverseS(char str[]) {
    int start = 0;
    int end = stringL(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


void concatenateS(char str1[], char str2[], char result[]) {
    strcpy(result, str1);
    strcat(result, str2);
}

int Palindrome(char str[]) {
    int start = 0;
    int end = stringL(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0; 
        }
        start++;
        end--;
    }
    return 1; 
}


void copyS(char dest[], const char src[]) {
    strcpy(dest, src);
}

int stringL(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int charF(const char str[], char ch) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            count++;
        }
        i++;
    }
    return count;
}

int countVowels(const char str[]) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
        i++;
    }
    return count;
}

int countConsonants(const char str[]) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                  ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
                count++;
            }
        }
        i++;
    }
    return count;
}
int countBlankSpaces(const char str[]) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            count++;
        }
        i++;
    }
    return count;
}

int countDigits(const char str[]) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
        i++;
    }
    return count;
}
