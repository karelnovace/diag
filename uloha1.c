#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
int main(int argc, char **argv){

    if(argc != 3){
        printf("chyba");
        return 1;
    }

    int m = atoi(argv[1]);
    int p = atoi(argv[2]);

    if(m <= 0){
        printf("velikost matice musi byt kladne cislo\n");
        return 1;
    }


    char matice[m][m];

    //alokace matice pro poklad
    char** platno = (char**)malloc(m * sizeof(char*));
    for(int i = 0; i < m; i++) {
        platno[i] = (char*)malloc(m * sizeof(char));
        for(int j = 0; j < m; j++) {
            scanf(" %c", &matice[i][j]);
        }
    }

    for(int i = 0; i < p; i++){
        int row;
        int col;
        int smer;

        scanf("%d %d %s", row, col, smer);

        int najdi = 0;
        if(smer == 'H'){
            for(int j = col; j < m; j++){
                if(matice[row][j] == 'T'){
                    najdi = 1;
                    break;
                }

                if(matice[row][j] == 'X'){
                    break;  
                }
            }
        }

        else if(smer == 'V') {
            for(int i = row; i < m; i++) {
                if (matice[i][col] == 'T'){
                    najdi = 1;
                    break;
                }

                if(matice[i][col] == 'X'){
                    break;  
                }
            }
        }

        if(najdi){
            printf("%d", najdi);
        }

    }

    //vytisk matice pokladu
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", matice[i][j]);
        }
        printf("\n");
    }


    
   



    for (int i = 0; i < m; i++) {
        free(platno[i]);
    }
    free(platno);
    

    return 0;
}
*/

/*
void processInstruction(char map[][100], int crossed[][100], int m, int startRow, int startCol, char direction) {
    if (direction == 'H') {  // horizontální směr
        for (int col = startCol; col < m; col++) {
            if (map[startRow][col] == 'X') break; // narazíme na překážku
            crossed[startRow][col] = 1;  // označíme místo jako vyškrtnuté
            if (map[startRow][col] == 'T') break;  // pokud je to část pokladu, vyškrtneme ji
        }
    } else if (direction == 'V') {  // vertikální směr
        for (int row = startRow; row < m; row++) {
            if (map[row][startCol] == 'X') break; // narazíme na překážku
            crossed[row][startCol] = 1;  // označíme místo jako vyškrtnuté
            if (map[row][startCol] == 'T') break;  // pokud je to část pokladu, vyškrtneme ji
        }
    }
}

int main(int argc, char **argv) {

    if(argc != 3){
        printf("chyba");
        return 1;
    }
    
    int m = atoi(argv[1]);
    int p = atoi(argv[2]);

    
    char map[m][100];  // Mapa pokladu
    int crossed[100][100];  // Pomocné pole pro označení vyškrtnutých míst

    // Inicializace pole crossed na 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            crossed[i][j] = 0;  // Všechna pole nastavíme na 0 (nevyškrtnuto)
        }
    }

    // Načteme mapu
    for (int i = 0; i < m; i++) {
        scanf("%s", map[i]);
    }

    // Načteme pokyny
    for (int i = 0; i < p; i++) {
        int startRow, startCol;
        char direction;
        scanf("%d %d %c", &startRow, &startCol, &direction);
        processInstruction(map, crossed, m, startRow, startCol, direction);
    }

    // Vytvoření výstupu: projdeme mapu a vytiskneme všechny nevyškrtnuté části pokladu
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'T' && crossed[i][j] == 0) {
                printf("%c", 'T');
            }
        }
    }

    printf("\n");

    return 0;
}
*/


int main(int argc, char **argv){

    if(argc != 3){
        printf("chyba");
        return 1;
    }

    int m = atoi(argv[1]);
    int p = atoi(argv[2]);

    if(m <= 0){
        printf("velikost matice musi byt kladne cislo\n");
        return 1;
    }

    char matice[100][100];
    if(m > 100){
        printf("chyba");
    }

    char x[101];
    for(int i = 0; i < m; i++) {
        if(fgets(x, sizeof(x), stdin) != NULL){
            for(int j = 0; j < m; j++){
                matice[j][i] = x[j];
            }
        }
        
    }

    printf("zadal si: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf(" %c", matice[j][i]);
        }
        printf("\n");
    }

    int px = 0;
    int py = 0;
    char smer;

    for(int i = 0; i < p; i++){
        if(fgets(x, sizeof(x), stdin) != NULL){

            char *token = strtok(x, " ");
            if(token != NULL){
                px = atoi(token);
            }

            token = strtok(NULL, " ");
            if(token != NULL){
                py = atoi(token);
            }

            token = strtok(NULL, " ");
            if(token != NULL){
                smer = token[0];
            }
            printf("px %d py %d smer %c", px, py, smer);
        }

        if(smer == 'H'){
            for(int i = px; i < m; i++){
                if(matice[i][py] == 'X'){
                    break;
                }

                if(matice[i][py] == 'T'){
                    matice[i][py] = '.';
                }
            }
        }

        else if(smer == 'V'){
            for(int j = py; j < m; j++){
                if(matice[px][j] == 'X'){
                    break;
                }

                if(matice[px][j] == 'T'){
                    matice[px][j] = '.';
                }
            }
        }

        else if (smer == 'L') { // Diagonála zleva nahoře do prava dole
            for (int i = 0; px + i < m && py + i < m; i++) {
                if (matice[px + i][py + i] == 'X') {
                    break;
                }

                if (matice[px + i][py + i] == 'T') {
                    matice[px + i][py + i] = '.';
                }
            }

        }

        else if (smer == 'R') { // Diagonála zprava nahoře do leva dole
            for (int i = 0; px - i >= 0 && py + i < m; i++) {
                if (matice[px - i][py + i] == 'X') {
                    break;
                }

                if (matice[px - i][py + i] == 'T') {
                    matice[px - i][py + i] = '.';
                }
            }
        }

        else{
            break;
        }

    }


    printf("vzsledek je: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf(" %c", matice[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}