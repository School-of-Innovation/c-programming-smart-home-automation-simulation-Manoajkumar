
/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

#define MAX_ROOMS 5  //  max number of rooms

// Function prototypes
void initializeSystem(int lights[], int temps[], int motion[], int locks[]);
void displayMenu();
void controlLights(int lights[]);
void readTemperature(int temps[]);
void detectMotion(int motion[]);
void securitySystem(int locks[]);
void analyzeHouseStatus(int lights[], int temps[], int motion[], int locks[]);

int main() {
    int lights[MAX_ROOMS], temps[MAX_ROOMS], motion[MAX_ROOMS], locks[MAX_ROOMS];
    initializeSystem(lights, temps, motion, locks);


    int choice;       
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: controlLights(lights); break;
            case 2: readTemperature(temps); break;
            case 3: detectMotion(motion); break;
            case 4: securitySystem(locks); break;
            case 5: analyzeHouseStatus(lights, temps, motion, locks); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
        
    } while (choice != 6);

    return 0;
}

 
void initializeSystem(int lights[], int temps[], int motion[], int locks[]) {
    printf("Initializing system...\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        lights[i] = 0;
        temps[i] = 22 + (i % 5);
        motion[i] = 0;
        locks[i] = 1;
    }
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n2. Read Temperature\n3. Check Motion Sensor\n4. Lock/Unlock Security System\n5. House Status Summary\n6. Exit\nEnter your choice: ");
    
}
void controlLights(int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room < 1 || room > MAX_ROOMS) {
        printf("Invalid room number!\n");
        return;
    }
    lights[room - 1] = !lights[room - 1];
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}
void readTemperature(int temps[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room < 1 || room > MAX_ROOMS) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Temperature in Room %d: %d°C\n", room, temps[room - 1]);
}
void detectMotion(int motion[]) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room < 1 || room > MAX_ROOMS) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Motion %s detected in Room %d.\n", motion[room - 1] ? "is" : "not", room);
}
void securitySystem(int locks[]) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room < 1 || room > MAX_ROOMS) {
        printf("Invalid room number!\n");
        return;
    }
    locks[room - 1] = !locks[room - 1];
    printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
}
void analyzeHouseStatus(int lights[], int temps[], int motion[], int locks[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1, 
               lights[i] ? "ON" : "OFF", temps[i],
               motion[i] ? "Motion Detected" : "No Motion", 
               locks[i] ? "Locked" : "Unlocked");
    }
}
