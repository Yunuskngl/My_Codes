#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void add_contact(FILE *file);
void display_contacts(FILE *file);
void search_contact(FILE *file);
void update_contact(FILE *file);
void delete_contact(FILE *file);

int main() {
    int choice;
    FILE *file;

    while (1) {
        printf("\nTelefon Rehberi Uygulaması\n");
        printf("1. Kişi Ekle\n");
        printf("2. Rehberi Görüntüle\n");
        printf("3. Kişi Ara\n");
        printf("4. Kişiyi Güncelle\n");
        printf("5. Kişi Sil\n");
        printf("6. Çıkış\n");
        printf("Seçiminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                file = fopen("contacts.txt", "a+");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                add_contact(file);
                fclose(file);
                break;
            case 2:
                file = fopen("contacts.txt", "r");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                display_contacts(file);
                fclose(file);
                break;
            case 3:
                file = fopen("contacts.txt", "r");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                search_contact(file);
                fclose(file);
                break;
            case 4:
                file = fopen("contacts.txt", "r+");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                update_contact(file);
                fclose(file);
                break;
            case 5:
                file = fopen("contacts.txt", "r+");
                if (file == NULL) {
                    printf("Dosya açılamadı.\n");
                    return 1;
                }
                delete_contact(file);
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

void add_contact(FILE *file) {
    Contact contact;
    printf("Adı: ");
    scanf("%s", contact.name);
    printf("Soyadı: ");
    scanf("%s", contact.surname);
    printf("Telefon Numarası: ");
    scanf("%s", contact.phone);

    fprintf(file, "%s %s %s\n", contact.name, contact.surname, contact.phone);
    printf("Kişi başarıyla eklendi.\n");
}

void display_contacts(FILE *file) {
    Contact contact;
    rewind(file);

    printf("\nRehberdeki Tüm Kişiler:\n");
    while (fscanf(file, "%s %s %s", contact.name, contact.surname, contact.phone) != EOF) {
        printf("Adı: %s, Soyadı: %s, Telefon: %s\n", contact.name, contact.surname, contact.phone);
    }
}

void search_contact(FILE *file) {
    char name[MAX_NAME_LENGTH];
    Contact contact;
    int found = 0;

    printf("Aramak istediğiniz kişinin adı: ");
    scanf("%s", name);

    rewind(file);
    while (fscanf(file, "%s %s %s", contact.name, contact.surname, contact.phone) != EOF) {
        if (strcmp(contact.name, name) == 0) {
            printf("Adı: %s, Soyadı: %s, Telefon: %s\n", contact.name, contact.surname, contact.phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Kişi bulunamadı.\n");
    }
}

void update_contact(FILE *file) {
    char name[MAX_NAME_LENGTH];
    Contact contact;
    int found = 0;
    long position;

    printf("Güncellemek istediğiniz kişinin adı: ");
    scanf("%s", name);

    rewind(file);
    while (!feof(file)) {
        position = ftell(file);
        if (fscanf(file, "%s %s %s", contact.name, contact.surname, contact.phone) == 3) {
            if (strcmp(contact.name, name) == 0) {
                printf("Yeni Telefon Numarası: ");
                scanf("%s", contact.phone);
                fseek(file, position, SEEK_SET);
                fprintf(file, "%s %s %s\n", contact.name, contact.surname, contact.phone);
                found = 1;
                printf("Kişi başarıyla güncellendi.\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Kişi bulunamadı.\n");
    }
}

void delete_contact(FILE *file) {
    char name[MAX_NAME_LENGTH];
    Contact contact;
    FILE *temp_file;
    int found = 0;

    printf("Silmek istediğiniz kişinin adı: ");
    scanf("%s", name);

    temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        printf("Geçici dosya açılamadı.\n");
        return;
    }

    rewind(file);
    while (fscanf(file, "%s %s %s", contact.name, contact.surname, contact.phone) != EOF) {
        if (strcmp(contact.name, name) != 0) {
            fprintf(temp_file, "%s %s %s\n", contact.name, contact.surname, contact.phone);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found) {
        printf("Kişi başarıyla silindi.\n");
    } else {
        printf("Kişi bulunamadı.\n");
    }
}
