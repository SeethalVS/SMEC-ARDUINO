
char user_pw[10],pw[]="pass@123";
int indx;
void setup() {
 Serial.begin(9600);
 Serial.println("Welcome");

}

void loop() {
 // int compare_value;
  char ch;
  if(Serial.available()>0){
    ch=Serial.read();
    if(ch=='*'){
     indx=0;
     Serial.print("Password:");
     do{
     
      if(Serial.available()>0){
        user_pw[indx]=Serial.read();
        if(user_pw[indx]!='#'){
           if(user_pw[indx]=='\b'){
              Serial.print('\b');
              indx=indx-2;
            }
            else{
              Serial.print('*');
            } 
          // Serial.print(user_pw[indx]);
        }
        indx++;
     
      }
    }while(user_pw[indx-1]!='#');
    user_pw[indx-1]='\0';
    //Serial.print(user_pw);
  
    Serial.println(" ");
    if(strcmp(pw,user_pw)==0){
      
      Serial.println("USER ACCESS GRANTED!!!");
      Serial.println("viewing data...!");
    }
    else{
      Serial.println("USER ACCESS DENIED!!!");
      Serial.println("System LOCKED :(");
    }
  }
 }
 
}
