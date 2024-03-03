//ONLINE VOTING SYSTEM
//MAIN FILE
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h> 
#include"header.h"   
int main(){

        int n;
        printf("--------------------------------------------------------------------------\n");
        printf("\t\tWELCOME to Online Voting Portal\n");
		printf("--------------------------------------------------------------------------\n");
        printf("ENTER CATEGORY YOU WANT TO LOG IN:\n");
        printf("1=Admin:\n2=Student:\n3=Exit:\n You:");

        scanf("%d",&n);

        switch(n){

        case 1:
                admin_data();
        break;

        case 2:
                printf("To proceed admin should enter data first.\n");
                admin_data();
        break;

        case 3:
                return 0;
        break;
        
        default:
        	printf("INVALID SELECTION\n");
}

}

