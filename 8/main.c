#include <stdio.h>
#include <stdlib.h>


//  Funcția de conversie zecimala in binară
void decimalToBinary(int decimalNumber);

// Funcție de conversie zecimala in octală
void decimalToOctal(int decimalNumber);

// Funcție de conversie zecimala in hexazecimală
void decimalToHexadecimal(int decimalNumber);

// Funcție de conversie hexazecimală în binar
void hexadecimalToBinary(char hexadecimalNumber[]);
//Funcție de conversie hexazecimală în octal
void hexadecimalToOctal(char hexadecimalNumber[]);

// Funcție de conversie hexazecimală în zecimală
void hexadecimalToDecimal(char hexadecimalNumber[]);


// Funcția de conversie binar în hexazecimal
void binaryToHexadecimal(char binaryNumber[]);


// Funcție de conversie binar în octal
void binaryToOctal(char binaryNumber[]);

// Funcția de conversie binar în zecimal
void binaryToDecimal(char binaryNumber[]);



int main() {
    int decimalNumber, Base, choice;
     char hexadecimalNumber[100];
     char binaryNumber[100];

  printf("Alegeti optiunea:\n");
    printf("1. Decimal -> Binare, Octal, Hexazecimal\n");
    printf("2. Hexazecimal -> Decimal, Binare, Octal\n");
    printf("3. Binare -> Decimal, Octal, Hexazecimal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
             // Introduceți numărul decimal
    printf("Introduceti numarul decimal: ");
    scanf("%d", &decimalNumber);

    // Apelul funcției de conversie
    decimalToBinary(decimalNumber);
    decimalToOctal(decimalNumber);
    decimalToHexadecimal(decimalNumber);
            break;
        case 2:
           // Introduceți numărul hexazecimal
    printf("Introduceti numarul hexazecimal: ");
    scanf("%s", hexadecimalNumber);

    //  Apelul funcției de conversie
    hexadecimalToBinary(hexadecimalNumber);
    hexadecimalToOctal(hexadecimalNumber);
    hexadecimalToDecimal(hexadecimalNumber);
            break;
        case 3:
              // Introduceți numărul binar
   printf("Introduceti numarul binar: ");
    scanf("%s", binaryNumber);

    // Apelul funcției de conversie
    binaryToHexadecimal(binaryNumber);
    binaryToOctal(binaryNumber);
    binaryToDecimal(binaryNumber);

            break;
        default:
                printf("\nNumăr nevalid!\n");

    }


    return 0;
}
// Funcția de conversie zecimala in binară
void decimalToBinary(int decimalNumber) {
    if (decimalNumber == 0) {
        printf("Reprezentare binară: 0/n");
        return;
    }

    int binaryNumber[32];  // Lungime maximă 32 de biți
    int i = 0;

    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }

    printf("Reprezentare binară: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
    }
    printf("\n");
}

// Funcție de conversie zecimala in octală
void decimalToOctal(int decimalNumber) {
    if (decimalNumber == 0) {
        printf("Reprezentare octală: 0\n");
        return;
    }

    int octalNumber[32];
    int i = 0;

    while (decimalNumber > 0) {
        octalNumber[i] = decimalNumber % 8;
        decimalNumber /= 8;
        i++;
    }

    printf("Reprezentare octală: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octalNumber[j]);
    }
    printf("\n");
}

// Funcție de conversie zecimala in hexazecimală
void decimalToHexadecimal(int decimalNumber) {
    if (decimalNumber == 0) {
        printf("Reprezentare hexazecimală: 0\n");
        return;
    }

    char hexadecimalNumber[32];
    int i = 0;

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10) {
            hexadecimalNumber[i] = remainder + '0';
        } else {
            hexadecimalNumber[i] = remainder - 10 + 'A';
        }
        decimalNumber /= 16;
        i++;
    }

    printf("Reprezentare hexazecimală: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }
    printf("\n");
}

// Funcție de conversie hexazecimală în binar
void hexadecimalToBinary(char hexadecimalNumber[]) {
    int binaryNumber[32];  // Lungime maximă 32 de biți
    int i, j;
printf("Binar: ");
    // Conversia fiecărui caracter hexazecimal în notație binară
    for (i = 0; hexadecimalNumber[i] != '\0'; i++) {
        switch (hexadecimalNumber[i]) {
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
            case 'a':
                printf("1010");
                break;
            case 'B':
            case 'b':
                printf("1011");
                break;
            case 'C':
            case 'c':
                printf("1100");
                break;
            case 'D':
            case 'd':
                printf("1101");
                break;
            case 'E':
            case 'e':
                printf("1110");
                break;
            case 'F':
            case 'f':
                printf("1111");
                break;
            default:
                printf("\nNumăr hexazecimal nevalid!\n");
                return;
        }
    }

    printf("\n");
}

