int fanSpeed = 0;
String command;
char werd;
int fanSpeed = 0;
int fan = 6;
int frontSpeed = 0;
int commandCheck;
String frontMarker = "-> ";

void setup() {
  pinMode(fan, OUTPUT);
  analogWrite(fan,0);
  Serial.begin(9600);
  Serial.println();
}

void loop(){
  while ( Serial.available() > 0 ) {
    delay(5);
    werd = Serial.read();
    command += werd;
  }
  Serial.flush();
  if ( command.length() > 0 ) {
    commandCheck = 0;
    if ( command == "front" ) {
        currentFan = 0;
        frontMarker = "-> ";
    } else {
        commandCheck = 1;
    }
    if ( commandCheck == 1 ) {
      if ( currentFan == 0 ) {
        //front
        analogWrite(fan, command.toInt());
        frontSpeed = command.toInt();
      }else {
      }
    }
    command = "";
    Serial.print(frontMarker);
    Serial.print("Front: ");
    Serial.println(frontSpeed);

  }
}
