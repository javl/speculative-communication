## Add the Wemos D1 mini to the Arduino IDE
In order to be able to program your `Wemos D1 Mini` you need to add the board to the Arduino IDE:

1. Open the Arduino IDE.
2. Go to `File` > `Preferences`
3. Locate the textfield labeled `Additional boards manager URLs` at the bottom of the preferences window
4. If the field is empty, simply enter the following value: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
5. If the field already has an URL in it (maybe you added a different device in the past) just put a comma `,` at the end of the existing value, and paste the above URL after it.
6. Click OK to save the change and close the preferences window.
7. In the menu click `tools` > `board` > `board manager` and search for `esp8266`. Press install.
8. When Arduino is done installing the files you can select the right device to use: `tools` > `board` > `ESP8266` > `Lolin (Wemos) D1 R2 & mini`
9. Make sure you also select the right port. If in doubt, just unplug the board, check the list of port options, then plug the board back in and note which new port appeared.

## Create a The Things Network account
1. Go to [thethingsnetwork.org](https://www.thethingsnetwork.org/) and click the `sign up` button in the top right
2. Select the `Join The Things Network` option on the left (not `Get started for free`)
3. Confirm your email address via the email they'll send you and log in
4. In the menu in the top right, click `console`
5. Select the region you are in (e.g. `Europe 1`)
6. In the menu bar select `Applications` to create your application.
