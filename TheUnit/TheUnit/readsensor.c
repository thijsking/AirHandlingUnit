#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void writebyte(int fd, char data){
	unsigned char buffer[2] = {data, 0};
	int length = 1;
	if(write(fd, buffer, length) != length)
	{
		printf("Failed to write to the i2c bus.\n");
		printf("%s\n", strerror(errno));
	}

}

int main(){
	int file_i2c;
	int length;
	unsigned char buffer[10] = {0};

	char *filename = "/dev/i2c-1";
	if((file_i2c = open(filename, O_RDWR)) < 0)
	{
		printf("Failed to open the i2c bus\n");
		printf("%s\n", strerror(errno));
		return -1;
	}

	int addr = 0x40;
	if((ioctl(file_i2c, I2C_SLAVE, addr)) < 0)
	{
		printf("Failed to acquire bus access and/or talk to slave.\n");
		printf("%s\n", strerror(errno));
		return -1;
	}

	while(1)
	{
		writebyte(file_i2c, 0xF5); //Measure RH, No-hold master mode

		int success = 0;
		while(!success){
			length = 3;
			if(read(file_i2c, buffer, length) != length)
			{
			//	printf("Failed to read from the i2c bus.\n");
			//	printf("%s\n", strerror(errno));
				usleep(100);
			}
			else
			{
			//	printf("Data read: %s\n", buffer);
				success = 1;
			}
		}
		int result = (buffer[0] << 8) + buffer[1];
		double humidity = (125.0*result)/65536 - 6;
		printf("Humidity: %.2f\%\t",humidity);

		writebyte(file_i2c, 0xE0); //Read temp from previous RH measurement

		length = 2;
		if(read(file_i2c, buffer, length) != length)
		{
		//	printf("Failed to read from the i2c bus.\n");
		//	printf("%s\n", strerror(errno));
			usleep(100);
		}
		else
		{
		//	printf("Data read: %s\n", buffer);
		}
		result = (buffer[0] << 8) + buffer[1];
		double temperature = (175.72*result)/65536 - 46.85;
		printf("Temperature: %.2f C\n",temperature);
		sleep(2);
	}

}

// vim: ts=4