// Funcție de conversie hexazecimală în octal
void hexadecimalToOctal(char hexadecimalNumber[]) {
    long int decimalNumber = 0;
    int octalNumber[100], i = 0;

    // Conversia notației hexazecimale în zecimală
    for (i = 0; hexadecimalNumber[i] != '\0'; i++) {
        if (hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9') {
            decimalNumber = decimalNumber * 16 + (hexadecimalNumber[i] - '0');
        } else if (hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F') {
            decimalNumber = decimalNumber * 16 + (hexadecimalNumber[i] - 'A' + 10);
        } else if (hexadecimalNumber[i] >= 'a' && hexadecimalNumber[i] <= 'f') {
            decimalNumber = decimalNumber * 16 + (hexadecimalNumber[i] - 'a' + 10);
        }
    }

    i = 0;

    // Conversia notației zecimale în octale
    while (decimalNumber != 0) {
        octalNumber[i] = decimalNumber % 8;
        decimalNumber /= 8;
        i++;
    }

    printf("Reprezentare octală: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", octalNumber[i]);
    }
    printf("\n");
}

// Funcție de conversie hexazecimală în zecimală
void hexadecimalToDecimal(char hexadecimalNumber[]) {
    long int decimalNumber = 0;
    int i, val, len;

    // Aflarea lungimii unui număr hexazecimal
    len = strlen(hexadecimalNumber);
    len--;

    // Conversia notației hexazecimale în zecimală
    for (i = 0; hexadecimalNumber[i] != '\0'; i++) {
        if (hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9') {
            val = hexadecimalNumber[i] - 48; // ascii cod 48 (0)
        } else if (hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F') {
            val = hexadecimalNumber[i] - 65 + 10; //asci cod 65(A)
        } else if (hexadecimalNumber[i] >= 'a' && hexadecimalNumber[i] <= 'f') {
            val = hexadecimalNumber[i] - 97 + 10; //ascii cod 97(a)
        }

        decimalNumber += val * pow(16, len);
        len--;
    }

    printf("Reprezentare zecimală: %ld\n", decimalNumber);
}


// Funcția de conversie binar în hexazecimal
void binaryToHexadecimal(char binaryNumber[]) {
    int decimalNumber = 0, i, j, remainder;
    char hexadecimalNumber[100];

    //Conversia notației binare în zecimală
    for (i = strlen(binaryNumber) - 1, j = 0; i >= 0; i--, j++) {
        decimalNumber += (binaryNumber[i] - '0') * pow(2, j);
    }

    // Conversia zecimală în notație hexazecimală
    i = 0;
    while (decimalNumber != 0) {
        remainder = decimalNumber % 16;
        if (remainder < 10) {
            hexadecimalNumber[i] = remainder + '0';
        } else {
            hexadecimalNumber[i] = remainder - 10 + 'A';
        }
        decimalNumber /= 16;
        i++;
    }

    // Scrierea notației hexazecimale înapoi
    printf("Reprezentare hexazecimală: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }
    printf("\n");
}

// Funcție de conversie binar în octal
void binaryToOctal(char binaryNumber[]) {
    int decimalNumber = 0, i, j, remainder;
    int octalNumber[100];

    // Conversia  binare în zecimală
    for (i = strlen(binaryNumber) - 1, j = 0; i >= 0; i--, j++) {
        decimalNumber += (binaryNumber[i] - '0') * pow(2, j);
    }

    // Conversie zecimală în octală
    i = 0;
    while (decimalNumber != 0) {
        octalNumber[i] = decimalNumber % 8;
        decimalNumber /= 8;
        i++;
    }

    // Scrierea notației octale înapoi
    printf("Reprezentare octală: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%d", octalNumber[j]);
    }
    printf("\n");
}

// Funcția de conversie binar în zecimal
void binaryToDecimal(char binaryNumber[]) {
    int decimalNumber = 0, i, j;

    // Conversia binarului în zecimal
    for (i = strlen(binaryNumber) - 1, j = 0; i >= 0; i--, j++) {
        decimalNumber += (binaryNumber[i] - '0') * pow(2, j);
    }

    printf("Reprezentare zecimală: %d\n", decimalNumber);
}



