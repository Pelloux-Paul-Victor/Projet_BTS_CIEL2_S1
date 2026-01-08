// VEHICLE_DETECTOR_H (Header et Implémentation de la classe combinés)
#ifndef VEHICLE_DETECTOR_H
#define VEHICLE_DETECTOR_H

#include <Arduino.h>

/**
 * @brief Classe pour gérer la détection de véhicules via une broche numérique.
 * * Предпоose que le circuit de détection (par ex., un module de boucle 
 * d'induction) fournit un signal LOW (0V) lorsqu'un véhicule est présent.
 */
class VehicleDetector {
public:
    // Constructeur : prend le numéro de pin Arduino et un nom
    VehicleDetector(uint8_t pin, const char* name)
        : _pin(pin), _name(name)
    {
    }

    // Initialise le capteur (mode INPUT)
    void begin() {
        // Définit la broche comme une entrée
        pinMode(_pin, INPUT);
    }

    // Retourne true si un véhicule est détecté
    bool isVehicleDetected() {
        // La logique de détection : 0 V (LOW) signifie véhicule présent
        return (digitalRead(_pin) == LOW);
    }

    // Retourne la valeur brute sur le pin (LOW ou HIGH)
    int readRaw() {
        return digitalRead(_pin);
    }

    // Retourne le nom du détecteur (ex: "ENTREE (R)")
    const char* getName() const {
        return _name;
    }

private:
    uint8_t _pin;
    const char* _name;
};

#endif
// Fin de l'inclusion de la classe VehicleDetector


// -----------------------------------------------------------------
// MAIN_CPP (Code principal)
// -----------------------------------------------------------------

// Définition des pins reliés aux modules de détection
constexpr uint8_t PIN_ENTREE = 2; // Broche Arduino pour la bobine R (Entrée)
constexpr uint8_t PIN_SORTIE = 3; // Broche Arduino pour la bobine Vi (Sortie)

// Création des objets détecteurs, un pour chaque voie
VehicleDetector detectorEntree(PIN_ENTREE, "ENTREE (R)");
VehicleDetector detectorSortie(PIN_SORTIE, "SORTIE (Vi)");


void setup() {
    // Initialisation de la communication série pour le débogage
    Serial.begin(9600);
    
    // Initialisation des détecteurs
    detectorEntree.begin();
    detectorSortie.begin();

    Serial.println("Systeme de detection vehicule initialise (Entree et Sortie).");
    Serial.println("----------------------------------------------------------");
}

void loop() {
    bool isEntreeDetected = detectorEntree.isVehicleDetected();
    bool isSortieDetected = detectorSortie.isVehicleDetected();

    if (isEntreeDetected) {
        // Envoi de l'information pour l'équipe (par exemple, un signal de barrière)
        Serial.print("ALARME VEHICULE DETECTE : ");
        Serial.println(detectorEntree.getName());
        
        // Exemple d'action : digitalWrite(PIN_BARRIERE_ENTREE, HIGH);
    }
    
    if (isSortieDetected) {
        // Envoi de l'information pour l'équipe
        Serial.print("ALARME VEHICULE DETECTE : ");
        Serial.println(detectorSortie.getName());
        
        // Exemple d'action : digitalWrite(PIN_BARRIERE_SORTIE, HIGH);
    }

    if (!isEntreeDetected && !isSortieDetected) {
        Serial.println("Monitoring : Aucun vehicule.");
    }
    
    // Sépare les lectures pour plus de clarté
    Serial.println("--");

    delay(500); // Lecture toutes les 500 ms
}