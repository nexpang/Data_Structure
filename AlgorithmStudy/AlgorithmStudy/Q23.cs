using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _07_28
{
    class Q23
    {
        static void Main(string[] args)
        {
            Console.Write("month : ");
            int a = int.Parse(Console.ReadLine());
            if(a>12)
            {
                Console.WriteLine("잘못된 값이 입력 되었습니다.");
                return;
            }
            Console.Write("day : ");
            int b = int.Parse(Console.ReadLine());
            if (a%2 == 0)
            {
                if(a!=2)
                {
                    if(b>30)
                    {
                        Console.WriteLine("잘못된 값이 입력 되었습니다.");
                        return;
                    }
                }
                else if(b>29)
                {
                    Console.WriteLine("잘못된 값이 입력 되었습니다.");
                    return;
                }
            }
            else
            {
                if (b > 31)
                {
                    Console.WriteLine("잘못된 값이 입력 되었습니다.");
                    return;
                }
            }
            Console.WriteLine();

            Console.WriteLine(Solution(a, b));
        }

        static string Solution(int a, int b)
        {
            DateTime dT = new DateTime(2024, a, b);

            switch (dT.DayOfWeek)
            {
                case DayOfWeek.Sunday:
                    return "SUN";
                    break;
                case DayOfWeek.Monday:
                    return "MON";
                    break;
                case DayOfWeek.Tuesday:
                    return "TUE";
                    break;
                case DayOfWeek.Wednesday:
                    return "WED";
                    break;
                case DayOfWeek.Thursday:
                    return "THU";
                    break;
                case DayOfWeek.Friday:
                    return "FRI";
                    break;
                case DayOfWeek.Saturday:
                    return "SAT";
                    break;
                default:
                    return "";
                    break;
            }
        }
    }
}