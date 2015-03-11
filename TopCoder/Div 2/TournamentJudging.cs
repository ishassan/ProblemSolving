//TC SRM 408-D2-1   Execution Time = 0.000 s
using System;
using System.Collections.Generic;
using System.Text;



public class TournamentJudging
{
    public int rounded(double num)
    {
        int intNum = (int)num;

        if ((num - intNum) < 0.5)
            return intNum;
        else
            return intNum + 1;

    }
    public int getPoints(int[] rawScores, int[] conversionFactor)
    {
        int sum = 0;

        for (int i = 0; i < rawScores.Length; i++)
        {
            sum += rounded((double)rawScores[i] / (double)conversionFactor[i]);
        }

        return sum;
        
    }
}

class Program
{
    
    public static void Main(string[] args)
    {
        TournamentJudging a = new TournamentJudging();
        int[] rawScores = { 0, 1000000, 5000, 1000000 };
        int[] conversionFactor ={ 1, 2, 1000000, 4 };

        Console.WriteLine(a.getPoints(rawScores, conversionFactor));
        
        Console.ReadKey(true);
    }
}

