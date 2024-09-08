#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int product_code;
    int quantity;
    float price;
} Product;

void add_product(FILE *file);
void display_products(FILE *file);
void search_product(FILE *file);
void update_product(FILE *file);
void delete_product(FILE *file);

int main() {
    int choice;
    FILE *file;

    while (1) {
        printf("\nStok Yönetim Sistemi\n");
        printf("1. Ürün Ekle\n");
        printf("2. Stok Durumunu Görüntüle\n");
        printf("3. Ürün Ara\n");
        printf("4. Ürün Güncelle\n");
        printf("5. Ürün Sil\n");
        printf("6. Çıkış\n");
        printf("Seçiminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                file = fopen("stock.txt", "a+");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                add_product(file);
                fclose(file);
                break;
            case 2:
                file = fopen("stock.txt", "r");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                display_products(file);
                fclose(file);
                break;
            case 3:
                file = fopen("stock.txt", "r");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                search_product(file);
                fclose(file);
                break;
            case 4:
                file = fopen("stock.txt", "r+");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                update_product(file);
                fclose(file);
                break;
            case 5:
                file = fopen("stock.txt", "r+");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                delete_product(file);
                fclose(file);
                break;
            case 6:
                printf("Çıkış yapılıyor...\n");
                exit(0);
            default:
                printf("Geçersiz seçim. Tekrar deneyin.\n");
        }
    }

    return 0;
}

void add_product(FILE *file) {
    Product product;
    printf("Ürün adı: ");
    scanf("%s", product.name);
    printf("Ürün kodu: ");
    scanf("%d", &product.product_code);
    printf("Miktar: ");
    scanf("%d", &product.quantity);
    printf("Fiyat: ");
    scanf("%f", &product.price);

    fprintf(file, "%s %d %d %.2f\n", product.name, product.product_code, product.quantity, product.price);
    printf("Ürün başarıyla eklendi.\n");
}

void display_products(FILE *file) {
    Product product;
    rewind(file);

    printf("\nStoktaki Tüm Ürünler:\n");
    while (fscanf(file, "%s %d %d %f", product.name, &product.product_code, &product.quantity, &product.price) != EOF) {
        printf("Adı: %s, Kodu: %d, Miktar: %d, Fiyat: %.2f\n", product.name, product.product_code, product.quantity, product.price);
    }
}

void search_product(FILE *file) {
    int code;
    Product product;
    int found = 0;

    printf("Aramak istediğiniz ürünün kodu: ");
    scanf("%d", &code);

    rewind(file);
    while (fscanf(file, "%s %d %d %f", product.name, &product.product_code, &product.quantity, &product.price) != EOF) {
        if (product.product_code == code) {
            printf("Adı: %s, Kodu: %d, Miktar: %d, Fiyat: %.2f\n", product.name, product.product_code, product.quantity, product.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Ürün bulunamadı.\n");
    }
}

void update_product(FILE *file) {
    int code;
    Product product;
    int found = 0;
    long position;

    printf("Güncellemek istediğiniz ürünün kodu: ");
    scanf("%d", &code);

    rewind(file);
    while (!feof(file)) {
        position = ftell(file);
        if (fscanf(file, "%s %d %d %f", product.name, &product.product_code, &product.quantity, &product.price) == 4) {
            if (product.product_code == code) {
                printf("Yeni Miktar: ");
                scanf("%d", &product.quantity);
                printf("Yeni Fiyat: ");
                scanf("%f", &product.price);
                fseek(file, position, SEEK_SET);
                fprintf(file, "%s %d %d %.2f\n", product.name, product.product_code, product.quantity, product.price);
                found = 1;
                printf("Ürün başarıyla güncellendi.\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Ürün bulunamadı.\n");
    }
}

void delete_product(FILE *file) {
    int code;
    Product product;
    FILE *temp_file;
    int found = 0;

    printf("Silmek istediğiniz ürünün kodu: ");
    scanf("%d", &code);

    temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Geçici dosya açılamadı.\n");
        return;
    }

    rewind(file);
    while (fscanf(file, "%s %d %d %f", product.name, &product.product_code, &product.quantity, &product.price) != EOF) {
        if (product.product_code != code) {
            fprintf(temp_file, "%s %d %d %.2f\n", product.name, product.product_code, product.quantity, product.price);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    if (found) {
        printf("Ürün başarıyla silindi.\n");
    } else {
        printf("Ürün bulunamadı.\n");
    }
}
