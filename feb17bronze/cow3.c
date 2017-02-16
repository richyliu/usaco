#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int cmp(const void *a,const void *b) {
    return ((const int*)a)[0] - ((const int*)b)[0];
}



int main() {
    FILE *inFile;
    char buff[16];
    int numCows = 0;

    inFile = fopen("cowqueue.in", "r");

    fgets(buff, 16, (FILE*)inFile);
    numCows = atoi(buff);
    int cows[numCows][2];


    int i = 0;
    for (;i < numCows; i++) {
        fgets(buff, 16, inFile);
        cows[i][0] = atoi(strtok(buff, " "));
        cows[i][1] = atoi(strtok(NULL, " "));
    }

    qsort(cows, numCows, 2 * sizeof(int), cmp);

    i = 1; // dont use first one
    for (;i < numCows; i++) {
        int prevEnd = cows[i - 1][0] + cows[i - 1][1];

        // only if no time in between
        if (prevEnd > cows[i][0]) {
            cows[i][0] = prevEnd; // fit as tightly as possible
        }
    }


    printf("%d\n", cows[numCows - 1][0] + cows[numCows - 1][1]);


    fclose(inFile);


    // print output
    FILE *outFile;
    outFile = fopen("cowqueue.out", "w");

    fprintf(outFile, "%d", cows[numCows - 1][0] + cows[numCows - 1][1]);

    fclose(outFile);
}