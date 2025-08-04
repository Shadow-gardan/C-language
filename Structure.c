#include<stdio.h>

struct automobile{
    int s_no;
    int year;
    char material[25];
    int quality;
};

struct automobile part[2];
void revtrieve();
void display();
void set_auto_data();

int main(){
    int i;

    set_auto_data();

    display();

    revtrieve();

    return 0;
}

void revtrieve(){
    int i,j = 0;
    printf("\n list the parts between BB1 & CC6");
    for(i=0;i<2;i++){
        if((part[i].s_no>=0xbbb1) && (part[i].s_no<=0xcc6)){
            j =1;
            printf("\n\n Part name = %d",i);
            printf("\n\n serial number = %x",part[i].s_no);
            printf("\n\n Year of manufacturing = %d",part[i].year);
            printf("\n\n Matwrial used = %s",part[i].material);
            printf("\n\n Manufacturing quality = %d",part[i].quality);
        }
    }
    if( j == 0){
        printf("\n No such record present");
    }
}

void display(){
    int i;
    for(i=0;i<2;i++){
            printf("\n\n Part name = %d",i);
            printf("\n\n serial number = %x",part[i].s_no);
            printf("\n\n Year of manufacturing = %d",part[i].year);
            printf("\n\n Matwrial used = %s",part[i].material);
            printf("\n\n Manufacturing quality = %d",part[i].quality);
    }
}

void set_auto_data(){
    int i;
    for(i=0;i<2;i++){

        while(1){
            printf("Enter the serial number of the part\n");
            printf("Number must be betweeen AA0 and FF9\n");
            scanf("%x",&part[i].s_no);
            if((part[i].s_no>=0xAA0) && (part[i].s_no<=0xff9)){
                break;
            }
        }

        printf("\n Enter the year of manufacturing of the part");
        scanf("%d",&part[i].year);

        printf("\n Enter the material of the part");
        scanf("%s",&part[i].material);

        printf("\n Enter the quality of the part");
        scanf("%d",&part[i].quality);

    }
}
