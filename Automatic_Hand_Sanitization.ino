//code for Dispenser Using Arduino(Automatic Hand Sanitizer Dispenser) 
// defines pins numbers 
#define led  12
#define buzzer 4
#define trigPin 9
# define echoPin 10
// defines variables
long duration;
int distance;
 
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(led,OUTPUT);     // here we define the pinmode of led i.e 12th digital pin
pinMode(7,OUTPUT);      // so here we have connected the base of NPN tansistor at 7th digital pin 
pinMode(buzzer,OUTPUT); // here we define the pinmode of buzzer i.e 4th digital pin  
Serial.begin(9600);     // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: "); // it will show us the distance measured in the serial moniter
Serial.println(distance);

if(distance<=20)               // checking the presence of hands in 20 cm limit
  {  
    digitalWrite(7,HIGH);    // if present motor operates for some time
    delay(1500);                  // delay value to changes the operating time
    digitalWrite(7,LOW);     // pump stop working for some time
    delay(1000);                 // some delay prevents continous operation
    digitalWrite(led,HIGH);  // led will glow
    delay(1000);
    digitalWrite(led,LOW);   
    delay(1000);
    tone(buzzer,4000);  // so here buzzer will start beeping at a frequency of 2000Hz
    delay(900);
    noTone(buzzer);
    }
  else 
  {
    digitalWrite(7,LOW);     // if no hands detected - no operation
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
  }
  delay(1000);        // delay of 1second pis given so that the whole system comes back to original
                      // original state
}
