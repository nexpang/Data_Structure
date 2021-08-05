using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q08
    {
        static void Main(string[] args)
        {
            Console.Write("num : ");
            int num = int.Parse(Console.ReadLine());
            Console.WriteLine();

            Console.Write(solution(num));

            int solution(int num, int count = 0)
            {
                if(num == 0)
                {
                    Console.WriteLine("0일땐 어떡하죠");
                    return 0;
                }
                else if(num == 1)
                {
                    return num;
                }
                else if (count >= 500)
                {
                    return -1;
                }
                else
                {
                    Console.Write(num + " -> ");
                    return solution(num % 2 == 0 ? num / 2 : (num * 3) + 1, ++count);
                }
            }
        }
    }
}