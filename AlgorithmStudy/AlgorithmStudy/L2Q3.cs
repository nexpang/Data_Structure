using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class L2Q3
    {
        static void Main(string[] args)
        {
            string s = "onetwo3fourseven12nine3";
            Console.WriteLine();
            int[] prices = { 1, 2, 3, 2, 3, 4, 5, 6, 1, 2, 5, 4, 2, 5 };
            int[] result = Solution(prices);

            for (int i = 0; i < prices.Length; i++)
            {
                Console.Write((i + 1) + "초의 시점의 \\" + prices[i] + "은 ");
                if(i < prices.Length-1)
                {
                    if (prices[i] > prices[i+1])
                    {
                        Console.WriteLine("1초뒤에 가격이 떨어집니다. 따라서 " + result[i] + "초간 가격이 떨어지지 않은 것으로 봅니다.");
                    }
                    else
                    {
                        Console.WriteLine(result[i] + " 초간 가격이 떨어지지 않았습니다.");
                    }
                }
                else
                {
                    Console.WriteLine(result[i] + " 초간 가격이 떨어지지 않았습니다.");
                }
            }
        }

        static int[] Solution(int[] prices)
        {
            int[] result = new int[prices.Length];
            result[0] = 0;
            int sec =0;

            for (int i = 1; i < prices.Length; i++)
            {
                if(prices[i-1] >= prices[i])
                {
                    sec = 0;
                    result[i] = sec;
                }
                else
                {
                    sec++;
                    result[i] = sec;
                }
            }

            return result;
        }
    }
}