int thumbwidth = 15;
int thumbheight = 15;
double xscale = (thumbwidth+0.0) / width;
double yscale = (thumbheight+0.0) / height;
double threshold = 0.5 / (xscale * yscale);
double yend = 0.0;
for (int f = 0; f < thumbheight; f++) // y on output
{
    double ystart = yend;
    yend = (f + 1) / yscale;
    if (yend >= height) yend = height - 0.000001;
    double xend = 0.0;
    for (int g = 0; g < thumbwidth; g++) // x on output
    {
        double xstart = xend;
        xend = (g + 1) / xscale;
        if (xend >= width) xend = width - 0.000001;
        double sum = 0.0;
        for (int y = (int)ystart; y <= (int)yend; ++y)
        {
            double yportion = 1.0;
            if (y == (int)ystart) yportion -= ystart - y;
            if (y == (int)yend) yportion -= y+1 - yend;
            for (int x = (int)xstart; x <= (int)xend; ++x)
            {
                double xportion = 1.0;
                if (x == (int)xstart) xportion -= xstart - x;
                if (x == (int)xend) xportion -= x+1 - xend;
                sum += picture4[y][x] * yportion * xportion;
            }
        }
        picture3[f][g] = (sum > threshold) ? 1 : 0;
    }
}


//for downsizing images, code is from https://stackoverflow.com/questions/9570895/image-downscaling-algorithm



//https://stackoverflow.com/questions/46124517/visual-studio-2017-windows-forms-how-to-set-exe-icon-visual-c



//how to set exe icon ^
