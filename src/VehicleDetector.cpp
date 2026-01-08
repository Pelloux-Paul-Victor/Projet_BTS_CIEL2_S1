#include "VehicleDetector.h"

VehicleDetector::VehicleDetector(uint8_t pin, const char* name)
    : _pin(pin), _name(name)
{
}

void VehicleDetector::begin() {
    // Définit la broche comme une entrée
    pinMode(_pin, INPUT);
}

bool VehicleDetector::isVehicleDetected() {
    // La logique de détection : 0 V (LOW) signifie véhicule présent
    return (digitalRead(_pin) == LOW);
}

int VehicleDetector::readRaw() {
    return digitalRead(_pin);
}

const char* VehicleDetector::getName() const {
    return _name;
}