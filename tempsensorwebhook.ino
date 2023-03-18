
float readtemp;
float voltage;
float tempOutput;
int tempPin = A1;

void setup() {

}

void loop() {
    readtemp = analogRead(tempPin);                             //READ TEMPERATURE FROM SENSOR
    voltage = (readtemp * 3.3) / 4095.0;                        //PERFORM CALCULATION TO CONVERT THE RAW DATA FROM DEVICE TO VOLTAGE
    tempOutput = (voltage - .5) * 100;                          //PERFORM ANOTHER CALCULATION TO CONVERT TO CELCIUS
    Particle.publish("temp", String(tempOutput), PRIVATE);      //PUBLISH AS "temp" TO PARTICULE OUTPUT. THIS WILL BE PICKED UP VIA THE WEBHOOK
    delay(30000);                                               //30 SECOND DELAY BETWEEN UPDATES
}   
    
// CODE USED DURING TESTING TO OUTPUT SENSOR VALUES AND ENSURE CALCULATIONS ARE ACCURATE
//   Particle.publish("temp", String(tempOutput), PRIVATE);
//   Particle.publish("readtemp", String(readtemp), PRIVATE);
//   Particle.publish("voltage", String(voltage), PRIVATE);
//   Particle.publish("temp", String(tempOutput), PRIVATE);

