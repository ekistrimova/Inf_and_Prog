using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    internal class BlurFilter : MatrixFilter
    {
        public BlurFilter()
        {
            int sizeX = 7;
            int sizeY = 7;
            kernel = new float[sizeX, sizeY];
            for (int i = 0; i < sizeX; i++)
                for (int j = 0; j < sizeY; j++)
                    kernel[i, j] = 1.0f / (float)(sizeX * sizeY);
        }
    }
}
