#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data {
    int num, year, total_voters;
    char candidates[100][100];
};

// Function prototypes
void student_data(struct data d);
void result();

// ADMIN ENTERING DATA
void input_data() {
    struct data d;
    int i;
    printf("\n----------------------------\n");
    printf("Enter year of election: \n");
    scanf("%d", &d.year);
    printf("How many voters are there: \n");
    scanf("%d", &d.total_voters);
    printf("Number of candidates: \n");
    scanf("%d", &d.num);

    for(i = 0; i < d.num; i++) {
        printf("Enter candidate %d: ", i + 1);
        getchar();  // To clear the buffer before using gets
        gets(d.candidates[i]);
    }

    char q;
    printf("Allow students to start voting?\n y for yes and n for no\n");
    scanf(" %c", &q);  // Added a space to skip any newline characters

    if(q == 'y' || q == 'Y') {
        system("cls");
        student_data(d);
    } else if(q == 'n' || q == 'N') {
        printf("\nExiting block.....");
        exit(0);
    }
}

// ADMIN LOGIN
void admin_data() {
    char admin[6] = "ADMIN";
    char password[6] = "12345";
    printf("\n----------------------------\n");
    printf("\nKindly enter credentials first\n");

    while(1) {
        char enteredAdmin[6], enteredPassword[6];
        printf("Enter username:\n");
        scanf("%s", enteredAdmin);
        printf("Enter password:\n");
        scanf("%s", enteredPassword);

        if(strcmp(enteredAdmin, admin) != 0 || strcmp(enteredPassword, password) != 0) {
            printf("Wrong username or password!\n");
        } else {
            printf("\n\t\tSuccessfully logged in!\n\t\tWELCOME TO ADMIN BLOCK!");
            break;
        }
    }

    int opt;
    printf("\t\n Enter option:\n\t 1-New election entry\n\t 2-Result\n");
    scanf("%d", &opt);

    if(opt == 1) {
        input_data();
    }
    if(opt == 2) {
        result();
    }
}

// STUDENT DATA
void student_data(struct data d) {
    int roll[d.total_voters];
    int freq[100000] = {0};
    int count[100] = {0};

    for(int s = 0; s < d.total_voters; s++) {
        printf("\n----------------------------\n");
        printf("\t\tSTUDENT BLOCK!\n");
        printf("\nEnter your roll number: ");
        scanf("%d", &roll[s]);

        if(freq[roll[s]] > 0) {
            system("cls");
            printf("You have already casted vote!\n");
            s--;
        } else if(roll[s] < 0 || roll[s] > d.total_voters) {
            system("cls");
            printf("\nInvalid. Please enter a correct roll number\n");
            s--;
        } else {
            int v;
            char vote[100] = {'\0'};
            printf("Welcome!\nWhat would you like to do:\n1- Cast vote\n2- Exit\n");
            scanf("%d", &v);

            if(v == 2) {
                count[0] += 0;  // No action needed here, just for clarity
            } else if(v == 1) {
                printf("\nPlease give your vote to one of the following candidates:\n");
                for(int i = 0; i < d.num; i++) {
                    printf("%s\n", d.candidates[i]);
                }
                printf("Your vote: ");
                getchar();  // To clear the buffer before using gets
                gets(vote);
                system("cls");

                for(int i = 0; i < d.num; i++) {
                    if(strcmp(vote, d.candidates[i]) == 0) {
                        count[i]++;
                    }
                }
            }
        }
    }

    // Save the results in a file
    FILE *ptr = fopen("result.txt", "w");
    if(ptr == NULL) {
        printf("File not created!\n");
    } else {
        fprintf(ptr, "\n\t\tRESULT FOR YEAR %d\n", d.year);
        for(int i = 0; i < d.num; i++) {
            fprintf(ptr, "%s  :  %d\n", d.candidates[i], count[i]);
        }
    }
    fclose(ptr);

    FILE *fp = fopen("result.txt", "a");
    if(fp == NULL) {
        printf("File not created!\n");
    } else {
        int max = 0;
        char winner[100];
        for(int i = 0; i < d.num; i++) {
            if(count[i] > max) {
                max = count[i];
                strcpy(winner, d.candidates[i]);
            }
        }
        fprintf(fp, "\nWINNER:\n%s wins with %d votes", winner, max);
        fclose(fp);
    }
}

// DISPLAY RESULT
void result() {
    FILE *textfile = fopen("result.txt", "r");
    if(textfile == NULL) {
        printf("No result yet\n");
        return;
    }

    fseek(textfile, 0L, SEEK_END);
    long numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    char *text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL) {
        return;
    }

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    printf("%s", text);
    free(text);
}


