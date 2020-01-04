/**************************************************************
 *                  TZXDuino Menu Code:
 *  Menu Button (was motor controll button) opens menu
 *  up/down move through menu, play select, stop back
 *  Menu Options:
 *  TSX Baud Rate:
 *    1200
 *    2400
 *    3600
 *  
 *  UEF Turbo Ctrl:
 *    On
 *    Off
 *  
 *  Pause @ Start
 *    On
 *    Off
 *    
 *  Save settings to eeprom on exit. 
 */

 

#if defined(__arm__) && defined(__STM32F1__)

uint8_t EEPROM_get(uint16_t address, byte *data) {
	if (EEPROM.init()==EEPROM_OK) {
		*data = (byte)(EEPROM.read(address) & 0xff);	
    return true;	
	} else 
    return false;
}


uint8_t EEPROM_put(uint16_t address, byte data) {
	if (EEPROM.init()==EEPROM_OK) {
		EEPROM.write(address, (uint16_t) data);	
    return true;		
	} else
    return false;
}
#endif

 
 
 void menuMode()
 {
  byte lastbtn=true;
  byte menuItem=0;
  byte subItem=0;
  byte updateScreen=true;
  
  while(digitalRead(btnStop)==HIGH || lastbtn)
  {
    if(updateScreen) {
      ////lcd_clearline(0);
      printtextF(PSTR("Menu Screen"),0);
      ////lcd_clearline(1);
      switch(menuItem) {
        
        case 0:
        printtextF(PSTR("TSX Baud Rate"),1);
        break;
        
        case 1:
        printtextF(PSTR("UEF Turbo"),1);
        break;
        
        case 2:
        printtextF(PSTR("Pause @ Start"),1);
        break;

        case 3:
        printtextF(PSTR("Gremlin Loader"),1);
        break;

        case 4:
        printtextF(PSTR("ID15"),1);
        break;
        
      }
      updateScreen=false;
    }
    
    if(digitalRead(btnDown)==LOW && !lastbtn){
      if(menuItem<4) menuItem+=1;
      lastbtn=true;
      updateScreen=true;
    }
    if(digitalRead(btnUp)==LOW && !lastbtn) {
      if(menuItem>0) menuItem+=-1;
      lastbtn=true;
      updateScreen=true;
    }

    
    if(digitalRead(btnPlay)==LOW && !lastbtn) {
      switch(menuItem){
        
        case 0:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(digitalRead(btnStop)==HIGH || lastbtn) {
            if(updateScreen) {
              ////lcd_clearline(0);
              printtextF(PSTR("TSX Baud Rate"),0);
              ////lcd_clearline(1);
              switch(subItem) {
                case 0:                                  
                printtextF(PSTR("1200 Baud"),1);
                if(BAUDRATE==1200) printtextF(PSTR("1200 Baud *     "),1);
                break;
                case 1:        
                  printtextF(PSTR("2400 Baud"),1);
                  if(BAUDRATE==2400) printtextF(PSTR("2400 Baud *     "),1);
                break;
                case 2:                  
                printtextF(PSTR("3600 Baud"),1);
                if(BAUDRATE==3600) printtextF(PSTR("3600 Baud *     "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(digitalRead(btnDown)==LOW && !lastbtn){
              if(subItem<2) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnUp)==LOW && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnPlay)==LOW && !lastbtn) {
              switch(subItem) {
                case 0:
                  BAUDRATE=1200;
                break;
                case 1:
                  BAUDRATE=2400;
                break;
                case 2:
                  BAUDRATE=3600;
                break;
              }
              updateScreen=true;
              lastbtn=true;
            }
            if(digitalRead(btnDown) && digitalRead(btnUp) && digitalRead(btnPlay) && digitalRead(btnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;
        
        case 1:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(digitalRead(btnStop)==HIGH || lastbtn) {
            if(updateScreen) {
              //lcd_clearline(0);
              printtextF(PSTR("UEF Turbo Ctrl"),0);
              //lcd_clearline(1);
              switch(subItem) {
                case 0:
                  printtext("On",1);
                  if(uefTurboMode==1) printtextF(PSTR("On  *           "),1);
                break;
                case 1:
                  printtext("Off",1);
                  if(uefTurboMode==0) printtextF(PSTR("Off *           "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(digitalRead(btnDown)==LOW && !lastbtn){
              if(subItem<1) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnUp)==LOW && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnPlay)==LOW && !lastbtn) {
              switch(subItem) {
                case 0:
                  uefTurboMode=1;
                break;
                case 1:
                  uefTurboMode=0;
                break;
              }
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnDown) && digitalRead(btnUp) && digitalRead(btnPlay) && digitalRead(btnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;

        case 2:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(digitalRead(btnStop)==HIGH || lastbtn) {
            if(updateScreen) {
              //lcd_clearline(0);
              printtextF(PSTR("Pause @ Start"),0);
              //lcd_clearline(1);
              switch(subItem) {
                case 0:
                  printtext("On",1);
                  if(PauseAtStart==true) printtextF(PSTR("On  *           "),1);
                break;
                
                case 1:
                  printtext("Off",1);
                  if(PauseAtStart==false) printtextF(PSTR("Off *           "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(digitalRead(btnDown)==LOW && !lastbtn){
              if(subItem<1) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnUp)==LOW && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnPlay)==LOW && !lastbtn) {
              switch(subItem) {
                case 0:
                  PauseAtStart=true;
                break;
                case 1:
                  PauseAtStart=false;
                break;
              }
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnDown) && digitalRead(btnUp) && digitalRead(btnPlay) && digitalRead(btnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;

        case 3:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(digitalRead(btnStop)==HIGH || lastbtn) {
            if(updateScreen) {
              //lcd_clearline(0);
              printtextF(PSTR("Gremlin Loader"),0);
              //lcd_clearline(1);
              switch(subItem) {
                case 0:
                  printtext("On",1);
                  if(FlipPolarity==1) printtextF(PSTR("On  *           "),1);
                break;
                
                case 1:
                  printtext("Off",1);
                  if(FlipPolarity==0) printtextF(PSTR("Off *           "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(digitalRead(btnDown)==LOW && !lastbtn){
              if(subItem<1) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnUp)==LOW && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnPlay)==LOW && !lastbtn) {
              switch(subItem) {
                case 0:
                  FlipPolarity = 1;
                break;
                case 1:
                  FlipPolarity = 0;
                break;
              }
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnDown) && digitalRead(btnUp) && digitalRead(btnPlay) && digitalRead(btnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;


        case 4:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(digitalRead(btnStop)==HIGH || lastbtn) {
            if(updateScreen) {
              //lcd_clearline(0);
              printtextF(PSTR("ID15 Switch"),0);
              //lcd_clearline(1);
              switch(subItem) {
                case 0:
                  printtext("On",1);
                  if(ID15switch==1) printtextF(PSTR("On  *           "),1);
                break;
                
                case 1:
                  printtext("Off",1);
                  if(ID15switch==0) printtextF(PSTR("Off *           "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(digitalRead(btnDown)==LOW && !lastbtn){
              if(subItem<1) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnUp)==LOW && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnPlay)==LOW && !lastbtn) {
              switch(subItem) {
                case 0:
                  ID15switch = 1;
                break;
                case 1:
                  ID15switch = 0;
                break;
              }
              lastbtn=true;
              updateScreen=true;
            }
            if(digitalRead(btnDown) && digitalRead(btnUp) && digitalRead(btnPlay) && digitalRead(btnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;
      }
    }
    if(digitalRead(btnDown) && digitalRead(btnUp) && digitalRead(btnPlay) && digitalRead(btnStop)) lastbtn=false;
  }
  updateEEPROM();
 }

 void updateEEPROM()
 {
  /* Setting Byte: 
   *  bit 0: 1200
   *  bit 1: 2400
   *  bit 2: 3600
   *  bit 3: n/a
   *  bit 4: ID15switch
   *  bit 5: Pause @ Start
   *  bit 6: Gremlin Loader
   *  bit 7: UEFTurbo
   */
  byte settings=0;

  switch(BAUDRATE) {
    case 1200:
    settings |=1;
    break;
    case 2400:
    settings |=2;
    break;
    case 3600:
    settings |=4;
    break;
  }
  if(ID15switch) settings |=16;
  if(PauseAtStart) settings |=32;
  if(FlipPolarity) settings |=64;
  if(uefTurboMode) settings |=128;

//  EEPROM.put(0,settings);
  #if defined(__AVR__)
  EEPROM.put(0,settings);
  #elif defined(__arm__) && defined(__STM32F1__)
  EEPROM_put(0,settings);
  #endif
 }

 void loadEEPROM()
 {
  byte settings=0;

  //EEPROM.get(0,settings);
  #if defined(__AVR__)
  EEPROM.get(0,settings);
  #elif defined(__arm__) && defined(__STM32F1__)
  EEPROM_get(0,&settings);
  #endif
    
  if(!settings) return;
  
  if(bitRead(settings,7)) {
    uefTurboMode=1;
  } else {
    uefTurboMode=0;
  }

  if(bitRead(settings,6)) {
    FlipPolarity=1;
  } else {
    FlipPolarity=0;
  }

  if(bitRead(settings,5)) {
    PauseAtStart=true;
  } else {
    PauseAtStart=false;
  }

  if(bitRead(settings,4)) {
    ID15switch=1;
  } else {
    ID15switch=0;
  }
  
  if(bitRead(settings,0)) {
    BAUDRATE=1200;
  }
  if(bitRead(settings,1)) {
    BAUDRATE=2400;
  }
  if(bitRead(settings,2)) {
    BAUDRATE=3600;
  }
  //setBaud();
  
 }
