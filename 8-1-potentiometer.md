#Potentiometer

Dagens lektion handlar om potentiometrar. En potentiometer är en komponent som används som input, och består i en liten ratt som går att vrida (tänk dimmer på lampa eller volymkontroll på gammal radio). Genom att man vrider ratten så förändras motståndet (resistansen) och därmed vilket värde som läses av från pinnen.

Potentiometrar ger analog input, istället för digital input (som en knapp). Digital input kan vara två värden, 1 eller 0. Analog input är mer kontinuerlig och kan anta flera olika värden på en skala.

För att hantera den analoga input:en konverteras intervallet som spänningen kan vara (0 V - 3,3 V) till små intervall. Det blir som att det delas upp i små steg, vilket blir närmare en kontinuerlig skala. För ESP32 är standard att den olika spänningen omvandlas till ett värde mellan 0-4095 (dvs 4096 steg).

För att styra så att upplösningen blir rätt, dvs antal steg, används analogReadResolution(12). 12 står för antalet bitar, dvs antalet tal (1 eller 0) som kan användas för att representera värdet. Med 12 bitar går det att skriva tal från 0-4095.

För att läsa av värdet på en potentiometer används analogRead(pin). Denna kommer alltså att ge ett värde mellan 0-4095 i form av en int.

En potentiometer kan endast kopplas till vissa pinnar, de som är märkta ADC (analog to digital converter). Se pin-kartan i lektionsloggen. Vi tittar tillsammans på koppling av potentiometer i [Wokwi](https://drive.google.com/file/d/1l6YPhqUT3YqhfzWMHGC-9oGlVphFVUu2/view?usp=sharing), [Velxio](https://drive.google.com/file/d/1_Ps8iSrP_-h_ENDnjSp7qaIQFFHBGdMZ/view?usp=sharing) och en bild som mer liknar [verkligheten](https://drive.google.com/file/d/1whGZmd3-8aJYOUm6ANobeW6OOrqhaZ2X/view?usp=sharing). I Wokwi och Velxio står VCC för den som ska kopplas till ström och SIG för den som ska kopplas till en pin.