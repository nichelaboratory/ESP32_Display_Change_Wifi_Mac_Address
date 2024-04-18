# ESP32 Display and Change Wifi Mac Address
How to display and change an ESP32 microcontroller's mac address
 
Here's how to quickly find and then change the Wifi Mac Address of an ESP32 microcontroller. The ESP32's Mac Address is assigned at the factory, but you can change it to another Mac Address of your choosing. This is really useful if you're using Home Assistant or another Internet of Things service or you're streaming video from an ESP32 CAM.

Just be aware you can't permanently change the ESP32's Mac Address. If you upload another sketch and it doesn't have the Mac Address changing code in it then the device's Mac Address will revert to the factory assigned one. 

Another important point to bear in mind is that the first bit of the first byte of the new Mac Address must be set to 0, it can't be 1. So in the video I successfully set my ESP32's new Mac Address to A0:B0:C0:D0:E0:F0 but I wouldn't be able to set it to A1:B0:C0:D0:E0:F0.
 
Full code walkthrough in this video:
 
[![ESP32 Find and Change Wifi Mac Address](https://img.youtube.com/vi/EW8Ft5zJi68/0.jpg)](https://www.youtube.com/watch?v=EW8Ft5zJi68)
 
Click on the image above to watch the video or go here: https://youtu.be/EW8Ft5zJi68
