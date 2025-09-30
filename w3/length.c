#include <stdio.h>

void length(){
    printf("\n-- Length of the String\n");
    int len = 0;
    char str[100];

    printf("Enter the string\n");
    scanf(" %[^\n]s", str);
    while (str[len] != '\0'){
        len = len + 1;
    }
    printf("Length = %d\n", len);
}

void concatination(){
    printf("\n-- Concat of the Strings\n");
    char str1[200];
    char str2[100];

    int i = 0, j = 0;

    printf("\nEnter String 1: ");
    scanf("%s", str1);

    printf("\nEnter String 2: ");
    scanf("%s", str2);

    while (str1[i] != '\0'){
        i++;
    }

    while (str2[j] != '\0'){
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';

    printf("%s\n", str1);
}

void comparison(){
    printf("\n-- Comparison of the Strings\n");
    char str1[100];
    char str2[100];
    int i = 0;

    printf("\nEnter String 1: ");
    scanf("%s", str1);

    printf("\nEnter String 2: ");
    scanf("%s", str2);

    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            break;
        }
        i++;
    }
    int diff = str1[i] - str2[i];
    printf("%d\n", diff);
}

void insertSubstring(){
    printf("\n-- Insert Substring\n");
    char str1[200], str2[100];
    int pos, i = 0, j = 0, len1 = 0, len2 = 0;

    printf("\nEnter main string: ");
    scanf(" %[^\n]s", str1);
    printf("Enter substring to insert: ");
    scanf(" %[^\n]s", str2);
    printf("Enter position to insert at (0-based index): ");
    scanf("%d", &pos);

    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    if (pos > len1) {
        printf("Position is beyond string length.\n");
        return;
    }

    for (i = len1 - 1; i >= pos; i--) {
        str1[i + len2] = str1[i];
    }
    for (j = 0; j < len2; j++) {
        str1[pos + j] = str2[j];
    }

    str1[len1 + len2] = '\0';

    printf("String after insertion: %s\n", str1);
}

void deleteSubstring(){
    printf("\n-- Delete Substring\n");
    char str[200];
    int pos, length, i = 0, len = 0;

    printf("\nEnter the string: ");
    scanf(" %[^\n]s", str);
    printf("Enter position to delete from (0-based index): ");
    scanf("%d", &pos);
    printf("Enter length of substring to delete: ");
    scanf("%d", &length);

    while (str[len] != '\0') len++;

    if (pos >= len || pos < 0 || length < 0) {
        printf("Invalid position or length.\n");
        return;
    }

    if (pos + length > len) {
        length = len - pos;
    }

    for (i = pos; i <= len - length; i++) {
        str[i] = str[i + length];
    }

    printf("String after deletion: %s\n", str);
}

int main(){
    length();
    concatination();
    comparison();
    insertSubstring();
    deleteSubstring();
    return 0;
}
