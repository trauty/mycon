#include <stdio.h>
#include "pico/stdlib.h"
#include "tft.h"
#include "pico/time.h"
#include "math.h"

void draw_circle(int x0, int y0, int radius, int color) 
{
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        // Draw horizontal lines to fill the circle
        for (int i = x0 - x; i <= x0 + x; i++) {
            tft_draw_pixel(i, y0 + y, color);
            tft_draw_pixel(i, y0 - y, color);
        }

        for (int i = x0 - y; i <= x0 + y; i++) {
            tft_draw_pixel(i, y0 + x, color);
            tft_draw_pixel(i, y0 - x, color);
        }

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

int main() 
{
    tft_init();

    tft_fill(0);
    
    uint32_t last_time = to_ms_since_boot(get_absolute_time());

    int x_pos = tft_width / 2, y_pos = tft_height / 2;
    int x_last_pos = 0, y_last_pos = 0;
    float x_mov = 0.24, y_mov = 0.21;

    int x1_pos = tft_width / 2, y1_pos = tft_height / 2;
    int x1_last_pos = 0, y1_last_pos = 0;
    float x1_mov = 0.4, y1_mov = 0.38;

    int radius = 12;
    int radius1 = 6;

    tft_swap_sync();

    // bouncy balls
    while (true)
    {
        uint32_t current_time = to_ms_since_boot(get_absolute_time());

        x_pos += x_mov * (current_time - last_time);
        y_pos += y_mov * (current_time - last_time);

        x1_pos += x1_mov * (current_time - last_time);
        y1_pos += y1_mov * (current_time - last_time);

        if (x_pos >= tft_width - radius || x_pos <= radius)
        {
            x_mov = -x_mov;
            x_pos = x_last_pos;
        }
        if (y_pos >= tft_height - radius || y_pos <= radius)
        {
            y_mov = -y_mov;
            y_pos = y_last_pos;
        }
        if (x1_pos >= tft_width - radius1 || x1_pos <= radius1)
        {
            x1_mov = -x1_mov;
            x1_pos = x1_last_pos;
        }
        if (y1_pos >= tft_height - radius1 || y1_pos <= radius1)
        {
            y1_mov = -y1_mov;
            y1_pos = y1_last_pos;
        }

        last_time = current_time;

        tft_fill(0);

        draw_circle(x_last_pos, y_last_pos, radius, 0);
        draw_circle(x_pos, y_pos, radius, 255);

        draw_circle(x1_last_pos, y1_last_pos, radius1, 0);
        draw_circle(x1_pos, y1_pos, radius1, 247);

        x_last_pos = x_pos;
        y_last_pos = y_pos;

        x1_last_pos = x1_pos;
        y1_last_pos = y1_pos;

        tft_swap_sync();
    }

    return 0;
}