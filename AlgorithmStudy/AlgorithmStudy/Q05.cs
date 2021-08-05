using System;
using System.Collections.Generic;
using System.Text;

namespace _07_28
{
    class Q05
    {
        static void Main(string[] args)
        {
            int[] nArr = { 2, 1, 3, 4, 6, 5};

            int[] nArr2 = Q5(nArr);
            for (int i = 0; i < nArr2.Length; i++)
            {
                Console.WriteLine(nArr2[i]);
            }
            int[] Q5(int[] arr)
            {
                if (arr.Length == 1) {
                    arr[0] = -1;
                    return arr;
                }

                int lowestNum = arr[0];

                for (int i = 1; i < arr.Length; i++)
                {
                    if (arr[i] < lowestNum) lowestNum = arr[i];
                }

                int[] arr1 = new int[arr.Length - 1];
                int cnt = 0;

                for (int i = 0; i < arr.Length; i++)
                {
                    if (lowestNum != arr[i])
                    {
                        arr1[cnt] = arr[i];
                        cnt++;
                    }
                }

                return arr1;
            }
        }
    }
}