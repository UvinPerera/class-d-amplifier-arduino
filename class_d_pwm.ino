#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit)) // define cbi and sbi
void setup() {
  // put your setup code here, to run once:
  sbi(ADCSRA, ADPS2);
  cbi(ADCSRA, ADPS1);
  cbi(ADCSRA, ADPS0); // ADC 76kHz prescaler 16
  
 
  TCCR0B = TCCR0B & B11111000 | B00000001; // for PWM frequency of 62500.00 Hz for pin 5
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot = analogRead(A0); // Input signal
  int scaled = pot*1; // scaling factor
  int output = map(scaled,0,150,0,255); /*
  input signal to PWM. 150 is eqilavent to (5/1024)*150 Volts which is the maximum input voltage
 */
  analogWrite(5,output); // PWM output

}
