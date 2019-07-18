#include <ePaperDriver.h>
#include <Fonts/FreeSansBoldOblique12pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

ePaperDisplay *device;

void setup() {
#if defined( ESP8266 )
	device = new ePaperDisplay( GDEW0371Z80, D1, D2, D3, D8 );
#else
	device = new ePaperDisplay( GDEW0371Z80, 3, 4, 5, 10 );
#endif
	device->initializeDevice();	
}

void loop() {
	//
	// demonstrate using the Adafruit GFX primitives to draw an image
	//
	device->powerOn();
	device->setFont(&FreeSansBoldOblique12pt7b);
	device->setTextColor(ePaper_BLACK);
	device->setRotation(0);
	
	const __FlashStringHelper	* str = F("Hello World!");
	int16_t x1, y1;
	uint16_t w, h;

	device->getTextBounds(str, 0, 0, &x1, &y1, &w, &h);
  
	int centerX = device->width()/2;
	int centerY = device->height()/2;
	int radius = device->width()/2 - 1;

	device->clearDisplay();
	device->fillCircle(centerX, centerY, radius, ePaper_COLOR);
	device->fillTriangle(
		centerX, centerY-radius,
		centerX - 2*radius*sin(PI/3.0)*sin(PI/6.0), centerY + radius*(2.0*sin(PI/3.0)*sin(PI/3.0)-1.0),
		centerX + 2*radius*sin(PI/3.0)*sin(PI/6.0), centerY + radius*(2.0*sin(PI/3.0)*sin(PI/3.0)-1.0),  
		ePaper_BLACK		
	);
	device->fillTriangle(
		centerX, centerY + radius*(2.0*sin(PI/3.0)*sin(PI/3.0)-1.0),
		centerX - radius*sin(PI/6.0)*sin(PI/3.0), centerY - radius*(1.0-sin(PI/3.0)*sin(PI/3.0)),
		centerX + radius*sin(PI/6.0)*sin(PI/3.0), centerY - radius*(1.0-sin(PI/3.0)*sin(PI/3.0)),  
		ePaper_WHITE		
	);
	
	device->setCursor(centerX-w/2, device->height() - 8);
	device->print(str);
		
	device->refreshDisplay();
	device->powerOff();
	delay(10000);

	//
	// demonstrate drawing to a "rotated" screen
	//
	device->powerOn();
	device->setFont(&FreeSansBold24pt7b);
	device->setTextColor(ePaper_INVERSE1);
	device->setRotation(1);
	device->clearDisplay();
	device->fillTriangle(
		0, 0,
		device->width(), 0,
		0, device->height(),
		ePaper_COLOR		
	);
	
	device->getTextBounds(str, 0, 0, &x1, &y1, &w, &h);
	device->setCursor(device->width()/2-w/2, device->height()/2 - 14 );
	device->print(str);
	device->setCursor(device->width()/2-w/2, device->height()/2 + 14 + h );
	device->print(str);
	
	device->refreshDisplay();
	device->powerOff();
	delay(10000);
	
}
