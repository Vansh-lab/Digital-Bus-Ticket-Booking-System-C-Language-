C Programming, CLI Application, Arrays, Structures, Modular Functions, Booking Logic, Fare Calculator, Problem Solving

#include <stdio.h>
#include <string.h>

#define MAX_SEATS 20
#define ROUTE_COUNT 2

typedef struct {
    int route_id;
    char source[20];
    char destination[20];
    int distance_km;
    int fare_per_km;
    int seats[MAX_SEATS]; // 0 = available, 1 = booked
} Route;

Route routes[ROUTE_COUNT] = {
    {1, "Delhi", "Agra", 200, 2, {0}},
    {2, "Delhi", "Jaipur", 280, 2, {0}}
};

void show_routes() {
    printf("\nAvailable Routes:\n");
    for (int i = 0; i < ROUTE_COUNT; i++) {
        printf("%d. %s to %s (%d km, ₹%d/km)\n", 
            routes[i].route_id, routes[i].source, routes[i].destination, 
            routes[i].distance_km, routes[i].fare_per_km);
    }
}

void show_seats(Route* r) {
    printf("Seat Status (0 = available, 1 = booked):\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("%d[%d] ", i+1, r->seats[i]);
        if ((i+1) % 5 == 0)
            printf("\n");
    }
}

void book_seat(Route* r) {
    int seat_no;
    printf("Enter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seat_no);
    if (seat_no < 1 || seat_no > MAX_SEATS || r->seats[seat_no-1] == 1) {
        printf("Invalid or already booked.\n");
        return;
    }
    r->seats[seat_no-1] = 1;
    int total_fare = r->distance_km * r->fare_per_km;
    printf("Seat %d booked successfully! Total Fare: ₹%d\n", seat_no, total_fare);
}

void cancel_seat(Route* r) {
    int seat_no;
    printf("Enter seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seat_no);
    if (seat_no < 1 || seat_no > MAX_SEATS || r->seats[seat_no-1] == 0) {
        printf("invalid or already available.\n");
        return;
    }
    r->seats[seat_no-1] = 0;
    printf("seat %d cancelled successfully.\n", seat_no);
}

int main() {
    int choice, route_choice;
    while (1) {
        printf("\n===== Bus Ticket Booking Menu =====\n");
        printf("1. Show Routes\n");
        printf("2. Show Seat Status\n");
        printf("3. Book Seat\n");
        printf("4. Cancel Seat\n");
        printf("0. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using Bus Booking System.\n");
            break;
        }

        if (choice >= 2 && choice <= 4) {
            show_routes();
            printf("Select Route ID: \n");
            scanf("%d", &route_choice);
            if (route_choice < 1 || route_choice > ROUTE_COUNT) {
                printf("invalid Route.\n");
                continue;
            }
        }

        switch (choice) {
            case 1:
                show_routes();
                break;
            case 2:
                show_seats(&routes[route_choice - 1]);
                break;
            case 3:
                book_seat(&routes[route_choice - 1]); 
                break;
            case 4:
                cancel_seat(&routes[route_choice - 1]);
                break;
            default:
             printf("Invalid option. Try again.\n");
              return 0;
        }
    }
}
