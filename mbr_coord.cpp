#define SEND_PACKET_TO_MAC 0

#define USER_PACKET_TYPE 0x30

void startNode()
{
//initialize sensors
	tmpInit();
	lightSensorInit();

//initialize mac layer
	macInit();

//initialize routing
	routingInit();


	addTask(USER,SEND_PACKET_TO_MAC,1*SECOND);
}

void userTaskHandler(uint8 taskType)
{
	uint8 packet[6],tmp;
	uint16 light;
	uint16 nodeId=getNodeId();
	int8 check;

	//read sensor values
	tmp=readTmp();
	light=readLux();

	packet[0]=USER_PACKET_TYPE;	//packet type info
	packet[1]=tmp;				//temperature
	packet[2]=light>>8;			//light info
	packet[3]=light;
	packet[4]=nodeId>>8;		//source address
	packet[5]=nodeId;

	check=routingSendData(packet, 6, 0);	//0 is the destination address

	if (check<=0)
	{
		//packet is dropped
	}

	addTask(USER,SEND_PACKET_TO_MAC,1*SECOND);

}


void userCriticalTaskHandler(uint8 critTaskType)
{
	
}

void userReceiveDataPacket(uint8* payload,uint8 length,uint16 prevAddr,uint8 linkQuality)
{
	
}
