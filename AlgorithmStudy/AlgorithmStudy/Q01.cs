using System;

namespace _07_28
{
    class Q01
    {
        static void Main(string[] args)
        {
            Console.Write("가로 길이: ");
            int n = int.Parse(Console.ReadLine());
            if (n > 1000) { Console.WriteLine("1000초과된수 입력됨"); return; }
            Console.Write("세로 길이: ");
            int m = int.Parse(Console.ReadLine());
            if (m > 1000) { Console.WriteLine("1000초과된수 입력됨"); return; }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    //Console.Write("*");
                    if (i == 0 || i == m-1 || j == 0 || j == n-1)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.Write("\n");
            }
        }
    }
}
