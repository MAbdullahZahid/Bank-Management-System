#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int login_account_number = -1; // Initialize to an invalid index
int highestAccountNumber = 0;  // Initialize with an invalid value

// Structure to represent user data
struct Userdatabase {
    char usernamearray[1000], gender_array, country_array[1000], passwordarray[1000];
    long long Idcardarray;
    int date_of_birth_array, phone_no_array, Latestmoney, account_number;
};

// Structure to represent login credentials
struct userlogin {
    char loginname[1000], loginpassword[1000];
};

// Array of structures to store user data
struct Userdatabase Signup[1000];
struct userlogin Login[1000];

// our Function prototypes
void printingtext();
void mainmenu();
void signup();
void login();
void options();
void Add_Amount();
void Withdraw_money();
void Transfer_Money();
void Personal_Info();
void saveUserData();
void loadUserData();
void forgotpassword();
void userchoice_funtion();





// our Main function.
int main() {
    loadUserData(); // Load user data from the file into struct.
    printingtext(); // Logo of our project
    mainmenu();     // Signup/login page
    return 0;
}





// Function of printing text on output screen.
void printingtext()
{

     system("cls");
    printf("\n\n\n\t\t\t\t\t\t\t    **********************************************    ");
    printf("\n\t\t\t\t\t\t\t   *                                               *   ");
    printf("\n\t\t\t\t\t\t\t  *     ---------------------------------------     *  ");
    printf("\n\t\t\t\t\t\t\t *     | WELCOME TO OUR BANK MANAGMENT SYSTEM |      * ");
    printf("\n\t\t\t\t\t\t\t *     ----------------------------------------      * ");
    printf("\n\t\t\t\t\t\t\t  *     -----AP_KY_DIL_MIEN_HMARA_ACCOUNT-----      *  ");
    printf("\n\t\t\t\t\t\t\t   *                                              *   ");
    printf("\n\t\t\t\t\t\t\t    *********************************************     \n\n\n");
}





// Main page of our bank System.
void mainmenu()
{
    char option ;
    do{
    printingtext();
    printf("Please Select your choice:\n");
    printf("\nFor Signup (s/S).\n\n");
    printf("For Login (l/L).\n\n");
    printf("For Termination (t/T).\n\n ");
    fflush(stdin);
    scanf(" %c", &option);
}while (option != 's' && option != 'S' && option != 't' && option != 'T' && option != 'l' && option != 'L');
 switch(option)
 { case 's' : case 'S':
        signup();
        break;                               // Function called
    case 'l' : case 'L':
        login();
        break;                                // Function called
    case 't' : case 'T' :
        printf("The program is Terminated.\n");
                exit(0);
    default:
        printf("Please Select s , l or t ! ");
}}





// Sigup Function
void signup() {
    char choice;

    do {
 int nextAvailableAccountNumber = highestAccountNumber + 1;
    int i = nextAvailableAccountNumber;
 highestAccountNumber++;
        printingtext();
        FILE *fp = fopen("BankDatabase.txt", "a");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
         printf("\nYou are now at Signup screen\n");
        printf("\nPlease enter your information\n");
        printf("\nEnter your Username: ");
        scanf("%s", Signup[i].usernamearray);

      do {
            printf("\nEnter your password (8 digits only): "); //added input validation
            scanf("%s", Signup[i].passwordarray);
        } while (strlen(Signup[i].passwordarray) != 8);

        printf("\nEnter your Id Card number : ");
        scanf("%ld", &Signup[i].Idcardarray);

        printf("\nNow please add your personal information:\n");
        printf("\n\tEnter your birth year: ");
        scanf("%d", &Signup[i].date_of_birth_array);

        do {
            printf("\n\tEnter your Gender (M/F): ");   //added input validation
            scanf(" %c", &Signup[i].gender_array);
        } while (Signup[i].gender_array != 'm' && Signup[i].gender_array != 'M' && Signup[i].gender_array != 'f' && Signup[i].gender_array != 'F');

        printf("\n\tEnter your Country: ");
        scanf("%s", Signup[i].country_array);

        printf("\n\tEnter your Phone No: ");
        scanf("%d", &Signup[i].phone_no_array);
        Signup[i].Latestmoney = 0;
        Signup[i].account_number = nextAvailableAccountNumber;
        printf("\nYour Account was successfully created\n");
        printf("\nYour Account No is %d\n",nextAvailableAccountNumber);
        fprintf(fp, "%s %s %ld %d %c %s %d %d %d\n", Signup[i].usernamearray, Signup[i].passwordarray, Signup[i].Idcardarray, Signup[i].date_of_birth_array, Signup[i].gender_array, Signup[i].country_array, Signup[i].phone_no_array,Signup[i].account_number, Signup[i].Latestmoney);
        //It saves the data of user into file.
        nextAvailableAccountNumber++; // Increament Account Number for next user.
        printf("\nDo you want to sign-up again? (y/n): ");
        scanf(" %c", &choice);
        fclose(fp);
    } while (choice == 'y' || choice == 'Y');
    if (choice == 'n' || choice == 'N')
        mainmenu();
}




