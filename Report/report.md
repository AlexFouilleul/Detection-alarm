# Rapport mini-projet IoT

Bachri Anas
Alex Fouilleul 

Polytech Grenoble - IESE5
2022 - 2023

<p align="center">
  <img src="Images/Logo2.png" width="100">
</p>

## Introduction

Nous avons disposé de quelques séances de TP réalisé au fablab MSTIC de l'UGA. Le but étant de créer un système "évolutif" prenant en compte des capteurs et réalisant une communication sans fils type LoRa ou encore Bluetooth.
Dans le cadre de ce projet nous avons choisis un compteur de personnes que nous avons très vite fait évoluer afin d'en faire une alarme de détection.

A noter que pour avoir un bref apercu du projet nous avons rédigé, en anglais, la page [readme.md](https://github.com/AlexFouilleul/Detection-alarm/blob/main/README.md) du dépot. Cependant ce compte rendu sera bien plus complet et expliquera les différents points pris en compte lors du travail autour de ce projet et son étude de cas.


## Analyse rapide du marché

(à rédiger - vis à vis des produits commerciaux concurrents)

Dans le cas d'une alarme, le prix des produits des concurrents peut très vite monter. Cela s'explique avant tout par les produits que ceux-ci propose (avec une centrale intérieure/extérieure ainsi que un ensemble de capteurs tels que des capteurs d'ouvertures de portes ou de détection de présence). En se référent au site de [Leroy Merlin](https://www.leroymerlin.fr/produits/electricite-domotique/alarme-telesurveillance/alarme-maison/alarme-maison-sans-fil/) on peut très vite se rendre compte des prix allant d'une centraine d'euros jusqu'au millier d'euros. A noter que ce genre d'alarme  est en général très robuste avec des équipments robuste résistant au temps. Elles sont donc pensées pour une durée de vie de plusieurs dizaines d'années avec en général et une sécurité et fiabilité relativement élevées.

<p align="center">
  <img src="Images/Alarm_PowerMaster.jpg" width="500">
</p>

Un autre type de système tout aussi intéréssant sur lequel on peut se pencher sont les centrales domotiques tel que la [Gateway Xiaomi](https://xifrance.com/product/xiaomi-gateway-v3/). Ce genre de produit repose sur la même approche que les alarmes avec une centrale intérieure et un ensemble de capteurs qui s'y connecte en utilisant différents protocoles tel que le Wifi (pour piloter la centrale à distance), ainsi que le Bluetooth et le Zigbee pour se connecter aux capteurs. Ce type de système peut être utilisé comme une alarme d'appoint et dispose de nombreux avantages qui seront énumérés plus bas dans ce compte rendu.

<p align="center">
  <img src="Images/Gateway_Xiaomi.png" width="400">
</p>

Avec les quelques séances de projet dont nous disposons, nous avons fait le choix de mélanger les deux types d'alarme vu précédemment et de concevoir un boitier unique disposant de l'ensemble des capteurs dont nous avons besoin. Cette solution nous permettra de développer rapidement le système et le tester tout en pouvant toucher aux différents aspects de ce projet et respecter des contraintes de ressources et de coûts.


## Architecture globale du système

L'idée étant d'avoir une solution clé en main, l'objet est donc un boitier contenant l'ensemble du système. 
Afin de le mettre en place il faut donc les éléments suivants : 
- Le boitier contenant le système
- Une surface sur laquelle fixer le boitier
- Une alimentation (comprise entre 3 et 20V) ou un chargeur de téléphone (5V) et un cable micro-USB

Le but étant de placer le boitier à une distance relativement haute afin qu'il ne puisse être atteint trop rapidement.

### Fonctionnalités

(lister fonctionnalités)


### Echange d'informations

(ajouter schéma d'échange d'infos)


## Sécurité globale

(à rédiger)


## Respect de la vie privée (RGPD)

(à rédiger)


## Architecture matérielle de l'objet

Afin de mener à bien ce projet nous avons utilisé différents éléments qui sont les suivants :
- Un [Arduino Tiny Machine Learning Kit](https://store.arduino.cc/products/arduino-tiny-machine-learning-kit) qui est basé sur une Arduino Nano 33 BLE Lite. Cette carte est spécifiquement concu pour les projets IoT. En effet, elle dispose de nombreux éléments dont : 
  - une connection BLE (Bluetooth Low Energy) : utilisé afin d'envoyer des informations au smartphone.
  - un capteur faisant office d'accéléromètre, magnétomètre et gyroscope : non utilisé dans notre projet car le boitier sera fixé.
  - un capteur de proximité : non utilisé car son utilisation est limitée dans le cadre de notre projet.
  - un microphone omnidirentionnel : non utilisé pour l'instant mais qui pourra être intégré plus tard.
- Un [Grove buzzer](https://wiki.seeedstudio.com/Grove-Buzzer/) permettant de jouer des sons.
- Un [Grove PIR sensor](https://wiki.seeedstudio.com/Grove-PIR_Motion_Sensor/) afin de détecter la présence d'une personne.
- Un [Grove bouton](https://wiki.seeedstudio.com/Grove-Button/) qui a pour but de vérifier que le boitier est bien fixé au mur.
- Un bandeau de LED addressables WS2812B permettant un retour d'informations visuelles

D'autres éléments sont également utilisés comme :
- Une alimentation mise en place à l'aide d'un chargeur de téléphone et un cable micro-USB.
- Un boitier concu à l'aide d'une découpeuse laser et d'une plaque de contreplaqué de 3 mm.

<u>Remarque :</u> On notera que l'Arduino ne peut fournir qu'une tension de 3,3V.


## Estimation de la BOM de notre produit

(à rédiger - basé sur 5000 unités produites)

La BOM est la liste compète de toutes les pièces et matières utilisée afin de fabriquer ce produit. Pour la réaliser, on se base sur une estimation de production de l'ordre de 5000 unités produites. On dresse alors le tableau suivant :

| Matériel                          | Quantité | Prix unitaire | Prix de groupe | Revendeur | Remarque                                   |
| --------------------------------- | -------- | ------------- | -------------- | --------- | ------------------------------------------ |
| Arduino Tiny Machine Learning Kit | 5000     | ???           | ???            | ???       | ???                                        |
| Buzzer Grove                      | 5000     | ???           | ???            | ???       | ???                                        |
| Bouton Grove                      | 5000     | ???           | ???            | ???       | ???                                        |
| Capteur PIR                       | 5000     | ???           | ???            | ???       | ???                                        |
| Bandeau LED WS2812B               | 5000     | ???           | ???            | ???       | Densité de ??? LED/m                       |
| Contreplaqué                      | 5000     | ???           | ???            | ???       | Surface unitaire de ???m² (total = ??? m²) |
| Chargeur de téléphone             | 5000     | ???           | ???            | ???       | Puissance de 5V et 1,5A                    |
| Cable micro-USB                   | 5000     | ???           | ???            | ???       | ???                                        |

La BOM réalisée ci-dessus ne prend pas en compte les coûts liés à l'utilsiation des machines du type découpeuse laser.


## Estimation du cout des certifications

(à rédiger)


## Implémentation logiciel embarqué de l'objet défini

(à rédiger)


## Format des messages échangés

(à rédiger)

## Définition du logiciel embarqué de l'objet

(à rédiger)


## Métriques du logiciel embarqué

(à rédiger)


## Mesure des temps d'éxécution des phases d'éxécution

(à rédiger)


## Estimation de la durée de vie de l'objet

(à rédiger)


## Analyse du cycle de vie du produit (ACV)

(à rédiger)


## Recherche et analyse des produits concurrents

Dans cette partie nous comparons les différents produits vis à vis du notre. L'idée n'est pas de cibler un produit en particulier mais plutot une gamme de produit afin d'éviter d'avoir un tableau redondant étant donné qu'ils existent de nombreuses alarme à détection et qu'elles se valent toutes plus ou moins dans les grandes lignes.

| Produit              | Avantages                                                                    | Inconvénients                                               |
| -------------------- | ---------------------------------------------------------------------------- | ----------------------------------------------------------- |
| Alarme classique     | <ul><li>Fiabilité</li><li>Robustesse</li></ul>                               | <ul><li>Prix (100 à 1500€)</li></ul>                        |
| Centrale domotique   | <ul><li>Prix(40€ la centrale, ~10€ le capteur)</li><li>Evolutivité</li></ul> | <ul><li>Facilement désactivable</li></ul>                   |
| Notre alarme         | <ul><li>Peu couteux</li><li>Open Source</li></ul>                            | <ul><li>Prototype</li><li>Facilement désactivable</li></ul> |


## Intégrations effectuées

Afin de communiquer avec le système une première intégration a été mise en place à travers l'application "[LightBlue® - Bluetooth Low Energy](https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer&hl=fr&gl=US&pli=1)" disponible seuelement Google Play Store pour les téléphones Android. 
Cette application permet de se connecter à n'importe quel appareil utilisant le protocole Bluetooth Low Energy. Grâce à celle-ci nous sommes donc en mesure de détecter le ou les services Bluetooth que propose le système. Elle a été spécifiquement concu pour les développeurs, ainsi pour chaque service on peut venir lire, écrire ou être notifié en fonction de comment le service a été défini dans le code auparavant. De plus on peut gérer l'envoi sous différentes forme (binaire, hexa, caractère, signed/unsigned ou encore little/big endian). 
Cette application nous a donc été très utile cependant elle ne dispose pas d'une interface claire et lisible pour un utilisateur lambda. 

Dans cette optique nous avons décidé de créer une seconde application Android qui serait spécifiquement dédié au projet. Cette application serait basique mais permettrait de mettre en forme les informations et communiquer avec les services Bluetooth dont dispose le système. N'ayant pas de connaissances particulières sur le développement d'application sous Android nous avons fait le choix de développer sous [MIT App Inventor](https://appinventor.mit.edu/). 


## Problèmes rencontrés

(à rédiger)


## Nombre de lignes de code développé

Afin de mettre à bien ce projet nous avons rédigé 112 lignes de code en C sous l'IDE Arduino. Afin de réduire ce nombre de ligne de code nous avons utilisé des librairies déjà concu et permettant de grandement gagner du temps face au peu de temps dont nous disposons. 

Concernant l'application développé sous MIT App Inventor celle-ci ne fonctionne pas sous forme de ligne de code mais sous forme de blocs à empiler (façon Scratch). Par conséquent il est difficile de quantifier le travail réalisé mais nous avons cependant essayé de faire des blocs génériques afin qu'ils puissent facilement s'adapter aux services Bluetooth dont nous disposons. Cette démarche nous a ainsi permis de gagner du temps là encore.

L'ensemble du code est disponible dans les répertoires [Arduino](https://github.com/AlexFouilleul/Detection-alarm/tree/main/Arduino) et [Application](https://github.com/AlexFouilleul/Detection-alarm/tree/main/Application). 
