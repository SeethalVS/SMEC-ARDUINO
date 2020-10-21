int led1=5,led2=6,led3=7,fn_sw=13,power_sw=12,led4=10;
int prev_status1=0,present_status1=0,ledstatus=0;
int prev_status2=0,present_status2=0,count=0;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(fn_sw,INPUT);
  pinMode(power_sw,INPUT);
}

void loop() {
  present_status1=digitalRead(power_sw);
  if(prev_status1==0&&present_status1==1){
    ledstatus=(ledstatus==0)?1:0;
    digitalWrite(led4,ledstatus);
 }
 prev_status1=present_status1;
 if(ledstatus==1){
  present_status2=digitalRead(fn_sw);
  if(prev_status2==0&&present_status2==1){
    count++;
    switch(count)
    {
      case 1:digitalWrite(led1,1);
      break;
      case 2:digitalWrite(led2,1);
      break;
      case 3:digitalWrite(led3,1);
      break;
      case 4:digitalWrite(led1,0);
      digitalWrite(led2,0);
      digitalWrite(led3,0);
      count=0;
      break;
    }
  }
  prev_status2=present_status2;
 }
 if(ledstatus==0){
  count=0;
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
 }
 
}
