using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q16
    {
        static void Main(string[] args)
        {
            Console.Write("num : ");
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine();

            Console.WriteLine(Solution(n));
        }

        static int Solution(int n)
        {
            int result = 0;
            if (n > 1)
            {
                for (int i = 0; i < n-2; i++)
                {
                    bool plus = true;

                    for (int j = 0; j < i; j++)
                    {
                        if ((i+2) % (j+2) == 0)
                        {
                            plus = false;
                            break;
                        }
                    }

                    if (plus)
                    {
                        result++;
                    }
                }
            }
            Console.WriteLine();

            return result;
        }
    }
}