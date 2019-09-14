This project uses the following libraries:

GxEPD: https://github.com/ZinggJM/GxEPD

Adafruit_GFX

QR Code generation: https://github.com/ricmoo/QRCode


The board used:

https://www.aliexpress.com/item/32989928508.html?spm=a2g0o.productlist.0.0.7b6c587fYZ39Pu&algo_pvid=8950ab73-0e3c-4a31-8d9f-1827b747e75f&algo_expid=8950ab73-0e3c-4a31-8d9f-1827b747e75f-16&btsid=b1862fbb-86db-49d9-b70d-52f4c520745e&ws_ab_test=searchweb0_0,searchweb201602_4,searchweb201603_52


I attached two buttons to pins 33 and 32.
Pin 33 turns on Bluetooth
Pin 32 wakes up the board.
Both are pulled up. 
Two LEDs are connected to pin 25.

When Bluetooth is ON, you see the icon appear on the screen.
You can send the following commands:

  QR=<QR CODE CONTENT>
  
  TT=<TITLE>
  
  T1=<LINE 1>
  
  T2=<LINE 2>
  
  T3=<LINE 3>
  
  T4=<LINE 4>
  
  T5=<LINE 5>
  
  SV - SAVE IT TO FLASH
  
  RR - REFRESH SCREEN
