#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct voter_information {
    char aadhar[20];
    char name[50];
    char birth_date[15];
    struct voter_information *next;
} node;

node *head = NULL;
node *start = NULL;

node *search(char x[], char y[], char z[], node *, int *);
node *register_voter(node *);
node *main_vote_logs(node *);
void admin_dashboard();
void winner();
void exi();
void voting();
void not_again();
void stop();
void show();

int count = 0, R = 3, vote = 0;
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;

int main() {
    while (1) {
        system("cls");
        printf("\n\n\n");
        printf("\t            ****** WELCOME TO THE ONLINE VOTING PORTAL ******        \n\n");
        printf("\t           ***************************************************        \n\n\n\n\n");
        printf("        \t\t *****Please Enter One(1) for logging vote main Logs*****    \n\n\n");
        int BB;
        scanf("%d", &BB);
        if (BB == 1) {
            start = main_vote_logs(start);
        }
    }
    return 0;
}

node *main_vote_logs(node *start) {
    system("cls");
    printf("\n\n\n");
    printf("        \t\t\t1. FOR VOTE ENTRY     \n");
    Sleep(300);
    printf("        \t\t\t2. FOR ADMIN PANEL    \n");
    Sleep(300);
    printf("        \t\t\t3. FOR WINNER         \n");
    printf("    \t IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT    \n\n\n");
    Sleep(500);
    printf("    \t ********So Plz Enter********\n\n\n");
    int T;
    scanf("%d", &T);
    if (T == 1) {
        start = register_voter(start);
    }
    if (T == 2) {
        admin_dashboard();
    }
    if (T == 3) {
        winner();
    }
    if (T != 1 && T != 2 && T != 3) {
        main_vote_logs(start);
    }
    return start;
}

node *register_voter(node *start) {
    int UNIVERSAL = 0;
    int *z = &UNIVERSAL;
    node *temp;
    char name[50], birth_date[15], aadhar[20];
    system("cls");
    printf("\n\n\n\n");
    printf("\t IF AADHAR ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
    Sleep(300);
    printf("\t\t\t ID YOU DO WRONG %d TIMES, THE PORTAL WILL BE CLOSED AUTOMATICALLY\n\n\n", R);
    Sleep(300);
    printf("\t\tPlease \n");
    Sleep(300);
    printf("\t\t\tEnter your AADHAR ID number  ");
    scanf("%s", aadhar);
    printf("\t\t\tEnter Your NAME   ");
    scanf(" %[^\n]", name);
    printf("\t\t\tEnter Your BIRTH DATE  in dd-mm-yyyy format");
    scanf("%s", birth_date);

    temp = (node *)malloc(sizeof(node));
    strcpy(temp->aadhar, aadhar);
    strcpy(temp->name, name);
    strcpy(temp->birth_date, birth_date);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }

    node *t = head;
    while (t != NULL) {
        if ((strcmp(t->aadhar, "10001") == 0 && strcmp(t->name, "Rajat Kumar") == 0 && strcmp(t->birth_date, "31-03-1999") == 0) ||
            (strcmp(t->aadhar, "10002") == 0 && strcmp(t->name, "Goutam Kumar Bhadani") == 0 && strcmp(t->birth_date, "01-01-1999") == 0) ||
            (strcmp(t->aadhar, "10003") == 0 && strcmp(t->name, "Gautam Kumar") == 0 && strcmp(t->birth_date, "12-10-1999") == 0) ||
            (strcmp(t->aadhar, "10004") == 0 && strcmp(t->name, "Kundan Kumar") == 0 && strcmp(t->birth_date, "08-12-1999") == 0) ||
            (strcmp(t->aadhar, "10005") == 0 && strcmp(t->name, "Aniket Arora") == 0 && strcmp(t->birth_date, "28-08-1999") == 0) ||
            (strcmp(t->aadhar, "10006") == 0 && strcmp(t->name, "Dipika Singh") == 0 && strcmp(t->birth_date, "20-10-2000") == 0) ||
            (strcmp(t->aadhar, "10007") == 0 && strcmp(t->name, "Avinash Kumar") == 0 && strcmp(t->birth_date, "02-03-1999") == 0) ||
            (strcmp(t->aadhar, "10008") == 0 && strcmp(t->name, "Ravi Raj") == 0 && strcmp(t->birth_date, "26-12-1999") == 0) ||
            (strcmp(t->aadhar, "10009") == 0 && strcmp(t->name, "Shubham Kumar") == 0 && strcmp(t->birth_date, "02-01-1999") == 0) ||
            (strcmp(t->aadhar, "10010") == 0 && strcmp(t->name, "Subham Kumar") == 0 && strcmp(t->birth_date, "03-01-1999") == 0)) {
            R = 3;
            start = search(temp->aadhar, temp->name, temp->birth_date, start, &UNIVERSAL);
            if (UNIVERSAL == 0) {
                voting();
            } else {
                not_again();
            }
            return start;
        } else {
            R--;
            if (R == 0) {
                stop();
                break;
            }
            printf("\n\n\n\n");
            printf("\tYour AADHAR ID or NAME or DATE OF BIRTH is wrong\n\n");
            Sleep(300);
            printf("\t\t\tPlz Re-Enter\n\n");
            Sleep(300);
            system("pause");
            start = main_vote_logs(start);
            return start;
        }
        t = t->next;
    }
    return start;
}

