#define analogPin A0
float flux=0;
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(analogPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  flux=(analogRead(analogPin)*4.951/1024.0);//*1000/1.8;
  flux=flux*1000/1.8;//into gauss
  //flux=flux/10;//in mT(miliTesla)
  
  if(flux > 1330.0){
    Serial.print("Flux : ");
    Serial.print(flux);
    Serial.print(" G");
    Serial.println(" N");
  }
  else if(flux < 1280.0){
    Serial.print("Flux : ");
    Serial.print(flux);
    Serial.print(" G");
    Serial.println(" S");
  }
  else Serial.println("Align magnet with the sensor ");
}
