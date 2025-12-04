#ifndef VEHICLE_DETECTOR_H
#define VEHICLE_DETECTOR_H

#include <Arduino.h>

class VehicleDetector {
public:
    // Constructeur : prend le numéro de pin Arduino et un nom
    VehicleDetector(uint8_t pin, const char* name);

    // Initialise le capteur (mode INPUT)
    void begin();

    // Retourne true si un véhicule est détecté
    bool isVehicleDetected();

    // Retourne la valeur brute sur le pin (LOW ou HIGH)
    int readRaw();

    // Retourne le nom du détecteur (ex: "ENTREE (R)")
    const char* getName() const;

private:
    uint8_t _pin;
    const char* _name;
};

#endif