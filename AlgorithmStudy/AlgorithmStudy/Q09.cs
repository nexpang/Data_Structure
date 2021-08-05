using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q09
    {
        static void Main(string[] args)
        {
            Console.Write("num : ");
            long num = long.Parse(Console.ReadLine());
            if (num < 1 || num > 8000000000) { Console.WriteLine("잘못된 수를 입력했습니다."); return; }
            Console.WriteLine();

            Console.WriteLine(solution(num));

            long solution(long num)
            {
                char[] cArrNum = num.ToString().ToCharArray();
                Array.Sort(cArrNum);
                Array.Reverse(cArrNum);

                return long.Parse(cArrNum);
            }
        }
    }
}