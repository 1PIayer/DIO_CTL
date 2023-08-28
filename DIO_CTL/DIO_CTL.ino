//HUSAMETTIN EKEN 28.08.2023

//DEFINES
#define COMMAND_HEADER_ERROR -1
#define COMMAND_TYPE_ERROR -2


//Variables
unsigned char Rxbuffer[8]={0};
unsigned char Txbuffer[8]={0x48,0,0,0,0,0,0,0};
unsigned char DIO_State[4]={0};
uint32_t cnt=0;


void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
}

void loop() {
  if(Serial.available()){
    Serial.readBytes(Rxbuffer, 8);
    if(Rxbuffer[0]== 0x48){
      if(Rxbuffer[1]==0){
        for(cnt=1;cnt<12;cnt++){
          pinMode(cnt,1);
        }
      }
      else if(Rxbuffer[1]==1){
        //digitalWrite(1);
      }
      else if(Rxbuffer[1]==2){
        //digitalRead(1);
      }
      else{
        Txbuffer[1]= COMMAND_TYPE_ERROR;
        Serial.write(Txbuffer,8);
      }
    }
    else{
      Txbuffer[1]= COMMAND_HEADER_ERROR;
      Serial.write(Txbuffer,8);
    }      
  }
}
