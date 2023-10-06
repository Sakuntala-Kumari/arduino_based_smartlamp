int trigger_pin=8;//recieve data
int echo_pin= 9; //send data
int relay1=12;
int distance;
long duration;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(relay1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger_pin,LOW);  //apply 0V to trigger pin
  delayMicroseconds(2); //pause of 2 micro sec
  digitalWrite(trigger_pin,HIGH);  //apply 5V to trigger pin
  delayMicroseconds(10);  //pause of 10 micro sec
  

  duration =pulseIn(echo_pin,HIGH); //listen for echo
  distance=(duration/2)/29.1;

  Serial.println("Distance :"); //prints distance
  Serial.println(distance);
  Serial.println("CM");
  if(distance <15){
  digitalWrite(relay1,LOW);
  Serial.print("on");}
  else{
    digitalWrite(relay1,HIGH);
    Serial.print("Success");}
  
  
}
