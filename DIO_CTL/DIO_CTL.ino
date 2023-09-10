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
        unsigned char DioBuffer[4]={Rxbuffer[2],Rxbuffer[3],Rxbuffer[4],Rxbuffer[5]};
        setPins(DioBuffer,4);
      }
      else if(Rxbuffer[1]==1){
        unsigned char DioBuffer[4]={Rxbuffer[2],Rxbuffer[3],Rxbuffer[4],Rxbuffer[5]};
        WritePins(DioBuffer,4);
      }
      else if(Rxbuffer[1]==2){
        unsigned char DioBuffer[4]={0};
        ReadPins(DioBuffer,4);
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

void setPins(unsigned char * buffer, unsigned char size){
  for(cnt=1;cnt<9;cnt++){
    pinMode(cnt,1);
  }
}
void WritePins(unsigned char * buffer, unsigned char size){
  //digitalWrite(1);
}
void ReadPins(unsigned char * buffer, unsigned char size){
  //digitalRead(1);
}