void voting() {
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t     * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    Sleep(300);
    printf("\t\t\t NAME     & THEIR RESPECTIVE      SYMBOL\n\n");
    Sleep(300);
    printf("\t\t\t 1. Mamata Banerjee                1. Fish\n");
    Sleep(300);
    printf("\t\t\t 2. Deepa Dasmunsi                 2. Boat\n");
    Sleep(300);
    printf("\t\t\t 3. Protima Rajak                  3. Motorcycle\n");
    Sleep(300);
    printf("\t\t\t 4. Joydeb Halder                  4. Broomstick\n");
    Sleep(300);
    printf("\t\t\t 5. Kartik Chandra Ghosh           5. Wheel\n\n\n");

    int B;
    printf("\t\t\t Plzz, \n");
    printf("\t\t\t Enter Your Choice \n");
    scanf("%d", &B);

    switch (B) {
        case 1:
            vote1++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO MAMTA BANERJEE\n");
            break;
        case 2:
            vote2++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO DEEPA DASMUNSI\n");
            break;
        case 3:
            vote3++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO PROTIMA RAJAK\n");
            break;
        case 4:
            vote4++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO JOYDEB HALDER\n");
            break;
        case 5:
            vote5++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO KARTIK CHANDRA GHOSH\n");
            break;
        default:
            printf("\n\n\t\t\t\tInvalid choice. Please try again.\n");
            break;
    }

    printf("\n\n\n\n");
    printf("\t\t\tYour Voting is Successfully Recorded\n\n");
    system("pause");
    main_vote_logs(start);
}

node *search(char x[], char y[], char z[], node *start, int *count) {
    node *temp = start;
    while (temp != NULL) {
        if (strcmp(temp->aadhar, x) == 0 && strcmp(temp->name, y) == 0 && strcmp(temp->birth_date, z) == 0) {
            *count = 1;
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void admin_dashboard() {
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t ************* ADMIN DASHBOARD *************** \n");
    Sleep(300);
    printf("\t\t\tTotal Vote Given = %d\n", vote);
    Sleep(300);
    printf("\t\t\tVote of MAMTA BANERJEE = %d\n", vote1);
    Sleep(300);
    printf("\t\t\tVote of DEEPA DASMUNSI = %d\n", vote2);
    Sleep(300);
    printf("\t\t\tVote of PROTIMA RAJAK = %d\n", vote3);
    Sleep(300);
    printf("\t\t\tVote of JOYDEB HALDER = %d\n", vote4);
    Sleep(300);
    printf("\t\t\tVote of KARTIK CHANDRA GHOSH = %d\n", vote5);
    Sleep(300);
    printf("\n\n\n\n");
    system("pause");
    main_vote_logs(start);
}

void winner() {
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t ************ WINNER ************ \n");
    if (vote1 > vote2 && vote1 > vote3 && vote1 > vote4 && vote1 > vote5) {
        printf("\n\n\t\t\t MAMATA BANERJEE is the winner with %d votes\n", vote1);
    } else if (vote2 > vote1 && vote2 > vote3 && vote2 > vote4 && vote2 > vote5) {
        printf("\n\n\t\t\t DEEPA DASMUNSI is the winner with %d votes\n", vote2);
    } else if (vote3 > vote1 && vote3 > vote2 && vote3 > vote4 && vote3 > vote5) {
        printf("\n\n\t\t\t PROTIMA RAJAK is the winner with %d votes\n", vote3);
    } else if (vote4 > vote1 && vote4 > vote2 && vote4 > vote3 && vote4 > vote5) {
        printf("\n\n\t\t\t JOYDEB HALDER is the winner with %d votes\n", vote4);
    } else if (vote5 > vote1 && vote5 > vote2 && vote5 > vote3 && vote5 > vote4) {
        printf("\n\n\t\t\t KARTIK CHANDRA GHOSH is the winner with %d votes\n", vote5);
    } else {
        printf("\n\n\t\t\t No clear winner\n");
    }
    printf("\n\n\n\n");
    system("pause");
    main_vote_logs(start);
}

void not_again() {
    printf("\n\n\n\tYou have already voted. You cannot vote again.\n");
    Sleep(300);
    system("pause");
    main_vote_logs(start);
}

void stop() {
    printf("\n\n\n\n");
    printf("\t\t\t ********** THE PORTAL HAS BEEN CLOSED ************ \n");
    Sleep(300);
    exit(0);
}
