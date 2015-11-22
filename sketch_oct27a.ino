/*Author :JASKARAN (jvsg1303)
 *Date : 27 October,2015
 *Feel Free to contribute
 *The following program is made for Arduino based Smart Punching Bag
 *Read The Documentation to know more
 */

/* Initialize the Pins*/
const int led1=1,led2=2,led3=3,led4=4;
const int button1=5,button2=6,button3=7,button4=8;

/* Set the delay time and number of loops*/
const int dlay=1000;
const int loops=10;


void setup(){
  /*Assign INPUT or OUTPUTS to the pins*/
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  /*Setting baud rate for Communicating with the computer*/
  Serial.begin(9600);
}
  
void loop(){
  /*Initializing the Button State to low*/
  int buttonstate1=LOW;
  int buttonstate2=LOW;
  int buttonstate3=LOW;
  int buttonstate4=LOW;
  /*Fetch random number*/
  int r=random(1,5);
  /*Array to store the values obtained after a boxing round*/
  int A[loops];
  /*cl : counts the number of loops*/
  int cl=0;
  while(cl!=loops){
  /*Delay between Punches*/ 
  delay(dlay);
  switch(r){
   case 1 : { digitalWrite(led1,HIGH);
          int t1=millis();
          while(buttonstate1!=1){
            buttonstate1=digitalRead(button1);
            delay(1);
          }
          
          int t2=millis();
          /*Difference between the LED glowing time and Punching time
           *to measure Player's reflexes. Next few blocks do the same work
           *as this block does. */
          A[cl]=t2-t1;
          cl++;
    }
    break;
    
    case 2 : { digitalWrite(led2,HIGH);
          int t1=millis();
          while(buttonstate2!=1){
            buttonstate2=digitalRead(button2);
            delay(1);
          }
          
          int t2=millis();
          A[cl]=t2-t1;
          cl++;
    }
    break;
    
    case 3 : { digitalWrite(led3,HIGH);
          int t1=millis();
          while(buttonstate3!=1){
            buttonstate3=digitalRead(button3);
            delay(1);
          }
          
          int t2=millis();
          A[cl]=t2-t1;
          cl++;
    }
    break;
    
    case 4 : { digitalWrite(led4,HIGH);
          int t1=millis();
          while(buttonstate4!=1){
            buttonstate4=digitalRead(button4);
            delay(1);
          }
          
          int t2=millis();
          A[cl]=t2-t1;
          cl++;
    }
    break;
  };
 }
 /*Sending Measured values to the Computer to compute the Generated Data
  * for Mean, Median , Mode, Graphs using Python, Matlab,or your very own brain
  * Enjoy*/  
 for(int i=0;i<loops;i++){
   Serial.write(A[i]);
 }
   /*Prints the next round message to your Computer Screen*/
   Serial.println("Done with this. Next Round.");
   /*Have fun Boxing*/
}
  


  
