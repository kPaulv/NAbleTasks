using System;

namespace MaclaurinRow
{
    class Program
    {
        static long fact(uint x)
        {
            long factorial = 1;
            for(int i = 2; i <= x; i++)
            {
                factorial *= i;
            }
            return factorial;
        }

        static bool isEven(uint k)
        {
            return k % 2 == 0;
        }

        static double rowSum(double x, double eps)
        {
            double rowSum = 0;
            double prevSum = 0;
            uint k = 0;
            do
            {
                prevSum = rowSum;
                if(isEven(k))
                {
                    rowSum += Math.Pow(x, 2 * k + 1) / fact(2 * k + 1);
                } else
                {
                    rowSum -= Math.Pow(x, 2 * k + 1) / fact(2 * k + 1);
                }
                k++;
            } while (Math.Abs(rowSum - prevSum) > eps);
            return rowSum;
        }
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine("Enter value of x: ");
                double x = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("Enter epsilon - accuracy: ");
                double eps = Convert.ToDouble(Console.ReadLine());
                double sum = rowSum(x, eps);
                Console.WriteLine($"The sum of a Maclaurin row for sin(x) is: " + "{0:f4}", sum);
            } catch (FormatException)
            {
                Console.WriteLine("Wrong data format.");
            }
        }
    }
}
