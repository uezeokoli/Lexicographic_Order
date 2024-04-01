// /****************************************************************************************
// *  Ugonna Ezeokoli
// *  uezeokol
// *  2024 Winter CSE101 PA1 
// *  Lex.c
// *  Reads the input file and outputs the contents of it in lexicographical order
// *****************************************************************************************/

#include "List.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    if (argc != 3){
        fprintf(stderr, "Invalid number of command line arguments\n");
        exit(EXIT_FAILURE);
    }
    FILE *output = fopen(argv[2],"w");
    FILE *input = fopen(argv[1], "r");
    if (input == NULL){
        // fclose(input);
        fclose(output);
        fprintf(stderr, "Invalid file\n");
        exit(EXIT_FAILURE);
    }

    int num_lines = 0;
    char word[500];
    // Finds number of lines in the text file
    while(1){
        if (fgets(word, 500, input)== NULL){
            break;
        }
        num_lines++;
    }
    fclose(input);
    input = fopen(argv[1], "r");
    char **arr = (char **) calloc(num_lines+1, sizeof(char *));
    for (int ind = 0; ind < num_lines; ind++){
        arr[ind] = (char *)calloc(500, sizeof(char));
    }
    // char arr[num_lines][100];
    int ind = 0;
    
    //adds string from each line into string array
    
    while(1){
        if (fgets(arr[ind], 100, input)== NULL){
            break;
        }
        ind++;

    }
    //adds the \n to the last word
    // char *last_word = strcat(arr[ind-1], "\n");
    strcat(arr[ind-1], "\n");
    //strcpy(arr[ind-1],last_word);

    List sort_list = newList();
    //Insertion sort method
    for (int i = 0; i<ind ;i++){
        if (length(sort_list) == 0){
            append(sort_list,i);
        }
        else{
            moveFront(sort_list);
            for (int x = 0; x<length(sort_list);x++){
                if(strcmp(arr[i],arr[get(sort_list)])<0){
                    insertBefore(sort_list,i);
                    break;
                }
                if(x == length(sort_list)-1){
                    insertAfter(sort_list, i);
                    break;
                }
                moveNext(sort_list);
            }
        }
    }
    // printList(stdout,sort_list);
    // printf("\n");

    moveFront(sort_list);
    for (int i = 0; i < length(sort_list);i++){
        // if (i == length(sort_list)-1){
            // This removes the \n for the last word
            // if (strstr(arr[get(sort_list)], "\n") != NULL){
            //         char *last_word = arr[get(sort_list)];
            //         size_t length = strlen(last_word);
            //         char remove_endl[1000];
            //         strncpy(remove_endl,arr[get(sort_list)], length-2);
            //         fprintf(output, "%s",remove_endl);
            //         break;
            // }
        // }
        fprintf(output,"%s", arr[get(sort_list)]);
        moveNext(sort_list);
    }
    freeList(&sort_list);
    for (int i = 0; i < num_lines; i++){
        free(arr[i]);
    }
    free(arr);
    fclose(output);
    fclose(input);
}
