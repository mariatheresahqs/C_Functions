#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void alocateMatrix(int ***matrix, int line, int column);
void showMatrix(int** matrix, int line, int column);

int main(){
    char str[] = "Let's break this string into pieces";


    // Breaking a fixed string
    // string token
    char *piece = strtok(str, " ");
    while(piece!=NULL){
        printf("%s\n", piece);
        piece = strtok(NULL, " ");
    }
    printf("\n");


    /**************************************
    *   PASSING STRING FROM FILE          *
    ***************************************/
    char nameFile[25];
    char text[100];
    FILE *fileName;
    int line, column, data, columnBeginning, columnFinal, lineBeginning, lineFinal;
    int **matrix;

    printf("Enter the file name: ");
            scanf("%s", nameFile);
            fileName = fopen (nameFile, "r");
            if (fileName == NULL) {
                printf("Error reading the file name!\n");
                printf("Try again.\n");
            } else {
                printf("\nFile successfully uploaded!! \n");
                fscanf(fileName, "%d %d %d ", &line, &column, &data);
                alocateMatrix(&matrix, line, column);

                // Read line
                for(int i=0;i<line;i++){
                    fgets(text, 100, fileName);
                    if(i < line-1)
                        text[strlen(text)-1] = '\0';
                    else
                        text[strlen(text)] = '\0';

                    // Break line in pieces of strings
                    char *piece = strtok(text, " ");
                    int contcolumn = 0;
                    while(piece!=NULL){
                        
                        // Compare strings with I and F
                        if(!strcmp(piece, "F")){
                            piece = "X";
                            lineFinal = i;
                            columnFinal = contcolumn;
                        }
                        if(!strcmp(piece, "I")){
                            piece = "X";
                            lineBeginning = i;
                            columnBeginning = contcolumn;
                        }
                        // printf("%s ", piece);
                        
                        // Convert strings to int type and
                        // put values into matrix position
                        matrix[i][contcolumn] = atoi(piece);
                        piece = strtok(NULL, " ");
                        contcolumn++;
                    }
                }
                
            }
    showMatrix(matrix, line, column);
    return 0;
}

void alocateMatrix(int ***matrix, int line, int column){
    *matrix = (int**)malloc(line*(sizeof(int*))); 

    for(int i=0; i<line; i++){
        (*matrix)[i] = (int*)malloc(column*(sizeof(int)));
    }
}

void showMatrix(int** matrix, int line, int column){
    printf("\nShowing matrix:\n");
    for(int i =0; i<line; i++){
        for(int j=0; j<column;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
