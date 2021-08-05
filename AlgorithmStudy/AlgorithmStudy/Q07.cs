using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q07
    {
        static void Main(string[] args)
        {

            Console.Write("x : ");
            int x = int.Parse(Console.ReadLine());
            if (x < -10000000 || x > 10000000) { Console.WriteLine("잘못된 수를 입력했습니다."); return; }
            Console.Write("n : ");
            int n = int.Parse(Console.ReadLine());
            if (n > 1000) { Console.WriteLine("잘못된 수를 입력했습니다."); return; }
            Console.WriteLine();

            foreach (int item in solution(x, n))
            {
                Console.Write(item+" ");
            }

            List<int> solution(int x, int n)
            {
                List<int> list = new List<int>();
                for (int i = 0; i < n; i++)
                {
                    list.Add(x + i * x);
                }

                return list;
            }
        }
    }
}