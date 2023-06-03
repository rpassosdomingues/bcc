// Here I created a project to calculate the fuel efficiency of a vehicle.

#include <stdio.h>

int main(void){
  
  float trip_distance, fuel_liters, vehicle_efficiency;

  printf("\n Enter the distance of the trip (km): ");
  scanf(" %f", &trip_distance);

  printf("\n Enter the amount of fuel consumed (liters): ");
  scanf(" %f", &fuel_liters);

  vehicle_efficiency = trip_distance / fuel_liters;

  printf("\n\t The vehicle has an efficiency of: %.2f km/L \n\n", vehicle_efficiency);

  return 0;
}
