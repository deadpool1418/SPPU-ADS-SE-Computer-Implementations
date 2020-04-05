package calculator;
interface cal
{
   public int add(int a,int b);
   public int sub(int a,int b);
}
public class calc implements cal{
   public int add(int a,int b)
     {  return a+b;}
   public int sub(int a,int b)
     {return a-b;}
}
   
    

