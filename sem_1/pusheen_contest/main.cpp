#include <iostream>
#define NANOSVG_IMPLEMENTATION	   // Expands implementation
#include "nanosvg/src/nanosvg.h"
#define NANOSVGRAST_IMPLEMENTATION
#include "nanosvg/src/nanosvgrast.h"

#include "./draw/sdlwrapper.h"

using namespace std;

float lerp2(float a, float b, float x) { return x * a + (1. - x) * b; }

float lerp3(float a, float b, float c, float x) { return lerp2(lerp2(a, b, x), lerp2(b, c, x), x); }
float lerp4(float a, float b, float c, float d, float x) { return lerp2(lerp3(a, b, c, x), lerp3(b, c, d, x), x); }

void hsv2rgb(float h, float s, float v, float &r, float &g, float &b) {
	float hh, p, q, t, ff;
	long  i;

	if (s <= 0.0) {		// < is bogus, just shuts up warnings
		r = v;
		g = v;
		b = v;
		return;
	}
	hh = h;
	if (hh >= 360.0) hh = hh - floor(hh / 360.) * 360;
	hh /= 60.0;
	i  = (long)hh;
	ff = hh - i;
	p  = v * (1.0 - s);
	q  = v * (1.0 - (s * ff));
	t  = v * (1.0 - (s * (1.0 - ff)));

	switch (i) {
		case 0:
			r = v;
			g = t;
			b = p;
			break;
		case 1:
			r = q;
			g = v;
			b = p;
			break;
		case 2:
			r = p;
			g = v;
			b = t;
			break;

		case 3:
			r = p;
			g = q;
			b = v;
			break;
		case 4:
			r = t;
			g = p;
			b = v;
			break;
		case 5:
		default:
			r = v;
			g = p;
			b = q;
			break;
	}
	return;
}

float maxColor = -1.0;

void drawBezier(float a, float b, float c, float d, float e, float f, float g, float h, float &color) {
	float offset = 0.1;
	float prevX	 = lerp4(a, c, e, g, 0.);
	float prevY	 = lerp4(b, d, f, h, 0.);
	for (float i = 0; i <= 1.01; i += offset) {
		float x = lerp4(a, c, e, g, i);
		float y = lerp4(b, d, f, h, i);
		
        float r, g, b;
		hsv2rgb(color + maxColor, 1.0, 1.0, r, g, b);
        color += 1.0;
		sdlw::setColor(r * 255, g * 255, b * 255);
		
        sdlw::drawLine(prevX, prevY, x, y);
		prevX = x;
		prevY = y;
	}
}

int main() {
	sdlw::setColor(255, 255, 255);

	// // Load
	struct NSVGimage *image;
	image = nsvgParseFromFile("pusheen.svg", "px", 96);
	
	// Main loop flag
	bool quit = false;

	// Event handler
	SDL_Event e;

	// While application is running
	while (!quit) {
		// Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			// User requests quit
			if (e.type == SDL_QUIT) { quit = true; }
		}

		sdlw::setColor(0, 0, 0);
		sdlw::clear();
		sdlw::setColor(255, 255, 255);

		float color = 0;
		for (auto shape = image->shapes; shape != NULL; shape = shape->next) {
            for (auto path = shape->paths; path != NULL; path = path->next) {
				for (int i = 0; i < path->npts - 1; i += 3) {
					float *p = &path->pts[i * 2];
                    if(color > maxColor) break;

					drawBezier(p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], color);

					
                    // sdlw::drawLine(p[0], p[1], p[2], p[3]);
					// sdlw::drawLine(p[2], p[3], p[4], p[5]);
					// sdlw::drawLine(p[4], p[5], p[6], p[7]);
				}
			}
		}

        maxColor += 3.;

		// Update screen
		// SDL_Delay(16);
        SDL_Delay(10);
		sdlw::updateGraphics();
	}

	nsvgDelete(image);
}