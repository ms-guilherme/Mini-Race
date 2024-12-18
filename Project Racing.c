#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// Structures section
typedef struct { 
int laps;
int currentLap;
char *firstName;
char *firstColor;
} race;

typedef struct {
char *name;
char *vehicle;
int totalKm;
} racer;


// Print functions section
void Registration(racer *infosUser) {
printf("\n--------------------------------\n");
printf("So, let's create your rider's profile:");
printf("\nWhat's your name? ");
scanf("%s", infosUser->name);
printf("\nWhat's your vehicle? ");
scanf("%s", infosUser->vehicle);
printf("\n--------------------------------\n");
printf("\n%s, you and your %s will be running tonigh with:\n", infosUser->name, infosUser->vehicle);
}


void CreateInfoRacer(int seed, racer *infoRacer, int number) {
switch(seed) {
  case 1: infoRacer->vehicle = "Ferrari";
  break;
  case 2: infoRacer->vehicle = "Tesla Model S";
  break;
  case 3: infoRacer->vehicle = "Motorcycle";
  break;
  case 4: infoRacer->vehicle = "SUV";
  break;
  case 5: infoRacer->vehicle = "Green Race Car";
  break;
  case 6: infoRacer->vehicle = "Quick bike";
  break;
  case 7: infoRacer->vehicle = "Off-road";
  break;
  case 8: infoRacer->vehicle = "Monstertruck";
  break;
  case 9: infoRacer->vehicle = "Ripper";
  break;
  case 10: infoRacer->vehicle = "Tesla Cybertruck";
  break;
  case 11: infoRacer->vehicle = "BMW i8";
  break;
  case 12: infoRacer->vehicle = "Lamborghini Aventador";
  break;
  default: infoRacer->vehicle = "Generic Car";
}

switch (number) {
  case 0: infoRacer->name = "Larance";
  break;
  case 1: infoRacer->name = "Elon Reeve Musk";
  break;
  case 2: infoRacer->name = "Riley 'Fastline' Cruz";
  break;
  case 3: infoRacer->name = "Enzo Anselmo";
  break;
  case 4: infoRacer->name = "Camillo Castiglioni";
  break;
  case 5: infoRacer->name = "Turbo Hawk";
  break;
  default: infoRacer->name = "Senna";
  break;
}

}


void CreateRacers(racer *infosRacers, int totalDrivers) {

int seed;

for (int i = totalDrivers; i >= 0; i--) {  //Racers Creation
  seed = rand() % 12 + 1;
  CreateInfoRacer(seed, &infosRacers[i], i);
  printf("%s, in his %s!\n", infosRacers[i].name, infosRacers[i].vehicle);
}

}


int Race(racer *infosRacers) {

int raceKm = 5 * 3; // 5km de pista, 3 voltas (15km)
int seed;
int biggerSeed = 0;
int lapMVP;
int lap = 1;

for (int i = 0; i <= 6; i++) {

  Sleep(400);

  if (lap == 1) infosRacers[i].totalKm = 0;

  seed = rand() % 6 + 1;
  if (seed > biggerSeed) {
    biggerSeed = seed;
    lapMVP = i;
  }

  infosRacers[i].totalKm += seed;
  printf("The racer %s ran more %ikm!\n", infosRacers[i].name, seed);
  if (infosRacers[i].totalKm >= raceKm) {
    printf("\nThe %i lap has been finished!\n", lap);
    Sleep(2000);
    return(i);
  }
  
  if (i >= 6) {
    printf("\n%s is at full steam\n\n", infosRacers[lapMVP].name);
    i = 0;
    lap++;
    Sleep(2000);
  }
}

}


int main() {
srand(time(0));

racer infosMain;
racer infosRacers[6];
char enter[4];
int totalDrivers = 6;
int winner;

infosMain.name = (char*) malloc(99 * sizeof(char));
infosMain.vehicle = (char*) malloc(99 * sizeof(char));

printf("Welcome to the Race's night event! Would you like to register yourself as a racer? (yes/no)\n");
scanf(" %s", enter);

if (strcmp(enter, "yes") == 0) {
  Registration(&infosMain);
  infosRacers[5] = infosMain;
  totalDrivers--;
}
else printf("\nSo... it will be a pleasure to have you tonigh as a viewer!\nPlease, enjoy the show!\n");

CreateRacers(infosRacers, totalDrivers);

Sleep(4000);

printf("\n\nRacers Ready!");
Sleep(1000);
printf("In\n5\n4\n3\n2\n1...\n");
Sleep(500);
printf("Race!\n\n");

Sleep(2000);

winner = Race(infosRacers);

printf("And the tonigth's race Winner is... %s, in the fastest %s! Congratulations!\n", (infosRacers[winner]).name, (infosRacers[winner]).vehicle);

free(infosMain.name);
free(infosMain.vehicle);

}