#define DELAY 20
#define MIN_RAW 0
#define MAX_RAW 1023
#define MIN_CMD 0
#define MAX_CMD 200

const int sensorPin = A0;
const int ledPin = 3; 

int sensorVal;
int cmd;

void setup(void) {
 	Serial.begin(9600);
 	pinMode(ledPin,OUTPUT);
}

void loop(void) {
 	sensorVal = analogRead(sensorPin);
 	cmd=sensorToLed(sensorVal);
 	analogWrite(ledPin,cmd);
 	delay(DELAY);
 	Serial.print("Sensor : ");
 	Serial.println(sensorVal);
 	Serial.print("Command : ");
 	Serial.println(cmd);
}

int sensorToLed(int raw){
 	int val = map(sensorVal, MIN_RAW, MAX_RAW, MIN_CMD, MAX_CMD);
 	val=max(val,MIN_CMD);
 	val=min(val,MAX_CMD);
 	return val;
}
