#include <stdio.h>

typedef struct {
    char id[6];
    char name[50];
    float price;
    int stock;
} Product;

int main(void) {
    FILE *fp = fopen("inventory.dat", "wb");

    Product data[] = {
        {"P001", "Apple iPhone 15", 32900.00, 42},
        {"P002", "Samsung Galaxy S24", 28500.50, 17},
        {"P003", "Sony WH-1000XM5", 9990.00, 8},
        {"P004", "Logitech MX Master 3", 3490.00, 0}
    };

    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        fwrite(&data[i], sizeof(Product), 1, fp);
    }

    fclose(fp);
    printf("Written %d products.\n", n);
    return 0;
}