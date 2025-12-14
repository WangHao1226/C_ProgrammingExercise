//3. 修改 8.2 节的 deal.c 程序，使它显示出牌的全名：
//Enter number of cards in hand: 5
//Your hand:
//Seven of clubs
//        Two of spades
//Five of diamonds
//        Ace of spades
//Two of hearts
//        提示：用指向字符串的指针的数组来替换数组 rank_code 和数组 suit_code。
//程序负责发一副标准纸牌。每张标准纸
//        牌都有一种花色（梅花、方块、红桃或黑桃）和一个点数（2、3、4、5、6、7、8、9、10、J、
//Q、K 或 A）。程序需要用户指明手里应该握有几张牌：
//Enter number of cards in hand: 5
//Your hand: 7c 2s 5d as 2h

/* Deals a random hand of cards */
#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int exercise13_3(){
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char rank_code[][9] = {"Two","Three","Four","Five",
                              "Six","Seven","Eight","Nine","Ten",
                              "Jack","Queen","King","Ace"};
    const char suit_code[][9] = {"Clubs","Diamonds","Hearts","Spades"};
    char temp_rank[14] = {""};
    char temp_suit[14] = {""};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    fflush(stdout);

    scanf("%d", &num_cards);
    printf("Your hand: \n");

    while (num_cards > 0) {
        suit = rand() % NUM_SUITS; /* picks a random suit */
        rank = rand() % NUM_RANKS; /* picks a random rank */

        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;

            printf("%s of %s\n", rank_code[rank], suit_code[suit]);
        }
    }

    printf("\n");
    return 0;
}
