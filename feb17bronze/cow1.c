#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    FILE *inFile;
    char buff[8];
    int numSightings = 0;
    int cows[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int numCrosses = 0;


    inFile = fopen("crossroad.in", "r");

    fgets(buff, 8, (FILE*)inFile);
    numSightings = atoi(buff);

    int i = 0;
    for (;i < numSightings; i++) {
        fgets(buff, 8, inFile);
        int cowID = buff[0] - '0';
        int roadSide = buff[2] - '0';

        // 10
        if (buff[0] == 49 && buff[1] == 48) {
            printf("aersnt\n");
            cowID = 10;
            roadSide = buff[3] - '0';
        }

        if (cows[cowID - 1] == 2) {
            cows[cowID - 1] = roadSide;
        } else if (cows[cowID - 1] != roadSide) {
            numCrosses++;
            cows[cowID - 1] = roadSide;
        }
    }

    fclose(inFile);


    FILE *outFile;
    outFile = fopen("crossroad.out", "w");

    fprintf(outFile, "%d", numCrosses);
    printf("%d\n", numCrosses);

    fclose(outFile);
}