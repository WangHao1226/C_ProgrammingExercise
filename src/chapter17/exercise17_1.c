//1. 修改 16.3 节的程序 inventory.c，使其可以对数组 inventory 进行动态内存分配，并且在以后填满时
//        重新进行内存分配。初始使用 malloc 为拥有 10 个 part 结构的数组分配足够的内存空间。当数组没
//        有足够的空间给新的零件时，使用 realloc 函数来使内存数量加倍。在每次数组变满时重复加倍操
//        作步骤。

/* Maintains a parts database (array version) */
#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#define NAME_LEN 25
#define INITIAL_CAPACITY 10
struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
};

struct part *inventory = NULL;
int num_parts = 0; /* number of parts currently stored */
int capacity = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
/**********************************************************
 * main: Prompts the user to enter an operation code, *
 * then calls a function to perform the requested *
 * action. Repeats until the user enters the *
 * command 'q'. Prints an error message if the user *
 * enters an illegal code. *
 **********************************************************/
int exercise17_1(void)
{
    char code;
    capacity = INITIAL_CAPACITY;
    inventory = malloc(sizeof (struct part) * capacity);
    if(inventory == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (;;) {
        printf("Enter operation code: ");
        fflush(stdout);
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert();
                break;
            case 's': search();
                break;
            case 'u': update();
                break;
            case 'p': print();
                break;
            case 'q':
                free(inventory);
                return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}
/**********************************************************
 * find_part: Looks up a part number in the inventory *
 * array. Returns the array index if the part *
 * number is found; otherwise, returns -1. *
 **********************************************************/
int find_part(int number)
{
    int i;
    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}
/**********************************************************
 * resize_inventory: 重新调整库存数组的大小              *
 **********************************************************/
int resize_inventory(void){
    int new_capacity = capacity * 2;
    struct part *new_inventory;

    new_inventory = realloc(inventory, new_capacity * sizeof (struct part));
    if(new_inventory == NULL){
        printf("Error: Memory reallocation failed.Cannot add more parts.\n");
        return 0;
    }
    inventory = new_inventory;
    capacity = new_capacity;

    printf("Database capacity increased to %d parts.\n", capacity);
    return 1;
}
/**********************************************************
 * insert: Prompts the user for information about a new *
 * part and then inserts the part into the *
 * database. Prints an error message and returns *
 * prematurely if the part already exists or the *
 * database is full. *
 **********************************************************/
void insert(void)
{
    int part_number;
    if (num_parts == capacity) {
        if (!resize_inventory()) {
            return;  /* 内存重新分配失败，无法添加新零件 */
        }
    }
    printf("Enter part number: ");
    fflush(stdout);
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }
    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}
/**********************************************************
 * search: Prompts the user to enter a part number, then *
 * looks up the part in the database. If the part *
 * exists, prints the name and quantity on hand; *
 * if not, prints an error message. *
 **********************************************************/
void search(void)
{
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else
        printf("Part not found.\n");
}
/**********************************************************
 * update: Prompts the user to enter a part number. *
 * Prints an error message if the part doesn't *
 * exist; otherwise, prompts the user to enter *
 * change in quantity on hand and updates the *
 * database. *
 **********************************************************/
void update(void)
{
    int i, number, change;
    printf("Enter part number: ");
    fflush(stdout);
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else
        printf("Part not found.\n");
}
/**********************************************************
 * print: Prints a listing of all parts in the database, *
 * showing the part number, part name, and *
 * quantity on hand. Parts are printed in the *
 * order in which they were entered into the *
 * database. *
 **********************************************************/
void print(void)
{
    int i;
    printf("Part Number Part Name "
           "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d %-25s%11d\n", inventory[i].number,
               inventory[i].name, inventory[i].on_hand);
}