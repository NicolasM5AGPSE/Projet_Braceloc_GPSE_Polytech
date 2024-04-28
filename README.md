# Projet_Braceloc_GPSE_Polytech

un rappel des éléments de conception du projet, comprenant le cahier des charges, l'analyse fonctionnelle et les choix et justifications,
une architecture système à jour et la plus détaillée possible (éventuellement au moyen du logiciel Capella),
pour chaque bloc fonctionnel, un chapitre qui contient les éléments de développement ainsi que les tests de validations réalisés
une description des perspectives de développement complémentaire,
en annexe : 
un tableau récapitulatif qui reprend les différentes fonctions réalisées et les personnes qui ont travaillé dessus avec des pourcentages d'implication.
une auto-évaluation des connaissances et compétences acquises/renforcées + le niveau (découverte, approfondissement, expertise), pour chaque participant.
le lien de la video et du dépôt git (cf. ci-dessous)
glossaires,  références bibliographiques et

glossaires,  références bibliographiques

toutes les sources et documents utiles permettant de refaire le projet. mettre en place uen arborescence adaptée
listes des fichiers rendus avec l'endroit où ils sont rangés et à quoi ils servent,  lien web, etc.),
votre rapport technique



## Nom des logiciels :
IDE Arduino
PlateformIO

## Librairies utilisées : 
### Network transmission security
  #include "mbedtls/aes.h"
  #include "Arduino.h"
  #include "mbedtls/entropy.h"
  #include "mbedtls/ctr_drbg.h"
  #include "mbedtls/config.h"
  #include "mbedtls/platform.h"
  #include "mbedtls/rsa.h"
  #include "mbedtls/error.h"
  #include "mbedtls/md.h
  #include "mbedtls/bignum.h"

### BLE & GPS
  #include <Arduino.h>
  #include <BLEDevice.h>
  #include <BLEUtils.h>
  #include <BLEServer.h>
  #include <BLE2902.h>
  #include <TinyGPSPlus.h>
  #include <SoftwareSerial.h>
