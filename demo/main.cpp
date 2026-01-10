#include <Arduino.h>
#include "VehicleDetector.cpp"

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
