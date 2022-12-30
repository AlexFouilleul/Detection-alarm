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


## Sécurité globale

(à rédiger)


## Respect de la vie privée (RGPD)

(à rédiger)


##Architecture matérielle de l'objet

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

(à rédiger sous forme d'une grille avantages/inconvénients)

Dans cette partie nous comparons les différents produits vis à vis du notre. L'idée n'est pas de cibler un produit en particulier mais plutot une gamme de produit afin d'éviter d'avoir un tableau redondant étant donné qu'ils existent de nombreuses alarme à détection et qu'elles se valent toutes plus ou moins dans les grandes lignes.

| Produit              | Avantages                                                                    | Inconvénients                             |
| -------------------- | ---------------------------------------------------------------------------- | ----------------------------------------- |
| Alarme classique     | <ul><li>Fiabilité</li><li>Robustesse</li></ul>                               | <ul><li>Prix (100 à 1500€)</li></ul>      |
| Centrale domotique   | <ul><li>Prix(40€ la centrale, ~10€ le capteur)</li><li>Evolutivité</li></ul> | <ul><li>Facilement désactivable</li></ul> |
| Notre alarme         | <ul><li>Peu couteux</li><li>Open Source</li></ul>                            | <ul><li>Prototype</li></ul>               |

<span style="color:blue">some *blue* text</span>

## Intéggrations effectuées

(à rédiger)

## Nombre de lignes de code développé

(à rédiger en spécifiant les outils utilisés)
