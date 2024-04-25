#include <stdio.h>
#include <stdlib.h>
 
#define ROWS 5
#define COLS 5
 
// Function prototypes
void displaySeats(char seats[ROWS][COLS]);
int bookSeat(char seats[ROWS][COLS], int row, int col);
void printMenu();
 
int main() {
   char seats[ROWS][COLS];
   int row, col;
   int choice;
   int totalSeats = ROWS * COLS;
   int bookedSeats = 0;
 
   // Initialize the seats array
   for (int i = 0; i < ROWS; i++) {
       for (int j = 0; j < COLS; j++) {
           seats[i][j] = 'A'; // A for Available
       }
   }
 
   while (1) {
       printMenu();
       printf("Enter your choice: ");
       scanf("%d", &choice);
 
       switch (choice) {
           case 1:
               displaySeats(seats);
               break;
           case 2:
               if (bookedSeats >= totalSeats) {
                   printf("All seats are booked!\n");
                   break;
               }
               printf("Enter row and column to book (e.g., 1 1 for first row and column): ");
               scanf("%d %d", &row, &col);
               if (bookSeat(seats, row - 1, col - 1)) {
                   bookedSeats++;
                   printf("Seat booked successfully!\n");
               } else {
                   printf("Seat booking failed! It might be already booked or invalid position.\n");
               }
               break;
           case 3:
               printf("Exiting system.\n");
               exit(0);
               break;
           default:
               printf("Invalid choice, please try again.\n");
       }
   }
   return 0;
}
 
void displaySeats(char seats[ROWS][COLS]) {
   printf("Seating Plan:\n");
   printf("   ");
   for (int j = 0; j < COLS; j++) {
       printf("%d ", j + 1);
   }
   printf("\n");
 
   for (int i = 0; i < ROWS; i++) {
       printf("%d: ", i + 1);
       for (int j = 0; j < COLS; j++) {
           printf("%c ", seats[i][j]);
       }
       printf("\n");
   }
}
 
int bookSeat(char seats[ROWS][COLS], int row, int col) {
   if (row >= 0 && row < ROWS && col >= 0 && col < COLS && seats[row][col] == 'A') {
       seats[row][col] = 'B'; // B for Booked
       return 1;
   }
   return 0;
 
 
void printMenu() {
   printf("\nMovie Theater Ticket Booking\n");
   printf("1. Display available seats\n");
   printf("2. Book a seat\n");
   printf("3. Exit\n");
}
