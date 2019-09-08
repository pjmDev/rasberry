#include <stdio.h>
#include <wiringPi.h>

#define PINE 7
#define PIN1 8
#define PIN2 9
#define PIR 1


int main(void){

	if(wiringPiSetup() == -1)
	return 1;

	pinMode(PINE, OUTPUT);
	pinMode(PIN1, OUTPUT);
	pinMode(PIN2, OUTPUT);
	pinMode(PIR, INPUT);

	int a = 0;
	
	for(;;){
		if(digitalRead(PIR) == 1){
			digitalWrite(PINE, 1);
			digitalWrite(PIN1, 1);
			digitalWrite(PIN2, 1);
			printf("A");
		}
		else if(digitalRead(PIR) == 0){
			digitalWrite(PINE, 1);
			digitalWrite(PIN1, 1);
			digitalWrite(PIN2, 1);
			printf("B");
			return 0;
		}
	}
	
	return 0;

}
