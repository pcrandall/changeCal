// Implement a program that calculates the minimum number of coins required to give a user change.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

float exchangeMoney(float change);
int getMoney (int paperChange, int coinChange);
int parser (int coin, int index, int numberOfCoins);

int main (){
    float change;
    int paperChange, coinChange;
    paperChange = coinChange = change = 0;

    change = exchangeMoney(change);
    paperChange = floor(change / 1);
    coinChange = (((change - paperChange) +.005)* 100);
    printf("\nChange due:  $%0.2f \n", change);
    getMoney (paperChange, coinChange);
}

float exchangeMoney(float change) {
    int input;
    char S1 = '\0';
    float i, j;
    i = j = change = input = 0;
    do
    {
        printf("How much does the item cost?\n$ ");
        scanf("%f", &i);
        input++;
    }
    while (i < 0 && input < 2);

    input = 0;
    do
    {
        printf("Insert cash amount. \n$ ");
        scanf("%f", &j);
        input++;
    }
    while (i >= j && input < 2);

    if (input == 2 && (i == 0 || j < i)) {
        printf("This isn't enough!\nDo you have more money?\n\tY or N \n");
        scanf("%s", &S1);
        if (S1 == ('Y' | 'y')) {
            main();
        }
    } else if (input == 2 && j < i) {
        printf("Goodbye.\n");
        exit(0);
    }

    change = j - i;
    return change;
}


int getMoney (int paperChange, int coinChange){
    bool init = true;
    bool paperDone = false;
    int index, coin, changedOwed, numberOfCoins, totalNumberOfCoins;
    index = coin = changedOwed = numberOfCoins = totalNumberOfCoins = 0;

    do {
        coin = 0;
        if (index == 0){
            changedOwed = paperChange;
        }
        if (index == 5 && paperDone == false){
            init = true;
            changedOwed = coinChange;
        }

// calculate change
getChange:
        if (changedOwed != 0){
            numberOfCoins = 0;
            coin = parser(index, coin, numberOfCoins);
            if ((coin != 0 ) && (changedOwed / coin) >= 1){
                numberOfCoins = changedOwed / coin;
                changedOwed = changedOwed % coin ;
                totalNumberOfCoins = totalNumberOfCoins + numberOfCoins;
                if (index < 5){
                    paperChange = changedOwed;
                }else{
                    coinChange = changedOwed;
                }
            }
        }

        // Send em to the print shop.
        if (index < 5 && numberOfCoins > 0 && init == true){
            printf("\n");
            init = false;
            parser(index, coin, numberOfCoins);
        } else if (index > 4 && numberOfCoins > 0 && init == true){
            printf("\n");
            init = false;
            parser(index, coin, numberOfCoins);
        } else {
            parser(index, coin, numberOfCoins);
        }

        // total prints.
        if (index < 5 && changedOwed == 0 && totalNumberOfCoins > 0){
            printf("Total amount of bills used:  %d \n", totalNumberOfCoins);
            totalNumberOfCoins = 0;
            paperChange = 0;
        } else if (index > 4 && changedOwed == 0 && totalNumberOfCoins > 0){
            printf("Total amount of coins used:  %d \n", totalNumberOfCoins);
            totalNumberOfCoins = 0;
            coinChange = 0;
        }

        if (changedOwed == 0 && paperChange == 0 && paperDone == false){
            index = 5;
            changedOwed = coinChange;
            init = true;
            paperDone = true;
            goto getChange;

        } else if(changedOwed == 0 && paperChange == 0  && coinChange == 0 ){
            exit(0);
        }
        index ++;
    }
    while (changedOwed != 0);

    return 0;
}

int parser(int index, int coin, int numberOfCoins){
    switch (index){
        case 0:
            coin = 100;
            break;
        case 1:
            coin = 20;
            break;
        case 2:
            coin = 10;
            break;
        case 3:
            coin = 5;
            break;
        case 4:
            coin = 1;
            break;
        case 5:
            coin = 25;
            break;
        case 6:
            coin = 10;
            break;
        case 7:
            coin = 5;
            break;
        case 8:
            coin = 1;
            break;
    }

    switch (index){
        case 0:
            if (numberOfCoins > 0) {
                printf("Hundreds: %d \n", numberOfCoins);
            }
            break;
        case 1:
            if (numberOfCoins > 0) {
                printf("Twenties: %d \n", numberOfCoins);
            }
            break;
        case 2:
            if (numberOfCoins > 0) {
                printf("Tens: %d \n", numberOfCoins);
            }
            break;
        case 3:
            if (numberOfCoins > 0) {
                printf("Fives: %d \n", numberOfCoins);
            }
            break;
        case 4:
            if (numberOfCoins > 0) {
                printf("Ones: %d \n", numberOfCoins);
            }
            break;
        case 5:
            if (numberOfCoins > 0) {
                printf("Quarters: %d \n", numberOfCoins);
            }
            break;
        case 6:
            if (numberOfCoins > 0) {
                printf("Dimes: %d \n", numberOfCoins);
            }
            break;
        case 7:
            if (numberOfCoins > 0) {
                printf("Nickels: %d \n", numberOfCoins);
            }
            break;
        case 8:
            if (numberOfCoins > 0) {
                printf("Pennies: %d \n", numberOfCoins);
            }
            break;
    }
    return coin;
}
