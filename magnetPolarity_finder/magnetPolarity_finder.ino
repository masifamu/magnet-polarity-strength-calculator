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
  flux=flux/10;//in mT(miliTesla)
  Serial.print("Flux : ");
  Serial.print(flux);
  Serial.print("mT");
  if(flux > 150.0) Serial.println(" N-Ploe");
  else if(flux < 110.0) Serial.println(" S-Pole");
  else Serial.println(" ");
}
