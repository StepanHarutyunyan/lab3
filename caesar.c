#include <stdio.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = (text[i] + shift) % 128;
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 128 - (shift % 128));
}

int main() {
    char text[100];
    int shift;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter shift (1-127): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 127) {
        printf("Shift must be between 1 and 127.\n");
        return 1;
    }

    encrypt(text, shift);
    printf("Encrypted text: ");
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
    }
    printf("\n");

    decrypt(text, shift);
    printf("Decrypted text: ");
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
    }
    printf("\n");

    return 0;
}
