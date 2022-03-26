#include <stdio.h>

struct Meal{
    char name[20];
    int point;
};

int main() {
    const int mealCount = 5;
    int peopleCount;

    struct Meal meals[mealCount];
    strcpy(meals[0].name, "Kebab");
    strcpy(meals[1].name, "Burger");
    strcpy(meals[2].name, "Pasta");
    strcpy(meals[3].name, "Lahmacun");
    strcpy(meals[4].name, "Salad");

    printf("Hi, how many people will be eating?\n");
    scanf("%d", &peopleCount);

    printf("\nNow, you will be ordering the meals according to your preference.\n")

    for(int i=0; i<peopleCount; i++){
        printf("\nPerson ID: %d\n------------\nHere are the IDs of the meals:\n", i);
        for(int i=0; i<mealCount; i++){
            printf("%d - %s\n", i+1, meals[i].name);
        }
        for(int j=0; j<mealCount; j++){
            int selectedID;
            printf("Enter the ID of #%d preference: ");
            scanf("%d", &selectedID);

            meals[selectedID-1].point += (6-selectedID);
        }
    }

    return 0;
}