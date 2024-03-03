//ONLINE VOTING SYSTEM
//header file

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct data{

    int num,year,total_voters;
    char candidates[100];

};

//ADMIN ENTERING DATA

void input_data(){

    struct data d;
    int i;
    printf("\n----------------------------\n");
    printf("enter year of election: \n");
    scanf("%d",&d.year);
    printf("\nHow many voters are there: \n");
    scanf("%d",&d.total_voters);
    printf("\nNumber of candidates: \n");
	scanf("%d",&d.num);
    struct data c[d.num];
                   
    for(i=0;i<d.num;i++){
    	
	    printf("enter canditate %d: ",i+1);
        fflush(stdin);
        gets(c[i].candidates);
		fflush(stdin);

    }
    char q;        
    printf("Allow students to start voting?\n y for yes and n for no\n");
	fflush(stdin);
	scanf("%c",&q);
	    
	 if(q=='y'|| q=='Y') {
	system("cls");
        student_data(c,d);
}
    else if(q=='n'|| q=='N'){
    	
	    printf("\nexiting block.....");
	    exit(0);
    
	}

}


//ADMIN LOGIN
void admin_data(){

    printf("\n----------------------------\n");
    char admin[6]="ADMIN";
    char password[6]="12345";
    printf("\nKindly enter credentials first\n");
    while(1){
    	
    printf("Enter username:\n");
	scanf("%s",admin);
    printf("Enter password:\n");
    scanf("%s",password);
    
        if(strcmp(admin,"ADMIN")!=0||strcmp(password,"12345")!=0){
            printf("wrong username or password!\n");
		}
        else{
            printf("\n\t\t Successfully login!\n\t\tWELCOME TO ADMIN BLOCK!");
			break;
		}
    }
    int opt;

    printf("\t\n Enter option:\n\t 1-New election entry\n\t 2-Result\n");
    scanf("%d",&opt);

    if(opt==1){
    	input_data();
    }
    if(opt==2){
        result();
	}
}

//STUDENT DATA
int student_data(struct data c[],struct data d){

int max=0;
int roll[d.total_voters],s;
 int freq[100000]={0};
 


int count[1000]={0};

        for(s=0;s<d.total_voters;s++){  
	
        printf("\n----------------------------\n");
        printf("\t\t STUDENT BLOCK!\n");          
                printf("\n Enter your roll no: ");
                scanf("%d",&roll[s]);
                
                ++freq[roll[s]];
                if(freq[roll[s]]>1){
                 system("cls");	
                printf("You have already casted vote!\n");  
                s--;

        }

                else if(!(roll[s]>=0&& roll[s]<=d.total_voters)){
  system("cls");
                printf("\nInvalid.Please enter correct roll number\n");
                s--;
                }

                else{
		int v,i;
                int a[d.num];
                char vote[100]={'\0'};
        printf("welcome!\n what would you like to do:\n");
        printf("1- Cast vote\n 2-Exit\n");
        scanf("%d",&v);
        if(v==2){
                count[i]+=0;
	}

       if(v==1){
        printf("\nPlease give vote to one of the following candidates:\n");
        for( i=0;i<d.num;i++){
                printf("%s\n",c[i].candidates);
        }

         printf("Your vote: ");

        fflush(stdin);
        gets(vote);
         printf("\n----------------------------\n");
  system("cls");
        for( i=0;i<d.num;i++){
                if(strcmp(vote,c[i].candidates)==0){
                         count[i]++;

                }
              }
              
         }

     }
    // system("cls");
}
printf("\nTo know the result kindly contact admin.");
         FILE *ptr=fopen("result.txt","w");
          if(ptr == NULL){
 	printf("file not created!");
 }
        else{
        	fprintf(ptr,"\n\t\tRESULT FOR YEAR %d\n",d.year);
	 for( int i=0;i<d.num;i++){

                fprintf(ptr,"%s  :  %d\n ",c[i].candidates,count[i]);
                }
        }
   fclose(ptr);
   
   FILE *fp=fopen("result.txt","a");    
   if(fp ==NULL){
   	printf("file not created!");
   }
      else{
                      int max=0,k=1;
	 char h[10]={'\0'};
	 
	 for(int i=0;i<d.num;i++){
	 	if(count[i]>max){
 	max=count[i];
	strcpy(h,c[i].candidates);
	 		
	 }
}
	 fprintf(fp,"\nWINNER:\n%s wins with %d votes",h,max);
	
	fclose(fp);
}
}

//CREATING RESULT IN FILE

 result(struct data d,struct data c[],int count[]){
    FILE    *textfile;
    char    *text;
    long    numbytes;
    printf("Calculating result.....\n\n");
     
    textfile = fopen("result.txt", "r");
    if(textfile == NULL){
    	printf("no result yet\n");
        return 1;
}
    fseek(textfile, 0L,SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);  
 
    text = (char*)calloc(numbytes, sizeof(char));   
    if(text == NULL)
        return 1;
 
    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);
 
    printf(text);
    free(text);

}
