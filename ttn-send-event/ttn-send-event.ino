import paho.mqtt.client as mqtt
import base64
import json

username = 'FILLMEIN'
device_id = 'FILLMEIN'
api_key = 'FILLMEIN'

mqtt_server = 'eu1.cloud.thethings.network'
mqtt_port = 1883

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, reason_code, properties):
    print(f"Connected with result code: {reason_code}")
    client.subscribe(f"v3/{username}/devices/{device_id}/up")



# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    print("----------------------")
    print("Message received: ")
    print("Topic: ", msg.topic)
    payload = json.loads(msg.payload)
    print("Payload: ", payload)
    base64_message = payload['uplink_message']['frm_payload']
    decoded_bytes_message = base64.b64decode(base64_message)
    string_message = decoded_bytes_message.decode('utf-8')
    print("Decoded frm_payload: ", string_message)
    if string_message == 'A':
        print("Got an A, do thing one!")
    elif string_message == 'B':
        print("Got a B, do thing two!")

mqttclient = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
mqttclient.on_connect = on_connect
mqttclient.on_message = on_message

mqttclient.username_pw_set(username, api_key)
mqttclient.connect(mqtt_server, mqtt_port, 60)

# Don't exit the script but keep waiting for more data
mqttclient.loop_forever()
