using System;
public class Test
{


    public static void Main(string[] args)
    {
        int a = 10;
        Static.b = a;
        Static st = new Static();

        Console.WriteLine(Static.b++);
        Console.WriteLine(Static.b);
        Console.WriteLine(a);
        Console.WriteLine(st.a);
    }

    
}

class Static
{
    public int a = 20;
    public static int b = 0;
}