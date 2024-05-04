/*
  HG7881_Motor_Driver_Example - Arduino sketch
   
  This example shows how to drive a motor with using HG7881 (L9110) Dual
  Channel Motor Driver Module.  For simplicity, this example shows how to
  drive a single motor.  Both channels work the same way.
   
  This example is meant to illustrate how to operate the motor driver
  and is not intended to be elegant, efficient or useful.
   
  Connections:
   
    Arduino digital output D10 to motor driver input B-IA.
    Arduino digital output D11 to motor driver input B-IB.
    Motor driver VCC to operating voltage 5V.
    Motor driver GND to common ground.
    Motor driver MOTOR B screw terminals to a small motor.
     
  Related Banana Robotics items:
   
    BR010038 HG7881 (L9110) Dual Channel Motor Driver Module
    https://www.BananaRobotics.com/shop/HG7881-(L9110)-Dual-Channel-Motor-Driver-Module
 
  https://www.BananaRobotics.com
*/
 
// wired connections
#define HG7881_B_1A 36
#define HG7881_B_2A 16
#define HG7881_A_1A 6
#define HG7881_A_1B 5

// functional connections
#define MOTOR_B_PWM HG7881_B_1A // Motor B PWM Speed
#define MOTOR_B_DIR HG7881_B_2A // Motor B Direction
#define MOTOR_A_PWM HG7881_A_1A // Motor A PWM Speed
#define MOTOR_A_DIR HG7881_A_1B // Motor A Direction
 
// the actual values for "fast" and "slow" depend on the motor
#define PWM_SLOW 50  // arbitrary slow speed PWM duty cycle
#define PWM_FAST 200 // arbitrary fast speed PWM duty cycle
#define DIR_DELAY 1000 // brief delay for abrupt motor changes
 
void setup()
{
  Serial.begin( 9600 );
  pinMode( MOTOR_B_DIR, OUTPUT );
  
  ledcAttachPin(MOTOR_B_PWM, 0);

  ledcSetup(0, 500, 8);

  // set the motor speed and direction
  digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
  ledcWrite(0, 255-PWM_SLOW);
}
 
void loop()
{
   /*
  boolean isValidInput;
  // draw a menu on the serial port
  Serial.println( "-----------------------------" );
  Serial.println( "MENU:" );
  Serial.println( "1) Fast forward" );
  Serial.println( "2) Forward" );
  Serial.println( "3) Soft stop (coast)" );
  Serial.println( "4) Reverse" );
  Serial.println( "5) Fast reverse" );
  Serial.println( "6) Hard stop (brake)" );
  Serial.println( "-----------------------------" );
  do
  {
    byte c;
    // get the next character from the serial port
    Serial.print( "?" );
    while( !Serial.available() )
      ; // LOOP...
    c = Serial.read();
    // execute the menu option based on the character recieved
    
    switch( c )
    {
      case '1': // 1) Fast forward
        Serial.println( "Fast forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        ledcWrite(0, 0);
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
        ledcWrite(0, 255-PWM_FAST);
        isValidInput = true;
        break;      
         
      case '2': // 2) Forward      
        Serial.println( "Forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        ledcWrite(0, 0);
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
        ledcWrite(0, 255-PWM_SLOW);
        isValidInput = true;
        break;      
         
      case '3': // 3) Soft stop (preferred)
        Serial.println( "Soft stop (coast)..." );
        digitalWrite( MOTOR_B_DIR, LOW );
        ledcWrite(0, 0);
        isValidInput = true;
        break;      
 
      case '4': // 4) Reverse
        Serial.println( "Fast forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        ledcWrite(0, 0);
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, LOW ); // direction = reverse
        ledcWrite(0, PWM_SLOW);
        isValidInput = true;
        break;      
         
      case '5': // 5) Fast reverse
        Serial.println( "Fast forward..." );
        // always stop motors briefly before abrupt changes
        digitalWrite( MOTOR_B_DIR, LOW );
        ledcWrite(0, 0);
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, LOW ); // direction = reverse      
        ledcWrite(0, PWM_FAST);
        isValidInput = true;
        break;
         
      case '6': // 6) Hard stop (use with caution)
        Serial.println( "Hard stop (brake)..." );
        digitalWrite( MOTOR_B_DIR, HIGH );
        ledcWrite(0, 255);
        isValidInput = true;
        break;      
         
      default:
        // wrong character! display the menu again!
        isValidInput = false;
        break;
    }
  } while( isValidInput == true );
  */
  // repeat the main loop and redraw the menu...
}
/*EOF*/