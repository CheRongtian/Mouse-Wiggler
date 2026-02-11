#include <stdio.h>
#include <stdlib.h>
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>

int main()
{
	// Create a fake mouse device
	struct libevdev *dev = libevdev_new();
	struct libevdev_uinput *uidev = NULL;

	int code = libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev);
	if(code != 0) 
	{
		perror("Error");
		return -1;
	}
	// Define what the is mouse if capable of
	// Fire fake mouse events
	// printf("Hello World\n"); // just for test head files
	return 0;
}