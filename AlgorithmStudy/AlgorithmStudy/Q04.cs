using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q04
    {
        static void Main(string[] args)
        {
            int[] nArr = { 5,5,5,5,5 };

            Console.WriteLine(Avr(nArr));

            int Avr(int[] arr)
            {
                int n = 0;
                if(arr.Length<1 || arr.Length > 100)
                {
                    Console.WriteLine("잘못된 배열입니다.");
                    return 0;
                }

                for (int i = 0; i < arr.Length; i++)
                {
                    if(arr[i]<-10000 || arr[i] > 10000)
                    {
                        Console.WriteLine("잘못된 원소입니다.");
                        return 0;
                    }
                    n += (int)((float)arr[i] / (float)arr.Length);
                }
                    
                return n;
            }
        }
    }
}