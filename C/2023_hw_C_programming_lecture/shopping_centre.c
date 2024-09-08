#include <stdio.h>
#define N 1
#define M 2
struct product{
    char reference_code[20];
    float price;
};
struct isci{
    char surname[20];
    char name[20];
    int old;
};
struct shop{
    char name[10];
    char street_name[20];
    char mahalle[12];
    char telephone[15];
    float sale;
    struct isci e1;
    struct isci e2;
    struct isci e3;
    struct product p[M];
};
void create_product(struct product *pr){
    printf("enter reference code\n : ");
    scanf("%s",pr->reference_code);
    printf("pleace enter price\n : ");
    scanf("%f",&pr->price);
}
void create_isci(struct isci *em){
    printf("enter surname isci\n : ");
    scanf("%s",em->surname);
    printf("please enter name isci:\n ");
    scanf("%s",em->name);
    printf("please enter old isci:\n ");
    scanf("%d",&em->old);
}
void create_shop(struct shop *m){
    int i;
    printf("please enter shop name \n: ");
    scanf("%s",m->name);
    printf("please enter name street of shop\n : ");
    scanf("%s",m->street_name);
    printf("please enter name mahalle of shop \n: ");
    scanf("%s",m->mahalle);
    printf("please enter telephone number of shop\n: ");
    scanf("%s",m->telephone);
    printf("please enter sale price : \n");
    scanf("%f",&m->sale);
    printf("Isci 1 : \n");
    create_isci(&m->e1);
    printf("Isci 2 : \n");
    create_isci(&m->e2);
    printf("Isci 3 : \n");
    create_isci(&m->e3);
    for ( i = 0; i< M; i++){
        printf("enter products %d : \n",i);
        create_product(&m->p[i]);
    }
}
void urunu_bas(struct product p){
    printf("\treference code: %s\n",p.reference_code);
    printf("\tprice : %f\n",p.price);
}
void isciyi_bas(struct isci e){
    printf("\tname : %s\n",e.name);
    printf("\tsurname : %s\n",e.surname);
    printf("\told : %d\n",e.old);
}
void magazayi_bas(struct shop m){
    int i;
    printf("shop name : %s\n",m.name);
    printf("street of shop: %s\n",m.street_name);
    printf(":mahalle of shop%s\n",m.mahalle);
    printf("telephone of shop : %s\n",m.telephone);
    printf("sale price : %f\n",m.sale);
    printf("Isci 1 :\n");
    isciyi_bas(m.e1);
    printf("Isci 2 :\n");
    isciyi_bas(m.e2);
    printf("Isci 3 :\n");
    isciyi_bas(m.e3);
    for ( i = 0; i< M; i++){
        printf("product %d : \n",i);
        urunu_bas(m.p[i]);
    }
}
void en_yasli(struct shop m){
    struct isci yasli;
    if (m.e1.old >yasli.old)
        yasli = m.e1;
    if (m.e2.old >yasli.old)
        yasli = m.e2;
    if (m.e3.old >yasli.old)
        yasli = m.e3;
    printf("oldest isci:\n");
    isciyi_bas(yasli);
}
void ortalama_fiyat(struct shop m[N]){
    int i, j;
    float s;
    for ( i=0; i<N; i++){
        for( j =0; j<M; j++){
            s+=m[i].p[j].price;
        }
        printf(" %s The average price of the products in the store :   %f\n",m[i].name,(float) s/M);
    }
}
void bulundugu_mahalle(struct shop m[N], char q[12]){
    int i;
    for ( i = 0; i<N; i++){
        if(strcmp(m[i].mahalle,q)==0)
            printf("There is a %s store in the neighborhood of %s \n", m[i].mahalle, m[i].name);
    }
}
int main(){
    struct shop m[N];
    int i;
    for(i=0; i<N; i++){
        printf("shop %d :\n",i);
        create_shop(&m[i]);
    }
    for(i=0; i<N; i++){
        printf("shop %d :\n",i);
        magazayi_bas(m[i]);
    }
    en_yasli(m[0]); 
    ortalama_fiyat(m);
    bulundugu_mahalle(m, "sisli");

return 0;}