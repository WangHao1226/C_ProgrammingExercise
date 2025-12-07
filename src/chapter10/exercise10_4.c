////4. 修改 10.5 节的 poker.c 程序，使其能识别牌的另一种类别——“同花大顺”（同花色的 A、K、Q、J
////        和 10）。同花大顺的级别高于其他所有的类别。
//
///* Classifies a poker hand */
///* Classifies a poker hand */
//#include <stdbool.h> /* C99 only */
//#include <stdio.h>
//#include <stdlib.h>
//#define NUM_RANKS 13
//#define NUM_SUITS 4
//#define NUM_CARDS 5
///* external variables */
//int num_in_rank[NUM_RANKS];
//int num_in_suit[NUM_SUITS];
//bool royal_flush;
//bool straight, flush, four, three;
//int pairs; /* can be 0, 1, or 2 */
///* prototypes */
//void read_cards(void);
//void analyze_hand(void);
//void print_result(void);
///************************************************************
// * main: Calls read_cards, analyze_hand, and print_result *
// * repeatedly. *
// ************************************************************/
//int exercise10_4(void)
//{
//    for (;;) {
//        read_cards();
//        analyze_hand();
//        print_result();
//    }
//}
///************************************************************
// * read_cards: Reads the cards into the external *
// * variables num_in_rank and num_in_suit; *
// * checks for bad cards and duplicate cards. *
// ************************************************************/
//void read_cards(void)
//{
//    bool card_exists[NUM_RANKS][NUM_SUITS];
//    char ch, rank_ch, suit_ch;
//    int rank, suit;
//    bool bad_card;
//    int cards_read = 0;
//    for (rank = 0; rank < NUM_RANKS; rank++) {
//        num_in_rank[rank] = 0;
//        for (suit = 0; suit < NUM_SUITS; suit++)
//            card_exists[rank][suit] = false;
//    }
//    for (suit = 0; suit < NUM_SUITS; suit++)
//        num_in_suit[suit] = 0;
//    while (cards_read < NUM_CARDS) {
//        bad_card = false;
//        printf("Enter a card: ");
//        rank_ch = getchar();
//        switch (rank_ch) {
//            case '0': exit(EXIT_SUCCESS);
//            case '2': rank = 0; break;
//            case '3': rank = 1; break;
//            case '4': rank = 2; break;
//            case '5': rank = 3; break;
//            case '6': rank = 4; break;
//            case '7': rank = 5; break;
//            case '8': rank = 6; break;
//            case '9': rank = 7; break;
//            case 't': case 'T': rank = 8; break;
//            case 'j': case 'J': rank = 9; break;
//            case 'q': case 'Q': rank = 10; break;
//            case 'k': case 'K': rank = 11; break;
//            case 'a': case 'A': rank = 12; break;
//            default: bad_card = true;
//        }
//        suit_ch = getchar();
//        switch (suit_ch) {
//            case 'c': case 'C': suit = 0; break;
//            case 'd': case 'D': suit = 1; break;
//            case 'h': case 'H': suit = 2; break;
//            case 's': case 'S': suit = 3; break;
//            default: bad_card = true;
//        }
//        while ((ch = getchar()) != '\n')
//            if (ch != ' ') bad_card = true;
//        if (bad_card)
//            printf("Bad card; ignored.\n");
//        else if (card_exists[rank][suit])
//            printf("Duplicate card; ignored.\n");
//        else {
//            num_in_rank[rank]++;
//            num_in_suit[suit]++;
//            card_exists[rank][suit] = true;
//            cards_read++;
//        }
//    }
//}
///************************************************************
// * analyze_hand: Determines whether the hand contains a *
// * straight, a flush, four-of-a-kind, *
// * and/or three-of-a-kind; determines the *
// * number of pairs; stores the results into *
// * the external variables straight, flush, *
// * four, three, and pairs. *
// ************************************************************/
//void analyze_hand(void)
//{
//    int num_consec = 0;
//    int rank, suit;
//    straight = false;
//    flush = false;
//    four = false;
//    three = false;
//    pairs = 0;
//    royal_flush = false;
//
//    /* check for flush */
//    for (suit = 0; suit < NUM_SUITS; suit++)
//        if (num_in_suit[suit] == NUM_CARDS)
//            flush = true;
//
//    /* check for straight */
//    rank = 0;
//    while (num_in_rank[rank] == 0) rank++;
//    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
//        num_consec++;
//    if (num_consec == NUM_CARDS) {
//        straight = true;
//    }
//
//    /* 检查同花大顺：既是同花又是顺子，且包含A、K、Q、J、10 */
//    if (straight && flush) {
//        // 检查是否包含10、J、Q、K、A（点数8, 9, 10, 11, 12）
//        if (num_in_rank[8] == 1 &&  // 10
//            num_in_rank[9] == 1 &&  // J
//            num_in_rank[10] == 1 && // Q
//            num_in_rank[11] == 1 && // K
//            num_in_rank[12] == 1)   // A
//        {
//            royal_flush = true;
//            // 如果是同花大顺，则不是普通的顺子或同花
//            straight = false;
//            flush = false;
//        }
//        return;  // 如果是同花顺（包括同花大顺），直接返回
//    }
//
//    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
//    for (rank = 0; rank < NUM_RANKS; rank++) {
//        if (num_in_rank[rank] == 4) four = true;
//        if (num_in_rank[rank] == 3) three = true;
//        if (num_in_rank[rank] == 2) pairs++;
//    }
//}
///************************************************************
// * print_result: prints the classification of the hand, *
// * based on the values of the external *
// * variables straight, flush, four, three, *
// * and pairs. *
// ************************************************************/
//void print_result(void)
//{
//    if (royal_flush)
//        printf("Royal flush");  // 同花大顺
//    else if (straight && flush)
//        printf("Straight flush");
//    else if (four) printf("Four of a kind");
//    else if (three &&
//             pairs == 1) printf("Full house");
//    else if (flush) printf("Flush");
//    else if (straight) printf("Straight");
//    else if (three) printf("Three of a kind");
//    else if (pairs == 2) printf("Two pairs");
//    else if (pairs == 1) printf("Pair");
//    else printf("High card");
//    printf("\n\n");
//}