// Operations After Login.
void options() {       // OPERATIONS
    int ch;
    int j =1;
    printingtext();
    do{ printf("\n\nWelcome %s!",Login[j].loginname);
    printf("\n\nEnter your Operation: ");
    printf("\n1. Deposit money \n2. Withdraw money \n3. Transfer Money\n4. Check Account Details\n5. To log out\n ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            Add_Amount(); // Function called
            break;

        case 2:
            Withdraw_money();   // Function called
            break;

        case 3:
            Transfer_Money();   // Function called
            break;

        case 4:
            Personal_Info();    // Function called
            break;

        case 5:
            printingtext();
            printf("You are now being logged out!");
            sleep(1);
            mainmenu();        // Function called
            break;

        default:
            printf("\nInvalid Choice. Please select from the given options only!");
            sleep(1);
            printingtext();}
            }while(ch!=1 && ch!=2 && ch!=3 && ch!=4 && ch!=5);
}




// Login function.
void login() {
    int j = 1;
    printingtext();
    printf("\nYou are now at Login screen\n");
    printf("\n\nEnter your username: ");
    scanf("%s", Login[j].loginname);
    printf("\nEnter your password: ");
    scanf("%s", Login[j].loginpassword);
    printingtext();                                 // Function called
    char line[1000];
    FILE *fp = fopen("BankDatabase.txt", "r");         // openning file for reading

    while (fgets(line, sizeof(line), fp) != NULL) {         // Used tokenization here to seperate
        char *username = strtok(line, " ");
        char *password = strtok(NULL, " ");
        long long idcard = strtoll(strtok(NULL, " "), NULL, 10);
        int dob = atoi(strtok(NULL, " "));
        char gender = strtok(NULL, " ")[0];
        char *country = strtok(NULL, " ");
        int phone_no = atoi(strtok(NULL, " "));
        int accountnumber=atoi(strtok(NULL, " "));
        int Latestmoney = atoi(strtok(NULL, " "));

       if (strcmp(username, Login[j].loginname) == 0 && strcmp(password, Login[j].loginpassword) == 1)
       { char op;
           printf("You have entered an incorrect password!");
           printf("\n\nDo you want to try again (t/T) or forgot password (f/F)? ");
           printf("\nPress any key to go back to home page:  ");
           fflush(stdin);
           scanf("%c",&op);
           switch(op)
           {
           case 't': case 'T':
            login();
            break;

           case 'f': case 'F':
            forgotpassword();
            break;

           default:

            mainmenu();
           }
       }

        if (strcmp(username, Login[j].loginname) == 0 && strcmp(password, Login[j].loginpassword) == 0) // match the user name from file.
        {
            for (int i =1; i < 1000; ++i) {
                if (strcmp(Signup[i].usernamearray, Login[j].loginname) == 0) {
                    login_account_number = i;
                    break;
                }}
            printf("Login successful! You are now being directed to main menu\n");
            sleep(2);

            options();
            }
            }

    fclose(fp);
    printf("Login failed! Your account does not exist in our database.\nPlease select from below options \n");  // Password or Name did not match.
    printf("\n\nTry again (t/T)\nForgot password (f/F)\nCreate an account (s/S)\nMain menu (m/M) ");
           char opt;
           fflush(stdin);
           scanf("%c",&opt);
           switch(opt)
           {
           case 't': case 'T':
            login();
            break;

           case 'f': case 'F':
            forgotpassword();
            break;

           case 's': case 'S':
            signup();
            break;

           case 'm': case 'M':
           mainmenu();
           break;

           default:
            printf("Invalid choice");
            sleep(1);
            mainmenu();
           }
}// login function ends.




// Function of Withdraw money.
void Withdraw_money() {
    printingtext() ;
    int withdrawmoney;
    printf("Enter Amount to withdraw: ");
    scanf("%d", &withdrawmoney);
    if (Signup[login_account_number].Latestmoney >= withdrawmoney){
        Signup[login_account_number].Latestmoney -= withdrawmoney;
        printf("\nYour new balance is Rs.%d\n", Signup[login_account_number].Latestmoney);}
    else
      {
        printf("\nInsufficient Balance\n");             // not enough money to withdraw
        printf("\nBecause your balance is: %d ",Signup[login_account_number].Latestmoney );}
        saveUserData(); // Update the data in file.
        userchoice_funtion();

}





