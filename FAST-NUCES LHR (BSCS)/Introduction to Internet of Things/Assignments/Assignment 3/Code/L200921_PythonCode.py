import asyncio
import time
import json
from azure.iot.device.aio import IoTHubDeviceClient
from azure.iot.device import Message


async def connect():
    connection_str = "HostName=aishaHub.azure-devices.net;DeviceId=VirtualDeviceAisha;SharedAccessKey=AXcaGK5QrFV2DjCpb2g/et0bVrKS0eGNqAIoTFG+TxA="
    device_client = IoTHubDeviceClient.create_from_connection_string(connection_str)

    await device_client.connect()
    print('connected')
    return device_client


async def send_data(device_client, points):
    #Here looping over points list and sending each point to IoT hub 
    i=0
    for point in points:
        # each point dictionary object must be stringified, because Message() constructor only accepts integer or string data
        message = Message(data=json.dumps(point))
        await device_client.send_message(message)
        i=i+1
        print(f"Message {i} successfully sent!")
        time.sleep(0.5)  # delay before sending next point

def main():
    device_client = asyncio.run(connect())

    #Reading points from route file
    
    # file opening
    file = open('route1.json')
    route = json.load(file) #JSON object in dictionary form saved in 'route'

    # Iterating through file contents
    points=[]
    count=0
    for point in route['features'][0]['geometry']['coordinates']:
        dictionaryTemp={"lat":point[0],"lng":point[1],"count":count}
        points.append(dictionaryTemp)
        count=count+1
        
    # Closing file
    file.close()
    asyncio.run(send_data(device_client, points))

    # finally, shut down the client
    asyncio.run(device_client.shutdown())


if __name__ == "__main__":
    main()