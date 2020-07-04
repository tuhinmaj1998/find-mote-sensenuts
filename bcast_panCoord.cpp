#define USER_PACKET_TYPE 0x30


void startNode()
{
//initialize uart
	sendToPcInit();

//initialize mac layer
	macInit();
}

void userTaskHandler(uint8 taskType)
{
}

void userReceiveDataPacket(uint8* payload,uint8 length,uint16 prevAddr,uint8 linkQuality)
{
	uint8 tmp;
	uint16 light;	

	if (payload[0]==USER_PACKET_TYPE)
	{
		tmp=payload[1];
		light=payload[2];
		light=light<<8;
		light=light | payload[3];

		//update info in database present in PC
		updateAmbientdb(prevAddr,linkQuality,tmp);
	}
}

void userCriticalTaskHandler(uint8 critTaskType)
{	
}
