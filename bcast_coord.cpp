#define USER_PACKET_TYPE 0x30
void startNode()
{
//initialize sensors
	tmpInit();
	lightSensorInit();

//initialize mac layer
	macInit();

	addTask(USER,SEND_PACKET_TO_MAC,1*SECOND);
}
void userTaskHandler(uint8 taskType)
{
	uint8 packet[4];
	uint8 tmp;
	uint16 light;
	bool check;

	//read sensor values
	tmp=readTmp();
	light=readLux();
	packet[0]=USER_PACKET_TYPE;
	packet[1]=tmp;
	packet[2]=light>>8;
	packet[3]=light;

	check=sendDataToMac(packet,4,0xFFFF,0,FALSE);	//16 bit broadcast address with no ack req. Mac ack should be disabled
								//when broadcast is done.
	if (check==FALSE)
	{
	}
	addTask(USER,SEND_PACKET_TO_MAC,1.2*SECOND);
}
void userCriticalTaskHandler(uint8 critTaskType)
{
	
}
void userReceiveDataPacket(uint8* payload,uint8 length,uint16 prevAddr,uint8 linkQuality)
{
	
}
