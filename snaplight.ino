Servo servo;// create servo object using the built-in Particle Servo Library

// Declare constants
const int step = 15;
const int button = D0;    //declare variable for button
const int servoPin = D1;  //declare variable for servo

// Declare variables
int pos = 0;        //variable to keep track of the servo's position
bool flag = 1;      //variable to keep track of the button presses


// This routine runs only once upon reset
void setup()
{
  Serial.begin(9600);//Start the Serial port @ 9600 baud
  Serial.println("Setting up...");

  pinMode(button, INPUT_PULLUP);   // sets button pin as input with internal pullup resistor
}

// Force servo down without controls.
int forceHigh()
{
    Serial.println("forceHigh()");
    servo.attach(servoPin);
    servo.write(0);
    delay(1000);
    // Now move to a rest position
    servo.write(30);
    delay(500);
    servo.detach();
}

int forceLow()
{
    Serial.println("forceLow()");
    servo.attach(servoPin);
    servo.write(180);
    delay(1000);
    // Now move to a rest position
    servo.write(150);
    delay(500);
    servo.detach();
}

// Toggle the light on/off
int toggle()
{
    Serial.println("toggling");

    //This is known a s state machine.
    //It will move the servo to the opposite end from where it's set currently
    if (flag == 1) {
        forceLow();
    }

    if (flag == 0){
        forceHigh();
    }

    flag = !flag;         //set flag to the opposite of what it's currently set to

    Serial.println(servo.read());  //prints to the serial port to keep track of the position
}

// This routine loops forever
void loop()
{
    if (digitalRead(button) == LOW) //if a button press has been detected...
    {
        toggle();
    }
}
