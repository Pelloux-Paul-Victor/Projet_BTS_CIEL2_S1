#include <Arduino.h>
#include "VehicleDetector.h"

// Définition du pin relié au module
constexpr uint8_t SENSOR_PIN = 2;

// Création de l’objet détecteur
VehicleDetector detector(SENSOR_PIN);

void setup() {
    Serial.begin(9600);
    detector.begin();

    Serial.println("Systeme de detection vehicule initialise.");
}

void loop() {
    if (detector.isVehicleDetected()) {
        Serial.println("Vehicule detecte !");
    }
    else {
        Serial.println("Aucun vehicule.");
    }

    delay(500); // Lecture toutes les 500 ms
}


