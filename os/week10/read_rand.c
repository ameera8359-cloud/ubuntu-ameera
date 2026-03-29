#include <stdio.h>

typedef struct {
    char id[6];
    char name[50];
    float price;
    int stock;
} Product;

int main(void) {
    FILE *fp = fopen("inventory.dat", "rb");
    Product p;

    int order[] = {3, 1, 0, 2};

    printf("ID     Name                         Price     Stock\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        fseek(fp, order[i] * sizeof(Product), SEEK_SET);
        fread(&p, sizeof(Product), 1, fp);

        printf("%-6s %-28s %8.2f %6d\n",
               p.id, p.name, p.price, p.stock);
    }

    fclose(fp);
    return 0;
}