#include <stdio.h>
#include <stdlib.h>
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>
#include <unistd.h>
#include <time.h>

int main()
{
	// Create a fake mouse device
	struct libevdev *dev = libevdev_new();
	struct libevdev_uinput *uidev = NULL;

	libevdev_set_name(dev, "USB Fake Mouse");
	// Define what the is mouse if capable of
	libevdev_enable_event_type(dev, EV_REL);
	libevdev_enable_event_code(dev, EV_REL, REL_X, NULL);
	libevdev_enable_event_code(dev, EV_REL, REL_Y, NULL);

	libevdev_enable_event_type(dev, EV_KEY);
	libevdev_enable_event_code(dev, EV_KEY, BTN_LEFT, NULL);

	libevdev_enable_event_type(dev, EV_SYN);
	libevdev_enable_event_code(dev, EV_SYN, SYN_REPORT, NULL);

	int code = libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev);
	if(code != 0) 
	{
		perror("Error");
		return -1;
	}

	srand(time(NULL));
	// Fire fake mouse events
	while(1)
	{
		int amplitude = rand() % 410 - 200; // random number between [-20, 20]
		int direction = rand() % 2 == 0 ? REL_X : REL_Y; 
		libevdev_uinput_write_event(uidev, EV_REL, direction, amplitude);
		libevdev_uinput_write_event(uidev, EV_SYN, SYN_REPORT, 0);
		usleep(500000);
	}
	// printf("Hello World\n"); // just for test head files
	return 0;
}