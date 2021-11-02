#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()


//Function to sort a string alphabetically
char* sort (char* string) {
    char* result = malloc(sizeof(char)*strlen(string)+1);
    strncpy(result, string, strlen(string)+1);
    char temp;
    int i, j;
    int n = strlen(result);
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (result[i] > result[j]) {
                temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    return result;
}

//Function to check whether a jumbled word is equal to a word in the dictionary
int check(char* jumbled, char* dict){
    int jLen = strlen(jumbled);
    int dLen = strlen(dict);
    if(jLen!=dLen){
        return 1;
    }
    else{
        char* sortedJumbled = malloc(sizeof(jLen)+1);
        char* sortedDict = malloc(sizeof(jLen)+1);
        sortedJumbled = sort(jumbled);
        sortedDict = sort(dict);
        if(strcmp(sortedJumbled,sortedDict) == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
}

void readFile(char* dictFile, char* jumbledFile){
    //To access the file of jumbled words
    FILE *ptrJumbles;

    //To access the dictionary file
    FILE *ptrDict;

    char* jumbled = malloc(sizeof(char)*51); //to store the jumbled word which will later be used to check with dictionary
    char* dict = malloc(sizeof(char)*51); //to store the dictionary word


    char c;
    char c1;


    // Open file for jumbled words
    ptrJumbles = fopen(jumbledFile, "r");
    if (ptrJumbles == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    //Open file for dictionary

    ptrDict = fopen(dictFile, "r");
    if (ptrDict == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    fclose(ptrDict);

    // Read contents from file
    c = fgetc(ptrJumbles);

    //count number of matching words for each jumbled word
    int count = 0;

    //Read content from jumbled file
    while (c != EOF)
    {
        int i=0;

        //Store jumbled word in var: jumbled
        while(c != '\n'){
            if(c==EOF){
                break;
            }
            jumbled[i] = c;
            i++;
            c = fgetc(ptrJumbles);
        }

        //Print jumbled word
        printf("%s: ", jumbled);

        //Read content from Dictionary
        ptrDict = fopen(dictFile, "r");
        c1 = fgetc(ptrDict);
        while(c1 != EOF){
            int i = 0;

            //Store word from dictionary in  var: dict
            if(c1 == '\n'){
                c1 = fgetc(ptrDict);
            }
            while(c1 != '\n'){
                if(c1 == EOF){
                    fclose(ptrDict);
                    break;
                }
                dict[i] = c1;
                i++;
                c1 = fgetc(ptrDict);
            }

            //check if the two words are equal, print if it is equal
            if(check(jumbled,dict) == 0){
                printf("%s ", dict);
                count+=1;
            }
            memset(dict, 0, sizeof(char)*51);

        }
        if(c == '\n'){
            if(count==0){
                printf("NO MATCHES");
            }
            printf("\n");
            c = fgetc(ptrJumbles);
            memset(jumbled, 0, sizeof jumbled);
            count=0;
        }
    }
    fclose(ptrJumbles);
    fclose(ptrDict);
}


int main(int argc, char *argv[])
{
    readFile(argv[1],argv[2]);
    return 0;
}