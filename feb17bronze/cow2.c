#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    FILE *inFile;
    char paths[53];
    int crosses = 0;
    // 0 is not checked; 1 is checked; 2 is first pair found
    int cows[26][3] = {
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0},
        {-1, -1, 0}
    };
    int positions[52] = {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1
    };


    inFile = fopen("circlecross.in", "r");

    fgets(paths, 53, (FILE*)inFile);

    printf("%s\n", paths);

    // int i = 0;
    // for (; i < 52; i++) {
    //     printf("path: %d\n", paths[i]);
    // }

    int i = 0;
    for (; i < 52; i++) {
        int cowID = paths[i] - 65;
        positions[i] = cowID;
        if (cows[cowID][0] == -1) {
            cows[cowID][0] = i;
        } else {
            cows[cowID][1] = i;
        }
    }

    i = 0;
    for (; i < 26; i++) { // all cows
        int start = cows[i][0];
        int end = cows[i][1];

        int j = start + 1;
        for (; j < end; j++) { // loop through positions
            // already found first one
            if (cows[positions[j]][2] == 2) {
                // checked
                cows[positions[j]][2] = 1;
            } else {
                // first one found
                cows[positions[j]][2] = 2;
            }
        }

        j = start + 1;
        for (; j < end; j++) { // loop through positions
            // alone
            if (cows[positions[j]][2] == 2) {
                crosses++;
            }
            // reset positions
            cows[positions[j]][2] = 0;
        }
    }

    // i = 0;
    // for (; i < 26; i++) {
    //     printf("cows: %d, %d\n", cows[i][0], cows[i][1]);
    // }

    crosses /= 2;
    printf("%d\n", crosses);

    fclose(inFile);


    FILE *outFile;
    outFile = fopen("circlecross.out", "w");

    fprintf(outFile, "%d", crosses);

    fclose(outFile);
}