#include<stdio.h>
#include<math.h> 
#include<windows.h>
#include<tchar.h>
//#define n 10
/*int main() {
    for (float y = 1.5f; y > -1.5f; y -= 0.1f) {
        for (float x = -1.5f; x < 1.5f; x += 0.05f) {
            float a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
        }
        putchar('\n');
    }
}*/

/*const int w = 23;
const int h = 12;
int main(void)*/

//main(int i){for(i=0;i<288;i++)printf(i%24-23?abs(i%24-11)*24>i|abs((i%24+i/72*3+3)%6-2)>i/24%3?"  ":"* ":"\n");}
/*int f(int x, int y) {
    return  ((x*x+y*y-1)*(x*x+y*y-1)*(x*x+y*y-1)-x*x*y*y*y)<= 0 ;
}

int main() 
{
    int x, y;
    for (y = 0; y < h; y++)
	{
        for (x = 0; x < w; x++)
            printf(f(x, y) ? "* " : "  ");
        puts("");
    }
}*/

//--------------------------------------------------------------------------------------------

/*float f(float x, float y, float z) {
    float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z) {
    for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
        if (f(x, y, z) <= 0.0f)
            return y;
    return 0.0f;
}

int main() {
    for (float z = 1.5f; z > -1.5f; z -= 0.05f) {
        for (float x = -1.5f; x < 1.5f; x += 0.025f) {
            float v = f(x, 0.0f, z);
            if (v <= 0.0f) {
                float y0 = h(x, z);
                float ny = 0.01f;
                float nx = h(x + ny, z) - y0;
                float nz = h(x, z + ny) - y0;
                float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
                float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
                putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }
}*/

//--------------------------------------------------------------------------------

float f(float x, float y, float z) {
    float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z) {
    for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
        if (f(x, y, z) <= 0.0f)
            return y;
    return 0.0f;
}

int main() {
	 HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
    _TCHAR buffer[25][80] = { _T(' ') };
    _TCHAR ramp[] = _T(".:-=+*#%@");
	for (float t = 0.0f;; t += 0.1f) {
        int sy = 0;
        float s = sinf(t);
        float a = s * s * s * s * 0.2f;
        for (float z = 1.3f; z > -1.2f; z -= 0.1f) {
            _TCHAR* p = &buffer[sy++][0];
            float tz = z * (1.2f - a);
            for (float x = -1.5f; x < 1.5f; x += 0.05f) {
                float tx = x * (1.2f + a);
                float v = f(tx, 0.0f, tz);
                if (v <= 0.0f) {
                    float y0 = h(tx, tz);
                    float ny = 0.01f;
                    float nx = h(tx + ny, tz) - y0;
                    float nz = h(tx, tz + ny) - y0;
                    float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
                    float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
                    *p++ = ramp[(int)(d * 5.0f)];
                }
                else
                    *p++ = ' ';
            }
        }

        for (sy = 0; sy < 25; sy++) {
            COORD coord = { 0, sy };
            SetConsoleCursorPosition(o, coord);
            WriteConsole(o, buffer[sy], 79, NULL, 0);
        }
        Sleep(33);
    }
}
