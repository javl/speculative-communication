## Setting up the Arduino IDE
### Add the Wemos D1 mini to the list of available devices
In order to be able to program your `Wemos D1 Mini` you need to add the board to the Arduino IDE:

1. Open the Arduino IDE.
2. Go to `File` > `Preferences`
3. Locate the textfield labeled `Additional boards manager URLs` at the bottom of the preferences window
4. If the field is empty, simply enter the following value: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
5. If the field already has a URL in it (maybe you added a different device in the past) just put a comma `,` at the end of the existing value, and paste the above URL after it.
6. Click OK to save the change and close the preferences window.
7. Open the Board Manager (`tools` > `board` > `board manager`) and search for `esp8266`. Click install.
8. When Arduino is done installing the files you can select the right device to use: `tools` > `board` > `ESP8266` > `Lolin (Wemos) D1 R2 & mini`
9. To be able to upload make sure you select the right port. When in doubt, just unplug the board, check the list of port options, then plug the board back in and note which new port appeared.

### Install the Arduino LoRaWAN library
1. Find and install "MCCI LoRaWAN LMIC Library" from the library manager.
![MCCI LoRaWAN LMIC Library](images/library.png)
2. Now go into your Arduino libraries folder using Finder or Windows Explorer, and find the `MCCI LoRaWAN LMIC Library` folder. Inside is a folder called `project_config` with a single file called `lmic_project_config.h`. Open this file in some text editor.
4. Find the line `#define CFG_eu868 1` and uncomment it by removing the `//` in front of it, and comment out the other frequency plans by adding `//` in front of them. This will make sure the library is set up for the European frequency plan. So the file will look like this:

![File contents](images/library_config.png)


## Getting started with The Things Network
In order to use The Things Network (TTN) we need to create an account. From this account we can create an application which will allow us to start receiving data from devices.

### Create an account
1. Go to [thethingsnetwork.org](https://www.thethingsnetwork.org/) and click the `sign up` button in the top right.
2. Select the `Join The Things Network` option on the left.
3. Confirm your email address via the email they'll send you and log in.
4. Select the region you are in (e.g. `Europe 1`).
5. In the menu in the top right, click `console` to get to your dashboard.

### Create your application and login credentials
We need to create an application on TTN. This application will be the place where we can access any data being sent from our node.

1. In the menu bar select `Applications` and create your application.
2. In the menu bar on the left select `integrations` > `MQTT`.
3. At the bottom of the page, click `Generate new API key`

### Register your node to the application
Now we need to add our node to the application. This gives us some codes we can paste into the Arduino project, which will let TTN know what application our node belongs to.

1. Go to `applications` > select your application
2. On the bottom right select `Register end device`
3. For `input method` select `Enter end device specifics manually` and use these settings:

* Frequency plan: `Europe 863*871 MHz (SF9 for RX2 - recommmended)`
* LoRaWAN version: `LoRaWAN Specification 1.0.3`
* Regional Parameters version: `RP001 Regional Parameters 1.0.3 revision A`

![Device frequency settings](images/device_frequency_settings.png)

4. For JoinEUI, just enter 8 pairs of zeroes: `00 00 00 00 00 00 00 00`
5. Press `confirm` next to the JoinEUI field to have the next fields appear.
6. Press `Generate` behind the `DevEUI` and `APPKey` fields to generate random values.
7. The `End device ID` gets filled in automatically: replace this value with a human-readable name, like `my-wemos-node`. This will help you recognize your node in the interface.
8. Press `Register end device` to finish

![Device ID settings](images/device_ID_settings.png)

You now have all information you need to start programming your Wemos D1 mini to send data to The Things Network. Specifically what you need to copy to the Arduino code are the `AppEUI`, `DevEUI` and `AppKey` values.

First, click the `<>` icon behind the `AppEUI` and `DevEUI` fields. The text `msb` and two little arrows appear. Click those arrows to change the format to `lsb` (this basically reverses the values which is needed by the Arduino library), then press the copy icon to copy the value to your clipboard and paste them into the right spot in the Arduino code.

![Instructions on copying the keys](images/keys.png)
