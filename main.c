#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void bcd(int nombre);

void sm(int nombre);

void complement2n(int nombre);

unsigned int passageDecimalABinaire(unsigned int nombre, unsigned int tableau[]);

int main(void) {
    while (1) {
        printf("Entrez un nombre et le format souhaité : ");
        char commande[100];
        fgets(commande, sizeof(commande), stdin);
        if (strcmp(commande, "exit\n") == 0)
            return 0;
        int nombre;
        sscanf(commande, "%d %s", &nombre, commande);
        for (unsigned int i = 0; i < strlen(commande); ++i)
            commande[i] = (char) tolower(commande[i]);
        if (strcmp(commande, "bcd") == 0)
            bcd(nombre);
        else if (strcmp(commande, "2sm") == 0)
            sm(nombre);
        else if (strcmp(commande, "c2n") == 0)
            complement2n(nombre);
        else
            printf("Commande inconnue");
        printf("\n");
        fflush(stdin);
    }
}

void bcd(int nombre) {
    if (nombre < 0) {
        printf("Nombre incorrect (négatif)");
        return;
    }
    char compteur[20];
    sprintf(compteur, "%d", nombre);
    unsigned int *chiffres = malloc(strlen(compteur) * sizeof(unsigned int));
    unsigned int nombrebkp = nombre;
    for (unsigned int i = 0; nombre > 0; ++i) {
        chiffres[i] = nombre % 10;
        nombre /= 10;
    }
    printf("Le nombre %u en BCD est : ", nombrebkp);
    for (int i = (int) strlen(compteur) - 1; i >= 0; --i) {
        unsigned int tableau[4];
        unsigned int count = passageDecimalABinaire(chiffres[i], tableau);
        for (unsigned int j = 0; j < 4 - count; ++j)
            printf("0");
        for (unsigned int j = 0; j < count; ++j)
            printf("%u", tableau[count - j - 1]);
        printf(" ");
    }
    free(chiffres);
}

void sm(int nombre) {
    unsigned int signe;
    if (nombre < 0)
        signe = 1;
    else signe = 0;
    char compteur[20];
    sprintf(compteur, "%d", nombre);
    unsigned int *tableau = malloc(strlen(compteur) * sizeof(unsigned int));
    unsigned int count = passageDecimalABinaire(abs(nombre), tableau);
    printf("Le nombre %d en 2sm est : %u ", nombre, signe);
    for (unsigned int i = 0; i < count; ++i) {
        if ((count - i) % 4 == 0 && i != 0)
            printf(" ");
        printf("%u", tableau[count - i - 1]);
    }
    free(tableau);
}

void complement2n(int nombre) {
    unsigned int tailleBits = (unsigned int) (log2(abs(nombre)) + 1) + 1;
    unsigned int masque = (unsigned int) pow(2, tailleBits) - 1;
    printf("Le nombre %d en complément à 2n est : ", nombre);
    if (nombre >= 0) {
        unsigned int tableau[tailleBits];
        unsigned int count = passageDecimalABinaire(nombre, tableau);
        for (unsigned int i = 0; i < count; ++i) {
            if ((count - i) % 4 == 0 && i != 0)
                printf(" ");
            printf("%u", tableau[count - i - 1]);
        }
    } else {
        unsigned int nombreComplement2 = (unsigned int) (nombre & masque);
        unsigned int tableau[tailleBits];
        unsigned int count = passageDecimalABinaire(nombreComplement2, tableau);
        for (unsigned int i = 0; i < count; ++i) {
            if ((count - i) % 4 == 0 && i != 0)
                printf(" ");
            printf("%u", tableau[count - i - 1]);
        }
    }
}

unsigned int passageDecimalABinaire(unsigned int nombre, unsigned int tableau[]) {
    unsigned int indiceTableau = 0;
    unsigned int i = 0;
    while (nombre > 0) {
        tableau[i] = nombre % 2;
        nombre /= 2;
        i++;
        indiceTableau++;
    }
    return indiceTableau;
}