// Function of Transfering Money from one account to another account.
void Transfer_Money() {
    printingtext() ;
    int transfermoney, d;
    printf("Enter the account number in which you want to add money: ");
    scanf("%d", &d);
    printf("\nEnter the amount you want to transfer: ");
    scanf("%d", &transfermoney);
    if (Signup[login_account_number].Latestmoney >= transfermoney) {      // Checking if user have sufficent balance to send or not
        Signup[login_account_number].Latestmoney -= transfermoney;
        Signup[d].Latestmoney += transfermoney;
        printingtext() ;
        printf("\nRs.%d is transferred to the account Number %d\n",transfermoney,d);
        printf("\nYour New Balance is: Rs.%d",  Signup[login_account_number].Latestmoney);
    } else {
        char chh;                                               // not enough money to send to another user
        printf("\nYou dont have sufficient balance! ");
        printf("\nDo you want to Add money? (select 'y' for yes and 'n' for no )");
        fflush(stdin);
        scanf(" %c", &chh);
        if (chh == 'y' || chh == 'Y')
            Add_Amount();}
        saveUserData();                                         // Save the updated user data after adding money
        userchoice_funtion();
}





// Function of add money into the user account.
void Add_Amount() {
    printingtext();
    int money;
    printf("Enter Amount: ");
    scanf(" %d", &money);
    Signup[login_account_number].Latestmoney += money;
    printf("Now your Money is Rs.%d\n", Signup[login_account_number].Latestmoney);
    saveUserData();                                // Save the updated user data after adding money
    userchoice_funtion();
}




// This function is used when the user forgot password then he will recover his password by giving his account number or name.
void forgotpassword() {
    char choice;
    char username[100];
    int account_number;
    printingtext();
    printf("\nDo you want to check your password with your name(n/N) or account number (a/A)?: ");
    scanf(" %c", &choice);

    if (choice == 'n' || choice == 'N') {
        printf("\nEnter your username: ");
        fflush(stdin);
        scanf("%s", username);
        for (int i = 1; i <= 1000; i++) {
            if (strcmp(Signup[i].usernamearray, username) == 0) {
                printf("\nYour password is: %s", Signup[i].passwordarray);}}}
    else if (choice == 'A' || choice == 'a') {
        printf("\nEnter your account number: ");
        scanf("%d", &account_number);
        for (int i = 1; i <= 1000; i++) {
            if (Signup[i].account_number == account_number) {
                printf("\nYour password is: %s", Signup[i].passwordarray);
                break;
                }}}
    else {
        printf("\nInvalid choice! Going back to main menu.\n");
        sleep(2);
        mainmenu();
        return;}
    char a;
    printf("\n\nPress (l/L) to log in again or any other key to go back to the main menu: ");
    scanf(" %c", &a);
    if (a == 'l' || a == 'L') {
        login();
    } else {
        mainmenu();}}




// Function of displaying the personal information of a user which is saved in bank
void Personal_Info() {
    printingtext() ;
    char a;
    printf("\n\nLogin Name: %s\nPassword: %s\nIdcard: %ld\nYear of birth: %d\nUser Gender: %c\nUser Country %s\nUser Phone number: %d\nMoney: %d\n", Signup[login_account_number].usernamearray,
           Signup[login_account_number].passwordarray, Signup[login_account_number].Idcardarray, Signup[login_account_number].date_of_birth_array,
           Signup[login_account_number].gender_array, Signup[login_account_number].country_array, Signup[login_account_number].phone_no_array,
           Signup[login_account_number].Latestmoney);

           userchoice_funtion();
   }





void saveUserData() {                               // This function will keep changing the data
    FILE *fp = fopen("BankDatabase.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 1 ; i <= Signup[i].account_number ; i++) {
fprintf(fp, "%s %s %ld %d %c %s %d %d %d\n", Signup[i].usernamearray, Signup[i].passwordarray, Signup[i].Idcardarray, Signup[i].date_of_birth_array, Signup[i].gender_array, Signup[i].country_array, Signup[i].phone_no_array, Signup[i].account_number, Signup[i].Latestmoney);
}
    fclose(fp);
}




// This will load the data from file into struct on every time when the program run..
void loadUserData() {
    FILE *fp = fopen("BankDatabase.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading. Assuming it doesn't exist yet.\n");
        return;
    }
int i=1;
    int currentAccountNumber = 1 ;
    while (fscanf(fp, "%s %s %lld %d %c %s %d %d %d", Signup[i].usernamearray, Signup[i].passwordarray, &Signup[i].Idcardarray, &Signup[i].date_of_birth_array, &Signup[i].gender_array, Signup[i].country_array, &Signup[i].phone_no_array, &Signup[i].account_number, &Signup[i].Latestmoney) != EOF) {
        // This will check the Booked account number in file and give the next available account Number to user.
        // We use it in a signup function...
        currentAccountNumber = Signup[i].account_number;
        if (currentAccountNumber > highestAccountNumber) {
            highestAccountNumber = currentAccountNumber;
        }

        i++;
    }

    fclose(fp);
}





// This will used multiple time in our program so we make a function and its purpose is to go back to main page of our Bank System
void userchoice_funtion(){
     char choice;
    printf("\n\nPress (m) to go to main menu ");
    scanf(" %c", &choice);
    if (choice == 'm' || choice == 'M')
        options();
    else {
    printf("Invalid Choice! ");
    mainmenu();}
}
