using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q06
    {
        static void Main(string[] args)
        {
            Console.Write("첫번째 수: ");
            int num1 = int.Parse(Console.ReadLine());
            if (num1 < 1 || num1 > 1000000) { Console.WriteLine("잘못된 수를 입력했습니다."); return; }
            Console.Write("두번째 수: ");
            int num2 = int.Parse(Console.ReadLine());
            if (num2 < 1 || num2 > 1000000) { Console.WriteLine("잘못된 수를 입력했습니다."); return; }

            int[] arr = solution(num1, num2);

            Console.WriteLine("최대공약수: "+arr[0]+ ", 최소공배수: " +arr[1]);

            int[] solution(int num1, int num2)
            {
                int[] arr = new int[2];
                arr[0] = s1(num1, num2);
                arr[1] = num1 * num2 / arr[0];
                return arr;
            }

            int s1(int num1, int num2)
            {
                int min = num1 > num2 ? num2 : num1;
                int max = num1 > num2 ? num1 : num2;

                int result = min;

                result = max % min;
                max = min;

                if(result == 0)
                {
                    return min;
                }
                else
                {
                    return s1(max, result);
                }
            }
        }
    }
}