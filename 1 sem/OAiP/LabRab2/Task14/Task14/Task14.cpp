#include <iostream>

int main()
{
    long long W, H, x1, x2, y1, y2, w, h, rw, rh;
    std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if (x2 - x1 + w > W && y2 - y1 + h > H || W < w || H < h || W < x2 - x1 || H < y2 - y1) {
        std::cout << "-1";
        return 0;
    }

    if (x2 - x1 < W) {
        if (W - x2 >= w || x1 >= w)
        {
            rw = 0;
        }
        else if (w - W + x2 <= w - x1)
        {
            rw = w - W + x2;
        }
        else
        {
            rw = w - x1;
        }
    }

    if (y2 - y1 < H) {
        if (h - y2 >= h || y1 >= h)
        {
            rh = 0;
        }
        else if (h - H + y2 <= h - y1)
        {
            rh = h - H + y2;
        }
        else
        {
            rh = h - y1;
        }
    }


    if (rh == 0 && rw == 0)
    {
        std::cout << 0;
    }
    else if (rw <= rh)
    {
        std::cout << rw;
    }
    else
    {
        std::cout << rh;
    }

    return 0;
}