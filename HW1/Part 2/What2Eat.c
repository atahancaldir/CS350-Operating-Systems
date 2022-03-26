#include <stdio.h>
#include <string.h>

int main() {
    const int mealCount = 5;
    int peopleCount;

    char mealNames[mealCount][20]; //names of the meals
    int mealPoints[mealCount]; // scores of the meals

    strcpy(mealNames[0], "Kebab");
    strcpy(mealNames[1], "Burger");
    strcpy(mealNames[2], "Pasta");
    strcpy(mealNames[3], "Lahmacun");
    strcpy(mealNames[4], "Salad");

    for(int i=0; i<mealCount; i++)
        mealPoints[i] = 0; // each meal has the score of 0 at the beginning

    printf("ROUND 1\n------------\nWelcome to the restaurant! How many people will be eating today?\n");
    scanf("%d", &peopleCount);

    int threshold = peopleCount*(mealCount*3/4); // threshold is calculated with respect to the number of people

    printf("\nNow, you will be ordering the meals according to your preference.");

    for(int i=0; i<peopleCount; i++){
        printf("\n\nGuest ID: %d\n------------\nHere are the IDs of the meals:\n", i+1);
        for(int j=0; j<mealCount; j++){
            printf("%d - %s\n", j+1, mealNames[j]);
        }
        for(int j=0; j<mealCount; j++){
            int selectedID;
            printf("Enter the ID of #%d preference: ", j+1);
            scanf("%d", &selectedID);

            mealPoints[selectedID-1] += (mealCount-j);
        }
    }

    char selectedMealNames[mealCount][20]; //names of the selected meals
    int selectedCount = 0;

    printf("\nRound 1 points of the meals:\n");

    for(int i=0; i<mealCount; i++){
        printf("%s - %d\n", mealNames[i], mealPoints[i]);
        if(mealPoints[i] >= threshold){
            strcpy(selectedMealNames[selectedCount], mealNames[i]);
            selectedCount++;
        }
        mealPoints[i] = 0; // we will reuse the meal points array for the selected meals
    }

    if(selectedCount==0){
        printf("\nYou are eating at home/dorm today!");
        return 0;
    }

    printf("\nROUND 2\n------------\nThis time you will order the selected meals. (Threshold: %d)", threshold);
    for(int i=0; i<peopleCount; i++){
        printf("\n\nGuest ID: %d\n------------\nHere are the IDs of the selected meals:\n", i+1);
        for(int j=0; j<selectedCount; j++){
            printf("%d - %s\n", j+1, selectedMealNames[j]);
        }
        for(int j=0; j<selectedCount; j++){
            int selectedID;
            printf("Enter the ID of #%d preference: ", j+1);
            scanf("%d", &selectedID);

            mealPoints[selectedID-1] += (selectedCount-j);
        }
    }

    int topScore = 0;
    int topMealIndex = 0;
    for(int i=0; i<selectedCount; i++){
        if(mealPoints[i] > topScore){
            topScore = mealPoints[i];
            topMealIndex = i;
        }
    }

    printf("\nRound 2 points of the meals:\n");

    for(int i=0; i<selectedCount; i++){
        printf("%s - %d\n", selectedMealNames[i], mealPoints[i]);
    }

    printf("You are eating %s today.\n\nBon Apetit!", selectedMealNames[topMealIndex]);

    return 0;
}