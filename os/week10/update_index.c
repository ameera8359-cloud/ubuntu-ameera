#include <stdio.h>
#include <string.h>

typedef struct {
    char id[6];
    char name[50];
    float price;
    int stock;
} Product;

int main(void) {
    FILE *fp = fopen("inventory.dat", "rb+"); // อ่าน + เขียน
    Product p;
    char search_id[6];
    int found = 0;
    int index = 0;

    printf("Enter product ID to update: ");
    scanf("%s", search_id);

    while (fread(&p, sizeof(Product), 1, fp)) {
        if (strcmp(p.id, search_id) == 0) {
            found = 1;

            // แก้ stock เป็น 100
            p.stock = 100;

            // ย้อน pointer กลับไป record เดิม
            fseek(fp, -sizeof(Product), SEEK_CUR);

            // เขียนทับ
            fwrite(&p, sizeof(Product), 1, fp);

            printf("\nUpdated successfully!\n");
            break;
        }
        index++;
    }

    if (!found) {
        printf("\nProduct not found!\n");
    }

    // แสดงข้อมูลใหม่ทั้งหมด
    rewind(fp);

    printf("\nUpdated Inventory:\n");
    printf("ID     Name                         Price     Stock\n");
    printf("-----------------------------------------------------\n");

    while (fread(&p, sizeof(Product), 1, fp)) {
        printf("%-6s %-28s %8.2f %6d\n",
               p.id, p.name, p.price, p.stock);
    }

    fclose(fp);
    return 0;
}